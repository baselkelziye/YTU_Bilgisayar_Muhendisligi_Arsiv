const { query } = require('../config/database');

// ============================================
// ADMIN CONTROLLER
// Sadece admin rolündeki kullanıcılar erişebilir
// ============================================

/**
 * GET /api/admin/users
 * Tüm kullanıcıları listele
 */
const getAllUsers = async (req, res) => {
  try {
    const { role, city, is_active } = req.query;

    let sql = `
      SELECT 
        user_id, first_name, last_name, email, phone,
        role, city, district, neighborhood,
        is_verified, is_active, created_at
      FROM users
      WHERE 1=1
    `;
    const params = [];
    let paramIndex = 1;

    if (role) {
      sql += ` AND role = $${paramIndex}`;
      params.push(role);
      paramIndex++;
    }

    if (city) {
      sql += ` AND city = $${paramIndex}`;
      params.push(city);
      paramIndex++;
    }

    if (is_active !== undefined) {
      sql += ` AND is_active = $${paramIndex}`;
      params.push(is_active === 'true');
      paramIndex++;
    }

    sql += ` ORDER BY created_at DESC`;

    const result = await query(sql, params);

    res.json({
      success: true,
      count: result.rows.length,
      data: result.rows
    });

  } catch (error) {
    console.error('getAllUsers error:', error);
    res.status(500).json({
      success: false,
      message: 'Kullanıcılar listelenirken hata oluştu',
      error: error.message
    });
  }
};

/**
 * PUT /api/admin/users/:id/role
 * Kullanıcı rolünü değiştir
 */
const updateUserRole = async (req, res) => {
  try {
    const { id } = req.params;
    const { role } = req.body;

    if (!role || !['admin', 'resident'].includes(role)) {
      return res.status(400).json({
        success: false,
        message: "Geçersiz rol. Geçerli değerler: 'admin', 'resident'"
      });
    }

    const result = await query(`
      UPDATE users 
      SET role = $1 
      WHERE user_id = $2
      RETURNING user_id, first_name, last_name, email, role
    `, [role, id]);

    if (result.rows.length === 0) {
      return res.status(404).json({
        success: false,
        message: 'Kullanıcı bulunamadı'
      });
    }

    res.json({
      success: true,
      message: `Kullanıcı rolü '${role}' olarak güncellendi`,
      data: result.rows[0]
    });

  } catch (error) {
    console.error('updateUserRole error:', error);
    res.status(500).json({
      success: false,
      message: 'Rol güncellenirken hata oluştu',
      error: error.message
    });
  }
};

/**
 * PUT /api/admin/users/:id/status
 * Kullanıcı durumunu değiştir (aktif/pasif)
 */
const updateUserStatus = async (req, res) => {
  try {
    const { id } = req.params;
    const { is_active } = req.body;

    if (is_active === undefined) {
      return res.status(400).json({
        success: false,
        message: 'is_active değeri gerekli'
      });
    }

    const result = await query(`
      UPDATE users 
      SET is_active = $1 
      WHERE user_id = $2
      RETURNING user_id, first_name, last_name, email, is_active
    `, [is_active, id]);

    if (result.rows.length === 0) {
      return res.status(404).json({
        success: false,
        message: 'Kullanıcı bulunamadı'
      });
    }

    res.json({
      success: true,
      message: `Kullanıcı ${is_active ? 'aktifleştirildi' : 'deaktif edildi'}`,
      data: result.rows[0]
    });

  } catch (error) {
    console.error('updateUserStatus error:', error);
    res.status(500).json({
      success: false,
      message: 'Durum güncellenirken hata oluştu',
      error: error.message
    });
  }
};

/**
 * DELETE /api/admin/users/:id
 * Kullanıcı sil (CASCADE ile atıkları ve rezervasyonları da silinir)
 */
const deleteUser = async (req, res) => {
  try {
    const { id } = req.params;

    // Kendi kendini silmeyi engelle
    if (parseInt(id) === req.user.user_id) {
      return res.status(400).json({
        success: false,
        message: 'Kendinizi silemezsiniz'
      });
    }

    const userCheck = await query(
      'SELECT user_id, first_name, last_name, email FROM users WHERE user_id = $1',
      [id]
    );

    if (userCheck.rows.length === 0) {
      return res.status(404).json({
        success: false,
        message: 'Kullanıcı bulunamadı'
      });
    }

    // CASCADE: Atıklar ve rezervasyonlar da silinir
    await query('DELETE FROM users WHERE user_id = $1', [id]);

    res.json({
      success: true,
      message: 'Kullanıcı ve tüm ilişkili veriler silindi (CASCADE)',
      deletedUser: userCheck.rows[0]
    });

  } catch (error) {
    console.error('deleteUser error:', error);
    res.status(500).json({
      success: false,
      message: 'Kullanıcı silinirken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/admin/waste-types
 * Atık türlerini listele
 */
const getWasteTypes = async (req, res) => {
  try {
    const result = await query(`
      SELECT 
        wt.*,
        COUNT(w.waste_id) as usage_count
      FROM waste_types wt
      LEFT JOIN waste w ON wt.type_id = w.type_id
      GROUP BY wt.type_id
      ORDER BY wt.type_name
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

/**
 * POST /api/admin/waste-types
 * Yeni atık türü ekle
 */
const createWasteType = async (req, res) => {
  try {
    const { type_name, official_unit, recycle_score } = req.body;

    if (!type_name || !official_unit || recycle_score === undefined) {
      return res.status(400).json({
        success: false,
        message: 'type_name, official_unit ve recycle_score gerekli'
      });
    }

    // CHECK constraint: recycle_score 0-100 arası
    if (recycle_score < 0 || recycle_score > 100) {
      return res.status(400).json({
        success: false,
        message: 'recycle_score 0-100 arasında olmalı'
      });
    }

    const result = await query(`
      INSERT INTO waste_types (type_name, official_unit, recycle_score)
      VALUES ($1, $2, $3)
      RETURNING *
    `, [type_name, official_unit, recycle_score]);

    res.status(201).json({
      success: true,
      message: 'Atık türü başarıyla eklendi',
      data: result.rows[0]
    });

  } catch (error) {
    console.error('createWasteType error:', error);

    if (error.message.includes('duplicate key')) {
      return res.status(400).json({
        success: false,
        message: 'Bu atık türü zaten mevcut'
      });
    }

    res.status(500).json({
      success: false,
      message: 'Atık türü eklenirken hata oluştu',
      error: error.message
    });
  }
};

/**
 * PUT /api/admin/waste-types/:id
 * Atık türü güncelle
 */
const updateWasteType = async (req, res) => {
  try {
    const { id } = req.params;
    const { type_name, official_unit, recycle_score } = req.body;

    const updates = [];
    const values = [];
    let paramIndex = 1;

    if (type_name !== undefined) {
      updates.push(`type_name = $${paramIndex}`);
      values.push(type_name);
      paramIndex++;
    }

    if (official_unit !== undefined) {
      updates.push(`official_unit = $${paramIndex}`);
      values.push(official_unit);
      paramIndex++;
    }

    if (recycle_score !== undefined) {
      if (recycle_score < 0 || recycle_score > 100) {
        return res.status(400).json({
          success: false,
          message: 'recycle_score 0-100 arasında olmalı'
        });
      }
      updates.push(`recycle_score = $${paramIndex}`);
      values.push(recycle_score);
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
      UPDATE waste_types 
      SET ${updates.join(', ')} 
      WHERE type_id = $${paramIndex}
      RETURNING *
    `;

    const result = await query(sql, values);

    if (result.rows.length === 0) {
      return res.status(404).json({
        success: false,
        message: 'Atık türü bulunamadı'
      });
    }

    res.json({
      success: true,
      message: 'Atık türü güncellendi',
      data: result.rows[0]
    });

  } catch (error) {
    console.error('updateWasteType error:', error);
    res.status(500).json({
      success: false,
      message: 'Atık türü güncellenirken hata oluştu',
      error: error.message
    });
  }
};

/**
 * DELETE /api/admin/waste-types/:id
 * Atık türü sil (RESTRICT: Kullanımda ise silinemez)
 */
const deleteWasteType = async (req, res) => {
  try {
    const { id } = req.params;

    // Kullanımda mı kontrol et
    const usageCheck = await query(
      'SELECT COUNT(*) FROM waste WHERE type_id = $1',
      [id]
    );

    if (parseInt(usageCheck.rows[0].count) > 0) {
      return res.status(400).json({
        success: false,
        message: `Bu atık türü ${usageCheck.rows[0].count} atıkta kullanılıyor. RESTRICT kısıtı nedeniyle silinemez.`,
        usageCount: parseInt(usageCheck.rows[0].count)
      });
    }

    const result = await query(
      'DELETE FROM waste_types WHERE type_id = $1 RETURNING *',
      [id]
    );

    if (result.rows.length === 0) {
      return res.status(404).json({
        success: false,
        message: 'Atık türü bulunamadı'
      });
    }

    res.json({
      success: true,
      message: 'Atık türü silindi',
      deletedType: result.rows[0]
    });

  } catch (error) {
    console.error('deleteWasteType error:', error);

    // RESTRICT constraint hatası
    if (error.message.includes('violates foreign key constraint')) {
      return res.status(400).json({
        success: false,
        message: 'Bu atık türü kullanımda olduğu için silinemez (RESTRICT)',
        error: error.message
      });
    }

    res.status(500).json({
      success: false,
      message: 'Atık türü silinirken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/admin/trigger-logs
 * Trigger loglarını görüntüle
 */
const getTriggerLogs = async (req, res) => {
  try {
    const { limit } = req.query;
    const maxRows = limit || 50;

    const result = await query(`
      SELECT * FROM trigger_logs
      ORDER BY created_at DESC
      LIMIT $1
    `, [maxRows]);

    res.json({
      success: true,
      message: 'Trigger logları',
      count: result.rows.length,
      data: result.rows
    });

  } catch (error) {
    console.error('getTriggerLogs error:', error);
    res.status(500).json({
      success: false,
      message: 'Trigger logları alınırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/admin/dashboard
 * Admin dashboard istatistikleri
 */
const getDashboard = async (req, res) => {
  try {
    // Kullanıcı sayıları
    const userStats = await query(`
      SELECT 
        COUNT(*) as total_users,
        COUNT(CASE WHEN role = 'admin' THEN 1 END) as admin_count,
        COUNT(CASE WHEN role = 'resident' THEN 1 END) as resident_count,
        COUNT(CASE WHEN is_active = true THEN 1 END) as active_users
      FROM users
    `);

    // Atık sayıları
    const wasteStats = await query(`
      SELECT 
        COUNT(*) as total_waste,
        COUNT(CASE WHEN status = 'waiting' THEN 1 END) as waiting_count,
        COUNT(CASE WHEN status = 'reserved' THEN 1 END) as reserved_count,
        COUNT(CASE WHEN status = 'collected' THEN 1 END) as collected_count,
        COALESCE(SUM(amount), 0) as total_amount
      FROM waste
    `);

    // Rezervasyon sayıları
    const reservationStats = await query(`
      SELECT 
        COUNT(*) as total_reservations,
        COUNT(CASE WHEN status = 'waiting' THEN 1 END) as pending_count,
        COUNT(CASE WHEN status = 'collected' THEN 1 END) as completed_count
      FROM reservations
    `);

    // Son trigger aktiviteleri
    const recentTriggers = await query(`
      SELECT trigger_name, message, created_at
      FROM trigger_logs
      ORDER BY created_at DESC
      LIMIT 5
    `);

    res.json({
      success: true,
      data: {
        users: userStats.rows[0],
        waste: wasteStats.rows[0],
        reservations: reservationStats.rows[0],
        recentTriggerActivity: recentTriggers.rows
      }
    });

  } catch (error) {
    console.error('getDashboard error:', error);
    res.status(500).json({
      success: false,
      message: 'Dashboard verisi alınırken hata oluştu',
      error: error.message
    });
  }
};

// ============================================
// DATABASE EXPLORER - Veritabanı Gezgini
// ============================================

/**
 * GET /api/admin/database/tables
 * Tüm tabloları listele
 */
const getTableList = async (req, res) => {
  try {
    const result = await query(`
      SELECT 
        table_name,
        (SELECT COUNT(*) FROM information_schema.columns WHERE table_name = t.table_name AND table_schema = 'public') as column_count
      FROM information_schema.tables t
      WHERE table_schema = 'public' 
        AND table_type = 'BASE TABLE'
      ORDER BY table_name
    `);

    // Her tablo için kayıt sayısını al
    const tablesWithCounts = await Promise.all(
      result.rows.map(async (table) => {
        const countResult = await query(`SELECT COUNT(*) FROM "${table.table_name}"`);
        return {
          ...table,
          row_count: parseInt(countResult.rows[0].count)
        };
      })
    );

    res.json({
      success: true,
      count: tablesWithCounts.length,
      data: tablesWithCounts
    });

  } catch (error) {
    console.error('getTableList error:', error);
    res.status(500).json({
      success: false,
      message: 'Tablo listesi alınırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/admin/database/tables/:name/schema
 * Tablo şemasını getir (columns, types, constraints)
 */
const getTableSchema = async (req, res) => {
  try {
    const { name } = req.params;

    // Column bilgilerini al
    const columns = await query(`
      SELECT 
        c.column_name,
        c.data_type,
        c.character_maximum_length,
        c.is_nullable,
        c.column_default,
        CASE WHEN pk.column_name IS NOT NULL THEN true ELSE false END as is_primary_key,
        CASE WHEN fk.column_name IS NOT NULL THEN true ELSE false END as is_foreign_key,
        fk.foreign_table_name,
        fk.foreign_column_name
      FROM information_schema.columns c
      LEFT JOIN (
        SELECT ku.column_name
        FROM information_schema.table_constraints tc
        JOIN information_schema.key_column_usage ku ON tc.constraint_name = ku.constraint_name
        WHERE tc.table_name = $1 AND tc.constraint_type = 'PRIMARY KEY'
      ) pk ON c.column_name = pk.column_name
      LEFT JOIN (
        SELECT 
          kcu.column_name,
          ccu.table_name as foreign_table_name,
          ccu.column_name as foreign_column_name
        FROM information_schema.table_constraints tc
        JOIN information_schema.key_column_usage kcu ON tc.constraint_name = kcu.constraint_name
        JOIN information_schema.constraint_column_usage ccu ON tc.constraint_name = ccu.constraint_name
        WHERE tc.table_name = $1 AND tc.constraint_type = 'FOREIGN KEY'
      ) fk ON c.column_name = fk.column_name
      WHERE c.table_name = $1 AND c.table_schema = 'public'
      ORDER BY c.ordinal_position
    `, [name]);

    // CHECK constraints
    const checks = await query(`
      SELECT 
        tc.constraint_name,
        cc.check_clause
      FROM information_schema.table_constraints tc
      JOIN information_schema.check_constraints cc ON tc.constraint_name = cc.constraint_name
      WHERE tc.table_name = $1 AND tc.constraint_type = 'CHECK'
    `, [name]);

    // Index bilgileri
    const indexes = await query(`
      SELECT indexname, indexdef
      FROM pg_indexes
      WHERE tablename = $1
    `, [name]);

    res.json({
      success: true,
      tableName: name,
      data: {
        columns: columns.rows,
        checkConstraints: checks.rows,
        indexes: indexes.rows
      }
    });

  } catch (error) {
    console.error('getTableSchema error:', error);
    res.status(500).json({
      success: false,
      message: 'Tablo şeması alınırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/admin/database/tables/:name/data
 * Tablo verilerini getir (paginated)
 */
const getTableData = async (req, res) => {
  try {
    const { name } = req.params;
    const { page = 1, limit = 20 } = req.query;
    const offset = (page - 1) * limit;

    // Güvenlik: Sadece izin verilen tablolar
    const allowedTables = ['users', 'waste', 'waste_types', 'reservations', 'environmental_scores', 'trigger_logs'];
    if (!allowedTables.includes(name)) {
      return res.status(400).json({
        success: false,
        message: 'Geçersiz tablo adı'
      });
    }

    const countResult = await query(`SELECT COUNT(*) FROM "${name}"`);
    const totalRows = parseInt(countResult.rows[0].count);

    const result = await query(`SELECT * FROM "${name}" LIMIT $1 OFFSET $2`, [limit, offset]);

    res.json({
      success: true,
      tableName: name,
      pagination: {
        page: parseInt(page),
        limit: parseInt(limit),
        totalRows,
        totalPages: Math.ceil(totalRows / limit)
      },
      data: result.rows
    });

  } catch (error) {
    console.error('getTableData error:', error);
    res.status(500).json({
      success: false,
      message: 'Tablo verileri alınırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/admin/database/schema
 * ER diyagramı için veritabanı şemasını getir
 */
const getDatabaseSchema = async (req, res) => {
  try {
    // Tüm tablolar
    const tables = await query(`
      SELECT table_name
      FROM information_schema.tables
      WHERE table_schema = 'public' AND table_type = 'BASE TABLE'
      ORDER BY table_name
    `);

    // Her tablo için columns
    const tableDetails = await Promise.all(
      tables.rows.map(async (table) => {
        const columns = await query(`
          SELECT 
            c.column_name,
            c.data_type,
            c.is_nullable,
            CASE WHEN pk.column_name IS NOT NULL THEN true ELSE false END as is_primary_key
          FROM information_schema.columns c
          LEFT JOIN (
            SELECT ku.column_name
            FROM information_schema.table_constraints tc
            JOIN information_schema.key_column_usage ku ON tc.constraint_name = ku.constraint_name
            WHERE tc.table_name = $1 AND tc.constraint_type = 'PRIMARY KEY'
          ) pk ON c.column_name = pk.column_name
          WHERE c.table_name = $1 AND c.table_schema = 'public'
          ORDER BY c.ordinal_position
        `, [table.table_name]);

        return {
          name: table.table_name,
          columns: columns.rows
        };
      })
    );

    // Foreign key ilişkileri
    const relationships = await query(`
      SELECT
        tc.table_name as source_table,
        kcu.column_name as source_column,
        ccu.table_name as target_table,
        ccu.column_name as target_column,
        rc.delete_rule
      FROM information_schema.table_constraints tc
      JOIN information_schema.key_column_usage kcu ON tc.constraint_name = kcu.constraint_name
      JOIN information_schema.constraint_column_usage ccu ON tc.constraint_name = ccu.constraint_name
      JOIN information_schema.referential_constraints rc ON tc.constraint_name = rc.constraint_name
      WHERE tc.constraint_type = 'FOREIGN KEY' AND tc.table_schema = 'public'
    `);

    res.json({
      success: true,
      data: {
        tables: tableDetails,
        relationships: relationships.rows
      }
    });

  } catch (error) {
    console.error('getDatabaseSchema error:', error);
    res.status(500).json({
      success: false,
      message: 'Veritabanı şeması alınırken hata oluştu',
      error: error.message
    });
  }
};

// ============================================
// ÖDEV GEREKSİNİMİ: UNION / INTERSECT / EXCEPT SORGUSU
// Hem atık paylaşan HEM de toplayan kullanıcılar
// ============================================
const getActiveContributors = async (req, res) => {
  try {
    // INTERSECT: Hem atık paylaşan hem de toplayan kullanıcılar
    const intersectResult = await query(`
      SELECT user_id, first_name, last_name, email, 'Paylaşımcı & Toplayıcı' as contributor_type
      FROM users u
      WHERE EXISTS (SELECT 1 FROM waste w WHERE w.user_id = u.user_id)
      INTERSECT
      SELECT user_id, first_name, last_name, email, 'Paylaşımcı & Toplayıcı' as contributor_type
      FROM users u
      WHERE EXISTS (SELECT 1 FROM reservations r WHERE r.collector_id = u.user_id)
    `);

    // UNION: Atık paylaşan VEYA toplayan tüm aktif kullanıcılar
    const unionResult = await query(`
      SELECT user_id, first_name, last_name, 'Paylaşımcı' as activity_type
      FROM users u
      WHERE EXISTS (SELECT 1 FROM waste w WHERE w.user_id = u.user_id)
      UNION
      SELECT user_id, first_name, last_name, 'Toplayıcı' as activity_type
      FROM users u
      WHERE EXISTS (SELECT 1 FROM reservations r WHERE r.collector_id = u.user_id)
      ORDER BY first_name
    `);

    // EXCEPT: Hiç rezervasyon yapmamış kullanıcılar
    const exceptResult = await query(`
      SELECT user_id, first_name, last_name, email
      FROM users
      EXCEPT
      SELECT DISTINCT u.user_id, u.first_name, u.last_name, u.email
      FROM users u
      JOIN reservations r ON u.user_id = r.collector_id
    `);

    res.json({
      success: true,
      data: {
        intersect: {
          description: 'Hem paylaşan hem toplayan kullanıcılar (INTERSECT)',
          count: intersectResult.rows.length,
          users: intersectResult.rows
        },
        union: {
          description: 'Tüm aktif kullanıcılar - paylaşan veya toplayan (UNION)',
          count: unionResult.rows.length,
          users: unionResult.rows
        },
        except: {
          description: 'Hiç rezervasyon yapmamış kullanıcılar (EXCEPT)',
          count: exceptResult.rows.length,
          users: exceptResult.rows
        }
      },
      sql_info: {
        intersect_query: 'SELECT ... WHERE EXISTS(waste) INTERSECT SELECT ... WHERE EXISTS(reservations)',
        union_query: 'SELECT ... paylaşımcılar UNION SELECT ... toplayıcılar',
        except_query: 'SELECT all users EXCEPT SELECT users with reservations'
      }
    });

  } catch (error) {
    console.error('getActiveContributors error:', error);
    res.status(500).json({
      success: false,
      message: 'Aktif katılımcılar alınırken hata oluştu',
      error: error.message
    });
  }
};

// ============================================
// ÖDEV GEREKSİNİMİ: AGGREGATE + HAVING SORGUSU
// En az N atık paylaşmış kullanıcılar
// ============================================
const getTopContributors = async (req, res) => {
  try {
    const { minWaste = 1 } = req.query;

    // Aggregate fonksiyonlar (COUNT, SUM) + HAVING kullanımı
    const result = await query(`
      SELECT 
        u.user_id,
        u.first_name || ' ' || u.last_name AS full_name,
        u.email,
        u.city,
        COUNT(w.waste_id) AS waste_count,
        COALESCE(SUM(w.amount), 0) AS total_amount,
        COUNT(CASE WHEN w.status = 'collected' THEN 1 END) AS collected_count,
        COALESCE(SUM(CASE WHEN w.status = 'collected' THEN w.amount * wt.recycle_score ELSE 0 END), 0)::INTEGER AS total_score
      FROM users u
      LEFT JOIN waste w ON u.user_id = w.user_id
      LEFT JOIN waste_types wt ON w.type_id = wt.type_id
      GROUP BY u.user_id, u.first_name, u.last_name, u.email, u.city
      HAVING COUNT(w.waste_id) >= $1
      ORDER BY waste_count DESC, total_score DESC
    `, [parseInt(minWaste)]);

    res.json({
      success: true,
      data: result.rows,
      count: result.rows.length,
      filter: {
        minWaste: parseInt(minWaste),
        description: `En az ${minWaste} atık paylaşmış kullanıcılar`
      },
      sql_info: {
        aggregate_functions: ['COUNT(w.waste_id)', 'SUM(w.amount)', 'SUM(w.amount * wt.recycle_score)'],
        having_clause: `HAVING COUNT(w.waste_id) >= ${minWaste}`,
        description: 'Aggregate fonksiyonlar ve HAVING ifadesi kullanıldı'
      }
    });

  } catch (error) {
    console.error('getTopContributors error:', error);
    res.status(500).json({
      success: false,
      message: 'Top paylaşımcılar alınırken hata oluştu',
      error: error.message
    });
  }
};

module.exports = {
  getAllUsers,
  updateUserRole,
  updateUserStatus,
  deleteUser,
  getWasteTypes,
  createWasteType,
  updateWasteType,
  deleteWasteType,
  getTriggerLogs,
  getDashboard,
  getTableList,
  getTableSchema,
  getTableData,
  getDatabaseSchema,
  getActiveContributors,
  getTopContributors
};
