const express = require('express');
const router = express.Router();
const wasteController = require('../controllers/waste.controller');
const { authenticateToken, requireRole } = require('../middleware/auth.middleware');

// ============================================
// WASTE ROUTES - /api/waste
// ============================================

// Public routes
router.get('/types', wasteController.getWasteTypes);

// Protected routes (giriş yapmış kullanıcılar)
router.get('/', authenticateToken, wasteController.getAllWaste);
router.get('/search', authenticateToken, wasteController.searchWasteByCity);
router.get('/my', authenticateToken, wasteController.getMyWaste);
router.get('/stats', authenticateToken, wasteController.getImpactStats);  // Must be before /:id
router.get('/:id', authenticateToken, wasteController.getWasteById);
router.post('/', authenticateToken, wasteController.createWaste);
router.put('/:id', authenticateToken, wasteController.updateWaste);
router.delete('/:id', authenticateToken, wasteController.deleteWaste);

module.exports = router;

