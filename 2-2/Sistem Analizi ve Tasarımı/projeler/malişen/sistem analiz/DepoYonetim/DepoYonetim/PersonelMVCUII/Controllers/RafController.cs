using PersonelMVCUII.Models.EntityFramework;
using PersonelMVCUII.ViewModel;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Security;

namespace PersonelMVCUII.Controllers
{
    public class RafController : Controller
    {

        DepoYonetimSistemiEntities db = new DepoYonetimSistemiEntities();

        public ActionResult Index()
        {
            return View(db.Raf.ToList());
        }
        public ActionResult Yeni()
        {
            var kategori = db.Kategori.ToList();
            List<string> KategoriListesi = new List<string>();
            foreach (var item in kategori)
            {
                KategoriListesi.Add(item.Kategoriler);
            }
            SelectList list = new SelectList(KategoriListesi);
            ViewBag.Kategoriler = list;

            return View("RafForm", new Raf());
        }
        [HttpPost]
        public ActionResult Kaydet(Raf raf)
        {
            if (!ModelState.IsValid)
            {
                return View("RafForm");
            }
            
            MesajViewModel model = new MesajViewModel();
            if (raf.Id == 0)
            {
                if(raf.Kategori.Kategoriler==null)
                {
                    model.Mesaj = "öncelikle raf için kategori eklemeniz gerekiyor.";
                    return View("_Mesaj", model);
                }
                if(raf.Kapasite<1)
                {
                    model.Mesaj = "Rafın minimum kapasitesi 1'dir";
                    return View("_Mesaj", model);
                }
                var raflist=db.Raf.ToList();
                foreach (var item in raflist)
                {
                    if(item.Kategori.Kategoriler==raf.Kategori.Kategoriler && item.AnlıkKapasite<item.Kapasite)
                    {
                        model.Mesaj = "öncelikle boşta olan rafı doldurmanız gerekiyor.";
                        return View("_Mesaj", model);
                    }
                    else if(item.AnlıkKapasite == item.Kapasite && item.Kategori.Kategoriler == raf.Kategori.Kategoriler)
                    {
                        model.Mesaj = "Raf tamamen dolu ise kapasite artırımı yapabilirsiniz.";
                        return View("_Mesaj", model);
                    }
                }

                    raf.AnlıkKapasite = 0;
                    db.Raf.Add(raf);
                    model.Mesaj = "raf başarıyla eklendi";
            }
            else
            {
                var guncellenecekRaf = db.Raf.Find(raf.Id);
                if (guncellenecekRaf == null)
                    return HttpNotFound();
                else if(guncellenecekRaf.AnlıkKapasite>=raf.Kapasite)
                {
                    model.Mesaj = "depomuzda belirttiğiniz kapasiteden fazla mal vardır";
                    return View("_Mesaj",model);
                }
                else if(guncellenecekRaf.AnlıkKapasite<=raf.Kapasite)
                {
                    guncellenecekRaf.Kapasite = raf.Kapasite;
                    guncellenecekRaf.Kategori.Kategoriler = raf.Kategori.Kategoriler;
                    var urunler = db.UrunRafBilgisi.Where(x => x.RafId == raf.Id).ToList();
                    foreach (var item in urunler)
                    {
                        var urun = db.Urun.Where(x => x.Id == item.Id).FirstOrDefault();
                        urun.Kategori= raf.Kategori.Kategoriler;
                        db.Entry(urun).State = EntityState.Modified;
                    }
                    
                    db.Entry(guncellenecekRaf).State = EntityState.Modified;
                    model.Mesaj = "raf başarıyla güncellendi";
                }
                else
                {
                    model.Mesaj = "raf eklenemez kapasite düşük";
                    return View("_Mesaj", model);
                }

            }

            db.SaveChanges();
            model.Status = true;
            model.Linktext = "Raf Listesi";
            model.Url = "/Raf";
            return View("_Mesaj", model);
        }

        public ActionResult Guncelle(int id)
        {
            var model = db.Raf.Find(id);
            if (model == null)
            {
                return HttpNotFound();
            }
            return View("RafForm", model);

        }

        public ActionResult Sil(int id)
        {
            MesajViewModel model = new MesajViewModel();
            var silinecekRaf = db.Raf.Find(id);

            if (silinecekRaf == null)
            {
                model.Mesaj = "Raf yok veya dolu";
                return View("_Mesaj",model);
            }
            var raftakiUrunler = db.UrunRafBilgisi.Where(x => x.RafId == id).ToList();
            var kategori = db.Kategori.Where(x => x.Kategoriler == silinecekRaf.Kategori.Kategoriler).FirstOrDefault();
            

            foreach (var item in raftakiUrunler)
            {
                db.UrunRafBilgisi.Remove(item);
                var urun = db.Urun.Where(x => x.Id == item.Id).FirstOrDefault();
                db.Urun.Remove(urun);
            }
            db.Raf.Remove(silinecekRaf);
            db.Kategori.Remove(kategori);
            db.SaveChanges();
            return RedirectToAction("Index");
        }
    }
}