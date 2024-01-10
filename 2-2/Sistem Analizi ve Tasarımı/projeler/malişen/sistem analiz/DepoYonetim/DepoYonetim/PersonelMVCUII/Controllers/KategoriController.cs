
using PersonelMVCUII.Models.EntityFramework;
using PersonelMVCUII.ViewModel;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.IO;
using System.Linq;
using System.Text;
using System.Web.Mvc;

namespace PersonelMVCUII.Controllers
{
    public class KategoriController : Controller
    {
        DepoYonetimSistemiEntities db = new DepoYonetimSistemiEntities();

        public ActionResult Index()
        {
            return View(db.Kategori.ToList());
        }
        public ActionResult Yeni()
        {

            return View("KategoriForm", new Kategori());
        }
        [HttpPost]
        public ActionResult Kaydet(Kategori kategori)
        {
            if (!ModelState.IsValid)
            {
                return View("KategoriForm");
            }

            MesajViewModel model = new MesajViewModel();
            if (kategori.Id == 0)
            {
                db.Kategori.Add(kategori);
                model.Mesaj = "kategori başarıyla eklendi";
            }
            //else
            //{
            //    var guncellenecekKategori = db.Kategori.Find(kategori.Id);
            //    if (guncellenecekKategori == null)
            //        return HttpNotFound();
            //    guncellenecekKategori.Kategoriler = kategori.Kategoriler;
            //    db.Entry(guncellenecekKategori).State = EntityState.Modified;
            //    model.Mesaj = "kategori başarıyla güncellendi";


            //}

            db.SaveChanges();
            model.Status = true;
            model.Linktext = "Kategori Listesi";
            model.Url = "/Kategori";
            //  return RedirectToAction("Index", "Departman");
            return View("_Mesaj", model);
        }

        //public ActionResult Guncelle(int id)
        //{
        //    var model = db.Kategori.Find(id);
        //    if (model == null)
        //    {
        //        return HttpNotFound();
        //    }
        //    return View("KategoriForm", model);

        //}

        public ActionResult Sil(int id)
        {
            MesajViewModel model = new MesajViewModel();
            var silinecekKategori = db.Kategori.Find(id);

            if (silinecekKategori == null)
            {
                model.Mesaj = "Kategori yok";
                return View("_Mesaj", model);
            }
            //var raflar = db.Raf.Where(x => x.Kategori.Kategoriler == silinecekKategori.Kategoriler).ToList();


            //foreach (var item in raflar)
            //{
            //    db.Raf.Remove(item);
            //}

            var urunler = db.Urun.Where(x => x.Kategori == silinecekKategori.Kategoriler).ToList();

            foreach (var item1 in urunler)
            {
                db.Urun.Remove(item1);
            }



            db.Kategori.Remove(silinecekKategori);
            db.SaveChanges();
            return RedirectToAction("Index");
        }


    }
}