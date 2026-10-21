import { FiMail, FiLock, FiEye, FiEyeOff, FiUser, FiPhone } from 'react-icons/fi'

// Text Input Component
export const TextInput = ({ 
  label, 
  icon: Icon, 
  error, 
  ...props 
}) => {
  return (
    <div className="form-control w-full">
      {label && (
        <label className="label">
          <span className="label-text text-gray-700 font-medium">{label}</span>
        </label>
      )}
      <div className="relative">
        {Icon && (
          <div className="absolute inset-y-0 left-0 pl-4 flex items-center pointer-events-none">
            <Icon className="h-5 w-5 text-gray-400" />
          </div>
        )}
        <input
          className={`eco-input w-full ${Icon ? 'pl-12' : ''} ${error ? 'border-red-400 focus:border-red-500' : ''}`}
          {...props}
        />
      </div>
      {error && (
        <label className="label">
          <span className="label-text-alt text-red-500">{error}</span>
        </label>
      )}
    </div>
  )
}

// Password Input Component
export const PasswordInput = ({ 
  label, 
  error,
  showPassword,
  onTogglePassword,
  ...props 
}) => {
  return (
    <div className="form-control w-full">
      {label && (
        <label className="label">
          <span className="label-text text-gray-700 font-medium">{label}</span>
        </label>
      )}
      <div className="relative">
        <div className="absolute inset-y-0 left-0 pl-4 flex items-center pointer-events-none">
          <FiLock className="h-5 w-5 text-gray-400" />
        </div>
        <input
          type={showPassword ? 'text' : 'password'}
          className={`eco-input w-full pl-12 pr-12 ${error ? 'border-red-400 focus:border-red-500' : ''}`}
          {...props}
        />
        <button
          type="button"
          onClick={onTogglePassword}
          className="absolute inset-y-0 right-0 pr-4 flex items-center text-gray-400 hover:text-gray-600 transition-colors"
        >
          {showPassword ? <FiEyeOff className="h-5 w-5" /> : <FiEye className="h-5 w-5" />}
        </button>
      </div>
      {error && (
        <label className="label">
          <span className="label-text-alt text-red-500">{error}</span>
        </label>
      )}
    </div>
  )
}

// Phone Input Component
export const PhoneInput = ({ 
  label, 
  error,
  countryCode = '+90',
  onCountryCodeChange,
  ...props 
}) => {
  const countryCodes = [
    { code: '+90', country: '🇹🇷 TR' },
    { code: '+1', country: '🇺🇸 US' },
    { code: '+44', country: '🇬🇧 UK' },
    { code: '+49', country: '🇩🇪 DE' },
    { code: '+33', country: '🇫🇷 FR' },
    { code: '+81', country: '🇯🇵 JP' },
    { code: '+86', country: '🇨🇳 CN' },
    { code: '+91', country: '🇮🇳 IN' },
  ]

  return (
    <div className="form-control w-full">
      {label && (
        <label className="label">
          <span className="label-text text-gray-700 font-medium">{label}</span>
        </label>
      )}
      <div className="relative flex">
        <select
          value={countryCode}
          onChange={(e) => onCountryCodeChange?.(e.target.value)}
          className="select select-bordered border-eco-200 focus:border-emerald-500 rounded-xl rounded-r-none border-r-0 bg-eco-50 font-medium min-h-0 h-12"
        >
          {countryCodes.map(({ code, country }) => (
            <option key={code} value={code}>{country} {code}</option>
          ))}
        </select>
        <div className="relative flex-1">
          <input
            type="tel"
            className={`eco-input w-full rounded-l-none ${error ? 'border-red-400 focus:border-red-500' : ''}`}
            {...props}
          />
        </div>
      </div>
      {error && (
        <label className="label">
          <span className="label-text-alt text-red-500">{error}</span>
        </label>
      )}
    </div>
  )
}

// Loading Button Component
export const LoadingButton = ({ 
  loading, 
  children, 
  className = '',
  ...props 
}) => {
  return (
    <button
      className={`eco-btn ${className} ${loading ? 'opacity-80 cursor-not-allowed' : ''}`}
      disabled={loading}
      {...props}
    >
      {loading ? (
        <>
          <span className="loading loading-spinner loading-sm"></span>
          <span className="ml-2">Please wait...</span>
        </>
      ) : (
        children
      )}
    </button>
  )
}

// Divider with text
export const Divider = ({ text }) => {
  return (
    <div className="flex items-center my-6">
      <div className="flex-grow border-t border-eco-200"></div>
      <span className="px-4 text-sm text-gray-500 font-medium">{text}</span>
      <div className="flex-grow border-t border-eco-200"></div>
    </div>
  )
}

// Export icons for convenience
export { FiMail, FiLock, FiEye, FiEyeOff, FiUser, FiPhone }
