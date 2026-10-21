using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Security;

namespace GeziRehberi.Helper
{
    public class CustomAuthorizeAttribute : AuthorizeAttribute
    {
        protected override bool AuthorizeCore(HttpContextBase httpContext)
        {
            // Session kontrolü
            if (httpContext.Session["UserId"] == null)
            {
                return false;
            }

            // Role kontrolü
            if (!string.IsNullOrEmpty(Roles))
            {
                string userRole = httpContext.Session["Role"]?.ToString();
                if (string.IsNullOrEmpty(userRole))
                {
                    return false;
                }

                // Roles virgülle ayrılmış rol listesi olabilir (örn: "Admin,User")
                string[] allowedRoles = Roles.Split(new char[] { ',' }, StringSplitOptions.RemoveEmptyEntries);
                foreach (string role in allowedRoles)
                {
                    if (userRole.Trim().Equals(role.Trim(), StringComparison.OrdinalIgnoreCase))
                    {
                        return true;
                    }
                }

                return false;
            }


            return true;
        }

        protected override void HandleUnauthorizedRequest(AuthorizationContext filterContext)
        {
            if (filterContext.HttpContext.Session["UserId"] == null)
            {
                // Giriş yapmamış, login sayfasına yönlendir
                filterContext.Result = new RedirectResult("~/Account/Login");
            }
            else
            {
                // Giriş yapmış ama yetkisi yok, erişim reddedildi sayfasına yönlendir
                filterContext.Result = new RedirectResult("~/Account/AccessDenied");
            }
        }
    }
}
