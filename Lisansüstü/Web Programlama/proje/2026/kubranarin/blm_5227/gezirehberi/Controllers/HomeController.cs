using GeziRehberi.Helper;
using GeziRehberi.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace GeziRehberi.Controllers
{
    public class HomeController : Controller
    {
        private GeziRehberiEntities db = new GeziRehberiEntities();

        [CustomAuthorize(Roles = "Admin,User")]
        public ActionResult Index()
        {
            var countries = db.Countries.ToList();
            ViewBag.Countries = countries;
            var blogs =
              (from b in db.Blogs
               join u in db.Users on b.UserId equals u.Id into gu
               from u in gu.DefaultIfEmpty()              // ← LEFT JOIN
               join p in db.BlogPhotos on b.Id equals p.BlogId into gp
               from photo in gp.OrderBy(p => p.Id).Take(1).DefaultIfEmpty()
               orderby b.CreatedDate descending
               select new BlogCardViewModel
               {
                   Id = b.Id,
                   Title = b.Title,
                   CreatedDate = b.CreatedDate,
                   Article = b.Article,
                   Author = (u != null ? (u.Name + " " + u.Surname) : "Admin"),
                   CoverPhoto = photo != null ? photo.PhotoUrl : null
               })
              .Take(12)
              .ToList();


            return View(blogs);
        }
        public ActionResult Detail(int id)
        {
            var blog =
        (from b in db.Blogs
         join u in db.Users on b.UserId equals u.Id into gu
         from u in gu.DefaultIfEmpty()
         join p in db.BlogPhotos on b.Id equals p.BlogId into gp
         from photo in gp.OrderBy(p => p.Id).Take(1).DefaultIfEmpty()

         where b.Id == id

         select new BlogCardViewModel
         {
             Id = b.Id,
             Title = b.Title,
             CreatedDate = b.CreatedDate,
             Article = b.Article,
             Author = (u != null ? (u.Name + " " + u.Surname) : "Admin"),
             CoverPhoto = photo != null ? photo.PhotoUrl : null
         })
        .FirstOrDefault();

            if (blog == null)
                return HttpNotFound();

            return View(blog);
        }

        public ActionResult GetCities(int countryId)
        {
            var cities = db.Cities
                           .Where(x => x.CountryId == countryId)
                           .Select(x => new
                           {
                               x.Id,
                               x.Name
                           })
                           .ToList();

            return Json(cities, JsonRequestBehavior.AllowGet);
        }  
        public JsonResult SearchBlogs(int? countryId, int? cityId)
        {
            var blogs =
            (from b in db.Blogs
             join pl in db.Places on b.PlaceId equals pl.Id
             join ct in db.Cities on pl.CityId equals ct.Id
             join u in db.Users on b.UserId equals u.Id into gu
             from u in gu.DefaultIfEmpty()
             join p in db.BlogPhotos on b.Id equals p.BlogId into gp
             from photo in gp.OrderBy(p => p.Id).Take(1).DefaultIfEmpty()

             where (!countryId.HasValue || ct.CountryId == countryId)
                && (!cityId.HasValue || pl.CityId == cityId)

             orderby b.CreatedDate descending

             select new BlogCardViewModel
             {
                 Id = b.Id,
                 Title = b.Title,
                 Article = b.Article,
                 CreatedDate = b.CreatedDate,
                 Author = (u != null ? (u.Name + " " + u.Surname) : "Admin"),
                 CoverPhoto = photo != null ? photo.PhotoUrl : null
             })
            .ToList();


            return Json(blogs, JsonRequestBehavior.AllowGet);
        }


    }
}