using PersonelMVCUII.Models.EntityFramework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace PersonelMVCUII.ViewModel
{
    public class KullaniciViewModel
    {
        public int Id { get; set; }
        public string KullaniciAdi { get; set; }
        public string Sifre { get; set; }
        public string Rol { get; set; }
    }
    public class UrunViewModel
    {
        public int Id { get; set; }
        public string UrunAdi { get; set; }
        public Nullable<System.DateTime> SonTuketimTarihi { get; set; }
        public string UrunKategorisi { get; set; }
        public Nullable<double> UrunFiyati { get; set; }
        public string ToplamUrunSayisi { get; set; }
    }
    public class RafViewModel
    {
        public int Id { get; set; }
        public Nullable<int> Kapasite { get; set; }
        public Nullable<int> AnlıkKapasite { get; set; }
    }
    public class UrunRafViewModel
    {
        public int Id { get; set; }
        public int UrunId { get; set; }
        public int RafId { get; set; }

        public virtual List<RafViewModel> Raf { get; set; }
        public virtual List<UrunViewModel> Urunler { get; set; }
    }
}