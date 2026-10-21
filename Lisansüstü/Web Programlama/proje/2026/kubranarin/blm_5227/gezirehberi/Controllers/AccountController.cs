using GeziRehberi.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Web;
using System.Web.Mvc;

namespace GeziRehberi.Controllers
{
    public class AccountController : Controller
    {
   
        public ActionResult Register()
        {
            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Register(Users model)
        {
            if (ModelState.IsValid)
            {
                try
                {
                    using (var db = new GeziRehberiEntities())
                    {
             
                        if (db.Users.Any(u => u.Email == model.Email || u.Username == model.Username))
                        {
                            ModelState.AddModelError("", "Bu kullanıcı zaten kayıtlı.");
                            return View(model);
                        }

                        string hashedPassword = HashPassword(model.Password);
                        var user = new Users
                        {
                            Username = model.Username,
                            Email = model.Email,
                            Name = model.Name,
                            Surname = model.Surname,
                            CreatedDate = DateTime.Now,
                            IsActive = true,
                            Password = model.Password,
                            Role = 2 // Varsayılan rol: Kullanıcı
                        };

                        db.Users.Add(user);
                        db.SaveChanges();

                        TempData["SuccessMessage"] = "Kayıt İşleminiz Başarılı! Giriş Yapabilirsiniz.";
                        return RedirectToAction("Login", "Account");
                    }
                }
                catch (Exception ex)
                {
                    ModelState.AddModelError("", "Kayıt esnasında bir hata oluştu!. Lütfen sonra tekrar deneyin.");
              
                }
            }

            return View(model);
        }

        private string HashPassword(string password)
        {
            using (SHA256 sha256Hash = SHA256.Create())
            {
       
                byte[] bytes = sha256Hash.ComputeHash(Encoding.UTF8.GetBytes(password));

                StringBuilder builder = new StringBuilder();
                for (int i = 0; i < bytes.Length; i++)
                {
                    builder.Append(bytes[i].ToString("x2"));
                }
                return builder.ToString();
            }
        }

        public ActionResult Login()
        {
            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Login(Users model)
        {
            if (ModelState.IsValid)
            {
                try
                {
                    using (var db = new GeziRehberiEntities())
                    {
                 
                        var user = db.Users.FirstOrDefault(u =>
                            (u.Username == model.Username || u.Email == model.Username) &&
                            u.IsActive == true
                        );
           
                        if (user != null)
                        {
                            if (user.Password != model.Password)
                            {
                                ModelState.AddModelError("", "Geçersiz kullanıcı adı veya şifre!");
                                return View(model);
                            }
                            else
                            {
                                string roleString = user.Role == 1 ? "Admin" :  user.Role == 2 ? "User" :   "";
                                Session["UserId"] = user.Id;
                                Session["Username"] = user.Username;
                                Session["Email"] = user.Email;
                                Session["Role"] = roleString;

                                TempData["SuccessMessage"] = "Giriş Başarılı! Hoşgeldiniz!";
                                return RedirectToAction("Index", "Home");
                            }
                              
                        }
                        else
                        {
                            ModelState.AddModelError("", "Kullanıcı Bulunamadı.");
                        }
                    }
                }
                catch (Exception ex)
                {
                    ModelState.AddModelError("", "Giriş yaparken hata oluştu!. Lütfen tekrar deneyin!");
            
                }
            }

            return View(model);
        }

        public ActionResult Logout()
        {
            Session.Clear();
            Session.Abandon();
            TempData["SuccessMessage"] = "Başarıyla çıkış yaptınız.";
            return RedirectToAction("Login", "Account");
        }

    }
}



