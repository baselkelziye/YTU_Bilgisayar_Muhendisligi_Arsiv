const express = require('express');
const router = express.Router();
const reservationController = require('../controllers/reservation.controller');
const { authenticateToken } = require('../middleware/auth.middleware');

// ============================================
// RESERVATION ROUTES - /api/reservations
// ============================================

// All routes require authentication
router.use(authenticateToken);

// My reservations
router.get('/my/collector', reservationController.getMyCollectorReservations);
router.get('/my/owner', reservationController.getMyOwnerReservations);

// Complete collection (Collector completes pickup)
// Register specific route before generic '/:id' to avoid accidental mismatches
router.post('/:id/complete-collection', reservationController.completeCollection);
// Also accept PUT for clients that may use PUT instead of POST
router.put('/:id/complete-collection', reservationController.completeCollection);

// CRUD operations
router.get('/', reservationController.getAllReservations);
router.get('/:id', reservationController.getReservationById);
router.post('/', reservationController.createReservation);
router.put('/:id', reservationController.updateReservation);
router.delete('/:id', reservationController.deleteReservation);

module.exports = router;
