import axios from 'axios'

const API_URL = import.meta.env.VITE_API_URL || 'http://localhost:5000/api'

// Create axios instance
const api = axios.create({
  baseURL: API_URL,
  headers: {
    'Content-Type': 'application/json'
  },
  timeout: 30000 // 30 seconds timeout for Render cold start
})

// Request interceptor - add auth token
api.interceptors.request.use(
  (config) => {
    const token = localStorage.getItem('token')
    if (token) {
      config.headers.Authorization = `Bearer ${token}`
    }
    return config
  },
  (error) => {
    return Promise.reject(error)
  }
)

// Response interceptor - handle errors
api.interceptors.response.use(
  (response) => response,
  (error) => {
    // Handle timeout
    if (error.code === 'ECONNABORTED') {
      error.message = 'Request timed out. Server might be starting up, please try again.'
    }

    // Handle network error
    if (!error.response) {
      error.message = 'Network error. Please check your connection.'
    }

    if (error.response?.status === 401) {
      // Token expired or invalid
      localStorage.removeItem('token')
      localStorage.removeItem('user')
      window.location.href = '/login'
    }
    return Promise.reject(error)
  }
)

// Auth API calls
export const authAPI = {
  // Standard registration
  register: async (data) => {
    const response = await api.post('/auth/register', data)
    return response.data
  },

  // Standard login
  login: async (data) => {
    const response = await api.post('/auth/login', data)
    return response.data
  },

  // Verify OTP
  verifyOTP: async (data) => {
    const response = await api.post('/auth/verify-otp', data)
    return response.data
  },

  // Resend OTP
  resendOTP: async (email) => {
    const response = await api.post('/auth/resend-otp', { email })
    return response.data
  },

  // Google auth initial
  googleAuth: async (credential) => {
    const response = await api.post('/auth/google', { credential })
    return response.data
  },

  // Google auth complete with phone
  googleAuthComplete: async (data) => {
    const response = await api.post('/auth/google/complete', data)
    return response.data
  },

  // Get current user
  getCurrentUser: async () => {
    const response = await api.get('/auth/me')
    return response.data
  }
}

// Admin API calls
export const adminAPI = {
  // Dashboard
  getDashboard: async () => {
    const response = await api.get('/admin/dashboard')
    return response.data
  },

  // User Management
  getAllUsers: async (params = {}) => {
    const response = await api.get('/admin/users', { params })
    return response.data
  },

  updateUserRole: async (userId, role) => {
    const response = await api.put(`/admin/users/${userId}/role`, { role })
    return response.data
  },

  updateUserStatus: async (userId, isActive) => {
    const response = await api.put(`/admin/users/${userId}/status`, { is_active: isActive })
    return response.data
  },

  deleteUser: async (userId) => {
    const response = await api.delete(`/admin/users/${userId}`)
    return response.data
  },

  // Waste Types
  getWasteTypes: async () => {
    const response = await api.get('/admin/waste-types')
    return response.data
  },

  // Trigger Logs
  getTriggerLogs: async (limit = 50) => {
    const response = await api.get('/admin/trigger-logs', { params: { limit } })
    return response.data
  },

  // Database Explorer
  getTableList: async () => {
    const response = await api.get('/admin/database/tables')
    return response.data
  },

  getTableSchema: async (tableName) => {
    const response = await api.get(`/admin/database/tables/${tableName}/schema`)
    return response.data
  },

  getTableData: async (tableName, page = 1, limit = 20) => {
    const response = await api.get(`/admin/database/tables/${tableName}/data`, { params: { page, limit } })
    return response.data
  },

  getDatabaseSchema: async () => {
    const response = await api.get('/admin/database/schema')
    return response.data
  },

  // Ödev Gereksinimleri - SQL Sorguları
  getActiveContributors: async () => {
    const response = await api.get('/admin/active-contributors')
    return response.data
  },

  getTopContributors: async (minWaste = 1) => {
    const response = await api.get('/admin/top-contributors', { params: { minWaste } })
    return response.data
  }
}

// Waste API calls
export const wasteAPI = {
  getImpactStats: async () => {
    const response = await api.get('/waste/stats')
    return response.data
  },

  // fn_get_waste_by_city fonksiyonunu çağırır
  searchByCity: async (city) => {
    const response = await api.get('/waste/search', { params: { city } })
    return response.data
  }
}

// Report API calls (SQL VIEW ve FUNCTION entegrasyonu)
export const reportAPI = {
  // v_user_statistics VIEW'ını çağırır
  getUserStatistics: async () => {
    const response = await api.get('/reports/user-statistics')
    return response.data
  },

  // v_monthly_recycling_report VIEW'ını çağırır
  getMonthlyOverview: async (year) => {
    const response = await api.get('/reports/monthly-overview', { params: { year } })
    return response.data
  },

  // fn_get_user_monthly_report fonksiyonunu çağırır (CURSOR & RECORD)
  getUserMonthlyReport: async (userId, year, month) => {
    const response = await api.get(`/reports/user/${userId}/monthly`, { params: { year, month } })
    return response.data
  },

  // fn_calculate_user_total_score fonksiyonunu çağırır
  getUserTotalScore: async (userId) => {
    const response = await api.get(`/reports/user/${userId}/score`)
    return response.data
  },

  // Top contributors (HAVING + AGGREGATE)
  getTopContributors: async (minWasteCount = 1) => {
    const response = await api.get('/reports/top-contributors', { params: { minWasteCount } })
    return response.data
  }
}

export default api

