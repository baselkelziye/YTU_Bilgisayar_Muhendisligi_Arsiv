import { useState, useEffect } from 'react'
import { useNavigate } from 'react-router-dom'
import { useAuth } from '../context/AuthContext'
import { adminAPI } from '../services/api'
import toast from 'react-hot-toast'
import { FiLogOut, FiUsers, FiDatabase, FiActivity, FiTrash2, FiEdit2, FiShield, FiRefreshCw } from 'react-icons/fi'

const AdminDashboard = () => {
    const { user, logout } = useAuth()
    const navigate = useNavigate()

    const [activeTab, setActiveTab] = useState('dashboard')
    const [loading, setLoading] = useState(true)
    const [dashboardData, setDashboardData] = useState(null)
    const [users, setUsers] = useState([])
    const [triggerLogs, setTriggerLogs] = useState([])
    const [sqlData, setSqlData] = useState(null)
    const [minWaste, setMinWaste] = useState(1)

    useEffect(() => {
        if (activeTab === 'dashboard') {
            loadDashboard()
        } else if (activeTab === 'users') {
            loadUsers()
        } else if (activeTab === 'triggers') {
            loadTriggerLogs()
        } else if (activeTab === 'sql') {
            loadSqlData()
        }
    }, [activeTab])

    const loadDashboard = async () => {
        setLoading(true)
        try {
            const response = await adminAPI.getDashboard()
            if (response.success) {
                setDashboardData(response.data)
            }
        } catch (error) {
            toast.error('Dashboard verileri yüklenemedi')
        } finally {
            setLoading(false)
        }
    }

    const loadUsers = async () => {
        setLoading(true)
        try {
            const response = await adminAPI.getAllUsers()
            if (response.success) {
                setUsers(response.data)
            }
        } catch (error) {
            toast.error('Kullanıcılar yüklenemedi')
        } finally {
            setLoading(false)
        }
    }

    const loadTriggerLogs = async () => {
        setLoading(true)
        try {
            const response = await adminAPI.getTriggerLogs()
            if (response.success) {
                setTriggerLogs(response.data)
            }
        } catch (error) {
            toast.error('Trigger logları yüklenemedi')
        } finally {
            setLoading(false)
        }
    }

    const loadSqlData = async () => {
        setLoading(true)
        try {
            const [contributors, topContrib] = await Promise.all([
                adminAPI.getActiveContributors(),
                adminAPI.getTopContributors(minWaste)
            ])
            if (contributors.success && topContrib.success) {
                setSqlData({ contributors: contributors.data, topContributors: topContrib })
            }
        } catch (error) {
            toast.error('SQL verileri yüklenemedi')
        } finally {
            setLoading(false)
        }
    }

    const handleRoleChange = async (userId, newRole) => {
        try {
            const response = await adminAPI.updateUserRole(userId, newRole)
            if (response.success) {
                toast.success(response.message)
                loadUsers()
            }
        } catch (error) {
            toast.error('Rol güncellenemedi')
        }
    }

    const handleDeleteUser = async (userId) => {
        if (!confirm('Bu kullanıcıyı silmek istediğinize emin misiniz?')) return
        try {
            const response = await adminAPI.deleteUser(userId)
            if (response.success) {
                toast.success(response.message)
                loadUsers()
            }
        } catch (error) {
            toast.error(error.response?.data?.message || 'Kullanıcı silinemedi')
        }
    }

    const handleLogout = () => {
        logout()
        toast.success('Çıkış yapıldı')
        navigate('/login')
    }

    const tabs = [
        { id: 'dashboard', label: '📊 Dashboard', icon: FiActivity },
        { id: 'users', label: '👥 Kullanıcılar', icon: FiUsers },
        { id: 'database', label: '🗄️ Veritabanı', icon: FiDatabase },
        { id: 'triggers', label: '⚡ Trigger Logs', icon: FiRefreshCw },
        { id: 'sql', label: '🔍 SQL Sorguları', icon: FiDatabase }
    ]

    return (
        <div className="min-h-screen bg-gradient-to-br from-slate-900 via-slate-800 to-slate-900">
            {/* Top Navigation */}
            <nav className="bg-black/30 backdrop-blur-xl border-b border-white/10 sticky top-0 z-50">
                <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
                    <div className="flex justify-between items-center h-16">
                        <div className="flex items-center gap-3">
                            <div className="w-10 h-10 bg-gradient-to-br from-emerald-500 to-teal-500 rounded-xl flex items-center justify-center">
                                <FiShield className="w-5 h-5 text-white" />
                            </div>
                            <div>
                                <span className="text-xl font-bold text-white">Admin Panel</span>
                                <span className="text-xs text-emerald-300 block">RecycleShare</span>
                            </div>
                        </div>

                        <div className="flex items-center gap-4">
                            <div className="hidden sm:flex items-center gap-2 bg-white/10 px-3 py-1.5 rounded-full">
                                <div className="w-6 h-6 rounded-full bg-gradient-to-br from-emerald-500 to-teal-500 flex items-center justify-center text-white text-xs font-bold">
                                    {user?.firstName?.charAt(0)}
                                </div>
                                <span className="text-white text-sm">{user?.firstName}</span>
                                <span className="text-emerald-300 text-xs px-2 py-0.5 bg-emerald-500/30 rounded">Admin</span>
                            </div>
                            <button
                                onClick={() => navigate('/dashboard')}
                                className="flex items-center gap-2 px-3 py-1.5 bg-blue-500/20 hover:bg-blue-500/30 text-blue-300 rounded-lg transition-colors"
                            >
                                <span className="text-lg">👤</span>
                                <span className="hidden sm:inline">User Panel</span>
                            </button>
                            <button
                                onClick={handleLogout}
                                className="flex items-center gap-2 px-3 py-1.5 bg-red-500/20 hover:bg-red-500/30 text-red-300 rounded-lg transition-colors"
                            >
                                <FiLogOut className="w-4 h-4" />
                                <span className="hidden sm:inline">Çıkış</span>
                            </button>
                        </div>
                    </div>
                </div>
            </nav>

            <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-8">
                {/* Tabs */}
                <div className="flex flex-wrap gap-2 mb-8">
                    {tabs.map((tab) => (
                        <button
                            key={tab.id}
                            onClick={() => tab.id === 'database' ? navigate('/admin/database') : setActiveTab(tab.id)}
                            className={`flex items-center gap-2 px-4 py-2 rounded-xl font-medium transition-all ${activeTab === tab.id
                                ? 'bg-gradient-to-r from-emerald-500 to-teal-500 text-white shadow-lg shadow-emerald-500/25'
                                : 'bg-white/10 text-white/70 hover:bg-white/20 hover:text-white'
                                }`}
                        >
                            <tab.icon className="w-4 h-4" />
                            {tab.label}
                        </button>
                    ))}
                </div>

                {/* Content */}
                {loading ? (
                    <div className="flex items-center justify-center py-20">
                        <div className="animate-spin rounded-full h-12 w-12 border-4 border-emerald-500 border-t-transparent"></div>
                    </div>
                ) : (
                    <>
                        {/* Dashboard Tab */}
                        {activeTab === 'dashboard' && dashboardData && (
                            <div className="space-y-6">
                                {/* Stats Grid */}
                                <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-4">
                                    <StatCard
                                        title="Toplam Kullanıcı"
                                        value={dashboardData.users?.total_users || 0}
                                        subtitle={`${dashboardData.users?.admin_count || 0} admin, ${dashboardData.users?.resident_count || 0} resident`}
                                        gradient="from-blue-500 to-cyan-500"
                                        icon="👥"
                                    />
                                    <StatCard
                                        title="Toplam Atık"
                                        value={dashboardData.waste?.total_waste || 0}
                                        subtitle={`${dashboardData.waste?.waiting_count || 0} bekliyor`}
                                        gradient="from-green-500 to-emerald-500"
                                        icon="♻️"
                                    />
                                    <StatCard
                                        title="Rezervasyonlar"
                                        value={dashboardData.reservations?.total_reservations || 0}
                                        subtitle={`${dashboardData.reservations?.completed_count || 0} tamamlandı`}
                                        gradient="from-orange-500 to-amber-500"
                                        icon="📦"
                                    />
                                    <StatCard
                                        title="Toplam Miktar"
                                        value={`${parseFloat(dashboardData.waste?.total_amount || 0).toFixed(1)}`}
                                        subtitle="birim atık"
                                        gradient="from-teal-500 to-cyan-500"
                                        icon="📊"
                                    />
                                </div>

                                {/* Recent Triggers */}
                                <div className="bg-white/10 backdrop-blur-xl rounded-2xl p-6 border border-white/10">
                                    <h3 className="text-lg font-semibold text-white mb-4">⚡ Son Trigger Aktiviteleri</h3>
                                    {dashboardData.recentTriggerActivity?.length > 0 ? (
                                        <div className="space-y-3">
                                            {dashboardData.recentTriggerActivity.map((log, idx) => (
                                                <div key={idx} className="flex items-start gap-3 p-3 bg-white/5 rounded-xl">
                                                    <div className="w-2 h-2 mt-2 rounded-full bg-green-400 animate-pulse"></div>
                                                    <div>
                                                        <p className="text-white/90 text-sm">{log.message}</p>
                                                        <p className="text-white/50 text-xs mt-1">
                                                            {log.trigger_name} • {new Date(log.created_at).toLocaleString('tr-TR')}
                                                        </p>
                                                    </div>
                                                </div>
                                            ))}
                                        </div>
                                    ) : (
                                        <p className="text-white/50 text-sm">Henüz trigger aktivitesi yok</p>
                                    )}
                                </div>
                            </div>
                        )}

                        {/* Users Tab */}
                        {activeTab === 'users' && (
                            <div className="bg-white/10 backdrop-blur-xl rounded-2xl border border-white/10 overflow-hidden">
                                <div className="p-4 border-b border-white/10">
                                    <h3 className="text-lg font-semibold text-white">👥 Kullanıcı Yönetimi ({users.length})</h3>
                                </div>
                                <div className="overflow-x-auto">
                                    <table className="w-full">
                                        <thead>
                                            <tr className="bg-white/5">
                                                <th className="px-4 py-3 text-left text-xs font-medium text-white/70 uppercase">ID</th>
                                                <th className="px-4 py-3 text-left text-xs font-medium text-white/70 uppercase">Ad Soyad</th>
                                                <th className="px-4 py-3 text-left text-xs font-medium text-white/70 uppercase">Email</th>
                                                <th className="px-4 py-3 text-left text-xs font-medium text-white/70 uppercase">Rol</th>
                                                <th className="px-4 py-3 text-left text-xs font-medium text-white/70 uppercase">Şehir</th>
                                                <th className="px-4 py-3 text-left text-xs font-medium text-white/70 uppercase">İşlemler</th>
                                            </tr>
                                        </thead>
                                        <tbody className="divide-y divide-white/5">
                                            {users.map((u) => (
                                                <tr key={u.user_id} className="hover:bg-white/5">
                                                    <td className="px-4 py-3 text-sm text-white/80">{u.user_id}</td>
                                                    <td className="px-4 py-3 text-sm text-white">{u.first_name} {u.last_name}</td>
                                                    <td className="px-4 py-3 text-sm text-white/70">{u.email}</td>
                                                    <td className="px-4 py-3">
                                                        <select
                                                            value={u.role}
                                                            onChange={(e) => handleRoleChange(u.user_id, e.target.value)}
                                                            className="bg-white/10 text-white text-sm rounded-lg px-2 py-1 border border-white/20"
                                                        >
                                                            <option value="resident" className="bg-slate-800">Resident</option>
                                                            <option value="admin" className="bg-slate-800">Admin</option>
                                                        </select>
                                                    </td>
                                                    <td className="px-4 py-3 text-sm text-white/70">{u.city || '-'}</td>
                                                    <td className="px-4 py-3">
                                                        <button
                                                            onClick={() => handleDeleteUser(u.user_id)}
                                                            disabled={u.user_id === user?.userId}
                                                            className="p-2 text-red-400 hover:bg-red-500/20 rounded-lg disabled:opacity-30 disabled:cursor-not-allowed"
                                                        >
                                                            <FiTrash2 className="w-4 h-4" />
                                                        </button>
                                                    </td>
                                                </tr>
                                            ))}
                                        </tbody>
                                    </table>
                                </div>
                            </div>
                        )}

                        {/* Trigger Logs Tab */}
                        {activeTab === 'triggers' && (
                            <div className="bg-white/10 backdrop-blur-xl rounded-2xl border border-white/10 overflow-hidden">
                                <div className="p-4 border-b border-white/10 flex justify-between items-center">
                                    <h3 className="text-lg font-semibold text-white">⚡ Trigger Logları ({triggerLogs.length})</h3>
                                    <button onClick={loadTriggerLogs} className="p-2 text-white/70 hover:text-white hover:bg-white/10 rounded-lg">
                                        <FiRefreshCw className="w-4 h-4" />
                                    </button>
                                </div>
                                <div className="overflow-x-auto max-h-[600px] overflow-y-auto">
                                    <table className="w-full">
                                        <thead className="sticky top-0 bg-slate-800">
                                            <tr>
                                                <th className="px-4 py-3 text-left text-xs font-medium text-white/70 uppercase">Trigger</th>
                                                <th className="px-4 py-3 text-left text-xs font-medium text-white/70 uppercase">Tablo</th>
                                                <th className="px-4 py-3 text-left text-xs font-medium text-white/70 uppercase">İşlem</th>
                                                <th className="px-4 py-3 text-left text-xs font-medium text-white/70 uppercase">Mesaj</th>
                                                <th className="px-4 py-3 text-left text-xs font-medium text-white/70 uppercase">Tarih</th>
                                            </tr>
                                        </thead>
                                        <tbody className="divide-y divide-white/5">
                                            {triggerLogs.map((log) => (
                                                <tr key={log.log_id} className="hover:bg-white/5">
                                                    <td className="px-4 py-3 text-sm text-emerald-300 font-mono">{log.trigger_name}</td>
                                                    <td className="px-4 py-3 text-sm text-white/70">{log.table_name}</td>
                                                    <td className="px-4 py-3">
                                                        <span className={`px-2 py-1 rounded text-xs font-medium ${log.action === 'INSERT' ? 'bg-green-500/20 text-green-300' :
                                                            log.action === 'UPDATE' ? 'bg-yellow-500/20 text-yellow-300' :
                                                                'bg-red-500/20 text-red-300'
                                                            }`}>
                                                            {log.action}
                                                        </span>
                                                    </td>
                                                    <td className="px-4 py-3 text-sm text-white/80 max-w-md truncate">{log.message}</td>
                                                    <td className="px-4 py-3 text-sm text-white/50">
                                                        {new Date(log.created_at).toLocaleString('tr-TR')}
                                                    </td>
                                                </tr>
                                            ))}
                                        </tbody>
                                    </table>
                                </div>
                            </div>
                        )}

                        {/* SQL Queries Tab */}
                        {activeTab === 'sql' && sqlData && (
                            <div className="space-y-6">
                                {/* INTERSECT Section */}
                                <div className="bg-white/10 backdrop-blur-xl rounded-2xl border border-white/10 overflow-hidden">
                                    <div className="p-4 border-b border-white/10 bg-yellow-500/10">
                                        <h3 className="text-lg font-semibold text-yellow-300">🔀 INTERSECT Sorgusu</h3>
                                        <p className="text-white/60 text-sm mt-1">{sqlData.contributors?.intersect?.description}</p>
                                        <code className="text-xs text-yellow-200/70 block mt-2 bg-black/30 p-2 rounded">SELECT ... INTERSECT SELECT ...</code>
                                    </div>
                                    <div className="p-4">
                                        {sqlData.contributors?.intersect?.users?.length > 0 ? (
                                            <div className="grid gap-2">
                                                {sqlData.contributors.intersect.users.map((u, i) => (
                                                    <div key={i} className="flex items-center gap-3 p-3 bg-white/5 rounded-lg">
                                                        <span className="text-white">{u.first_name} {u.last_name}</span>
                                                        <span className="text-white/50 text-sm">{u.email}</span>
                                                        <span className="ml-auto px-2 py-1 bg-yellow-500/20 text-yellow-300 rounded text-xs">{u.contributor_type}</span>
                                                    </div>
                                                ))}
                                            </div>
                                        ) : (
                                            <p className="text-white/50">Hem paylaşan hem toplayan kullanıcı bulunamadı</p>
                                        )}
                                    </div>
                                </div>

                                {/* UNION Section */}
                                <div className="bg-white/10 backdrop-blur-xl rounded-2xl border border-white/10 overflow-hidden">
                                    <div className="p-4 border-b border-white/10 bg-blue-500/10">
                                        <h3 className="text-lg font-semibold text-blue-300">🔗 UNION Sorgusu</h3>
                                        <p className="text-white/60 text-sm mt-1">{sqlData.contributors?.union?.description}</p>
                                        <code className="text-xs text-blue-200/70 block mt-2 bg-black/30 p-2 rounded">SELECT ... UNION SELECT ...</code>
                                    </div>
                                    <div className="p-4 max-h-60 overflow-y-auto">
                                        <div className="grid gap-1">
                                            {sqlData.contributors?.union?.users?.map((u, i) => (
                                                <div key={i} className="flex items-center gap-3 p-2 hover:bg-white/5 rounded">
                                                    <span className="text-white text-sm">{u.first_name} {u.last_name}</span>
                                                    <span className={`ml-auto px-2 py-0.5 rounded text-xs ${u.activity_type === 'Paylaşımcı' ? 'bg-green-500/20 text-green-300' : 'bg-purple-500/20 text-purple-300'}`}>{u.activity_type}</span>
                                                </div>
                                            ))}
                                        </div>
                                    </div>
                                </div>

                                {/* EXCEPT Section */}
                                <div className="bg-white/10 backdrop-blur-xl rounded-2xl border border-white/10 overflow-hidden">
                                    <div className="p-4 border-b border-white/10 bg-red-500/10">
                                        <h3 className="text-lg font-semibold text-red-300">➖ EXCEPT Sorgusu</h3>
                                        <p className="text-white/60 text-sm mt-1">{sqlData.contributors?.except?.description}</p>
                                        <code className="text-xs text-red-200/70 block mt-2 bg-black/30 p-2 rounded">SELECT ... EXCEPT SELECT ...</code>
                                    </div>
                                    <div className="p-4 text-white/70 text-sm">
                                        Hiç rezervasyon yapmamış kullanıcı sayısı: <span className="text-red-300 font-bold">{sqlData.contributors?.except?.count || 0}</span>
                                    </div>
                                </div>

                                {/* HAVING Section */}
                                <div className="bg-white/10 backdrop-blur-xl rounded-2xl border border-white/10 overflow-hidden">
                                    <div className="p-4 border-b border-white/10 bg-emerald-500/10">
                                        <h3 className="text-lg font-semibold text-emerald-300">📊 Aggregate + HAVING Sorgusu</h3>
                                        <p className="text-white/60 text-sm mt-1">{sqlData.topContributors?.filter?.description}</p>
                                        <div className="flex items-center gap-2 mt-2">
                                            <span className="text-white/70 text-sm">Min atık sayısı:</span>
                                            <input
                                                type="number"
                                                value={minWaste}
                                                onChange={(e) => setMinWaste(parseInt(e.target.value) || 1)}
                                                className="w-16 px-2 py-1 bg-white/10 border border-white/20 rounded text-white text-sm"
                                                min="1"
                                            />
                                            <button onClick={loadSqlData} className="px-3 py-1 bg-emerald-500/30 text-emerald-300 rounded text-sm hover:bg-emerald-500/40">Filtrele</button>
                                        </div>
                                        <code className="text-xs text-emerald-200/70 block mt-2 bg-black/30 p-2 rounded">HAVING COUNT(w.waste_id) &gt;= {minWaste}</code>
                                    </div>
                                    <div className="overflow-x-auto">
                                        <table className="w-full">
                                            <thead>
                                                <tr className="bg-white/5">
                                                    <th className="px-4 py-3 text-left text-xs font-medium text-white/70">Kullanıcı</th>
                                                    <th className="px-4 py-3 text-left text-xs font-medium text-white/70">Şehir</th>
                                                    <th className="px-4 py-3 text-left text-xs font-medium text-white/70">Atık Sayısı</th>
                                                    <th className="px-4 py-3 text-left text-xs font-medium text-white/70">Toplam Miktar</th>
                                                    <th className="px-4 py-3 text-left text-xs font-medium text-white/70">Toplanan</th>
                                                    <th className="px-4 py-3 text-left text-xs font-medium text-white/70">Puan</th>
                                                </tr>
                                            </thead>
                                            <tbody className="divide-y divide-white/5">
                                                {sqlData.topContributors?.data?.map((u, i) => (
                                                    <tr key={i} className="hover:bg-white/5">
                                                        <td className="px-4 py-3 text-sm text-white">{u.full_name}</td>
                                                        <td className="px-4 py-3 text-sm text-white/70">{u.city || '-'}</td>
                                                        <td className="px-4 py-3 text-sm text-emerald-300 font-bold">{u.waste_count}</td>
                                                        <td className="px-4 py-3 text-sm text-white/70">{parseFloat(u.total_amount).toFixed(1)}</td>
                                                        <td className="px-4 py-3 text-sm text-white/70">{u.collected_count}</td>
                                                        <td className="px-4 py-3 text-sm text-yellow-300">{u.total_score}</td>
                                                    </tr>
                                                ))}
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                            </div>
                        )}
                    </>
                )}
            </div>
        </div>
    )
}

// Stat Card Component
const StatCard = ({ title, value, subtitle, gradient, icon }) => (
    <div className={`bg-gradient-to-br ${gradient} rounded-2xl p-6 shadow-xl`}>
        <div className="flex justify-between items-start">
            <div>
                <p className="text-white/80 text-sm font-medium">{title}</p>
                <p className="text-3xl font-bold text-white mt-2">{value}</p>
                <p className="text-white/70 text-xs mt-1">{subtitle}</p>
            </div>
            <span className="text-3xl">{icon}</span>
        </div>
    </div>
)

export default AdminDashboard
