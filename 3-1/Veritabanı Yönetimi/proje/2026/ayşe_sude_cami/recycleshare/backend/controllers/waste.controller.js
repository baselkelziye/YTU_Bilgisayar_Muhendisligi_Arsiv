const { query } = require('../config/database');

// ============================================
// WASTE CONTROLLER
// ============================================

/**
 * GET /api/waste
 * Tüm aktif atıkları listele (VIEW kullanır)
 * Query params: city, type_id, status
 */
const getAllWaste = async (req, res) => {
  try {
    const { city, district, neighborhood, street, type_id, status } = req.query;

    // Eğer type_id ile filtreleme geliyorsa VIEW'da type_id olmadığı için
    // doğrudan tabloları join ederek sorguluyoruz. Aksi halde VIEW kullan.
    let sql;
    const usingTable = !!type_id;
    if (usingTable) {
      sql = `
        SELECT 
          w.waste_id,
          w.amount,
          w.description,
          w.status,
          w.record_date,
          wt.type_id,
          wt.type_name,
          wt.official_unit,
          wt.recycle_score,
          u.user_id,
          u.first_name || ' ' || u.last_name AS owner_name,
          u.city,
          u.district,
          u.neighborhood,
          u.phone AS owner_phone
        FROM waste w
        JOIN waste_types wt ON w.type_id = wt.type_id
        JOIN users u ON w.user_id = u.user_id
        WHERE w.status IN ('waiting', 'reserved')`;
    } else {
      // VIEW kullanarak sorgula 
      sql = `SELECT * FROM v_active_waste_details WHERE 1=1`;
    }
    const params = [];
    let paramIndex = 1;

    if (city) {
      sql += usingTable ? ` AND u.city = $${paramIndex}` : ` AND city = $${paramIndex}`;
      params.push(city);
      paramIndex++;
    }

    if (district) {
      sql += usingTable ? ` AND u.district = $${paramIndex}` : ` AND district = $${paramIndex}`;
      params.push(district);
      paramIndex++;
    }

    if (neighborhood) {
      sql += usingTable ? ` AND u.neighborhood = $${paramIndex}` : ` AND neighborhood = $${paramIndex}`;
      params.push(neighborhood);
      paramIndex++;
    }

    if (street) {
      sql += usingTable ? ` AND u.street = $${paramIndex}` : ` AND street = $${paramIndex}`;
      params.push(street);
      paramIndex++;
    }

    if (type_id) {
      // Eğer type_id ile tablo sorgusunu kullanıyorsak wt.type_id üzerinden filtrele
      sql += usingTable ? ` AND wt.type_id = $${paramIndex}` : ` AND type_id = $${paramIndex}`;
      params.push(type_id);
      paramIndex++;
    }

    if (status) {
      sql += usingTable ? ` AND w.status = $${paramIndex}` : ` AND status = $${paramIndex}`;
      params.push(status);
      paramIndex++;
    }

    // Eğer kullanıcı girişliyse kendi paylaştığı atıkları gösterme
    if (req.user && req.user.user_id) {
      sql += usingTable ? ` AND w.user_id != $${paramIndex}` : ` AND user_id != $${paramIndex}`;
      params.push(req.user.user_id);
      paramIndex++;
    }

    // Ensure consistent ordering when using table query
    if (usingTable) {
      sql += ` ORDER BY w.record_date DESC`;
    }

    const result = await query(sql, params);

    res.json({
      success: true,
      message: 'Atıklar başarıyla listelendi',
      count: result.rows.length,
      data: result.rows
    });

  } catch (error) {
    console.error('getAllWaste error:', error);
    res.status(500).json({
      success: false,
      message: 'Atıklar listelenirken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/waste/search
 * Şehre göre atık ara (FONKSİYON kullanır - Ödev gereksinimi)
 */
const searchWasteByCity = async (req, res) => {
  try {
    const { city } = req.query;

    if (!city) {
      return res.status(400).json({
        success: false,
        message: 'Şehir parametresi gerekli'
      });
    }

    // PostgreSQL fonksiyonu kullan (Ödev gereksinimi)
    const result = await query(
      `SELECT * FROM fn_get_waste_by_city($1)`,
      [city]
    );

    res.json({
      success: true,
      message: `${city} şehrindeki atıklar`,
      count: result.rows.length,
      data: result.rows
    });

  } catch (error) {
    console.error('searchWasteByCity error:', error);
    res.status(500).json({
      success: false,
      message: 'Arama sırasında hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/waste/:id
 * Tek bir atık detayı
 */
const getWasteById = async (req, res) => {
  try {
    const { id } = req.params;

    const result = await query(`
      SELECT 
        w.*,
        wt.type_name,
        wt.official_unit,
        wt.recycle_score,
        u.first_name || ' ' || u.last_name AS owner_name,
        u.city,
        u.district,
        u.neighborhood,
        u.phone AS owner_phone
      FROM waste w
      JOIN waste_types wt ON w.type_id = wt.type_id
      JOIN users u ON w.user_id = u.user_id
      WHERE w.waste_id = $1
    `, [id]);

    if (result.rows.length === 0) {
      return res.status(404).json({
        success: false,
        message: 'Atık bulunamadı'
      });
    }

    res.json({
      success: true,
      data: result.rows[0]
    });

  } catch (error) {
    console.error('getWasteById error:', error);
    res.status(500).json({
      success: false,
      message: 'Atık detayı alınırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * POST /api/waste
 * Yeni atık ekle (INSERT - Ödev gereksinimi)
 * CHECK constraint test edilebilir: amount > 0 AND amount <= 1000
 */
const createWaste = async (req, res) => {
  try {
    const { type_id, amount, description } = req.body;
    const user_id = req.user.user_id; // Auth middleware'den

    // Validasyon
    if (!type_id || !amount) {
      return res.status(400).json({
        success: false,
        message: 'type_id ve amount gerekli'
      });
    }

    // Amount check constraint: 0 < amount <= 1000
    if (amount <= 0 || amount > 1000) {
      return res.status(400).json({
        success: false,
        message: 'Miktar 0-1000 arasında olmalı'
      });
    }

    // Atık türü kontrolü
    const typeCheck = await query(
      'SELECT type_id FROM waste_types WHERE type_id = $1',
      [type_id]
    );

    if (typeCheck.rows.length === 0) {
      return res.status(400).json({
        success: false,
        message: 'Geçersiz atık türü'
      });
    }

    // INSERT işlemi
    const result = await query(`
      INSERT INTO waste (user_id, type_id, amount, description, status)
      VALUES ($1, $2, $3, $4, 'waiting')
      RETURNING *
    `, [user_id, type_id, amount, description || null]);

    // Atık türü bilgisini de ekle
    const wasteWithType = await query(`
      SELECT 
        w.*,
        wt.type_name,
        wt.official_unit,
        wt.recycle_score
      FROM waste w
      JOIN waste_types wt ON w.type_id = wt.type_id
      WHERE w.waste_id = $1
    `, [result.rows[0].waste_id]);

    res.status(201).json({
      success: true,
      message: 'Atık başarıyla eklendi',
      data: wasteWithType.rows[0]
    });

  } catch (error) {
    console.error('createWaste error:', error);

    // Check constraint hatası
    if (error.message.includes('violates check constraint')) {
      return res.status(400).json({
        success: false,
        message: 'Geçersiz değer: Miktar 0-1000 arasında olmalı',
        error: error.message
      });
    }

    res.status(500).json({
      success: false,
      message: 'Atık eklenirken hata oluştu',
      error: error.message
    });
  }
};

/**
 * PUT /api/waste/:id
 * Atık güncelle (UPDATE - Ödev gereksinimi)
 */
const updateWaste = async (req, res) => {
  try {
    const { id } = req.params;
    const { type_id, amount, description, status } = req.body;
    const user_id = req.user.user_id;

    // Atık sahibi kontrolü
    const wasteCheck = await query(
      'SELECT * FROM waste WHERE waste_id = $1',
      [id]
    );

    if (wasteCheck.rows.length === 0) {
      return res.status(404).json({
        success: false,
        message: 'Atık bulunamadı'
      });
    }

    // Admin değilse sadece kendi atığını güncelleyebilir
    if (wasteCheck.rows[0].user_id !== user_id && req.user.role !== 'admin') {
      return res.status(403).json({
        success: false,
        message: 'Bu atığı güncelleme yetkiniz yok'
      });
    }

    // Dinamik güncelleme sorgusu
    const updates = [];
    const values = [];
    let paramIndex = 1;

    if (type_id !== undefined) {
      updates.push(`type_id = $${paramIndex}`);
      values.push(type_id);
      paramIndex++;
    }

    if (amount !== undefined) {
      updates.push(`amount = $${paramIndex}`);
      values.push(amount);
      paramIndex++;
    }

    if (description !== undefined) {
      updates.push(`description = $${paramIndex}`);
      values.push(description);
      paramIndex++;
    }

    if (status !== undefined) {
      updates.push(`status = $${paramIndex}`);
      values.push(status);
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
      UPDATE waste 
      SET ${updates.join(', ')} 
      WHERE waste_id = $${paramIndex}
      RETURNING *
    `;

    const result = await query(sql, values);

    // Trigger'ın çalışıp çalışmadığını kontrol et
    let triggerMessage = null;
    if (status === 'collected') {
      const triggerLog = await query(`
        SELECT message FROM trigger_logs 
        WHERE table_name = 'waste' 
        AND (new_data->>'waste_id')::int = $1
        ORDER BY created_at DESC LIMIT 1
      `, [id]);

      if (triggerLog.rows.length > 0) {
        triggerMessage = triggerLog.rows[0].message;
      }
    }

    res.json({
      success: true,
      message: 'Atık başarıyla güncellendi',
      triggerMessage: triggerMessage,
      data: result.rows[0]
    });

  } catch (error) {
    console.error('updateWaste error:', error);

    if (error.message.includes('violates check constraint')) {
      return res.status(400).json({
        success: false,
        message: 'Geçersiz değer girdiniz',
        error: error.message
      });
    }

    res.status(500).json({
      success: false,
      message: 'Atık güncellenirken hata oluştu',
      error: error.message
    });
  }
};

/**
 * DELETE /api/waste/:id
 * Atık sil (DELETE - Ödev gereksinimi)
 * CASCADE: İlgili rezervasyonlar da silinir
 */
const deleteWaste = async (req, res) => {
  try {
    const { id } = req.params;
    const user_id = req.user.user_id;

    // Atık kontrolü
    const wasteCheck = await query(
      'SELECT * FROM waste WHERE waste_id = $1',
      [id]
    );

    if (wasteCheck.rows.length === 0) {
      return res.status(404).json({
        success: false,
        message: 'Atık bulunamadı'
      });
    }

    // Admin değilse sadece kendi atığını silebilir
    if (wasteCheck.rows[0].user_id !== user_id && req.user.role !== 'admin') {
      return res.status(403).json({
        success: false,
        message: 'Bu atığı silme yetkiniz yok'
      });
    }

    // Attempt deletion inside a transaction: first remove reservations, then delete waste
    try {
      await query('BEGIN');
      await query('DELETE FROM reservations WHERE waste_id = $1', [id]);
      await query('DELETE FROM waste WHERE waste_id = $1', [id]);
      await query('COMMIT');

      res.json({
        success: true,
        message: 'Atık ve ilgili rezervasyonlar başarıyla silindi'
      });
    } catch (txErr) {
      await query('ROLLBACK');
      console.error('deleteWaste transaction error:', txErr);
      return res.status(500).json({ success: false, message: 'Atık silinirken hata oluştu', error: txErr.message });
    }

  } catch (error) {
    console.error('deleteWaste error:', error);
    res.status(500).json({
      success: false,
      message: 'Atık silinirken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/waste/my
 * Kullanıcının kendi atıkları
 */
const getMyWaste = async (req, res) => {
  try {
    const user_id = req.user.user_id;

    const result = await query(`
      SELECT 
        w.*,
        wt.type_name,
        wt.official_unit,
        wt.recycle_score
      FROM waste w
      JOIN waste_types wt ON w.type_id = wt.type_id
      WHERE w.user_id = $1
      ORDER BY w.record_date DESC
    `, [user_id]);

    res.json({
      success: true,
      count: result.rows.length,
      data: result.rows
    });

  } catch (error) {
    console.error('getMyWaste error:', error);
    res.status(500).json({
      success: false,
      message: 'Atıklar alınırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/waste/types
 * Atık türlerini listele
 */
const getWasteTypes = async (req, res) => {
  try {
    const result = await query(`
      SELECT * FROM waste_types ORDER BY type_name
    `);

    res.json({
      success: true,
      count: result.rows.length,
      data: result.rows
    });

  } catch (error) {
    console.error('getWasteTypes error:', error);
    res.status(500).json({
      success: false,
      message: 'Atık türleri alınırken hata oluştu',
      error: error.message
    });
  }
};
const getImpactStats = async (req, res) => {
  try {
    // 1. Kullanıcı ID'sini güvenli bir şekilde al
    const userId = parseInt(req.user?.user_id || req.user?.id, 10);

    if (isNaN(userId) || userId <= 0) {
      return res.status(401).json({ success: false, message: "Geçersiz Kullanıcı" });
    }

    // 2. Toplam ilan sayısını çek
    const totalResult = await query('SELECT COUNT(*) AS total FROM waste WHERE user_id = $1', [userId]);
    const itemsShared = parseInt(totalResult.rows[0]?.total || 0, 10);

    // 3. Environmental score'dan toplam puanı çek
    const scoreResult = await query('SELECT COALESCE(SUM(total_score), 0) as total_score FROM environmental_scores WHERE user_id = $1', [userId]);
    const totalScore = parseInt(scoreResult.rows[0]?.total_score || 0, 10);

    // 4. Toplanan atık sayısı (connections = completed reservations where user is owner)
    const connectionsResult = await query(`
      SELECT COUNT(*) as connections 
      FROM reservations r 
      JOIN waste w ON r.waste_id = w.waste_id 
      WHERE w.user_id = $1 AND r.status = 'collected'
    `, [userId]);
    const connections = parseInt(connectionsResult.rows[0]?.connections || 0, 10);

    // 5. Aylık grafik verisi
    const monthlyRows = await query(`
      SELECT TO_CHAR(record_date, 'Mon') as month_label, SUM(amount) as total_amount
      FROM waste 
      WHERE user_id = $1 AND status = 'collected'
      GROUP BY month_label, date_trunc('month', record_date)
      ORDER BY date_trunc('month', record_date) ASC
      LIMIT 6
    `, [userId]);

    const monthlyImpact = (monthlyRows.rows || []).map(row => ({
      month: row.month_label,
      value: parseFloat(row.total_amount) || 0
    }));

    // 6. Frontend'in beklediği format
    res.json({
      success: true,
      data: {
        itemsShared: itemsShared,
        co2Saved: (totalScore * 0.5).toFixed(1),  // Her puan 0.5kg CO2 tasarrufu
        connections: connections,
        totalScore: totalScore,
        monthlyImpact: monthlyImpact
      }
    });

  } catch (error) {
    console.error('Impact Stats Hatası:', error);
    res.status(500).json({ success: false, error: "Sunucu hatası oluştu" });
  }
};

// DOSYANIN EN ALTINDA BU KISIM MUTLAKA OLMALI
module.exports = {
  getAllWaste,
  searchWasteByCity,
  getWasteById,
  createWaste,
  updateWaste,
  deleteWaste,
  getMyWaste,
  getWasteTypes,
  getImpactStats
};
