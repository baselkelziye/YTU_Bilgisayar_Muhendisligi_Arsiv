using GeziRehberi.Helper;
using GeziRehberi.Models;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Diagnostics.Metrics;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using System.Windows.Forms;
namespace GeziRehberi.Controllers
{
    public class CountriesController : Controller
    {
      private GeziRehberiEntities db= new GeziRehberiEntities();
        [CustomAuthorize(Roles = "Admin")]
        public ActionResult List()
        {
            var countries = db.Countries.ToList();
            return View(countries);
        }
        [CustomAuthorize(Roles = "Admin")]
        public ActionResult Create()
        {
            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "Id,Name,CreatedDate,IsActive")] Countries country)
        {
            if (ModelState.IsValid)
            {
                country.CreatedDate = DateTime.Now;
                country.IsActive = true;             
                db.Countries.Add(country);
                db.SaveChanges();
                return RedirectToAction("List");
            }

            return View(country);
        }
        [CustomAuthorize(Roles = "Admin")]
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Countries country = db.Countries.Find(id);
            if (country == null)
            {
                return HttpNotFound();
            }
            return View(country);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "Id,Name,CreatedDate,IsActive")] Countries country)
        {
            if (ModelState.IsValid)
            {
                db.Entry(country).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("List");
            }
            return View(country);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Delete(int id)
        {
            Countries country = db.Countries.Find(id);
            db.Countries.Remove(country);
            db.SaveChanges();
            return RedirectToAction("List");
        }

 
    }
}