import { useState, useRef, useEffect } from 'react'
import { useLocation, useNavigate, Link } from 'react-router-dom'
import toast from 'react-hot-toast'
import AuthLayout from '../components/AuthLayout'
import { LoadingButton } from '../components/FormElements'
import { useAuth } from '../context/AuthContext'

const VerifyOTP = () => {
  const location = useLocation()
  const navigate = useNavigate()
  const { verifyOTP, resendOTP } = useAuth()
  
  const email = location.state?.email || ''
  
  const [otp, setOtp] = useState(['', '', '', '', '', ''])
  const [loading, setLoading] = useState(false)
  const [resendLoading, setResendLoading] = useState(false)
  const [countdown, setCountdown] = useState(60)
  const [canResend, setCanResend] = useState(false)
  
  const inputRefs = useRef([])

  // Redirect if no email in state
  useEffect(() => {
    if (!email) {
      navigate('/register')
    }
  }, [email, navigate])

  // Countdown timer for resend
  useEffect(() => {
    if (countdown > 0) {
      const timer = setTimeout(() => setCountdown(countdown - 1), 1000)
      return () => clearTimeout(timer)
    } else {
      setCanResend(true)
    }
  }, [countdown])

  const handleChange = (index, value) => {
    // Only allow numbers
    if (!/^\d*$/.test(value)) return
    
    const newOtp = [...otp]
    newOtp[index] = value.slice(-1) // Only take last character
    setOtp(newOtp)

    // Auto-focus next input
    if (value && index < 5) {
      inputRefs.current[index + 1]?.focus()
    }
  }

  const handleKeyDown = (index, e) => {
    // Handle backspace
    if (e.key === 'Backspace' && !otp[index] && index > 0) {
      inputRefs.current[index - 1]?.focus()
    }
  }

  const handlePaste = (e) => {
    e.preventDefault()
    const pastedData = e.clipboardData.getData('text').slice(0, 6)
    
    if (!/^\d+$/.test(pastedData)) return
    
    const newOtp = [...otp]
    pastedData.split('').forEach((char, index) => {
      if (index < 6) newOtp[index] = char
    })
    setOtp(newOtp)

    // Focus last filled input or last input
    const lastFilledIndex = Math.min(pastedData.length - 1, 5)
    inputRefs.current[lastFilledIndex]?.focus()
  }

  const handleSubmit = async (e) => {
    e.preventDefault()
    
    const code = otp.join('')
    
    if (code.length !== 6) {
      toast.error('Lütfen tam 6 haneli kodu girin')
      return
    }
    
    setLoading(true)
    try {
      const response = await verifyOTP(email, code)
      
      if (response.success) {
        toast.success('E-posta başarılı şekilde doğrulandı! 🎉')
        navigate('/dashboard')
      }
    } catch (error) {
      const errorMessage = error.response?.data?.message || 'Verification failed'
      toast.error(errorMessage)
      
      // Clear OTP on error
      setOtp(['', '', '', '', '', ''])
      inputRefs.current[0]?.focus()
    } finally {
      setLoading(false)
    }
  }

  const handleResend = async () => {
    if (!canResend) return
    
    setResendLoading(true)
    try {
      const response = await resendOTP(email)
      
      if (response.success) {
        toast.success('Yeni kod gönderildi! E-postanızı kontrol edin.')
        setCountdown(60)
        setCanResend(false)
        setOtp(['', '', '', '', '', ''])
        inputRefs.current[0]?.focus()
      }
    } catch (error) {
      toast.error(error.response?.data?.message || 'Kod yeniden gönderilemedi')
    } finally {
      setResendLoading(false)
    }
  }

  return (
    <AuthLayout 
      title="E-postanızı Doğrulayın" 
      subtitle="E-postanıza 6 haneli bir kod gönderdik"
    >
      {/* Email Display */}
      <div className="bg-eco-50 rounded-xl p-4 mb-6 text-center">
        <p className="text-sm text-gray-600">Kodu gönderilen adres:</p>
        <p className="font-semibold text-emerald-700">{email}</p>
      </div>

      <form onSubmit={handleSubmit}>
        {/* OTP Input Grid */}
        <div className="flex justify-center gap-2 sm:gap-3 mb-6">
          {otp.map((digit, index) => (
            <input
              key={index}
              ref={(el) => (inputRefs.current[index] = el)}
              type="text"
              inputMode="numeric"
              maxLength={1}
              value={digit}
              onChange={(e) => handleChange(index, e.target.value)}
              onKeyDown={(e) => handleKeyDown(index, e)}
              onPaste={index === 0 ? handlePaste : undefined}
              className="otp-input"
              autoFocus={index === 0}
            />
          ))}
        </div>

        {/* Timer & Resend */}
        <div className="text-center mb-6">
          {canResend ? (
            <button
              type="button"
              onClick={handleResend}
              disabled={resendLoading}
              className="text-emerald-600 hover:text-emerald-700 font-semibold hover:underline disabled:opacity-50"
            >
              {resendLoading ? (
                <span className="flex items-center justify-center gap-2">
                  <span className="loading loading-spinner loading-xs"></span>
                  Gönderiliyor...
                </span>
              ) : (
                "Kod gelmedi mi? Tekrar Gönder"
              )}
            </button>
          ) : (
            <p className="text-gray-500">
              Kodu tekrar gönder: {' '}
              <span className="font-semibold text-emerald-600">
                {Math.floor(countdown / 60)}:{(countdown % 60).toString().padStart(2, '0')}
              </span>
            </p>
          )}
        </div>

        <LoadingButton
          type="submit"
          loading={loading}
          className="w-full"
        >
          E-posta Doğrula
        </LoadingButton>
      </form>

      {/* Back to login */}
      <div className="text-center mt-6">
        <Link 
          to="/login"
          className="text-gray-600 hover:text-emerald-600 text-sm"
        >
          ← Giriş Sayfasına Dön
        </Link>
      </div>

      {/* Spam notice */}
      <div className="mt-6 bg-amber-50 border border-amber-200 rounded-xl p-4 text-center">
        <p className="text-sm text-amber-700">
          <span className="font-semibold">E-postası bulamadın mı?</span>
          <br />
          Spam veya Çöp klasörünü kontrol et
        </p>
      </div>
    </AuthLayout>
  )
}

export default VerifyOTP
