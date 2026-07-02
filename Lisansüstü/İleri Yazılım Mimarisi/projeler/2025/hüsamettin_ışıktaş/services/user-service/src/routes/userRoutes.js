const express = require('express');
const router = express.Router();
const userController = require('../controllers/userController');
const { validateRegister, validateLogin, validateUpdateProfile } = require('../middleware/validation');
const { authenticate } = require('../middleware/auth');

// Public routes
router.post('/register', validateRegister, userController.register);
router.post('/login', validateLogin, userController.login);

// Protected routes
router.get('/me', authenticate, userController.getMe);
router.get('/search', authenticate, userController.search);
router.get('/:userId', authenticate, userController.getProfile);
router.put('/:userId', authenticate, validateUpdateProfile, userController.updateProfile);

module.exports = router;

