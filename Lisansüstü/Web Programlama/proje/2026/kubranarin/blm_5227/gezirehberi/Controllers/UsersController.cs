using GeziRehberi.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace GeziRehberi.Controllers
{
    public class UsersController : Controller
    {
        private GeziRehberiEntities db = new GeziRehberiEntities();

        [Authorize(Roles = "Admin")]
        public ActionResult List()
        {
            var users = db.Users.OrderByDescending(u => u.CreatedDate).ToList();
            return View(users);
        }
    }
}