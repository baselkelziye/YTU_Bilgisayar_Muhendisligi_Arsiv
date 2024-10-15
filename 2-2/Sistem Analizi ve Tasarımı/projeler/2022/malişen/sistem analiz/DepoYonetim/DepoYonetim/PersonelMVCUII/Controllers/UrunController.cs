using PersonelMVCUII.Models.EntityFramework;
using PersonelMVCUII.ViewModel;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace PersonelMVCUII.Controllers
{
   
    public class UrunController : Controller
    {
        DepoYonetimSistemiEntities db = new DepoYonetimSistemiEntities();
       
        // GET: Departman
        public ActionResult Index()
        {
            var model = db.Urun.ToList();
            return View(model);
        }
        [HttpGet]
        public ActionResult Yeni()
        {
            var kategori=db.Kategori.ToList();
            List<string> KategoriListesi = new List<string>();
            foreach (var item in kategori)
            {
                KategoriListesi.Add(item.Kategoriler);
            }
            SelectList list = new SelectList(KategoriListesi);
            ViewBag.Kategoriler = list;
            return View("UrunForm",new Urun());
        }
        [HttpPost]
        public ActionResult Kaydet(Urun urun)
        {
            if(!ModelState.IsValid)
            {
                return View("UrunForm");
            }
            MesajViewModel model = new MesajViewModel();
            if (urun.Id == 0)
            {
                var kategori = urun.Kategori;
                var rafinKategorisi = db.Raf.Where(x=>x.Kategori.Kategoriler==kategori).FirstOrDefault();
                if(kategori==null)
                {
                    model.Mesaj = "Lütfen öncelikle ürünün kategorisini ekleyiniz";
                    return View("_Mesaj", model);
                }
                else if(rafinKategorisi.AnlıkKapasite+urun.ToplamUrunSayisi>rafinKategorisi.Kapasite)
                {
                    model.Mesaj = "Raf kapasitesi taşacak lütfen raf kapasitesini artırınız";
                    return View("_Mesaj", model);
                }
                else if (urun.ToplamUrunSayisi < 1)
                {
                    model.Mesaj = "Ürün sayısı 1'den düşük olamaz";
                    return View("_Mesaj", model);
                }
                UrunRafBilgisi urunRaf = new UrunRafBilgisi
                {
                    UrunId = urun.Id,
                    RafId = rafinKategorisi.Id
                };

                db.UrunRafBilgisi.Add(urunRaf);
                rafinKategorisi.AnlıkKapasite+=urun.ToplamUrunSayisi;
                db.Entry(rafinKategorisi).State = EntityState.Modified;
                db.Urun.Add(urun);
                model.Mesaj = urun.UrunAdi + "  başarıyla eklendi";
            }
               
            else
            {
                
                var guncellenecekUrun = db.Urun.Find(urun.Id);
                var rafid = db.UrunRafBilgisi.Where(x => x.UrunId == urun.Id).Select(y => y.RafId).FirstOrDefault();
                var raf2 = db.Raf.Where(x => x.Id == rafid).FirstOrDefault();
                var raf3 = db.Raf.Where(x => x.Kategori.Kategoriler == urun.Kategori).FirstOrDefault();
                
                if (raf3!=raf2)
                {
                    model.Mesaj = "Bu kategori başka bir rafa aittir";
                    return View("_Mesaj", model);
                }
                else if(raf2.Kapasite<= raf2.AnlıkKapasite - guncellenecekUrun.ToplamUrunSayisi + urun.ToplamUrunSayisi)
                {
                    model.Mesaj = "Raf kapasitesi taşacak lütfen raf kapasitesini artırınız";
                    return View("_Mesaj", model);
                }


                else
                {
                    
                    raf3.AnlıkKapasite = raf3.AnlıkKapasite -guncellenecekUrun.ToplamUrunSayisi+urun.ToplamUrunSayisi;
                    guncellenecekUrun.UrunAdi = urun.UrunAdi;
                    guncellenecekUrun.Kategori = urun.Kategori;
                    guncellenecekUrun.ToplamUrunSayisi = urun.ToplamUrunSayisi;
                    guncellenecekUrun.UrunFiyati = urun.UrunFiyati;
                    guncellenecekUrun.SonTuketimTarihi = urun.SonTuketimTarihi;
                    db.Entry(raf3).State = EntityState.Modified;
                }
                
                db.Entry(guncellenecekUrun).State = EntityState.Modified;
                


                model.Mesaj = urun.UrunAdi + "başarıyla güncellendi";
            }

            db.SaveChanges();
            model.Status = true;
            model.Linktext = "Urun Listesi";
            model.Url = "/Urun";
            //  return RedirectToAction("Index", "Departman");
            return View("_Mesaj",model);        
        }
        public ActionResult Guncelle(int id)
        {
            var kategori = db.Kategori.ToList();
            List<string> KategoriListesi = new List<string>();
            foreach (var item in kategori)
            {
                KategoriListesi.Add(item.Kategoriler);
            }
            SelectList list = new SelectList(KategoriListesi);
            ViewBag.Kategoriler = list;
            var model = db.Urun.Find(id);
            if (model == null)
            {
                return HttpNotFound();
            }
            return View("UrunForm",model);
            
        }
        public ActionResult Sil(int id)
        {
            var rafid = db.UrunRafBilgisi.Where(x => x.UrunId == id).Select(y => y.RafId).FirstOrDefault();
            var raf2 = db.Raf.Where(x => x.Id == rafid).FirstOrDefault();
            var urunRafid = db.UrunRafBilgisi.Where(x => x.UrunId == id).Select(y => y.Id).FirstOrDefault();
            var urunRaf = db.UrunRafBilgisi.Find(urunRafid);
            var silinecekUrun = db.Urun.Find(id);
            if (silinecekUrun == null)
            {
                return HttpNotFound();
            }
            raf2.AnlıkKapasite = raf2.AnlıkKapasite - silinecekUrun.ToplamUrunSayisi;
            db.Entry(raf2).State = EntityState.Modified;
            db.Urun.Remove(silinecekUrun);
            db.UrunRafBilgisi.Remove(urunRaf);
            db.SaveChanges();
            return RedirectToAction("Index");
        }
    }
}