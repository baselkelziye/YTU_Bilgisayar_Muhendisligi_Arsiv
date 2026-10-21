import { Link } from 'react-router-dom'

const AuthLayout = ({ children, title, subtitle }) => {
  return (
    <div className="min-h-screen flex flex-col lg:flex-row">
      {/* Left Side - Branding */}
      <div className="hidden lg:flex lg:w-1/2 bg-eco-gradient relative overflow-hidden">
        {/* Decorative Elements */}
        <div className="absolute inset-0 opacity-10">
          <div className="absolute top-20 left-20 w-40 h-40 bg-white rounded-full animate-float"></div>
          <div className="absolute bottom-40 right-20 w-60 h-60 bg-white rounded-full animate-float" style={{ animationDelay: '1s' }}></div>
          <div className="absolute top-1/2 left-1/3 w-20 h-20 bg-white rounded-full animate-float" style={{ animationDelay: '0.5s' }}></div>
        </div>

        {/* Content */}
        <div className="relative z-10 flex flex-col items-center justify-center w-full p-12 text-white">
          {/* Logo */}
          <div className="flex items-center gap-3 mb-8">
            <div className="w-16 h-16 bg-white/20 backdrop-blur-sm rounded-2xl flex items-center justify-center">
              <span className="text-4xl">🌿</span>
            </div>
            <span className="text-4xl font-bold">RecycleShare</span>
          </div>

          {/* Tagline */}
          <h1 className="text-3xl lg:text-4xl font-bold text-center mb-4">
            Gelecek İçin Dönüştür
          </h1>
          <p className="text-xl text-emerald-100 text-center max-w-md mb-12">
            Kaynakları paylaş, atıkları azalt ve gezegene olumlu etki yapmaya katkıda bulun.
          </p>

          {/* Features */}
          <div className="grid grid-cols-1 gap-6 max-w-sm">
            <div className="flex items-center gap-4 bg-white/10 backdrop-blur-sm rounded-xl p-4">
              <div className="w-12 h-12 bg-white/20 rounded-xl flex items-center justify-center text-2xl">
                ♻️
              </div>
              <div>
                <h3 className="font-semibold">Kolaylaştırılmış Geri Dönüşüm</h3>
                <p className="text-sm text-emerald-100">Yerel geri dönüştürücülerle bağlant kur</p>
              </div>
            </div>
            <div className="flex items-center gap-4 bg-white/10 backdrop-blur-sm rounded-xl p-4">
              <div className="w-12 h-12 bg-white/20 rounded-xl flex items-center justify-center text-2xl">
                🤝
              </div>
              <div>
                <h3 className="font-semibold">Kaynakları Paylaş</h3>
                <p className="text-sm text-emerald-100">Eşyalara ikinci bir hayat ver</p>
              </div>
            </div>
            <div className="flex items-center gap-4 bg-white/10 backdrop-blur-sm rounded-xl p-4">
              <div className="w-12 h-12 bg-white/20 rounded-xl flex items-center justify-center text-2xl">
                🌍
              </div>
              <div>
                <h3 className="font-semibold">Gezegeni Kurtar</h3>
                <p className="text-sm text-emerald-100">Çevresel etkini takip et</p>
              </div>
            </div>
          </div>
        </div>

        {/* Wave decoration */}
        <div className="absolute bottom-0 left-0 right-0">
          <svg viewBox="0 0 1440 120" fill="none" xmlns="http://www.w3.org/2000/svg">
            <path d="M0 120L60 105C120 90 240 60 360 45C480 30 600 30 720 37.5C840 45 960 60 1080 67.5C1200 75 1320 75 1380 75L1440 75V120H1380C1320 120 1200 120 1080 120C960 120 840 120 720 120C600 120 480 120 360 120C240 120 120 120 60 120H0Z" fill="white" fillOpacity="0.1"/>
          </svg>
        </div>
      </div>

      {/* Right Side - Form */}
      <div className="flex-1 flex items-center justify-center p-6 lg:p-12">
        <div className="w-full max-w-md">
          {/* Mobile Logo */}
          <div className="lg:hidden flex items-center justify-center gap-2 mb-8">
            <div className="w-12 h-12 bg-eco-gradient rounded-xl flex items-center justify-center">
              <span className="text-2xl">🌿</span>
            </div>
            <span className="text-2xl font-bold text-emerald-700">RecycleShare</span>
          </div>

          {/* Form Card */}
          <div className="eco-card p-8">
            {/* Header */}
            <div className="text-center mb-8">
              <h2 className="text-2xl font-bold text-gray-800">{title}</h2>
              {subtitle && (
                <p className="text-gray-500 mt-2">{subtitle}</p>
              )}
            </div>

            {/* Form Content */}
            {children}
          </div>

          {/* Footer */}
          <p className="text-center text-sm text-gray-500 mt-6">
            Devam ederek{' '}
            <Link to="/terms" className="text-emerald-600 hover:underline">Hizmet Şartlarımızı</Link>
            {' '}ve{' '}
            <Link to="/privacy" className="text-emerald-600 hover:underline">Gizlilik Politikasını</Link>
            {' '}kabul etmiş sayılırsınız.
          </p>
        </div>
      </div>
    </div>
  )
}

export default AuthLayout
