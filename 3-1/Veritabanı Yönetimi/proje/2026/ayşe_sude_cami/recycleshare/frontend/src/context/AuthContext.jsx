import { createContext, useContext, useState, useEffect } from 'react'
import { authAPI } from '../services/api'

const AuthContext = createContext(null)

export const useAuth = () => {
  const context = useContext(AuthContext)
  if (!context) {
    throw new Error('useAuth must be used within an AuthProvider')
  }
  return context
}

export const AuthProvider = ({ children }) => {
  const [user, setUser] = useState(null)
  const [loading, setLoading] = useState(true)

  // Check for existing session on mount
  useEffect(() => {
    const initAuth = async () => {
      const token = localStorage.getItem('token')
      const savedUser = localStorage.getItem('user')

      if (token && savedUser) {
        try {
          // Verify token is still valid
          const response = await authAPI.getCurrentUser()
          setUser(response.data.user)
        } catch (error) {
          // Token invalid - clear storage
          localStorage.removeItem('token')
          localStorage.removeItem('user')
          setUser(null)
        }
      }
      setLoading(false)
    }

    initAuth()
  }, [])

  // Login function
  const login = async (email, password) => {
    const response = await authAPI.login({ email, password })

    if (response.success && response.data.token) {
      localStorage.setItem('token', response.data.token)

      // Refresh full user from /auth/me to ensure address and latest fields
      try {
        const me = await authAPI.getCurrentUser()
        if (me.success && me.data?.user) {
          localStorage.setItem('user', JSON.stringify(me.data.user))
          setUser(me.data.user)
        } else {
          localStorage.setItem('user', JSON.stringify(response.data.user))
          setUser(response.data.user)
        }
      } catch (e) {
        localStorage.setItem('user', JSON.stringify(response.data.user))
        setUser(response.data.user)
      }
    }

    return response
  }

  // Register function
  const register = async (userData) => {
    const response = await authAPI.register(userData)
    return response
  }

  // Verify OTP function
  const verifyOTP = async (email, code) => {
    const response = await authAPI.verifyOTP({ email, code })

    if (response.success && response.data.token) {
      localStorage.setItem('token', response.data.token)
      try {
        const me = await authAPI.getCurrentUser()
        if (me.success && me.data?.user) {
          localStorage.setItem('user', JSON.stringify(me.data.user))
          setUser(me.data.user)
        } else {
          localStorage.setItem('user', JSON.stringify(response.data.user))
          setUser(response.data.user)
        }
      } catch (e) {
        localStorage.setItem('user', JSON.stringify(response.data.user))
        setUser(response.data.user)
      }
    }

    return response
  }

  // Resend OTP function
  const resendOTP = async (email) => {
    const response = await authAPI.resendOTP(email)
    return response
  }

  // Google auth function
  const googleAuth = async (credential) => {
    const response = await authAPI.googleAuth(credential)

    if (response.success && response.data.token) {
      localStorage.setItem('token', response.data.token)
      try {
        const me = await authAPI.getCurrentUser()
        if (me.success && me.data?.user) {
          localStorage.setItem('user', JSON.stringify(me.data.user))
          setUser(me.data.user)
        } else {
          localStorage.setItem('user', JSON.stringify(response.data.user))
          setUser(response.data.user)
        }
      } catch (e) {
        localStorage.setItem('user', JSON.stringify(response.data.user))
        setUser(response.data.user)
      }
    }

    return response
  }

  // Complete Google auth with phone
  const googleAuthComplete = async (data) => {
    const response = await authAPI.googleAuthComplete(data)

    if (response.success && response.data.token) {
      localStorage.setItem('token', response.data.token)
      try {
        const me = await authAPI.getCurrentUser()
        if (me.success && me.data?.user) {
          localStorage.setItem('user', JSON.stringify(me.data.user))
          setUser(me.data.user)
        } else {
          localStorage.setItem('user', JSON.stringify(response.data.user))
          setUser(response.data.user)
        }
      } catch (e) {
        localStorage.setItem('user', JSON.stringify(response.data.user))
        setUser(response.data.user)
      }
    }

    return response
  }

  // Logout function
  const logout = () => {
    localStorage.removeItem('token')
    localStorage.removeItem('user')
    setUser(null)
  }

  const value = {
    user,
    loading,
    login,
    register,
    verifyOTP,
    resendOTP,
    googleAuth,
    googleAuthComplete,
    logout
  }

  return (
    <AuthContext.Provider value={value}>
      {children}
    </AuthContext.Provider>
  )
}
