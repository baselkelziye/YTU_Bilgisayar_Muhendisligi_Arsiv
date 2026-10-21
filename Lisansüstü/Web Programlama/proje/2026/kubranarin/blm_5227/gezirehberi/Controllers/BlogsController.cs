using GeziRehberi.Helper;
using GeziRehberi.Models;
using GeziRehberi.Models;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;

namespace GeziRehberi.Controllers
{
    public class BlogsController : Controller
    {
        private GeziRehberiEntities db = new GeziRehberiEntities();
        public  List<Blogs> blogs = new List<Blogs>();
        // GET: Blogs
        [CustomAuthorize(Roles = "Admin,User")]
        public ActionResult List()
        {
            var userId = Convert.ToInt32(Session["UserId"]);
            var userRole = Session["Role"];
            if (userRole == "Admin")
            {
                blogs = db.Blogs.ToList();
            }
            else
            {
                blogs = db.Blogs.Where(b => b.UserId.Value == userId).ToList();
            }    
            ViewBag.Places = db.Places.ToList();
            ViewBag.Users = db.Users.ToList();
            return View(blogs);
        }

        // GET: Blogs/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Blogs blog = db.Blogs.Find(id);
            if (blog == null)
            {
                return HttpNotFound();
            }
            return View(blog);
        }
        [CustomAuthorize(Roles = "Admin,User")]
        // GET: Blogs/Create
        public ActionResult Create()
        {
            ViewBag.PlaceId = new SelectList(db.Places, "Id", "Name");
            ViewBag.UserId = new SelectList(db.Users, "Id", "Name");
            return View();
        }

        // POST: Blogs/Create
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "Id,PlaceId,UserId,Title,Article,Status,ViewCount,CreatedDate,IsActive")] Blogs blog)
        {
            if (ModelState.IsValid)
            {
                blog.CreatedDate = DateTime.Now;
                if (blog.ViewCount == null)
                {
                    blog.ViewCount = 0;
                }
                db.Blogs.Add(blog);
                db.SaveChanges();
                return RedirectToAction("List");
            }
            ViewBag.PlaceId = new SelectList(db.Places, "Id", "Name", blog.PlaceId);
            ViewBag.UserId = new SelectList(db.Users, "Id", "Name", blog.UserId);
            return View(blog);
        }
        [CustomAuthorize(Roles = "Admin,User")]
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Blogs blog = db.Blogs.Find(id);
            if (blog == null)
            {
                return HttpNotFound();
            }
            ViewBag.PlaceId = new SelectList(db.Places, "Id", "Name", blog.PlaceId);
            ViewBag.UserId = new SelectList(db.Users, "Id", "Name", blog.UserId);
            return View(blog);
        }


        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "Id,PlaceId,UserId,Title,Article,Status,ViewCount,CreatedDate,IsActive")] Blogs blog)
        {
            if (ModelState.IsValid)
            {
                db.Entry(blog).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("List");
            }
            ViewBag.PlaceId = new SelectList(db.Places, "Id", "Name", blog.PlaceId);
            ViewBag.UserId = new SelectList(db.Users, "Id", "Name", blog.UserId);
            return View(blog);
        }

        // POST: Blogs/Delete/5
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Delete(int id)
        {
            Blogs blog = db.Blogs.Find(id);
            db.Blogs.Remove(blog);
            db.SaveChanges();
            return RedirectToAction("List");
        }

    }
}