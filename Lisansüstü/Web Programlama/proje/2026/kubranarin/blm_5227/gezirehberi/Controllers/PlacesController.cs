using GeziRehberi.Helper;
using GeziRehberi.Models;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.IO;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;

namespace GeziRehberi.Controllers
{
    public class PlacesController : Controller
    {
        private GeziRehberiEntities db = new GeziRehberiEntities();

        [CustomAuthorize(Roles = "Admin,User")]
        public ActionResult List()
        {
            var places = db.Places.ToList();
            ViewBag.Cities = db.Cities.ToList();
            ViewBag.Categories = db.Categories.ToList();
            return View(places);
        }


        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Places place = db.Places.Find(id);
            if (place == null)
            {
                return HttpNotFound();
            }
            return View(place);
        }

        [CustomAuthorize(Roles = "Admin,User")]
        public ActionResult Create()
        {
            ViewBag.CityId = new SelectList(db.Cities, "Id", "Name");
            ViewBag.CategoryId = new SelectList(db.Categories, "Id", "Name");
            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "Id,CityId,CategoryId,Name,Description,Address,Latitude,Longitude,AverageRating,ViewCount,PhotoUrl,IsActive,CreatedDate")] Places place, HttpPostedFileBase photoFile)
        {
            if (ModelState.IsValid)
            {
                place.CreatedDate = DateTime.Now;
                if (place.ViewCount == null)
                {
                    place.ViewCount = 0;
                }

                // Fotoğraf yükleme işlemi
                if (photoFile != null && photoFile.ContentLength > 0)
                {
                    string uploadPath = Server.MapPath("~/Uploads/Places/");
                    if (!Directory.Exists(uploadPath))
                    {
                        Directory.CreateDirectory(uploadPath);
                    }

                    string fileName = Guid.NewGuid().ToString() + Path.GetExtension(photoFile.FileName);
                    string filePath = Path.Combine(uploadPath, fileName);
                    photoFile.SaveAs(filePath);
                    place.PhotoUrl = "/Uploads/Places/" + fileName;
                }

                db.Places.Add(place);
                db.SaveChanges();
                return RedirectToAction("List");
            }
            ViewBag.CityId = new SelectList(db.Cities, "Id", "Name", place.CityId);
            ViewBag.CategoryId = new SelectList(db.Categories, "Id", "Name", place.CategoryId);
            return View(place);
        }
        [CustomAuthorize(Roles = "Admin,User")]
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Places place = db.Places.Find(id);
            if (place == null)
            {
                return HttpNotFound();
            }
            ViewBag.CityId = new SelectList(db.Cities, "Id", "Name", place.CityId);
            ViewBag.CategoryId = new SelectList(db.Categories, "Id", "Name", place.CategoryId);
            return View(place);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "Id,CityId,CategoryId,Name,Description,Address,Latitude,Longitude,AverageRating,ViewCount,PhotoUrl,IsActive,CreatedDate")] Places place, HttpPostedFileBase photoFile)
        {
            if (ModelState.IsValid)
            {
                // Fotoğraf yükleme işlemi
                if (photoFile != null && photoFile.ContentLength > 0)
                {
                    // Eski fotoğrafı sil
                    if (!string.IsNullOrEmpty(place.PhotoUrl))
                    {
                        string oldFilePath = Server.MapPath(place.PhotoUrl);
                        if (System.IO.File.Exists(oldFilePath))
                        {
                            System.IO.File.Delete(oldFilePath);
                        }
                    }

                    string uploadPath = Server.MapPath("~/Uploads/Places/");
                    if (!Directory.Exists(uploadPath))
                    {
                        Directory.CreateDirectory(uploadPath);
                    }

                    string fileName = Guid.NewGuid().ToString() + Path.GetExtension(photoFile.FileName);
                    string filePath = Path.Combine(uploadPath, fileName);
                    photoFile.SaveAs(filePath);
                    place.PhotoUrl = "/Uploads/Places/" + fileName;
                }

                db.Entry(place).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("List");
            }
            ViewBag.CityId = new SelectList(db.Cities, "Id", "Name", place.CityId);
            ViewBag.CategoryId = new SelectList(db.Categories, "Id", "Name", place.CategoryId);
            return View(place);
        }

      
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Delete(int id)
        {
            Places place = db.Places.Find(id);
            db.Places.Remove(place);
            db.SaveChanges();
            return RedirectToAction("List");
        }
    }
}