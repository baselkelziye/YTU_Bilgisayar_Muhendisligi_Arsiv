import { useState, useEffect } from 'react'
import { useNavigate } from 'react-router-dom'
import api, { reportAPI } from '../services/api'
import toast from 'react-hot-toast'
import { useAuth } from '../context/AuthContext'
import { FiArrowLeft, FiMapPin, FiBox, FiUsers, FiX, FiCalendar, FiAlignLeft, FiUser, FiPhone, FiClock, FiDatabase, FiAward } from 'react-icons/fi'

const Community = () => {
  const navigate = useNavigate()
  const { user } = useAuth()

  const [leaderboard, setLeaderboard] = useState([])
  const [toCollect, setToCollect] = useState([])
  const [myResv, setMyResv] = useState([])
  const [loading, setLoading] = useState(true)
  const [activeTab, setActiveTab] = useState('collector')

  const [selectedItem, setSelectedItem] = useState(null)
  const [editAmount, setEditAmount] = useState('')

  // v_user_statistics VIEW state
  const [userStats, setUserStats] = useState([])
  const [statsLoading, setStatsLoading] = useState(false)
  const [showStatsModal, setShowStatsModal] = useState(false)

  const getWasteTypeLabel = (type) => {
    if (!type) return 'Atık'
    const map = {

      'Cables & Chargers': 'Kablo & Şarj Cihazları',
      'Recyclable Textiles': 'Geri Dönüştürülebilir Tekstil',
      'Glass Bottles & Jars': 'Cam Şişe & Kaplar',
      'Cardboard Boxes & Packaging': 'Karton Kutular & Ambalajlar',
      'Old Books & Newspapers': 'Eski Kitaplar & Gazeteler',
      'PET Bottles': 'PET şişeler',
      'Hard Plastic Packaging': 'Sert Plastik Ambalajlar',
      'Metal Beverage Cans': 'Metal İçecek Kutuları',
      'Kitchen Metal Waste': 'Metal Mutfak Atığı',
      'Small Household Appliances': 'Küçük Ev Aletleri',

    }
    return map[type] || type
  }

  // Helper function to get Turkish status labels
  const getStatusLabel = (s) => {
    if (!s) return '-'
    const map = {
      'waiting': 'Bekliyor',
      'reserved': 'Rezerve Edildi',
      'collected': 'Toplandı',
      'cancelled': 'İptal Edildi'
    }
    return map[s] || String(s).charAt(0).toUpperCase() + String(s).slice(1)
  }

  useEffect(() => {
    fetchInitialData()
  }, [])

  const fetchInitialData = async () => {
    setLoading(true)
    try {
      const [lbRes, collRes, ownRes, allWasteRes] = await Promise.all([
        api.get('/reports/top-contributors'),
        api.get('/reservations/my/collector'),
        api.get('/reservations/my/owner'),
        api.get('/waste')
      ])

      const allWaste = allWasteRes.data?.data || []

      const enhance = (resList, type) => resList.map(res => {
        const wasteInfo = allWaste.find(w => String(w.waste_id) === String(res.waste_id)) || {}

        return {
          ...res,
          display_name: res.type_name || wasteInfo.type_name || 'Geri Dönüştürebilir Atık',
          display_desc: res.waste_description || wasteInfo.description || 'Açıklama yok',
          display_amount: res.amount || wasteInfo.amount || '0',
          display_unit: res.official_unit || wasteInfo.official_unit || 'kg',

          city: res.city || wasteInfo.city || 'N/A',
          district: res.district || wasteInfo.district || '',
          neighborhood: res.neighborhood || wasteInfo.neighborhood || '',
          street: res.street || wasteInfo.street || '',
          address_details: res.address_details || wasteInfo.address_details || '',

          contact_label: type === 'collector' ? "Atığı Paylaşan" : "Toplayıcı Bilgileri",
          contact_name: type === 'collector' ? (res.owner_name || 'Anonim Kullanıcı') : (res.collector_name || 'Toplayıcı'),
          contact_phone: type === 'collector' ? (res.owner_phone || 'N/A') : (res.collector_phone || 'N/A')
        }
      })

      setLeaderboard(lbRes.data?.data || [])
      setToCollect(enhance(collRes.data?.data || [], 'collector'))
      setMyResv(enhance(ownRes.data?.data || [], 'owner'))
    } catch (err) {
      toast.error('Topluluk verileri senkronize edilemedi')
    } finally {
      setLoading(false)
    }
  }

  // v_user_statistics VIEW'ını çağır
  const fetchUserStatistics = async () => {
    setStatsLoading(true)
    try {
      const response = await reportAPI.getUserStatistics()
      if (response.success) {
        setUserStats(response.data || [])
        setShowStatsModal(true)
      }
    } catch (err) {
      console.error('Kullanıcı istatistikleri hatası:', err)
      toast.error('İstatistikler yüklenemedi')
    } finally {
      setStatsLoading(false)
    }
  }

  const handleCollectAction = async () => {
    if (!editAmount || parseFloat(editAmount) <= 0) {
      return toast.error("Uygun bir miktar girin");
    }

    try {
      // Call new dedicated endpoint for completing collection
      await api.post(`/reservations/${selectedItem.reservation_id}/complete-collection`, {
        actual_amount: parseFloat(editAmount)
      });

      toast.success('Atık başarıyla toplandı! Puan verildi.');
      setSelectedItem(null);
      fetchInitialData();
    } catch (err) {
      console.error("Güncelleme Hatası:", err.response?.data || err.message);
      toast.error(err.response?.data?.message || 'Güncellenirken hata oluştu');
    }
  }

  return (
    <div className="min-h-screen bg-[#F8FAFC] p-4 lg:p-8 uppercase font-bold">
      <div className="max-w-7xl mx-auto">
        {/* Header */}
        <div className="flex items-center justify-between gap-4 mb-8">
          <div className="flex items-center gap-4">
            <button onClick={() => navigate('/dashboard')} className="btn btn-circle btn-ghost bg-white shadow-sm text-emerald-600 border-none">
              <FiArrowLeft size={20} />
            </button>
            <h1 className="text-2xl font-black tracking-tighter text-slate-800">Topluluk Merkezi</h1>
          </div>
          <button
            onClick={fetchUserStatistics}
            disabled={statsLoading}
            className="btn btn-sm bg-purple-500 hover:bg-purple-600 text-white border-none gap-2"
            title="v_user_statistics VIEW"
          >
            <FiDatabase size={16} />
            {statsLoading ? 'Yükleniyor...' : 'Tüm Kullanıcı İstatistikleri'}
          </button>
        </div>

        <div className="grid grid-cols-1 lg:grid-cols-12 gap-8">
          {/* Main List */}
          <div className="lg:col-span-8 bg-white rounded-[2rem] shadow-sm border border-slate-100 overflow-hidden min-h-[500px]">
            <div className="flex bg-slate-50/50 border-b p-2 gap-2">
              <button onClick={() => setActiveTab('collector')} className={`flex-1 py-4 text-xs rounded-xl transition-all ${activeTab === 'collector' ? 'bg-white text-emerald-600 shadow-sm' : 'text-slate-400'}`}>Toplanacak Atıklar</button>
              <button onClick={() => setActiveTab('owner')} className={`flex-1 py-4 text-xs rounded-xl transition-all ${activeTab === 'owner' ? 'bg-white text-emerald-600 shadow-sm' : 'text-slate-400'}`}>Benim Atıklarım</button>
            </div>

            <div className="p-6">
              {loading ? (
                <div className="flex justify-center py-20"><span className="loading loading-spinner text-emerald-500"></span></div>
              ) : (
                <div className="space-y-4">
                  {(activeTab === 'collector' ? toCollect : myResv).map(item => (
                    <div key={item.reservation_id} className="flex justify-between items-center p-6 border border-slate-100 rounded-3xl hover:border-emerald-200 transition-all bg-white">
                      <div className="flex gap-4 items-center">
                        <div className="w-12 h-12 rounded-2xl bg-emerald-50 text-emerald-600 flex items-center justify-center text-xl"><FiBox /></div>
                        <div>
                          <h4 className="text-slate-800 text-sm">{getWasteTypeLabel(item.display_name)}</h4>
                          <p className="text-xs text-slate-400 uppercase tracking-wide">{item.display_amount} {item.display_unit} • {getStatusLabel(item.status)}</p>
                        </div>
                      </div>
                      <button onClick={() => { setSelectedItem(item); setEditAmount(item.display_amount); }} className="btn btn-sm btn-ghost bg-slate-100 px-6 rounded-xl">Detayları Gör</button>
                    </div>
                  ))}
                  {(activeTab === 'collector' ? toCollect : myResv).length === 0 && <p className="text-center py-10 font-bold text-slate-300">No records found.</p>}
                </div>
              )}
            </div>
          </div>

          {/* Leaderboard */}
          <div className="lg:col-span-4">
            <div className="bg-white rounded-[2rem] shadow-sm border border-slate-100 p-6 sticky top-8">
              <h3 className="text-xs mb-4 flex items-center gap-2 text-emerald-600 uppercase"><FiUsers /> En Çok Katkıda Bulunanlar</h3>
              <div className="space-y-3">
                {leaderboard.slice(0, 5).map((u, i) => (
                  <div
                    key={i}
                    className={`p-4 rounded-2xl border transition-all hover:shadow-md ${i === 0 ? 'bg-gradient-to-r from-amber-50 to-yellow-50 border-amber-200' :
                      i === 1 ? 'bg-gradient-to-r from-slate-50 to-gray-50 border-slate-200' :
                        i === 2 ? 'bg-gradient-to-r from-orange-50 to-amber-50 border-orange-200' :
                          'bg-slate-50 border-slate-100'
                      }`}
                  >
                    <div className="flex items-center gap-3 mb-2">
                      <div className={`w-10 h-10 rounded-full flex items-center justify-center text-lg font-black ${i === 0 ? 'bg-amber-400 text-white' :
                        i === 1 ? 'bg-slate-400 text-white' :
                          i === 2 ? 'bg-orange-400 text-white' :
                            'bg-emerald-100 text-emerald-600'
                        }`}>
                        {i === 0 ? '🥇' : i === 1 ? '🥈' : i === 2 ? '🥉' : `#${i + 1}`}
                      </div>
                      <div className="flex-1">
                        <h4 className="font-bold text-slate-800 text-sm">{u.full_name}</h4>
                        <p className="text-xs text-slate-400">{u.city || 'Bilinmeyen'}</p>
                      </div>
                      <div className="text-right">
                        <span className="text-emerald-600 font-black text-lg">🌱 {u.total_score || 0}</span>
                        <p className="text-[10px] text-slate-400 uppercase">puan</p>
                      </div>
                    </div>
                    <div className="flex gap-4 text-[10px] text-slate-500 pl-13">
                      <span className="flex items-center gap-1">
                        <FiBox className="text-emerald-500" /> {u.waste_count} atık
                      </span>
                      <span className="flex items-center gap-1">
                        ♻️ {u.collected_count || 0} toplanan
                      </span>
                    </div>
                  </div>
                ))}
                {leaderboard.length === 0 && (
                  <p className="text-center py-6 text-slate-300 text-sm">Henüz veri yok</p>
                )}
              </div>
            </div>
          </div>
        </div>

        {/* DETAILS MODAL */}
        {selectedItem && (
          <div className="fixed inset-0 z-50 flex items-center justify-center bg-slate-900/40 backdrop-blur-sm p-4">
            <div className="bg-white rounded-[2.5rem] w-full max-w-md p-10 shadow-2xl relative animate-in fade-in zoom-in duration-150">
              <button onClick={() => setSelectedItem(null)} className="absolute top-8 right-8 text-slate-400 hover:text-slate-600 transition-colors"><FiX size={24} /></button>

              <div className="mb-6">
                <h3 className="text-3xl font-black text-slate-800 uppercase leading-none mb-2">{getWasteTypeLabel(selectedItem.display_name)}</h3>
                <p className="text-emerald-600 font-black text-xl">{selectedItem.display_amount} {selectedItem.display_unit}</p>
              </div>

              <div className="space-y-3 mb-8">
                <div className="p-4 bg-slate-50 rounded-2xl border border-slate-100 flex gap-4">
                  <FiAlignLeft className="text-slate-400 mt-1" />
                  <div className="text-sm text-slate-600">
                    <p className="font-black text-slate-400 uppercase text-[10px] tracking-widest mb-1">Atık Açıklaması</p>
                    <p className="font-medium italic">"{selectedItem.display_desc}"</p>
                  </div>
                </div>

                <div className="p-4 bg-blue-50 rounded-2xl border border-blue-100 flex gap-4">
                  <FiClock className="text-blue-500 mt-1" />
                  <div className="text-sm">
                    <p className="font-black text-blue-400 uppercase text-[10px] tracking-widest mb-1">Alım Zamanı</p>
                    <p className="text-blue-700 font-bold uppercase">
                      {new Date(selectedItem.pickup_datetime).toLocaleDateString('en-GB')} at {new Date(selectedItem.pickup_datetime).toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' })}
                    </p>
                  </div>
                </div>

                {/* ADDRESS: Only shows for Collector tab */}
                {activeTab === 'collector' && (
                  <div className="p-4 bg-slate-50 rounded-2xl border border-slate-100 flex gap-4">
                    <FiMapPin className="text-emerald-500 mt-1" />
                    <div className="text-sm">
                      <p className="font-black text-slate-400 uppercase text-[10px] tracking-widest mb-1">Alım Adresi</p>
                      <p className="text-slate-700 font-bold">{selectedItem.neighborhood}, {selectedItem.street}</p>
                      <p className="text-slate-500 text-xs font-bold uppercase">{selectedItem.district} / {selectedItem.city}</p>
                      {selectedItem.address_details && <p className="text-slate-400 text-[11px] mt-1 italic">{selectedItem.address_details}</p>}
                    </div>
                  </div>
                )}

                <div className="p-4 bg-orange-50 rounded-2xl border border-orange-100 flex gap-4">
                  <FiUser className="text-orange-500 mt-1" />
                  <div className="text-sm">
                    <p className="font-black text-orange-400 uppercase text-[10px] tracking-widest mb-1">{selectedItem.contact_label}</p>
                    <p className="text-orange-900 font-bold mb-1">{selectedItem.contact_name}</p>
                    <p className="text-orange-700 font-black text-lg flex items-center gap-2">
                      <FiPhone size={16} /> {selectedItem.contact_phone}
                    </p>
                  </div>
                </div>
              </div>

              {activeTab === 'collector' && selectedItem.status === 'waiting' ? (
                <div className="space-y-4">
                  <div className="bg-slate-100 p-4 rounded-2xl">
                    <label className="text-[10px] font-black text-slate-500 uppercase mb-1 block">Ölçülen Miktar</label>
                    <input type="number" className="w-full bg-transparent border-none text-xl font-black focus:ring-0 outline-none" value={editAmount} onChange={(e) => setEditAmount(e.target.value)} />
                  </div>
                  <button onClick={handleCollectAction} className="btn btn-primary w-full h-16 bg-emerald-600 border-none text-white rounded-2xl font-black text-lg shadow-lg shadow-emerald-200">Atığı Topla</button>
                </div>
              ) : (
                <button onClick={() => setSelectedItem(null)} className="btn btn-ghost w-full h-14 text-slate-400 font-bold border border-slate-100 rounded-2xl uppercase">Kapat</button>
              )}
            </div>
          </div>
        )}

        {/* USER STATISTICS MODAL (v_user_statistics VIEW) */}
        {showStatsModal && (
          <div className="fixed inset-0 z-50 flex items-center justify-center bg-slate-900/40 backdrop-blur-sm p-4">
            <div className="bg-white rounded-[2.5rem] w-full max-w-3xl p-8 shadow-2xl relative animate-in fade-in zoom-in duration-150 max-h-[80vh] overflow-hidden">
              <button onClick={() => setShowStatsModal(false)} className="absolute top-6 right-6 text-slate-400 hover:text-slate-600 transition-colors">
                <FiX size={24} />
              </button>

              <div className="mb-6">
                <h3 className="text-2xl font-black text-slate-800 uppercase leading-none mb-2 flex items-center gap-3">
                  <FiAward className="text-purple-500" />
                  Kullanıcı İstatistikleri
                  <span className="text-xs bg-purple-100 text-purple-600 px-2 py-1 rounded-full ml-2 normal-case font-bold">
                    VIEW
                  </span>
                </h3>
                <p className="text-xs text-slate-400">
                  📌 SQL: <code className="bg-slate-100 px-1 rounded">v_user_statistics</code> — {userStats.length} kullanıcı
                </p>
              </div>

              <div className="overflow-y-auto max-h-[55vh]">
                {userStats.length === 0 ? (
                  <div className="text-center py-12">
                    <div className="text-4xl mb-2">📊</div>
                    <p className="text-slate-400">Veri bulunamadı</p>
                  </div>
                ) : (
                  <table className="w-full text-sm">
                    <thead className="sticky top-0 bg-white">
                      <tr className="bg-purple-50 text-purple-700">
                        <th className="text-left p-3 rounded-l-lg">Kullanıcı</th>
                        <th className="text-left p-3">Şehir</th>
                        <th className="text-right p-3">Paylaşılan</th>
                        <th className="text-right p-3">Rezervasyon</th>
                        <th className="text-right p-3 rounded-r-lg">Puan</th>
                      </tr>
                    </thead>
                    <tbody>
                      {userStats.map((u, idx) => (
                        <tr key={idx} className="border-b border-slate-50 hover:bg-purple-50/50 transition-colors">
                          <td className="p-3 font-medium text-slate-800">{u.full_name}</td>
                          <td className="p-3 text-slate-600">{u.city || '-'}</td>
                          <td className="p-3 text-right text-slate-600">{u.total_waste_posted || 0}</td>
                          <td className="p-3 text-right text-slate-600">{u.total_reservations_made || 0}</td>
                          <td className="p-3 text-right font-bold text-emerald-600">{u.total_environmental_score || 0}</td>
                        </tr>
                      ))}
                    </tbody>
                  </table>
                )}
              </div>

              <div className="mt-6 flex justify-end">
                <button onClick={() => setShowStatsModal(false)} className="btn bg-slate-100 text-slate-600 border-none px-8">Kapat</button>
              </div>
            </div>
          </div>
        )}
      </div>
    </div>
  )
}

// Sayfa sonuna modal ekleniyor
const CommunityWithModal = () => {
  return <Community />
}
export default Community