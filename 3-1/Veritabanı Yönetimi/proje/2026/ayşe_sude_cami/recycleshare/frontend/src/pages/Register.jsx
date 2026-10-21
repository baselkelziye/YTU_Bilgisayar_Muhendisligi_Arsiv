import { useState } from 'react'
import { Link, useNavigate } from 'react-router-dom'
import { GoogleLogin } from '@react-oauth/google'
import toast from 'react-hot-toast'
import AuthLayout from '../components/AuthLayout'
import { 
  TextInput, 
  PasswordInput, 
  PhoneInput,
  LoadingButton, 
  Divider,
  FiMail,
  FiUser
} from '../components/FormElements'
import { useAuth } from '../context/AuthContext'

const Register = () => {
  const navigate = useNavigate()
  const { register, googleAuth } = useAuth()
  
  const [formData, setFormData] = useState({
    firstName: '',
    lastName: '',
    email: '',
    phone: '',
    password: '',
    confirmPassword: ''
  })
  const [countryCode, setCountryCode] = useState('+90')
  const [showPassword, setShowPassword] = useState(false)
  const [showConfirmPassword, setShowConfirmPassword] = useState(false)
  const [loading, setLoading] = useState(false)
  const [googleLoading, setGoogleLoading] = useState(false)
  const [errors, setErrors] = useState({})

  const handleChange = (e) => {
    const { name, value } = e.target
    setFormData(prev => ({ ...prev, [name]: value }))
    if (errors[name]) {
      setErrors(prev => ({ ...prev, [name]: '' }))
    }
  }

  const validateForm = () => {
    const newErrors = {}
    
    if (!formData.firstName.trim()) {
      newErrors.firstName = 'First name is required'
    } else if (formData.firstName.length < 2) {
      newErrors.firstName = 'First name must be at least 2 characters'
    }

    if (!formData.lastName.trim()) {
      newErrors.lastName = 'Last name is required'
    } else if (formData.lastName.length < 2) {
      newErrors.lastName = 'Last name must be at least 2 characters'
    }
    
    if (!formData.email) {
      newErrors.email = 'Email is required'
    } else if (!/\S+@\S+\.\S+/.test(formData.email)) {
      newErrors.email = 'Please enter a valid email'
    }

    if (!formData.phone) {
      newErrors.phone = 'Phone number is required'
    } else if (!/^[\d\s\-()]{7,15}$/.test(formData.phone)) {
      newErrors.phone = 'Please enter a valid phone number'
    }
    
    if (!formData.password) {
      newErrors.password = 'Password is required'
    } else if (formData.password.length < 8) {
      newErrors.password = 'Password must be at least 8 characters'
    } else if (!/^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)/.test(formData.password)) {
      newErrors.password = 'Password must include uppercase, lowercase, and number'
    }

    if (formData.password !== formData.confirmPassword) {
      newErrors.confirmPassword = 'Passwords do not match'
    }
    
    setErrors(newErrors)
    return Object.keys(newErrors).length === 0
  }

  const handleSubmit = async (e) => {
    e.preventDefault()
    
    if (!validateForm()) return
    
    setLoading(true)
    try {
      const fullPhone = `${countryCode}${formData.phone.replace(/\D/g, '')}`
      
      const response = await register({
        firstName: formData.firstName,
        lastName: formData.lastName,
        email: formData.email,
        phone: fullPhone,
        password: formData.password
      })
      
      if (response.success) {
        toast.success('Hesap oluşturuldu! E-posta doğrulama kodu için e-postanızı kontrol edin.')
        navigate('/verify-otp', { 
          state: { email: formData.email } 
        })
      }
    } catch (error) {
      console.error('Kayıt hatası:', error)
      const errorData = error.response?.data
      
      if (errorData?.errors) {
        // Validation errors from backend
        const backendErrors = {}
        errorData.errors.forEach(err => {
          backendErrors[err.field] = err.message
        })
        setErrors(backendErrors)
      } else if (error.code === 'ECONNABORTED') {
        toast.error('Sunucu başlatılıyor. Lütfen biraz bekleyip tekrar deneyin.')
      } else if (!error.response) {
        toast.error('Sunucuya bağlanılamıyor. Lütfen tekrar deneyin.')
      } else {
        toast.error(errorData?.message || 'Kayıt başarısız oldu. Lütfen tekrar deneyin.')
      }
    } finally {
      setLoading(false)
    }
  }

  // Google OAuth Success Handler
  const handleGoogleSuccess = async (credentialResponse) => {
    setGoogleLoading(true)
    try {
      const response = await googleAuth(credentialResponse.credential)
      
      if (response.success) {
        if (response.data.requiresPhone) {
          navigate('/google-phone-setup', {
            state: {
              googleId: response.data.googleId,
              email: response.data.email,
              firstName: response.data.firstName,
              lastName: response.data.lastName,
              profilePicture: response.data.profilePicture
            }
          })
        } else {
          toast.success('RecycleShare’a Hoşgeldin! 🌿')
          navigate('/dashboard')
        }
      }
    } catch (error) {
      toast.error(error.response?.data?.message || 'Google kaydı başarısız oldu')
    } finally {
      setGoogleLoading(false)
    }
  }

  const handleGoogleError = () => {
    toast.error('Google kaydı başarısız oldu. Lütfen tekrar deneyin.')
  }

  return (
    <AuthLayout 
      title="Hesap Oluştur" 
      subtitle="Çevreci dost topluluğa katılın"
    >
      <form onSubmit={handleSubmit} className="space-y-4">
        {/* Name Fields - Side by Side */}
        <div className="grid grid-cols-2 gap-4">
          <TextInput
            label="Ad"
            icon={FiUser}
            type="text"
            name="firstName"
            placeholder="Ahmet"
            value={formData.firstName}
            onChange={handleChange}
            error={errors.firstName}
            autoComplete="given-name"
          />
          <TextInput
            label="Soyad"
            type="text"
            name="lastName"
            placeholder="Yılmaz"
            value={formData.lastName}
            onChange={handleChange}
            error={errors.lastName}
            autoComplete="family-name"
          />
        </div>

        <TextInput
          label="E-posta Adresi"
          icon={FiMail}
          type="email"
          name="email"
          placeholder="siz@ornek.com"
          value={formData.email}
          onChange={handleChange}
          error={errors.email}
          autoComplete="email"
        />

        <PhoneInput
          label="Telefon Numarası"
          name="phone"
          placeholder="555 123 4567"
          value={formData.phone}
          onChange={handleChange}
          countryCode={countryCode}
          onCountryCodeChange={setCountryCode}
          error={errors.phone}
          autoComplete="tel"
        />

        <PasswordInput
          label="Parola"
          name="password"
          placeholder="Min. 8 karakter"
          value={formData.password}
          onChange={handleChange}
          showPassword={showPassword}
          onTogglePassword={() => setShowPassword(!showPassword)}
          error={errors.password}
          autoComplete="new-password"
        />

        <PasswordInput
          label="Parola Onayla"
          name="confirmPassword"
          placeholder="Parolanızı onaylaın"
          value={formData.confirmPassword}
          onChange={handleChange}
          showPassword={showConfirmPassword}
          onTogglePassword={() => setShowConfirmPassword(!showConfirmPassword)}
          error={errors.confirmPassword}
          autoComplete="new-password"
        />

        {/* Password requirements hint */}
        <div className="text-xs text-gray-500 bg-eco-50 p-3 rounded-lg">
          <p className="font-medium text-gray-600 mb-1">Parola şu öğeleri içermelidir:</p>
          <ul className="space-y-1">
            <li className={`flex items-center gap-2 ${formData.password.length >= 8 ? 'text-emerald-600' : ''}`}>
              <span>{formData.password.length >= 8 ? '✓' : '○'}</span> En az 8 karakter
            </li>
            <li className={`flex items-center gap-2 ${/[A-Z]/.test(formData.password) ? 'text-emerald-600' : ''}`}>
              <span>{/[A-Z]/.test(formData.password) ? '✓' : '○'}</span> Bir büyük harf
            </li>
            <li className={`flex items-center gap-2 ${/[a-z]/.test(formData.password) ? 'text-emerald-600' : ''}`}>
              <span>{/[a-z]/.test(formData.password) ? '✓' : '○'}</span> Bir küçük harf
            </li>
            <li className={`flex items-center gap-2 ${/\d/.test(formData.password) ? 'text-emerald-600' : ''}`}>
              <span>{/\d/.test(formData.password) ? '✓' : '○'}</span> Bir sayı
            </li>
          </ul>
        </div>

        <LoadingButton
          type="submit"
          loading={loading}
          className="w-full mt-6"
        >
          Hesap Oluştur
        </LoadingButton>
      </form>

      <Divider text="veya kaydol" />

      {/* Google Sign Up Button */}
      <div className="flex justify-center">
        {googleLoading ? (
          <div className="btn btn-outline w-full rounded-xl border-gray-200">
            <span className="loading loading-spinner loading-sm"></span>
          </div>
        ) : (
          <GoogleLogin
            onSuccess={handleGoogleSuccess}
            onError={handleGoogleError}
            theme="outline"
            size="large"
            text="signup_with"
            shape="rectangular"
          />
        )}
      </div>

      {/* Sign In Link */}
      <p className="text-center mt-6 text-gray-600">
        Zaten bir hesabın var mı?{' '}
        <Link 
          to="/login" 
          className="text-emerald-600 font-semibold hover:text-emerald-700 hover:underline"
        >
          Giriş Yap
        </Link>
      </p>
    </AuthLayout>
  )
}

export default Register
