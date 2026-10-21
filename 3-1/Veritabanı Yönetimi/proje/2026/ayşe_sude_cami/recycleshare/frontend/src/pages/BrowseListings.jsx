import { useState, useEffect } from 'react'
import { useNavigate } from 'react-router-dom'
import api, { wasteAPI } from '../services/api'
import toast from 'react-hot-toast'
import { useAuth } from '../context/AuthContext'
import { FiArrowLeft, FiSearch, FiDatabase } from 'react-icons/fi'

const BrowseListings = () => {
  const { user } = useAuth()
  const navigate = useNavigate()
  const [pageError, setPageError] = useState(null)

  const [wasteTypes, setWasteTypes] = useState([])
  const [filters, setFilters] = useState({ city: '', district: '', neighborhood: '', street: '', type_id: '' })
  const [pendingOnly, setPendingOnly] = useState(true)
  const [listings, setListings] = useState([])
  const [loading, setLoading] = useState(false)

  const [reserveModal, setReserveModal] = useState({ open: false, item: null, datetime: '' })
  const [reservations, setReservations] = useState([])
  const [editingReservation, setEditingReservation] = useState(null)

  // fn_get_waste_by_city FUNCTION state
  const [citySearchResults, setCitySearchResults] = useState(null)
  const [citySearchLoading, setCitySearchLoading] = useState(false)
  const [editReservationForm, setEditReservationForm] = useState({ pickup_datetime: '' })

  useEffect(() => {
    const loadData = async () => {
      try {
        await Promise.all([
          fetchWasteTypes(),
          fetchListings(),
          fetchMyReservations()
        ])
      } catch (error) {
        console.error('Sayfa verileri yüklenirken hata oluştu:', error)
        setPageError('Failed to load page. Please check your connection and try again.')
      }
    }
    loadData()
  }, [])

  const fetchWasteTypes = async () => {
    try {
      const res = await api.get('/waste/types')
      console.log('Atık türleri cevapı:', res.data)
      setWasteTypes(res.data?.data || res.data || [])
    } catch (err) {
      console.error('Atık türleri yüklenirken hata oluştu:', err)
      setWasteTypes([])
    }
  }

  const buildQuery = () => {
    const params = {}
    if (filters.city) params.city = filters.city
    if (filters.district) params.district = filters.district
    if (filters.neighborhood) params.neighborhood = filters.neighborhood
    if (filters.street) params.street = filters.street
    if (filters.type_id) params.type_id = filters.type_id
    if (pendingOnly) params.status = 'waiting'
    return params
  }

  const fetchListings = async () => {
    try {
      setLoading(true)
      const params = buildQuery()
      console.log('İlanlar şu parametrelerle çekiliyor:', params)
      const res = await api.get('/waste', { params })
      console.log('İlanlar cevabı:', res.data)
      setListings(res.data?.data || res.data || [])
    } catch (err) {
      console.error('İlanlar yüklenirken hata oluştu:', err)
      toast.error(err.response?.data?.message || err.message || 'İlanlar yüklenemedi')
      setListings([])
    } finally {
      setLoading(false)
    }
  }

  const fetchMyReservations = async () => {
    try {
      const res = await api.get('/reservations/my/collector')
      console.log('Rezervasyonlar cevabı:', res.data)
      setReservations(res.data?.data || res.data || [])
    } catch (err) {
      console.error('Rezervasyonlar yüklenirken hata:', err)
      setReservations([])
    }
  }

  // Combined Search Handler
  const handleSearch = () => {
    if (filters.city) {
      searchByCity()
    } else {
      setCitySearchResults(null)
      fetchListings()
    }
  }

  // fn_get_waste_by_city fonksiyonunu çağır (SQL FUNCTION)
  const searchByCity = async () => {
    if (!filters.city) {
      toast.error('Şehir filtresi gerekli')
      return
    }

    setCitySearchLoading(true)
    try {
      const response = await wasteAPI.searchByCity(filters.city)
      if (response.success) {
        setCitySearchResults(response.data || [])
        toast.success(`${response.count || 0} atık bulundu (fn_get_waste_by_city)`)
      }
    } catch (err) {
      console.error('Şehir araması hatası:', err)
      toast.error('Şehir araması yapılamadı')
    } finally {
      setCitySearchLoading(false)
    }
  }

  const handleReserveClick = (item) => {
    const tomorrow = new Date()
    tomorrow.setDate(tomorrow.getDate() + 1)
    tomorrow.setHours(14, 0, 0, 0)
    const isoLocal = new Date(tomorrow.getTime() - tomorrow.getTimezoneOffset() * 60000).toISOString().slice(0, 16)
    setReserveModal({ open: true, item, datetime: isoLocal })
  }

  const submitReserve = async () => {
    const { item, datetime } = reserveModal
    if (!item) return
    if (!datetime) return toast.error('Lütfen tarih ve saat seçin')
    try {
      setLoading(true)
      const payload = { waste_id: item.waste_id || item.id || item.wasteId, pickup_datetime: new Date(datetime).toISOString() }
      const res = await api.post('/reservations', payload)
      toast.success(res.data?.message || 'Rezerve edildi')

      // remove listing from available list (existing behavior)
      setListings((prev) => prev.filter((l) => (l.waste_id || l.id) !== (item.waste_id || item.id)))

      // also remove from city search results if present
      if (citySearchResults) {
        setCitySearchResults((prev) => prev.filter((l) => (l.waste_id || l.id) !== (item.waste_id || item.id)))
      }

      // if backend returned reservation object, prepend it so status shows as reserved immediately
      const created = res.data?.data || res.data
      if (created && (created.reservation_id || created.id)) {
        setReservations((prev) => [created, ...prev])
      } else {
        // fallback: refresh reservations
        fetchMyReservations()
      }

      setReserveModal({ open: false, item: null, datetime: '' })
      // ensure listings reflect backend state
      fetchListings()
    } catch (err) {
      toast.error(err.response?.data?.message || err.message || 'Rezervasyon yapılamadı')
    } finally {
      setLoading(false)
    }
  }

  // new: delete reservation handler
  const handleDeleteReservation = async (r) => {
    const id = r.reservation_id || r.id
    if (!id) return toast.error('Geçersiz rezervasyon')
    if (!window.confirm('Rezervasyonu silmek istediğinize emin misiniz?')) return
    try {
      setLoading(true)
      await api.delete(`/reservations/${id}`)
      toast.success('Rezervasyon silindi')

      // remove from local reservations list
      setReservations((prev) => prev.filter((x) => (x.reservation_id || x.id) !== id))

      // refresh listings so the waste shows as waiting again
      fetchListings()
      // refresh reservations to get authoritative state
      fetchMyReservations()
    } catch (err) {
      console.error('Rezervasyon silinirken hata:', err)
      toast.error(err.response?.data?.message || err.message || 'Rezervasyon silinemedi')
    } finally {
      setLoading(false)
    }
  }

  // Edit reservation
  const handleEditReservation = (r) => {
    setEditingReservation(r)
    setEditReservationForm({
      pickup_datetime: r.pickup_datetime ? new Date(r.pickup_datetime).toISOString().slice(0, 16) : ''
    })
  }

  // Submit reservation update
  const handleUpdateReservation = async () => {
    if (!editingReservation) return
    try {
      setLoading(true)
      const id = editingReservation.reservation_id || editingReservation.id
      const payload = {
        pickup_datetime: new Date(editReservationForm.pickup_datetime).toISOString()
      }
      const res = await api.put(`/reservations/${id}`, payload)
      toast.success(res.data?.message || 'Rezervasyon güncellendi')

      // Update local reservations list
      setReservations((prev) => prev.map((r) =>
        (r.reservation_id || r.id) === id
          ? { ...r, ...payload }
          : r
      ))

      setEditingReservation(null)
      setEditReservationForm({ pickup_datetime: '' })
    } catch (err) {
      toast.error(err.response?.data?.message || err.message || 'Rezervasyon güncellenemedi')
    } finally {
      setLoading(false)
    }
  }

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


  if (pageError) {
    return (
      <div className="min-h-screen bg-gradient-to-br from-eco-50 via-white to-emerald-50 flex items-center justify-center">
        <div className="eco-card p-8 max-w-md text-center">
          <h2 className="text-lg font-semibold text-red-600 mb-2">Sayfa Yükleme Hatası</h2>
          <p className="text-gray-600 mb-4">{pageError}</p>
          <button onClick={() => navigate('/dashboard')} className="btn btn-primary">
            Ana Sayfa
          </button>
        </div>
      </div>
    )
  }

  return (
    <div className="min-h-screen bg-gradient-to-br from-eco-50 via-white to-emerald-50">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-6">

        {/* Header with Back Button */}
        <div className="flex items-center justify-between mb-6">
          <div className="flex items-center gap-3">
            <button
              onClick={() => navigate('/dashboard')}
              className="btn btn-ghost btn-sm gap-2"
              title="Ana Sayfa"
            >
              <FiArrowLeft className="w-4 h-4" />
              Geri
            </button>
            <h1 className="text-2xl font-bold">İlanlara Göz At & Rezerve Et</h1>
          </div>
        </div>

        {/* Filters Section */}
        <div className="eco-card p-4 mb-6">
          <h2 className="text-lg font-semibold mb-4">Filtreleme</h2>
          <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-6 gap-3">
            <select
              value={filters.type_id}
              onChange={(e) => setFilters({ ...filters, type_id: e.target.value })}
              className="select select-bordered select-sm"
            >
              <option value="">Seçiniz</option>
              {wasteTypes.map((wt) => (
                <option key={wt.type_id} value={wt.type_id}>{getWasteTypeLabel(wt.type_name)}</option>
              ))}
            </select>

            <input
              placeholder="Şehir"
              value={filters.city}
              onChange={(e) => setFilters({ ...filters, city: e.target.value })}
              className="input input-bordered input-sm"
            />

            <input
              placeholder="İlçe"
              value={filters.district}
              onChange={(e) => setFilters({ ...filters, district: e.target.value })}
              className="input input-bordered input-sm"
            />

            <input
              placeholder="Mahalle"
              value={filters.neighborhood}
              onChange={(e) => setFilters({ ...filters, neighborhood: e.target.value })}
              className="input input-bordered input-sm"
            />

            <input
              placeholder="Sokak"
              value={filters.street}
              onChange={(e) => setFilters({ ...filters, street: e.target.value })}
              className="input input-bordered input-sm"
            />

            <label className="flex items-center gap-2 justify-center">
              <input
                type="checkbox"
                checked={pendingOnly}
                onChange={(e) => setPendingOnly(e.target.checked)}
                className="checkbox checkbox-sm"
              />
              <span className="text-sm">Sadece Aktif</span>
            </label>
          </div>

          {/* Action Buttons - 2x3 Matrix */}
          <div className="grid grid-cols-2 sm:grid-cols-4 gap-3 mt-4">
            <button
              onClick={handleSearch}
              disabled={citySearchLoading || loading}
              className="btn btn-primary btn-sm w-full gap-1"
            >
              {(citySearchLoading || loading) ? <span className="loading loading-spinner loading-xs"></span> : <FiSearch className="w-4 h-4" />}
              Ara
            </button>

            <button
              onClick={() => {
                setFilters({ city: '', district: '', neighborhood: '', street: '', type_id: '' });
                setPendingOnly(true);
                setCitySearchResults(null);
                // Call fetchListings with empty filters immediately or just reset state?
                // Let's reset but not auto-fetch to let user decide, or auto-fetch all. 
                // Usually Clear triggers a refresh of default view.
                setLoading(true); // Manually trigger since we can't pass args easily to fetchListings via setState callback immediately
                // Actually safer to just set state and then call fetchListings manually with empty params obj logic if needed, 
                // or just let user click search. But user expects 'Temizle' to reset view.
                // We will just do a fresh fetch with empty filters logic:
                api.get('/waste', { params: { status: 'waiting' } }).then(res => {
                  setListings(res.data?.data || res.data || [])
                  setLoading(false)
                }).catch(() => setLoading(false))
              }}
              className="btn btn-ghost btn-sm w-full"
            >
              Temizle
            </button>
            <button
              onClick={fetchMyReservations}
              className="btn btn-info btn-sm w-full"
            >
              Yenile
            </button>
          </div>

          {/* fn_get_waste_by_city info */}
          <div className="text-xs text-slate-400 mt-2 flex items-center gap-2">
            <span className="badge badge-ghost badge-sm">İpucu</span>
            <span>Şehir filtresi girildiğinde otomatik olarak <strong>SQL Function</strong> (<code>fn_get_waste_by_city</code>) kullanılır.</span>
          </div>
        </div>

        {/* Main Content Grid */}
        <div className="grid grid-cols-1 lg:grid-cols-3 gap-6">

          {/* Listings Column */}
          <div className="lg:col-span-2">
            {/* City Search Results (fn_get_waste_by_city) */}
            {citySearchResults !== null && (
              <div className="eco-card p-4 mb-4 border-2 border-purple-200 bg-purple-50/50">
                <div className="flex items-center justify-between mb-4">
                  <h2 className="text-lg font-semibold flex items-center gap-2 text-purple-700">
                    <FiDatabase className="text-purple-500" />
                    Şehir Arama Sonuçları
                    <span className="text-xs bg-purple-100 text-purple-600 px-2 py-1 rounded-full ml-2">
                      FUNCTION
                    </span>
                  </h2>
                  <button
                    onClick={() => setCitySearchResults(null)}
                    className="btn btn-ghost btn-xs text-purple-600"
                  >
                    ✕ Kapat
                  </button>
                </div>
                <p className="text-xs text-purple-500 mb-3">
                  📌 SQL: <code className="bg-purple-100 px-1 rounded">fn_get_waste_by_city('{filters.city}')</code> — {citySearchResults.length} sonuç
                </p>
                <div className="grid grid-cols-1 md:grid-cols-2 gap-3">
                  {citySearchResults.length === 0 ? (
                    <div className="col-span-full text-sm text-purple-500 p-6 text-center">Bu şehirde aktif atık bulunamadı.</div>
                  ) : citySearchResults.map((l) => (
                    <div key={l.waste_id} className="p-3 border border-purple-200 rounded-lg bg-white hover:shadow-md transition">
                      <div className="text-sm text-purple-700 font-semibold">{l.owner_name}</div>
                      <div className="text-sm text-gray-600">{l.amount} kg — {getWasteTypeLabel(l.type_name)}</div>
                      <div className="text-xs text-gray-500 mt-1">{l.district} • {l.status}</div>
                    </div>
                  ))}
                </div>
              </div>
            )}

            <div className="eco-card p-4">
              <h2 className="text-lg font-semibold mb-4">Mevcut İlanlar</h2>
              <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-3">
                {loading && listings.length === 0 ? (
                  <div className="col-span-full py-8 flex justify-center">
                    <span className="loading loading-spinner loading-lg text-emerald-500"></span>
                  </div>
                ) : listings.length === 0 ? (
                  <div className="col-span-full text-sm text-gray-500 p-6 text-center">İlan bulunamadı.</div>
                ) : listings.map((l) => (
                  <div key={l.waste_id || l.id} className="p-3 border rounded-lg bg-white hover:shadow-md transition">
                    <div className="text-sm text-gray-700 font-semibold">{[l.city, l.neighborhood].filter(Boolean).join(', ') || l.city || 'Bilinmeyen'}</div>
                    <div className="text-sm text-gray-600">{l.amount} {l.official_unit || 'kg'} — {getWasteTypeLabel(l.type_name || l.waste_type_name || l.type)}</div>
                    <div className="text-xs text-gray-500 mt-2">{l.description ? l.description.slice(0, 80) : ''}</div>
                    <div className="mt-3 flex justify-end">
                      <button
                        onClick={() => handleReserveClick(l)}
                        className="btn btn-sm btn-primary"
                      >
                        Rezerve Et
                      </button>
                    </div>
                  </div>
                ))}
              </div>
            </div>
          </div>

          {/* My Reservations Sidebar */}
          <div className="space-y-4">
            <div className="eco-card p-4">
              <h3 className="text-lg font-semibold mb-3">Benim Rezervasyonlarım</h3>

              <div className="space-y-3">
                {reservations.length === 0 ? (
                  <div className="text-sm text-gray-500 p-4 text-center bg-gray-50 rounded">Henüz rezervasyon yok.</div>
                ) : reservations.map((r) => (
                  <div key={r.reservation_id || r.id} className="p-3 border rounded-lg bg-white">
                    <div className="flex items-start justify-between">
                      <div>
                        <div className="text-sm font-semibold">{getWasteTypeLabel(r.type_name || r.type)}</div>
                        <div className="text-xs text-gray-600">{r.waste_description || r.description}</div>
                        <div className="text-xs text-gray-500 mt-2">Alım: {r.pickup_datetime ? new Date(r.pickup_datetime).toLocaleString() : '-'}</div>
                        <div className="text-xs text-gray-700 mt-2">Adres: {[r.city, r.district, r.neighborhood, r.street, r.address_details].filter(Boolean).join(', ') || '-'}</div>
                        <div className="text-xs text-gray-700">Telefon: {r.owner_phone || '-'}</div>
                      </div>

                      <div className="flex flex-col items-end gap-2">
                        <div className="text-xs text-gray-500">Durum: <span className="badge badge-sm">{getStatusLabel(r.status)}</span></div>
                        <button onClick={() => handleEditReservation(r)} className="btn btn-sm btn-info flex items-center gap-2">
                          ✏️Düzenle
                        </button>
                        <button
                          onClick={() => handleDeleteReservation(r)}
                          className="btn btn-error btn-xs"
                          title="Rezervasyonu sil"
                        >
                          Sil
                        </button>
                      </div>
                    </div>
                  </div>
                ))}
              </div>
            </div>

            <div className="eco-card p-4">
              <h3 className="text-lg font-semibold mb-2">Nasıl Çalışır</h3>
              <ul className="text-sm text-gray-600 list-disc ml-5 space-y-1">
                <li><strong>Rezerve Et</strong>'i tıklayarak alımı planla</li>
                <li>Atığı paylaşanın iletişim bilgileri burada görünür</li>
              </ul>
            </div>
          </div>
        </div>

        {/* Reserve Modal */}
        {reserveModal.open && (
          <div className="fixed inset-0 z-50 flex items-center justify-center bg-black/50">
            <div className="bg-white rounded-lg shadow-lg w-11/12 max-w-md p-6">
              <h3 className="text-lg font-semibold mb-2">Alımı Planla</h3>
              <div className="text-sm text-gray-600 mb-3">
                {getWasteTypeLabel(reserveModal.item?.type_name || reserveModal.item?.waste_type_name)} — {reserveModal.item?.amount} {reserveModal.item?.official_unit || 'kg'}
              </div>
              <label className="label"><span className="label-text">Ne zaman alacaksın?</span></label>
              <input
                type="datetime-local"
                value={reserveModal.datetime}
                onChange={(e) => setReserveModal({ ...reserveModal, datetime: e.target.value })}
                className="input input-bordered w-full"
              />
              <div className="flex justify-end gap-2 mt-4">
                <button
                  onClick={() => setReserveModal({ open: false, item: null, datetime: '' })}
                  className="btn btn-ghost btn-sm"
                >
                  İptal
                </button>
                <button
                  onClick={submitReserve}
                  className="btn btn-primary btn-sm"
                >
                  Onayla
                </button>
              </div>
            </div>
          </div>
        )}

        {/* Edit Reservation Modal */}
        {editingReservation && (
          <div className="fixed inset-0 z-50 flex items-center justify-center bg-black/50">
            <div className="bg-white rounded-lg shadow-lg w-11/12 max-w-md p-6">
              <h3 className="text-lg font-semibold mb-2">Rezervasyonu Güncelle</h3>
              <div className="text-sm text-gray-600 mb-4">
                {getWasteTypeLabel(editingReservation?.type_name || editingReservation?.waste_type_name)}
              </div>
              <label className="label"><span className="label-text">Yeni Alım Tarihi & Saati</span></label>
              <input
                type="datetime-local"
                value={editReservationForm.pickup_datetime}
                onChange={(e) => setEditReservationForm({ ...editReservationForm, pickup_datetime: e.target.value })}
                className="input input-bordered w-full"
              />
              <div className="flex justify-end gap-2 mt-4">
                <button
                  onClick={() => { setEditingReservation(null); setEditReservationForm({ pickup_datetime: '' }); }}
                  className="btn btn-ghost btn-sm"
                >
                  İptal
                </button>
                <button
                  onClick={handleUpdateReservation}
                  disabled={loading}
                  className="btn btn-primary btn-sm"
                >
                  {loading ? 'Kaydediliyor...' : 'Kaydet'}
                </button>
              </div>
            </div>
          </div>
        )}

      </div>
    </div>
  )
}

export default BrowseListings