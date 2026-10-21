const express = require('express');
const router = express.Router();
const reportController = require('../controllers/report.controller');
const { authenticateToken, requireRole } = require('../middleware/auth.middleware');

// ============================================
// REPORT ROUTES - /api/reports
// ============================================

// Protected routes
router.use(authenticateToken);

// Kullanıcının kendi raporu
router.get('/my', reportController.getMyReport);

// Kullanıcı raporları
router.get('/user/:userId/monthly', reportController.getUserMonthlyReport);
router.get('/user/:userId/score', reportController.getUserTotalScore);

// Genel istatistikler
router.get('/user-statistics', reportController.getUserStatistics);
router.get('/waste-statistics', reportController.getWasteStatistics);
router.get('/monthly-overview', reportController.getMonthlyOverview);
router.get('/city-ranking', reportController.getCityRanking);

// Özel sorgular (UNION, EXCEPT, HAVING)
router.get('/active-users', reportController.getActiveUsers);
router.get('/inactive-collectors', reportController.getInactiveCollectors);
router.get('/top-contributors', reportController.getTopContributors);

module.exports = router;
