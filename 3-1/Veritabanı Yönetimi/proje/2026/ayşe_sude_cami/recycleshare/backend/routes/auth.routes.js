const express = require('express');
const router = express.Router();

const {
  register,
  verifyOTP,
  resendOTP,
  login,
  googleAuth,
  googleAuthComplete,
  getCurrentUser
} = require('../controllers/auth.controller');

const { updateCurrentUser } = require('../controllers/auth.controller');

const {
  registerValidation,
  loginValidation,
  verifyOTPValidation,
  resendOTPValidation,
  googleAuthValidation,
  googleAuthCompleteValidation
} = require('../validators/auth.validator');

const validate = require('../middleware/validate.middleware');
const { authenticate } = require('../middleware/auth.middleware');

// Standard Auth Routes
router.post('/register', registerValidation, validate, register);
router.post('/login', loginValidation, validate, login);

// OTP Verification Routes
router.post('/verify-otp', verifyOTPValidation, validate, verifyOTP);
router.post('/resend-otp', resendOTPValidation, validate, resendOTP);

// Google Auth Routes
router.post('/google', googleAuthValidation, validate, googleAuth);
router.post('/google/complete', googleAuthCompleteValidation, validate, googleAuthComplete);

// Protected Routes
router.get('/me', authenticate, getCurrentUser);
router.put('/me', authenticate, updateCurrentUser);

module.exports = router;
