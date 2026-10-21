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
    public class CommentsController : Controller
    {
        private GeziRehberiEntities db = new GeziRehberiEntities();

        // GET: Comments
        public ActionResult List()
        {
            var comments = db.Comments.OrderByDescending(c => c.CreatedDate).ToList();
            ViewBag.Blogs = db.Blogs.ToList();
            ViewBag.Users = db.Users.ToList();
            return View(comments);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Approve(int id)
        {
            Comments comment = db.Comments.Find(id);
            if (comment != null)
            {
                comment.IsApproved = true;
                db.Entry(comment).State = EntityState.Modified;
                db.SaveChanges();
            }
            return RedirectToAction("List");
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Disapprove(int id)
        {
            Comments comment = db.Comments.Find(id);
            if (comment != null)
            {
                comment.IsApproved = false;
                db.Entry(comment).State = EntityState.Modified;
                db.SaveChanges();
            }
            return RedirectToAction("List");
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Delete(int id)
        {
            Comments comment = db.Comments.Find(id);
            db.Comments.Remove(comment);
            db.SaveChanges();
            return RedirectToAction("List");
        }

    }
}