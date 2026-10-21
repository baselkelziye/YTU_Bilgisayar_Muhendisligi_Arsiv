const nodemailer = require('nodemailer');
const sgMail = require('@sendgrid/mail');

// Initialize SendGrid if API key available
if (process.env.SENDGRID_API_KEY) {
  sgMail.setApiKey(process.env.SENDGRID_API_KEY);
  console.log('📧 SendGrid initialized');
}

// Create nodemailer transporter for Gmail (local development only)
const createTransporter = () => {
  console.log('📧 Using Gmail SMTP (local)');
  return nodemailer.createTransport({
    host: process.env.SMTP_HOST || 'smtp.gmail.com',
    port: parseInt(process.env.SMTP_PORT) || 465,
    secure: true,
    auth: {
      user: process.env.SMTP_USER,
      pass: process.env.SMTP_PASSWORD
    },
    connectionTimeout: 10000,
    greetingTimeout: 10000,
    socketTimeout: 15000
  });
};

const transporter = !process.env.SENDGRID_API_KEY ? createTransporter() : null;

// Generate 6-digit OTP
const generateOTP = () => {
  return Math.floor(100000 + Math.random() * 900000).toString();
};

// Send OTP email
const sendOTPEmail = async (email, firstName, otp) => {
  // 🔧 DEV MODE: Always log OTP to console for testing
  console.log(`\n🔐 ========== OTP CODE ==========`);
  console.log(`📧 Email: ${email}`);
  console.log(`🔢 OTP Code: ${otp}`);
  console.log(`================================\n`);

  // Skip if no email config
  if (!process.env.RESEND_API_KEY && !process.env.SMTP_USER) {
    console.log('⚠️  Email not configured - skipped');
    return true;
  }

  // Use Resend's default domain or custom SMTP_USER
  const fromEmail = process.env.RESEND_API_KEY 
    ? 'RecycleShare <onboarding@resend.dev>'
    : `"RecycleShare 🌿" <${process.env.SMTP_USER}>`;

  const mailOptions = {
    from: fromEmail,
    to: email,
    subject: '🔐 Verify Your RecycleShare Account',
    html: `
      <!DOCTYPE html>
      <html>
      <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
      </head>
      <body style="margin: 0; padding: 0; font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; background-color: #f0fdf4;">
        <div style="max-width: 600px; margin: 0 auto; background-color: #ffffff; border-radius: 16px; overflow: hidden; margin-top: 40px; margin-bottom: 40px; box-shadow: 0 4px 6px -1px rgba(0, 0, 0, 0.1);">
          
          <!-- Header -->
          <div style="background: linear-gradient(135deg, #059669 0%, #10b981 100%); padding: 40px 30px; text-align: center;">
            <h1 style="color: #ffffff; margin: 0; font-size: 28px; font-weight: 700;">
              🌿 RecycleShare
            </h1>
            <p style="color: #d1fae5; margin: 10px 0 0 0; font-size: 14px;">
              Join the green revolution
            </p>
          </div>
          
          <!-- Content -->
          <div style="padding: 40px 30px;">
            <h2 style="color: #064e3b; margin: 0 0 20px 0; font-size: 22px;">
              Hello ${firstName}! 👋
            </h2>
            
            <p style="color: #374151; font-size: 16px; line-height: 1.6; margin: 0 0 30px 0;">
              Welcome to RecycleShare! Please use the verification code below to complete your registration:
            </p>
            
            <!-- OTP Box -->
            <div style="background: linear-gradient(135deg, #ecfdf5 0%, #d1fae5 100%); border-radius: 12px; padding: 30px; text-align: center; margin-bottom: 30px;">
              <p style="color: #065f46; font-size: 14px; margin: 0 0 15px 0; text-transform: uppercase; letter-spacing: 2px;">
                Your Verification Code
              </p>
              <div style="background-color: #ffffff; border-radius: 8px; padding: 20px; display: inline-block; border: 2px dashed #10b981;">
                <span style="font-size: 36px; font-weight: 700; letter-spacing: 8px; color: #059669; font-family: 'Courier New', monospace;">
                  ${otp}
                </span>
              </div>
              <p style="color: #6b7280; font-size: 13px; margin: 20px 0 0 0;">
                ⏱️ This code expires in <strong>10 minutes</strong>
              </p>
            </div>
            
            <p style="color: #6b7280; font-size: 14px; line-height: 1.6; margin: 0;">
              If you didn't request this code, please ignore this email. Someone may have entered your email address by mistake.
            </p>
          </div>
          
          <!-- Footer -->
          <div style="background-color: #f9fafb; padding: 25px 30px; text-align: center; border-top: 1px solid #e5e7eb;">
            <p style="color: #9ca3af; font-size: 12px; margin: 0;">
              © 2026 RecycleShare. Making the world greener, one share at a time 🌍
            </p>
          </div>
          
        </div>
      </body>
      </html>
    `
  };

  try {
    console.log(`📤 Attempting to send OTP email to ${email}...`);
    
    // Use SendGrid in production
    if (process.env.SENDGRID_API_KEY) {
      console.log('📧 Using SendGrid');
      await sgMail.send({
        to: email,
        from: process.env.SMTP_USER || 'recycleshareco@gmail.com',
        subject: '🔐 Verify Your RecycleShare Account',
        html: mailOptions.html
      });
    } else {
      // Use nodemailer for local development
      await transporter.sendMail(mailOptions);
    }
    
    console.log(`✅ OTP email sent to ${email}`);
    return true;
  } catch (error) {
    console.error('❌ Failed to send OTP email:', error.message);
    console.error('📋 Error details:', error.response?.body || error);
    // Don't throw - let the registration succeed even if email fails
    return false;
  }
};

// Send welcome email after verification
const sendWelcomeEmail = async (email, firstName) => {
  const fromEmail = process.env.RESEND_API_KEY 
    ? 'RecycleShare <onboarding@resend.dev>'
    : `"RecycleShare 🌿" <${process.env.SMTP_USER}>`;

  const mailOptions = {
    from: fromEmail,
    to: email,
    subject: '🎉 Welcome to RecycleShare!',
    html: `
      <!DOCTYPE html>
      <html>
      <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
      </head>
      <body style="margin: 0; padding: 0; font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; background-color: #f0fdf4;">
        <div style="max-width: 600px; margin: 0 auto; background-color: #ffffff; border-radius: 16px; overflow: hidden; margin-top: 40px; margin-bottom: 40px; box-shadow: 0 4px 6px -1px rgba(0, 0, 0, 0.1);">
          
          <!-- Header -->
          <div style="background: linear-gradient(135deg, #059669 0%, #10b981 100%); padding: 40px 30px; text-align: center;">
            <h1 style="color: #ffffff; margin: 0; font-size: 28px; font-weight: 700;">
              🌿 RecycleShare
            </h1>
          </div>
          
          <!-- Content -->
          <div style="padding: 40px 30px; text-align: center;">
            <div style="font-size: 60px; margin-bottom: 20px;">🎉</div>
            <h2 style="color: #064e3b; margin: 0 0 20px 0; font-size: 26px;">
              Welcome Aboard, ${firstName}!
            </h2>
            
            <p style="color: #374151; font-size: 16px; line-height: 1.6; margin: 0 0 30px 0;">
              Your account has been verified! You're now part of our eco-friendly community.
            </p>
            
            <a href="${process.env.FRONTEND_URL}" style="display: inline-block; background: linear-gradient(135deg, #059669 0%, #10b981 100%); color: #ffffff; text-decoration: none; padding: 14px 40px; border-radius: 8px; font-weight: 600; font-size: 16px;">
              Start Recycling ♻️
            </a>
          </div>
          
          <!-- Footer -->
          <div style="background-color: #f9fafb; padding: 25px 30px; text-align: center; border-top: 1px solid #e5e7eb;">
            <p style="color: #9ca3af; font-size: 12px; margin: 0;">
              © 2026 RecycleShare. Making the world greener 🌍
            </p>
          </div>
          
        </div>
      </body>
      </html>
    `
  };

  try {
    if (process.env.SENDGRID_API_KEY) {
      await sgMail.send({
        to: email,
        from: process.env.SMTP_USER || 'recycleshareco@gmail.com',
        subject: '🎉 Welcome to RecycleShare!',
        html: mailOptions.html
      });
    } else {
      await transporter.sendMail(mailOptions);
    }
    console.log(`✅ Welcome email sent to ${email}`);
    return true;
  } catch (error) {
    console.error('❌ Failed to send welcome email:', error);
    // Don't throw - welcome email is not critical
    return false;
  }
};

module.exports = {
  generateOTP,
  sendOTPEmail,
  sendWelcomeEmail
};
