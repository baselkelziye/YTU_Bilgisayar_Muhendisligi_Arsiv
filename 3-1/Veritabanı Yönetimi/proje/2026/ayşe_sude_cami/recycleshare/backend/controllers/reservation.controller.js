const { query } = require('../config/database');

// ============================================
// RESERVATIONS CONTROLLER
// ============================================

/**
 * GET /api/reservations
 * Tüm rezervasyonları listele
 */
const getAllReservations = async (req, res) => {
  try {
    const { status, waste_id } = req.query;

    let sql = `
      SELECT 
        r.*,
        w.amount,
        w.description AS waste_description,
        wt.type_name,
        wt.official_unit,
        u_owner.first_name || ' ' || u_owner.last_name AS owner_name,
        u_owner.city,
        u_owner.district,
        u_owner.phone AS owner_phone,
        u_collector.first_name || ' ' || u_collector.last_name AS collector_name,
        u_collector.phone AS collector_phone
      FROM reservations r
      JOIN waste w ON r.waste_id = w.waste_id
      JOIN waste_types wt ON w.type_id = wt.type_id
      JOIN users u_owner ON w.user_id = u_owner.user_id
      JOIN users u_collector ON r.collector_id = u_collector.user_id
      WHERE 1=1
    `;
    const params = [];
    let paramIndex = 1;

    if (status) {
      sql += ` AND r.status = $${paramIndex}`;
      params.push(status);
      paramIndex++;
    }

    if (waste_id) {
      sql += ` AND r.waste_id = $${paramIndex}`;
      params.push(waste_id);
      paramIndex++;
    }

    sql += ` ORDER BY r.created_at DESC`;

    const result = await query(sql, params);

    res.json({
      success: true,
      count: result.rows.length,
      data: result.rows
    });

  } catch (error) {
    console.error('getAllReservations error:', error);
    res.status(500).json({
      success: false,
      message: 'Rezervasyonlar listelenirken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/reservations/:id
 * Tek rezervasyon detayı
 */
const getReservationById = async (req, res) => {
  try {
    const { id } = req.params;

    const result = await query(`
      SELECT 
        r.*,
        w.amount,
        w.description AS waste_description,
        wt.type_name,
        wt.official_unit,
        u_owner.first_name || ' ' || u_owner.last_name AS owner_name,
        u_owner.city,
        u_owner.district,
        u_owner.neighborhood,
        u_owner.street,
        u_owner.address_details,
        u_owner.phone AS owner_phone,
        u_collector.first_name || ' ' || u_collector.last_name AS collector_name,
        u_collector.phone AS collector_phone
      FROM reservations r
      JOIN waste w ON r.waste_id = w.waste_id
      JOIN waste_types wt ON w.type_id = wt.type_id
      JOIN users u_owner ON w.user_id = u_owner.user_id
      JOIN users u_collector ON r.collector_id = u_collector.user_id
      WHERE r.reservation_id = $1
    `, [id]);

    if (result.rows.length === 0) {
      return res.status(404).json({
        success: false,
        message: 'Rezervasyon bulunamadı'
      });
    }

    res.json({
      success: true,
      data: result.rows[0]
    });

  } catch (error) {
    console.error('getReservationById error:', error);
    res.status(500).json({
      success: false,
      message: 'Rezervasyon detayı alınırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * POST /api/reservations
 * Yeni rezervasyon oluştur (SEQUENCE ve TRIGGER kullanır)
 */
const createReservation = async (req, res) => {
  try {
    const { waste_id, pickup_datetime } = req.body;
    const collector_id = req.user.user_id;

    // Validasyon
    if (!waste_id || !pickup_datetime) {
      return res.status(400).json({
        success: false,
        message: 'waste_id ve pickup_datetime gerekli'
      });
    }

    // Atık kontrolü
    const wasteCheck = await query(
      'SELECT * FROM waste WHERE waste_id = $1',
      [waste_id]
    );

    if (wasteCheck.rows.length === 0) {
      return res.status(404).json({
        success: false,
        message: 'Atık bulunamadı'
      });
    }

    // Atık durumu kontrolü
    if (wasteCheck.rows[0].status !== 'waiting') {
      return res.status(400).json({
        success: false,
        message: 'Bu atık için rezervasyon yapılamaz (durum: ' + wasteCheck.rows[0].status + ')'
      });
    }

    // Kendi atığına rezervasyon yapamaz
    if (wasteCheck.rows[0].user_id === collector_id) {
      return res.status(400).json({
        success: false,
        message: 'Kendi atığınıza rezervasyon yapamazsınız'
      });
    }

    // SEQUENCE kullanarak rezervasyon numarası al
    const seqResult = await query("SELECT nextval('reservation_number_seq') as reservation_number");
    const reservationNumber = seqResult.rows[0].reservation_number;

    // INSERT - trigger should update waste.status to 'reserved'.
    const result = await query(`
      INSERT INTO reservations (waste_id, collector_id, pickup_datetime, status)
      VALUES ($1, $2, $3, 'waiting')
      RETURNING *
    `, [waste_id, collector_id, pickup_datetime]);

    // Poll trigger_logs and waste status briefly to confirm trigger fired
    let triggerMessage = null;
    const maxRetries = 8;
    const waitMs = 150;
    for (let attempt = 0; attempt < maxRetries; attempt++) {
      // Try to find a trigger log specific to this waste_id
      const tLog = await query(`
        SELECT message, new_data, old_data FROM trigger_logs
        WHERE trigger_name = 'trg_reservation_status_change'
          AND table_name = 'reservations'
          AND (COALESCE((new_data->>'waste_id'), (old_data->>'waste_id')))::int = $1
        ORDER BY created_at DESC LIMIT 1
      `, [waste_id]);

      // Check current waste status
      const wasteRow = await query('SELECT status FROM waste WHERE waste_id = $1', [waste_id]);
      const currentStatus = wasteRow.rows.length > 0 ? wasteRow.rows[0].status : null;

      if (tLog.rows.length > 0) {
        triggerMessage = tLog.rows[0].message || null;
      }

      if (currentStatus === 'reserved' || triggerMessage) {
        break; // trigger likely ran
      }

      // wait a bit then retry
      await new Promise(resolve => setTimeout(resolve, waitMs));
    }

    // Re-fetch the reservation to return the most up-to-date row
    const freshRes = await query('SELECT * FROM reservations WHERE reservation_id = $1', [result.rows[0].reservation_id]);

    res.status(201).json({
      success: true,
      message: 'Rezervasyon başarıyla oluşturuldu',
      reservationNumber: reservationNumber,
      triggerMessage: triggerMessage,
      data: freshRes.rows[0]
    });

  } catch (error) {
    console.error('createReservation error:', error);
    res.status(500).json({
      success: false,
      message: 'Rezervasyon oluşturulurken hata oluştu',
      error: error.message
    });
  }
};

/**
 * PUT /api/reservations/:id
 * Rezervasyon durumunu güncelle - ADMIN AND RESERVER ONLY
 * Status: waiting, reserved, cancelled
 */
const updateReservation = async (req, res) => {
  try {
    const { id } = req.params;
    const { status, pickup_datetime } = req.body;

    // Rezervasyon kontrolü
    const resCheck = await query(`
      SELECT r.*, w.user_id as owner_id
      FROM reservations r
      JOIN waste w ON r.waste_id = w.waste_id
      WHERE r.reservation_id = $1
    `, [id]);

    if (resCheck.rows.length === 0) {
      return res.status(404).json({
        success: false,
        message: 'Rezervasyon bulunamadı'
      });
    }

    const reservation = resCheck.rows[0];

    // Authorization check - Admin veya rezervasyon sahibi
    if (req.user.role !== 'admin' && req.user.user_id !== reservation.collector_id) {
      return res.status(403).json({
        success: false,
        message: 'Bu işlem sadece adminler ve rezervasyon sahipleri tarafından yapılabilir'
      });
    }

    // Dinamik güncelleme
    const updates = [];
    const values = [];
    let paramIndex = 1;

    if (status !== undefined) {
      // Status değeri kontrolü - Admin sadece waiting, reserved, cancelled yapabilir
      const validStatuses = ['waiting', 'reserved', 'cancelled'];
      if (!validStatuses.includes(status)) {
        return res.status(400).json({
          success: false,
          message: 'Geçersiz durum. Admin yapabilir: ' + validStatuses.join(', ')
        });
      }
      updates.push(`status = $${paramIndex}`);
      values.push(status);
      paramIndex++;
    }

    if (pickup_datetime !== undefined) {
      updates.push(`pickup_datetime = $${paramIndex}`);
      values.push(pickup_datetime);
      paramIndex++;
    }

    if (updates.length === 0) {
      return res.status(400).json({
        success: false,
        message: 'Güncellenecek alan belirtilmedi'
      });
    }

    values.push(id);
    const sql = `
      UPDATE reservations 
      SET ${updates.join(', ')} 
      WHERE reservation_id = $${paramIndex}
      RETURNING *
    `;

    const result = await query(sql, values);

    // Eğer cancelled yapılıyorsa waste'i waiting'e çevir
    if (status === 'cancelled') {
      await query(
        'UPDATE waste SET status = $1 WHERE waste_id = $2',
        ['waiting', reservation.waste_id]
      );
    }

    res.json({
      success: true,
      message: 'Rezervasyon başarıyla güncellendi',
      data: result.rows[0]
    });

  } catch (error) {
    console.error('updateReservation error:', error);
    res.status(500).json({
      success: false,
      message: 'Rezervasyon güncellenirken hata oluştu',
      error: error.message
    });
  }
};

/**
 * POST /api/reservations/:id/complete-collection
 * Teslimat ve Veri Doğrulama: Collector tarafından çağrılır
 * 1. Waste amount güncellenir
 * 2. Reservation status = 'collected'
 * 3. Waste status = 'collected'
 * 4. Otomatik puan hesaplaması (Trigger)
 *    - Owner: recycle_score * amount
 *    - Collector: Owner puanının %70'i
 */
const completeCollection = async (req, res) => {
  try {
    const { id } = req.params;
    const { actual_amount } = req.body;
    const collector_id = req.user.user_id;

    // Validasyon
    if (!actual_amount || parseFloat(actual_amount) <= 0) {
      return res.status(400).json({
        success: false,
        message: 'Geçerli bir miktar giriniz (0 dan büyük olmalı)'
      });
    }

    // Rezervasyon kontrolü
    const resCheck = await query(`
      SELECT r.*, w.waste_id, w.user_id as owner_id, w.type_id
      FROM reservations r
      JOIN waste w ON r.waste_id = w.waste_id
      WHERE r.reservation_id = $1
    `, [id]);

    if (resCheck.rows.length === 0) {
      return res.status(404).json({
        success: false,
        message: 'Rezervasyon bulunamadı'
      });
    }

    const reservation = resCheck.rows[0];

    // Yetki kontrolü: Sadece bu rezervasyonun toplayıcısı yapabilir
    if (reservation.collector_id !== collector_id) {
      return res.status(403).json({
        success: false,
        message: 'Bu koleksiyonu tamamlama yetkiniz yok'
      });
    }

    // Durum kontrolü: Sadece waiting veya reserved durumdan tamamlanabilir
    if (!['waiting', 'reserved'].includes(reservation.status)) {
      return res.status(400).json({
        success: false,
        message: `Bu rezervasyon zaten ${reservation.status} durumundadır`
      });
    }

    // Atık türü bilgisini al (recycle_score için)
    const wasteTypeResult = await query(
      'SELECT recycle_score FROM waste_types WHERE type_id = $1',
      [reservation.type_id]
    );

    if (wasteTypeResult.rows.length === 0) {
      return res.status(404).json({
        success: false,
        message: 'Atık türü bulunamadı'
      });
    }

    const recycleScore = wasteTypeResult.rows[0].recycle_score;
    const ownerPoints = Math.floor(recycleScore * parseFloat(actual_amount));
    const collectorPoints = Math.floor(ownerPoints * 0.7);

    // Transaction başlat
    await query('BEGIN');

    try {
      // 1. Waste amount'ı güncelle
      await query(
        'UPDATE waste SET amount = $1, status = $2 WHERE waste_id = $3',
        [actual_amount, 'collected', reservation.waste_id]
      );

      // 2. Reservation statusunu güncelle
      await query(
        'UPDATE reservations SET status = $1 WHERE reservation_id = $2',
        ['collected', id]
      );

      // 3. Owner'a puan ekle
      const currentMonth = new Date().getMonth() + 1;
      const currentYear = new Date().getFullYear();

      await query(`
        INSERT INTO environmental_scores (user_id, month, year, total_score)
        VALUES ($1, $2, $3, $4)
        ON CONFLICT (user_id, month, year)
        DO UPDATE SET total_score = environmental_scores.total_score + $4
      `, [reservation.owner_id, currentMonth, currentYear, ownerPoints]);

      // 4. Collector'a puan ekle
      await query(`
        INSERT INTO environmental_scores (user_id, month, year, total_score)
        VALUES ($1, $2, $3, $4)
        ON CONFLICT (user_id, month, year)
        DO UPDATE SET total_score = environmental_scores.total_score + $4
      `, [collector_id, currentMonth, currentYear, collectorPoints]);

      // 5. Trigger log'a kaydet
      await query(
        `INSERT INTO trigger_logs (trigger_name, table_name, action, new_data, message)
         VALUES ($1, $2, $3, $4, $5)`,
        [
          'completeCollection',
          'reservations',
          'UPDATE',
          JSON.stringify({ reservation_id: id, status: 'collected', actual_amount }),
          `Koleksiyon tamamlandı! Owner: +${ownerPoints} PTS, Collector: +${collectorPoints} PTS`
        ]
      );

      // Transaction commit
      await query('COMMIT');

      // Güncellenmiş veriyi döndür
      const updatedRes = await query(
        'SELECT * FROM reservations WHERE reservation_id = $1',
        [id]
      );

      res.json({
        success: true,
        message: 'Koleksiyon başarıyla tamamlandı!',
        data: {
          reservation: updatedRes.rows[0],
          pointsAwarded: {
            owner: {
              userId: reservation.owner_id,
              points: ownerPoints,
              reason: `${recycleScore} score × ${actual_amount} amount`
            },
            collector: {
              userId: collector_id,
              points: collectorPoints,
              reason: `70% of owner's points`
            }
          },
          wasteUpdated: {
            wasteId: reservation.waste_id,
            newAmount: actual_amount,
            status: 'collected'
          }
        }
      });

    } catch (txError) {
      await query('ROLLBACK');
      console.error('completeCollection transaction error:', txError);
      throw txError;
    }

  } catch (error) {
    console.error('completeCollection error:', error);
    res.status(500).json({
      success: false,
      message: 'Koleksiyon tamamlanırken hata oluştu',
      error: error.message
    });
  }
};


/**
 * DELETE /api/reservations/:id
 * Rezervasyon sil
 */
const deleteReservation = async (req, res) => {
  try {
    const { id } = req.params;
    const user_id = req.user.user_id;

    // Rezervasyon kontrolü
    const resCheck = await query(
      'SELECT * FROM reservations WHERE reservation_id = $1',
      [id]
    );

    if (resCheck.rows.length === 0) {
      return res.status(404).json({
        success: false,
        message: 'Rezervasyon bulunamadı'
      });
    }

    // Admin değilse sadece kendi rezervasyonunu silebilir
    if (resCheck.rows[0].collector_id !== user_id && req.user.role !== 'admin') {
      return res.status(403).json({
        success: false,
        message: 'Bu rezervasyonu silme yetkiniz yok'
      });
    }

    // Atık durumunu 'waiting' yap
    await query(
      "UPDATE waste SET status = 'waiting' WHERE waste_id = $1",
      [resCheck.rows[0].waste_id]
    );

    // DELETE işlemi
    await query('DELETE FROM reservations WHERE reservation_id = $1', [id]);

    res.json({
      success: true,
      message: 'Rezervasyon başarıyla silindi ve atık tekrar listeye eklendi'
    });

  } catch (error) {
    console.error('deleteReservation error:', error);
    res.status(500).json({
      success: false,
      message: 'Rezervasyon silinirken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/reservations/my/collector
 * Kullanıcının toplayıcı olarak yaptığı rezervasyonlar
 */
const getMyCollectorReservations = async (req, res) => {
  try {
    const user_id = req.user.user_id;

    const result = await query(`
      SELECT 
        r.*,
        w.amount,
        w.description AS waste_description,
        wt.type_name,
        wt.official_unit,
        u.first_name || ' ' || u.last_name AS owner_name,
        u.city,
        u.district,
        u.neighborhood,
        u.street,
        u.address_details,
        u.phone AS owner_phone
      FROM reservations r
      JOIN waste w ON r.waste_id = w.waste_id
      JOIN waste_types wt ON w.type_id = wt.type_id
      JOIN users u ON w.user_id = u.user_id
      WHERE r.collector_id = $1
      ORDER BY r.created_at DESC
    `, [user_id]);

    res.json({
      success: true,
      count: result.rows.length,
      data: result.rows
    });

  } catch (error) {
    console.error('getMyCollectorReservations error:', error);
    res.status(500).json({
      success: false,
      message: 'Rezervasyonlar alınırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/reservations/my/owner
 * Kullanıcının atıklarına yapılan rezervasyonlar
 */
const getMyOwnerReservations = async (req, res) => {
  try {
    const user_id = req.user.user_id;

    const result = await query(`
      SELECT 
        r.*,
        w.amount,
        w.description AS waste_description,
        wt.type_name,
        wt.official_unit,
        u.first_name || ' ' || u.last_name AS collector_name,
        u.phone AS collector_phone
      FROM reservations r
      JOIN waste w ON r.waste_id = w.waste_id
      JOIN waste_types wt ON w.type_id = wt.type_id
      JOIN users u ON r.collector_id = u.user_id
      WHERE w.user_id = $1
      ORDER BY r.created_at DESC
    `, [user_id]);

    res.json({
      success: true,
      count: result.rows.length,
      data: result.rows
    });

  } catch (error) {
    console.error('getMyOwnerReservations error:', error);
    res.status(500).json({
      success: false,
      message: 'Rezervasyonlar alınırken hata oluştu',
      error: error.message
    });
  }
};

module.exports = {
  getAllReservations,
  getReservationById,
  createReservation,
  updateReservation,
  completeCollection,
  deleteReservation,
  getMyCollectorReservations,
  getMyOwnerReservations
};
