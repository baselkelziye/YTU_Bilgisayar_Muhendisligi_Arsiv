import { useState, useEffect } from 'react'
import { useNavigate } from 'react-router-dom'
import api from '../services/api'
import toast from 'react-hot-toast'
import { useAuth } from '../context/AuthContext'
import { FiArrowLeft, FiTrash } from 'react-icons/fi'

const Listings = () => {
  const navigate = useNavigate()
  const { user } = useAuth()

  const [form, setForm] = useState({
    description: '',
    weight: '',
    type_id: ''
  })

  const [addressFields, setAddressFields] = useState({
    city: '',
    district: '',
    neighborhood: '',
    street: '',
    address_details: ''
  })
  const [editingAddress, setEditingAddress] = useState(false)

  const [wasteTypes, setWasteTypes] = useState([])
  const [listings, setListings] = useState([])
  const [showListings, setShowListings] = useState(false)
  const [loading, setLoading] = useState(false)
  const [idToDelete, setIdToDelete] = useState(null)
  const [confirmDeleteOpen, setConfirmDeleteOpen] = useState(false)
  const [editingItem, setEditingItem] = useState(null)
  const [editForm, setEditForm] = useState({ description: '', amount: '', type_id: '' })

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

  

  // Fetch waste types on mount
  useEffect(() => {
    const fetchWasteTypes = async () => {
      try {
        const res = await api.get('/waste/types')
        setWasteTypes(res.data?.data || [])
      } catch (err) {
        toast.error('Atık türleri yüklenemedi')
      }
    }
    
    // Set user address fields from logged-in user
    if (user) {
      setAddressFields({
        city: user.city || '',
        district: user.district || '',
        neighborhood: user.neighborhood || '',
        street: user.street || '',
        address_details: user.address_details || ''
      })
    }
    
    fetchWasteTypes()
  }, [user])

  const handleChange = (e) => {
    setForm({ ...form, [e.target.name]: e.target.value })
  }

  const handleAddressChange = (e) => {
    setAddressFields({ ...addressFields, [e.target.name]: e.target.value })
  }

  const selectedType = wasteTypes.find((wt) => String(wt.type_id) === String(form.type_id))
  const weightUnit = selectedType?.official_unit || 'kg'

  const handleSubmit = async (e) => {
    e.preventDefault()
    try {
      setLoading(true)
      const payload = {
        description: form.description,
        amount: parseFloat(form.weight) || 0,
        type_id: parseInt(form.type_id),
      }

      // include composed address from user address fields if present
      const composedAddress = [addressFields.street, addressFields.neighborhood, addressFields.district, addressFields.city].filter(Boolean).join(', ')
      if (composedAddress) payload.address = composedAddress

      const res = await api.post('/waste', payload)
      toast.success(res?.data?.message || 'Atık oluşturuldu')
      setForm({ description: '', weight: '', type_id: '', latitude: '', longitude: '' })
    } catch (err) {
      toast.error(err.response?.data?.message || err.message || 'Atık oluşturulamadı')
    } finally {
      setLoading(false)
    }
  }

  const handleShowListings = async () => {
    try {
      setLoading(true)
      const res = await api.get('/waste/my')
      setListings(res.data?.data || res.data || [])
      setShowListings(true)
    } catch (err) {
      toast.error(err.response?.data?.message || err.message || 'Atıklar yüklenemedi')
    } finally {
      setLoading(false)
    }
  }

  // Open confirmation modal
  const handleDelete = (id) => {
    setIdToDelete(id)
    setConfirmDeleteOpen(true)
  }

  // Confirmed delete
  const handleConfirmDelete = async () => {
    if (!idToDelete) return
    try {
      setLoading(true)
      const res = await api.delete(`/waste/${idToDelete}`)
      toast.success(res.data?.message || 'Atık silindi')
      setListings((prev) => prev.filter((it) => (it.waste_id || it.id) !== idToDelete))
      setIdToDelete(null)
      setConfirmDeleteOpen(false)
    } catch (err) {
      toast.error(err.response?.data?.message || err.message || 'Atık silinemedi')
    } finally {
      setLoading(false)
    }
  }

  // Open edit modal
  const handleEditClick = (item) => {
    setEditingItem(item)
    setEditForm({
      description: item.description || '',
      amount: item.amount || item.weight || '',
      type_id: item.type_id || ''
    })
  }

  // Submit edit
  const handleEditSubmit = async () => {
    if (!editingItem) return
    try {
      setLoading(true)
      const payload = {
        description: editForm.description,
        amount: parseFloat(editForm.amount) || 0,
        type_id: parseInt(editForm.type_id)
      }
      const res = await api.put(`/waste/${editingItem.waste_id || editingItem.id}`, payload)
      toast.success(res.data?.message || 'Atık güncellendi')
      setListings((prev) => prev.map((it) => (it.waste_id || it.id) === (editingItem.waste_id || editingItem.id) ? { ...it, ...payload } : it))
      setEditingItem(null)
      setEditForm({ description: '', amount: '', type_id: '' })
    } catch (err) {
      toast.error(err.response?.data?.message || err.message || 'Atık güncellenemedi')
    } finally {
      setLoading(false)
    }
  }

  return (
    <div className="min-h-screen bg-gradient-to-br from-eco-50 via-white to-emerald-50">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-6">
        <div className="flex items-center gap-4 mb-6">
          <button onClick={() => navigate('/dashboard')} className="btn btn-ghost p-2">
            <FiArrowLeft className="w-5 h-5" />
          </button>
          <h1 className="text-2xl font-bold">Atık Ekle, Listele</h1>
        </div>

        <div className="grid grid-cols-1 lg:grid-cols-2 gap-6">
          {/* Left: Create Listing Form */}
          <div className="eco-card p-6">
            <h2 className="text-lg font-semibold mb-4">Yeni Atık Ekle</h2>
            <form onSubmit={handleSubmit} className="space-y-4">
              <div>
                <label className="label">
                  <span className="label-text">Açıklama</span>
                </label>
                <textarea name="description" value={form.description} onChange={handleChange} className="textarea textarea-bordered w-full" rows={3} />
              </div>

              <div className="grid grid-cols-2 gap-2">
                <div>
                  <label className="label"><span className="label-text">Boyut ({weightUnit})</span></label>
                  <input name="weight" value={form.weight} onChange={handleChange} type="number" step={weightUnit === 'adet' ? '1' : '0.1'}  className="input input-bordered w-full" required />
                </div>
                <div>
                  <label className="label"><span className="label-text">Atık tipi</span></label>
                  <select name="type_id" value={form.type_id} onChange={handleChange} required className="select select-bordered w-full">
                    <option value="">Seçiniz</option>
                    {wasteTypes.map((wt) => (
                      <option key={wt.type_id} value={wt.type_id}>{getWasteTypeLabel(wt.type_name)}</option>
                    ))}
                  </select>
                </div>
              </div>


              <div className="flex items-center gap-3">
                <button type="submit" disabled={loading} className="btn btn-primary">
                  {loading ? 'Kaydediliyor...' : 'Ekle'}
                </button>
                <button type="button" onClick={() => setForm({ description: '', weight: '', type_id: '' })} className="btn btn-ghost">Temizle</button>
              </div>
            </form>

            <div className="mt-4 text-sm text-gray-500">
              Konumunuz: <strong>{[addressFields.street, addressFields.neighborhood, addressFields.district, addressFields.city].filter(Boolean).join(', ') || 'Belirlenmedi'}</strong>
            </div>
          </div>

          {/* Right: Address & Listings Panel */}
          <div className="space-y-6">
            {/* Address Section */}
            <div className="eco-card p-6">
                <div className="flex justify-between items-center mb-4">
                  <h2 className="text-lg font-semibold">Adresiniz</h2>
                  <button onClick={() => setEditingAddress(!editingAddress)} className="btn btn-ghost btn-sm">
                    {editingAddress ? 'Vazgeç' : 'Düzenle'}
                  </button>
                </div>

                {editingAddress ? (
                  <div className="space-y-3">
                    <div className="grid grid-cols-2 gap-2">
                      <input name="city" value={addressFields.city} onChange={handleAddressChange} placeholder="Şehir" className="input input-bordered w-full" />
                      <input name="district" value={addressFields.district} onChange={handleAddressChange} placeholder="İlçe" className="input input-bordered w-full" />
                    </div>
                    <div className="grid grid-cols-2 gap-2">
                      <input name="neighborhood" value={addressFields.neighborhood} onChange={handleAddressChange} placeholder="Mahalle" className="input input-bordered w-full" />
                      <input name="street" value={addressFields.street} onChange={handleAddressChange} placeholder="Sokak" className="input input-bordered w-full" />
                    </div>
                    <div>
                      <input name="address_details" value={addressFields.address_details} onChange={handleAddressChange} placeholder="Detay" className="input input-bordered w-full" />
                    </div>
                    <div className="flex items-center gap-2">
                      <button onClick={async () => {
                        try {
                          setEditingAddress(false);
                          const res = await api.put('/auth/me', addressFields);
                          // update localStorage user object if present
                          try {
                            const stored = JSON.parse(localStorage.getItem('user') || '{}')
                            const updated = { ...stored, city: res.data?.data?.user?.city || addressFields.city, district: res.data?.data?.user?.district || addressFields.district, neighborhood: res.data?.data?.user?.neighborhood || addressFields.neighborhood, street: res.data?.data?.user?.street || addressFields.street, address_details: res.data?.data?.user?.address_details || addressFields.address_details }
                            localStorage.setItem('user', JSON.stringify(updated))
                          } catch (e) {}
                          toast.success(res.data?.message || 'Adres kaydedildi')
                        } catch (err) {
                          toast.error(err.response?.data?.message || err.message || 'Adres kaydedilemedi')
                        }
                      }} className="btn btn-sm btn-primary">Adresi Kaydet</button>
                      <button onClick={() => { setEditingAddress(false); setAddressFields({ city: user?.city||"", district: user?.district||"", neighborhood: user?.neighborhood||"", street: user?.street||"", address_details: user?.address_details||"" }) }} className="btn btn-sm btn-ghost">Sıfırla</button>
                    </div>
                  </div>
                ) : (
                  <div>
                    <p className="text-gray-700">{[addressFields.street, addressFields.neighborhood, addressFields.district, addressFields.city].filter(Boolean).join(', ') || 'Adres belirlenmedi.'}</p>
                    {addressFields.address_details && <p className="text-sm text-gray-500 mt-2">{addressFields.address_details}</p>}
                  </div>
                )}
            </div>

            {/* Listings Section */}
            <div className="eco-card p-6">
              <div className="flex justify-between items-center mb-4">
                <h2 className="text-lg font-semibold">Atıklarım</h2>
                <div className="flex items-center gap-2">
                  <button onClick={handleShowListings} className="btn btn-outline btn-sm">Yenile</button>
                  <button onClick={() => { setShowListings(false); setListings([]) }} className="btn btn-ghost btn-sm">Gizle</button>
                </div>
              </div>

              {loading && !showListings && (
                <div className="flex items-center justify-center py-8">
                  <span className="loading loading-spinner loading-lg text-emerald-500"></span>
                </div>
              )}

              {showListings && (
                <div className="space-y-3">
                  {listings.length === 0 && (
                    <div className="text-sm text-gray-500">Atık kaydı yok, hemen ekle!</div>
                  )}

                  {listings.map((l) => (
                    <div key={l.waste_id || l.id} className="p-3 border rounded-lg">
                      <div className="flex justify-between items-start">
                            <div>
                              <h3 className="font-semibold">{getWasteTypeLabel(l.type_name || l.waste_type_name || l.type)}</h3>
                              <p className="text-sm text-gray-600">{l.description}</p>
                              <div className="text-xs text-gray-500 mt-2 space-y-1">
                                <div>Boyut: {l.amount || l.weight} {l.official_unit || 'kg'}</div>
                                <div>Durum: <span className="badge badge-sm badge-success">{getStatusLabel(l.status)}</span></div>
                                {l.record_date && <div>Ekleme tarihi: {new Date(l.record_date).toLocaleDateString()}</div>}
                              </div>
                            </div>
                            <div className="ml-4">
                              <button onClick={() => handleEditClick(l)} className="btn btn-sm btn-info flex items-center gap-2 mb-2">
                                ✏️ Düzenle
                              </button>
                              <button onClick={() => handleDelete(l.waste_id || l.id)} className="btn btn-sm btn-error flex items-center gap-2">
                                <FiTrash className="w-3 h-3" />
                                Sil
                              </button>
                            </div>
                          </div>
                    </div>
                  ))}
                </div>
              )}

              {!showListings && (
                <div className="text-sm text-gray-500">.</div>
              )}
            </div>
          </div>
        </div>
        {confirmDeleteOpen && (
          <div className="fixed inset-0 z-50 flex items-center justify-center bg-black/50">
            <div className="bg-white rounded-lg shadow-lg w-11/12 max-w-sm p-6">
              <p className="text-sm text-gray-600 mb-4">Silmek istediğinize emin misiniz? Bu işlem geri alınamaz.</p>
              <div className="flex justify-end gap-2">
                <button onClick={() => { setConfirmDeleteOpen(false); setIdToDelete(null) }} className="btn btn-ghost">Vazgeç</button>
                <button onClick={handleConfirmDelete} className="btn btn-error">Sil</button>
              </div>
            </div>
          </div>
        )}

        {/* Edit Modal */}
        {editingItem && (
          <div className="fixed inset-0 z-50 flex items-center justify-center bg-black/50">
            <div className="bg-white rounded-lg shadow-lg w-11/12 max-w-md p-6">
              <h2 className="text-lg font-semibold mb-4">Atığı Düzenle</h2>
              <div className="space-y-4">
                <div>
                  <label className="label"><span className="label-text">Açıklama</span></label>
                  <textarea 
                    value={editForm.description} 
                    onChange={(e) => setEditForm({ ...editForm, description: e.target.value })} 
                    className="textarea textarea-bordered w-full" 
                    rows={2}
                  />
                </div>
                <div className="grid grid-cols-2 gap-2">
                  <div>
                    <label className="label"><span className="label-text">Boyut</span></label>
                    <input 
                      type="number" 
                      step="0.1"
                      value={editForm.amount} 
                      onChange={(e) => setEditForm({ ...editForm, amount: e.target.value })} 
                      className="input input-bordered w-full" 
                    />
                  </div>
                  <div>
                    <label className="label"><span className="label-text">Atık Tipi</span></label>
                    <select 
                      value={editForm.type_id} 
                      onChange={(e) => setEditForm({ ...editForm, type_id: e.target.value })} 
                      className="select select-bordered w-full"
                    >
                      <option value="">Seçiniz</option>
                      {wasteTypes.map((wt) => (
                        <option key={wt.type_id} value={wt.type_id}>{getWasteTypeLabel(wt.type_name)}</option>
                      ))}
                    </select>
                  </div>
                </div>
              </div>
              <div className="flex justify-end gap-2 mt-6">
                <button onClick={() => { setEditingItem(null); setEditForm({ description: '', amount: '', type_id: '' }); }} className="btn btn-ghost">Vazgeç</button>
                <button onClick={handleEditSubmit} disabled={loading} className="btn btn-primary">
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

export default Listings
