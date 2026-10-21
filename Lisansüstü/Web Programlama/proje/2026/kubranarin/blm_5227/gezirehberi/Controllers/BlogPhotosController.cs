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
    public class BlogPhotosController : Controller
    {
        private GeziRehberiEntities db = new GeziRehberiEntities();
        List<Blogs> blogs;
        List<BlogPhotos> blogPhotos;

        [CustomAuthorize(Roles = "Admin,User")]
        public ActionResult List()
        {
            var userId = Convert.ToInt32(Session["UserId"]);
            var userRole = Session["Role"];
            if (userRole == "Admin")
            {
                blogPhotos = db.BlogPhotos.ToList();
            }
            else
            {
                blogPhotos =
                (from p in db.BlogPhotos
                 join b in db.Blogs on p.BlogId equals b.Id
                 where b.UserId == userId
                 select p)
                .ToList();
             
            }
       
            ViewBag.Blogs = db.Blogs.ToList();
            return View(blogPhotos);
        }

 
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            BlogPhotos blogPhoto = db.BlogPhotos.Find(id);
            if (blogPhoto == null)
            {
                return HttpNotFound();
            }
            return View(blogPhoto);
        }

        [CustomAuthorize(Roles = "Admin,User")]
        public ActionResult Create()
        {
            ViewBag.BlogId = new SelectList(db.Blogs, "Id", "Title");
            return View();
        }


        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create(int? BlogId, HttpPostedFileBase[] photoFiles, string[] isCover)
        {
            if (BlogId == null)
            {
                ModelState.AddModelError("BlogId", "Blog seçimi zorunludur.");
            }

            if (photoFiles == null || photoFiles.Length == 0 || photoFiles.All(f => f == null))
            {
                ModelState.AddModelError("", "En az bir fotoğraf seçmelisiniz.");
            }

            if (ModelState.IsValid)
            {
                string uploadPath = Server.MapPath("~/Uploads/BlogPhotos/");
                if (!Directory.Exists(uploadPath))
                {
                    Directory.CreateDirectory(uploadPath);
                }

                int photoIndex = 0;
                for (int i = 0; i < photoFiles.Length; i++)
                {
                    if (photoFiles[i] != null && photoFiles[i].ContentLength > 0)
                    {
                        string fileName = Guid.NewGuid().ToString() + Path.GetExtension(photoFiles[i].FileName);
                        string filePath = Path.Combine(uploadPath, fileName);
                        photoFiles[i].SaveAs(filePath);

                        // Kapak fotoğrafı kontrolü - checkbox index'ine göre
                        bool isCoverPhoto = isCover != null && isCover.Contains(photoIndex.ToString());

                        BlogPhotos blogPhoto = new BlogPhotos
                        {
                            BlogId = BlogId,
                            PhotoUrl = "/Uploads/BlogPhotos/" + fileName,
                            IsCover = isCoverPhoto,
                            CreatedDate = DateTime.Now,
                            IsActive = true
                        };

                        db.BlogPhotos.Add(blogPhoto);
                        photoIndex++;
                    }
                }

                db.SaveChanges();
                return RedirectToAction("List");
            }

            ViewBag.BlogId = new SelectList(db.Blogs, "Id", "Title", BlogId);
            return View();
        }

        // GET: BlogPhotos/Edit/5
        [CustomAuthorize(Roles = "Admin,User")]
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            BlogPhotos blogPhoto = db.BlogPhotos.Find(id);
            if (blogPhoto == null)
            {
                return HttpNotFound();
            }
            ViewBag.BlogId = new SelectList(db.Blogs, "Id", "Title", blogPhoto.BlogId);
            return View(blogPhoto);
        }

        // POST: BlogPhotos/Edit/5
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "Id,BlogId,PhotoUrl,IsCover,CreatedDate,IsActive")] BlogPhotos blogPhoto, HttpPostedFileBase photoFile)
        {
            if (ModelState.IsValid)
            {
                // Yeni fotoğraf yükleme işlemi
                if (photoFile != null && photoFile.ContentLength > 0)
                {
                    // Eski fotoğrafı sil
                    if (!string.IsNullOrEmpty(blogPhoto.PhotoUrl))
                    {
                        string oldFilePath = Server.MapPath(blogPhoto.PhotoUrl);
                        if (System.IO.File.Exists(oldFilePath))
                        {
                            System.IO.File.Delete(oldFilePath);
                        }
                    }

                    string uploadPath = Server.MapPath("~/Uploads/BlogPhotos/");
                    if (!Directory.Exists(uploadPath))
                    {
                        Directory.CreateDirectory(uploadPath);
                    }

                    string fileName = Guid.NewGuid().ToString() + Path.GetExtension(photoFile.FileName);
                    string filePath = Path.Combine(uploadPath, fileName);
                    photoFile.SaveAs(filePath);
                    blogPhoto.PhotoUrl = "/Uploads/BlogPhotos/" + fileName;
                }

                db.Entry(blogPhoto).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("List");
            }
            ViewBag.BlogId = new SelectList(db.Blogs, "Id", "Title", blogPhoto.BlogId);
            return View(blogPhoto);
        }


        [HttpPost]
        [ValidateAntiForgeryToken]
        [CustomAuthorize(Roles = "Admin,User")]
        public ActionResult Delete(int id)
        {
            BlogPhotos blogPhoto = db.BlogPhotos.Find(id);

            // Fotoğrafı sil
            if (!string.IsNullOrEmpty(blogPhoto.PhotoUrl))
            {
                string filePath = Server.MapPath(blogPhoto.PhotoUrl);
                if (System.IO.File.Exists(filePath))
                {
                    System.IO.File.Delete(filePath);
                }
            }

            db.BlogPhotos.Remove(blogPhoto);
            db.SaveChanges();
            return RedirectToAction("List");
        }

    }
}