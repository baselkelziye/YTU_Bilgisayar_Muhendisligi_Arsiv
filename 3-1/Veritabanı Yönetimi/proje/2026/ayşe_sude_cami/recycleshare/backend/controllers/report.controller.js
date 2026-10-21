const { query } = require('../config/database');

// ============================================
// REPORTS CONTROLLER
// Aggregate functions, HAVING, UNION/EXCEPT sorguları
// ============================================

/**
 * GET /api/reports/user/:userId/monthly
 * Kullanıcının aylık raporu (CURSOR & RECORD fonksiyonu kullanır)
 */
const getUserMonthlyReport = async (req, res) => {
  try {
    const { userId } = req.params;
    const { year, month } = req.query;

    const targetYear = year || new Date().getFullYear();
    const targetMonth = month || new Date().getMonth() + 1;

    // PostgreSQL fonksiyonu kullan (CURSOR & RECORD - Ödev gereksinimi)
    const result = await query(
      `SELECT * FROM fn_get_user_monthly_report($1, $2, $3)`,
      [userId, targetYear, targetMonth]
    );

    res.json({
      success: true,
      message: `${targetYear}-${targetMonth} dönemi raporu`,
      userId: parseInt(userId),
      period: { year: parseInt(targetYear), month: parseInt(targetMonth) },
      data: result.rows
    });

  } catch (error) {
    console.error('getUserMonthlyReport error:', error);
    res.status(500).json({
      success: false,
      message: 'Rapor alınırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/reports/user/:userId/score
 * Kullanıcının toplam çevresel puanı (FONKSİYON kullanır)
 */
const getUserTotalScore = async (req, res) => {
  try {
    const { userId } = req.params;

    // PostgreSQL fonksiyonu kullan
    const result = await query(
      `SELECT fn_calculate_user_total_score($1) as total_score`,
      [userId]
    );

    // Kullanıcı bilgilerini de al
    const userInfo = await query(
      `SELECT user_id, first_name, last_name, email FROM users WHERE user_id = $1`,
      [userId]
    );

    if (userInfo.rows.length === 0) {
      return res.status(404).json({
        success: false,
        message: 'Kullanıcı bulunamadı'
      });
    }

    res.json({
      success: true,
      data: {
        user: userInfo.rows[0],
        totalScore: result.rows[0].total_score
      }
    });

  } catch (error) {
    console.error('getUserTotalScore error:', error);
    res.status(500).json({
      success: false,
      message: 'Puan hesaplanırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/reports/active-users
 * Aktif kullanıcılar: Hem atık paylaşan hem de toplayan (UNION sorgusu)
 */
const getActiveUsers = async (req, res) => {
  try {
    // UNION sorgusu (Ödev gereksinimi)
    const result = await query(`
      SELECT user_id, first_name, last_name, email, 'Paylaşımcı' as activity_type
      FROM users u
      WHERE EXISTS (SELECT 1 FROM waste w WHERE w.user_id = u.user_id)
      
      UNION
      
      SELECT user_id, first_name, last_name, email, 'Toplayıcı' as activity_type
      FROM users u
      WHERE EXISTS (SELECT 1 FROM reservations r WHERE r.collector_id = u.user_id)
      
      ORDER BY user_id, activity_type
    `);

    res.json({
      success: true,
      message: 'Aktif kullanıcılar (UNION sorgusu)',
      count: result.rows.length,
      sqlUsed: 'UNION',
      data: result.rows
    });

  } catch (error) {
    console.error('getActiveUsers error:', error);
    res.status(500).json({
      success: false,
      message: 'Aktif kullanıcılar alınırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/reports/inactive-collectors
 * Hiç rezervasyon yapmamış kullanıcılar (EXCEPT sorgusu)
 */
const getInactiveCollectors = async (req, res) => {
  try {
    // EXCEPT sorgusu (Ödev gereksinimi)
    const result = await query(`
      SELECT user_id, first_name, last_name, email, created_at
      FROM users
      WHERE is_active = true
      
      EXCEPT
      
      SELECT DISTINCT u.user_id, u.first_name, u.last_name, u.email, u.created_at
      FROM users u 
      JOIN reservations r ON u.user_id = r.collector_id
      
      ORDER BY created_at DESC
    `);

    res.json({
      success: true,
      message: 'Hiç rezervasyon yapmamış kullanıcılar (EXCEPT sorgusu)',
      count: result.rows.length,
      sqlUsed: 'EXCEPT',
      data: result.rows
    });

  } catch (error) {
    console.error('getInactiveCollectors error:', error);
    res.status(500).json({
      success: false,
      message: 'Kullanıcılar alınırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/reports/top-contributors
 * En çok atık paylaşan kullanıcılar (AGGREGATE + HAVING)
 */
const getTopContributors = async (req, res) => {
  try {
    const { minWasteCount } = req.query;
    const threshold = minWasteCount || 1;

    // Aggregate fonksiyonlar + HAVING (Ödev gereksinimi)
    const result = await query(`
      SELECT 
        u.user_id,
        u.first_name,
        u.last_name,
        u.first_name || ' ' || u.last_name AS full_name,
        u.email,
        u.city,
        COUNT(w.waste_id) AS waste_count,
        SUM(w.amount) AS total_amount,
        COUNT(CASE WHEN w.status = 'collected' THEN 1 END) AS collected_count,
        COALESCE((SELECT SUM(total_score) FROM environmental_scores es WHERE es.user_id = u.user_id), 0) AS total_score,
        MAX(w.record_date) AS last_contribution
      FROM users u
      JOIN waste w ON u.user_id = w.user_id
      GROUP BY u.user_id, u.first_name, u.last_name, u.email, u.city
      HAVING COUNT(w.waste_id) >= $1
      ORDER BY total_score DESC, waste_count DESC
    `, [threshold]);

    res.json({
      success: true,
      message: `En az ${threshold} atık paylaşan kullanıcılar (AGGREGATE + HAVING)`,
      count: result.rows.length,
      sqlUsed: 'COUNT, SUM, CASE WHEN + HAVING',
      threshold: parseInt(threshold),
      data: result.rows
    });

  } catch (error) {
    console.error('getTopContributors error:', error);
    res.status(500).json({
      success: false,
      message: 'Rapor alınırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/reports/waste-statistics
 * Atık türlerine göre istatistikler (AGGREGATE)
 */
const getWasteStatistics = async (req, res) => {
  try {
    // Aggregate fonksiyonlar (Ödev gereksinimi)
    const result = await query(`
      SELECT 
        wt.type_name,
        wt.official_unit,
        wt.recycle_score,
        COUNT(w.waste_id) AS total_items,
        COALESCE(SUM(w.amount), 0) AS total_amount,
        COALESCE(AVG(w.amount), 0)::DECIMAL(10,2) AS avg_amount,
        COALESCE(MIN(w.amount), 0) AS min_amount,
        COALESCE(MAX(w.amount), 0) AS max_amount,
        COUNT(CASE WHEN w.status = 'collected' THEN 1 END) AS collected_count,
        COUNT(CASE WHEN w.status = 'waiting' THEN 1 END) AS waiting_count
      FROM waste_types wt
      LEFT JOIN waste w ON wt.type_id = w.type_id
      GROUP BY wt.type_id, wt.type_name, wt.official_unit, wt.recycle_score
      ORDER BY total_items DESC
    `);

    res.json({
      success: true,
      message: 'Atık türlerine göre istatistikler',
      sqlUsed: 'COUNT, SUM, AVG, MIN, MAX, CASE WHEN',
      data: result.rows
    });

  } catch (error) {
    console.error('getWasteStatistics error:', error);
    res.status(500).json({
      success: false,
      message: 'İstatistikler alınırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/reports/monthly-overview
 * Aylık geri dönüşüm raporu (VIEW kullanır)
 */
const getMonthlyOverview = async (req, res) => {
  try {
    const { year } = req.query;
    const targetYear = year || new Date().getFullYear();

    // VIEW kullan (Ödev gereksinimi)
    const result = await query(`
      SELECT * FROM v_monthly_recycling_report
      WHERE year = $1
      ORDER BY month DESC, total_amount DESC
    `, [targetYear]);

    // Toplam özet
    const summary = await query(`
      SELECT 
        COUNT(*) as total_types,
        SUM(total_items) as total_items,
        SUM(total_amount) as total_amount,
        SUM(total_score_contribution) as total_score
      FROM v_monthly_recycling_report
      WHERE year = $1
    `, [targetYear]);

    res.json({
      success: true,
      message: `${targetYear} yılı aylık geri dönüşüm raporu (VIEW)`,
      year: parseInt(targetYear),
      sqlUsed: 'VIEW (v_monthly_recycling_report)',
      summary: summary.rows[0],
      data: result.rows
    });

  } catch (error) {
    console.error('getMonthlyOverview error:', error);
    res.status(500).json({
      success: false,
      message: 'Rapor alınırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/reports/user-statistics
 * Tüm kullanıcıların istatistikleri (VIEW kullanır)
 */
const getUserStatistics = async (req, res) => {
  try {
    // VIEW kullan (Ödev gereksinimi)
    const result = await query(`
      SELECT * FROM v_user_statistics
      ORDER BY total_environmental_score DESC
    `);

    res.json({
      success: true,
      message: 'Kullanıcı istatistikleri (VIEW)',
      count: result.rows.length,
      sqlUsed: 'VIEW (v_user_statistics)',
      data: result.rows
    });

  } catch (error) {
    console.error('getUserStatistics error:', error);
    res.status(500).json({
      success: false,
      message: 'İstatistikler alınırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/reports/city-ranking
 * Şehirlere göre geri dönüşüm sıralaması (AGGREGATE + HAVING)
 */
const getCityRanking = async (req, res) => {
  try {
    const { minUsers } = req.query;
    const threshold = minUsers || 1;

    // Aggregate + HAVING
    const result = await query(`
      SELECT 
        u.city,
        COUNT(DISTINCT u.user_id) AS user_count,
        COUNT(w.waste_id) AS total_waste_items,
        COALESCE(SUM(w.amount), 0)::DECIMAL(10,2) AS total_amount,
        COALESCE(SUM(w.amount * wt.recycle_score), 0)::INTEGER AS total_score
      FROM users u
      LEFT JOIN waste w ON u.user_id = w.user_id
      LEFT JOIN waste_types wt ON w.type_id = wt.type_id
      WHERE u.city IS NOT NULL
      GROUP BY u.city
      HAVING COUNT(DISTINCT u.user_id) >= $1
      ORDER BY total_score DESC
    `, [threshold]);

    res.json({
      success: true,
      message: `Şehir sıralaması (en az ${threshold} kullanıcı)`,
      sqlUsed: 'AGGREGATE + HAVING',
      threshold: parseInt(threshold),
      data: result.rows
    });

  } catch (error) {
    console.error('getCityRanking error:', error);
    res.status(500).json({
      success: false,
      message: 'Sıralama alınırken hata oluştu',
      error: error.message
    });
  }
};

/**
 * GET /api/reports/my
 * Giriş yapmış kullanıcının kendi raporu
 */
const getMyReport = async (req, res) => {
  try {
    const user_id = req.user.user_id;

    // Kullanıcı bilgileri
    const userInfo = await query(`
      SELECT * FROM v_user_statistics WHERE user_id = $1
    `, [user_id]);

    // Toplam puan (fonksiyon kullan)
    const score = await query(
      `SELECT fn_calculate_user_total_score($1) as total_score`,
      [user_id]
    );

    // Aylık detay
    const year = new Date().getFullYear();
    const month = new Date().getMonth() + 1;
    const monthlyReport = await query(
      `SELECT * FROM fn_get_user_monthly_report($1, $2, $3)`,
      [user_id, year, month]
    );

    // Son atıklar
    const recentWaste = await query(`
      SELECT w.*, wt.type_name, wt.official_unit
      FROM waste w
      JOIN waste_types wt ON w.type_id = wt.type_id
      WHERE w.user_id = $1
      ORDER BY w.record_date DESC
      LIMIT 5
    `, [user_id]);

    res.json({
      success: true,
      message: 'Kişisel çevresel etki raporu',
      data: {
        statistics: userInfo.rows[0],
        calculatedScore: score.rows[0].total_score,
        currentMonthReport: monthlyReport.rows,
        recentWaste: recentWaste.rows
      }
    });

  } catch (error) {
    console.error('getMyReport error:', error);
    res.status(500).json({
      success: false,
      message: 'Rapor alınırken hata oluştu',
      error: error.message
    });
  }
};

module.exports = {
  getUserMonthlyReport,
  getUserTotalScore,
  getActiveUsers,
  getInactiveCollectors,
  getTopContributors,
  getWasteStatistics,
  getMonthlyOverview,
  getUserStatistics,
  getCityRanking,
  getMyReport
};
