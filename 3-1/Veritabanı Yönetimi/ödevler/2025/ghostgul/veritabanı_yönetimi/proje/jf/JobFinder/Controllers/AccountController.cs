using System.Data.Common;
using System.Data;
using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;
using JobFinder.Models;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Primitives;
using Microsoft.IdentityModel.Tokens;
using Newtonsoft.Json;
using Microsoft.Data.SqlClient;
using Npgsql;
using Newtonsoft.Json.Linq;

namespace JobFinder.Controllers
{
	public class AccountController : Controller
	{

		private readonly PostgresContext _context;

		public AccountController(PostgresContext context)
		{
			_context = context;
		}

		public IActionResult Index()
		{
			Request.Cookies.TryGetValue("User", out string? cookieValue);
			if (string.IsNullOrEmpty(cookieValue))
			{
				return NotFound();
			}
			var logedIn = JsonConvert.DeserializeObject<User>(cookieValue);
			if (logedIn == null)
			{
				return NotFound();
			}

			var user = _context.Users.FromSqlRaw("Select * from jobfinder.users Where user_id ={0}", logedIn.UserId).FirstOrDefault();
			user.Applications = _context.Applications.FromSqlRaw("select * from jobfinder.get_user_applications({0})", logedIn.UserId).ToList();
			foreach (var app in user.Applications)
			{
				app.Job = _context.Jobs.FromSqlRaw("Select * from jobfinder.jobs Where job_id ={0}", app.JobId).FirstOrDefault();
			}
			user.Experiences = _context.Experiences.FromSqlRaw("Select * from jobfinder.experiences Where user_id ={0}", logedIn.UserId).ToList();

			var customQuery = "SELECT COUNT(a.application_id) " +
				  "FROM jobfinder.users u JOIN jobfinder.applications a ON u.user_id = a.user_id " +
				  "WHERE u.user_id = @id " +
				  "GROUP BY u.user_id HAVING COUNT(a.application_id) >= 1";
			
			var result = QueryScalar(customQuery, new List<NpgsqlParameter> { new NpgsqlParameter("@id", SqlDbType.Int) { Value = logedIn.UserId } });
			if(result != null)
				ViewData["ApplicationCount"] = Convert.ToInt32(result);

			ViewData["Contacts"] = _context.Database.SqlQueryRaw<StringResult>("select * from jobfinder.contact_companies({0})", logedIn.UserId).ToList().Select(x => x.Result);

			return View(user);
		}

		public object Query(string sql, List<NpgsqlParameter> paramList)
		{
			object value;
			DbConnection connection = _context.Database.GetDbConnection();

			using (DbCommand cmd = connection.CreateCommand())
			{

				cmd.CommandText = sql;
				foreach (var param in paramList)
					cmd.Parameters.Add(param);

				if (connection.State.Equals(ConnectionState.Closed))
				{
					connection.Open();
				}

				value = cmd.ExecuteReader();
			}

			if (connection.State.Equals(ConnectionState.Open))
			{
				connection.Close();
			}
			return value;
		}
		public object QueryScalar(string sql, List<NpgsqlParameter> paramList)
		{
			object value;
			DbConnection connection = _context.Database.GetDbConnection();

			using (DbCommand cmd = connection.CreateCommand())
			{

				cmd.CommandText = sql;
				foreach (var param in paramList)
					cmd.Parameters.Add(param);

				if (connection.State.Equals(ConnectionState.Closed))
				{
					connection.Open();
				}

				value = cmd.ExecuteScalar();
			}

			if (connection.State.Equals(ConnectionState.Open))
			{
				connection.Close();
			}
			return value;
		}

		public async Task<IActionResult> Search()
		{
			return View(await _context.Jobs.FromSqlRaw("Select * from jobfinder.jobs").ToListAsync());
		}

		[HttpPost]
		public async Task<IActionResult> SearchText()
		{
			string text = Request.Form["text"];
			if (string.IsNullOrEmpty(text))
				return RedirectToAction("Search");

			//var result = await _context.Jobs.Where(x => x.CompanyName.Contains(text) || x.Position.Contains(text) || x.Description.Contains(text)).ToListAsync();
			var result = await _context.Jobs.FromSqlRaw("SELECT * FROM jobfinder.search_jo	bs({0})", text).ToListAsync();

			return View("Search", result);
		}

		public async Task<IActionResult> Logout()
		{
			Response.Cookies.Delete("UserToken");
			Response.Cookies.Delete("User");
			return RedirectToAction("Index", "Home");
		}

		[HttpPost]
		[ValidateAntiForgeryToken]
		public async Task<IActionResult> Login([Bind("Username,Password")] LoginRequest user)
		{
			if (ModelState.IsValid)
			{
				var loggedIn = _context.Users.FromSqlRaw("Select * from jobfinder.active_users u where u.Username = {0} and u.Password = {1}", user.Username, user.Password, true).FirstOrDefault();
				if (loggedIn == null)
				{
					ViewData["LoginError"] = "Invalid username or password";
					return RedirectToAction("Index", "Home");
				}

				var claims = new[] {
					new Claim(ClaimTypes.NameIdentifier,loggedIn.Username),
					new Claim(ClaimTypes.Email,loggedIn.Email),
					new Claim(ClaimTypes.GivenName,loggedIn.FullName),
					new Claim(ClaimTypes.Role,"Standart")
				};

				var token = new JwtSecurityToken
				(
					claims: claims,
					expires: DateTime.UtcNow.AddHours(1),
					notBefore: DateTime.UtcNow,
					signingCredentials: new SigningCredentials(new SymmetricSecurityKey(Encoding.UTF8.GetBytes("SecretSecretSecretSecretSecret12")), SecurityAlgorithms.HmacSha256)
				);

				var tokenString = new JwtSecurityTokenHandler().WriteToken(token);
				Response.Cookies.Append("User", JsonConvert.SerializeObject(loggedIn, settings: new JsonSerializerSettings { ReferenceLoopHandling = ReferenceLoopHandling.Ignore }));
				Response.Cookies.Append("UserToken", tokenString, new CookieOptions
				{
					Expires = DateTimeOffset.Now.AddHours(1),
					HttpOnly = false,
					Secure = false
				});

				return RedirectToAction(nameof(Index));
			}
			return RedirectToAction("Index", "Home");
		}

		public async Task<IActionResult> JobDetail(int? id)
		{
			if (id == null)
			{
				return NotFound();
			}

			var job = await _context.Jobs.FromSqlRaw("Select * from jobfinder.jobs Where job_id = {0}", id).FirstOrDefaultAsync();

			if (job == null)
			{
				return NotFound();
			}

			return View(job);
		}

		[HttpPost]
		public async Task<IActionResult> Apply(int? jobId)
		{
			if (jobId == null)
			{
				return NotFound();
			}
			Request.Cookies.TryGetValue("User", out string? cookieValue);
			var user = JsonConvert.DeserializeObject<User>(cookieValue);
			var app = await _context.Applications.FromSqlRaw("Select * from jobfinder.applications Where job_id = {0} and user_id= {1} ", jobId, user.UserId).FirstOrDefaultAsync();
			if (app == null)
			{
				_context.Database.ExecuteSqlRaw("Insert into jobfinder.application(user_id,job_id,application_date) values({0},{1},{2})", user.UserId, jobId, DateOnly.FromDateTime(DateTime.Now));
				_context.SaveChanges();
			}
			return RedirectToAction("Index", "Account");
		}

		public IActionResult AddExperience()
		{
			return View();
		}

		[HttpPost]
		[ValidateAntiForgeryToken]
		public async Task<IActionResult> AddExperience([Bind("ExperienceId,UserId,CompanyName,Position,StartDate,EndDate,Description")] Experience experience)
		{
			Request.Cookies.TryGetValue("User", out string? cookieValue);
			if (string.IsNullOrEmpty(cookieValue))
			{
				return NotFound();
			}
			var user = JsonConvert.DeserializeObject<User>(cookieValue);

			experience.UserId = user.UserId;
			if (ModelState.IsValid)
			{
				try
				{
					_context.Database.ExecuteSqlRaw("Insert into jobfinder.experiences(user_id, company_name, position, start_date, end_date, description) values({0}, {1}, {2}, {3}, {4}, {5})",
						experience.UserId, experience.CompanyName, experience.Position, experience.StartDate, experience.EndDate, experience.Description);
					await _context.SaveChangesAsync();
				}
				catch (DbUpdateConcurrencyException ex)
				{

				}
				return RedirectToAction(nameof(Index));
			}
			return View(experience);
		}

		public async Task<IActionResult> Edit()
		{
			Request.Cookies.TryGetValue("User", out string? cookieValue);
			if (string.IsNullOrEmpty(cookieValue))
			{
				return NotFound();
			}
			var user = JsonConvert.DeserializeObject<User>(cookieValue);

			if (user == null)
			{
				return NotFound();
			}
			return View(user);
		}

		[HttpPost]
		[ValidateAntiForgeryToken]
		public async Task<IActionResult> Edit(int id, [Bind("UserId,Username,Password,FullName,Email,ExperienceYears,Education,Phone,Address")] User user)
		{
			if (id != user.UserId)
			{
				return NotFound();
			}

			if (ModelState.IsValid)
			{
				try
				{
					_context.Database.ExecuteSqlRaw("Update jobfinder.users set Username = {1}, Password = {2},Full_Name = {3},Email = {4},Experience_Years = {5},Education = {6},Phone = {7},Address = {8} Where user_id = {0}", user.UserId, user.Username, user.Password, user.FullName, user.Email, user.ExperienceYears, user.Education, user.Phone, user.Address);
					await _context.SaveChangesAsync();

					Response.Cookies.Delete("User");
					Response.Cookies.Append("User", JsonConvert.SerializeObject(user, settings: new JsonSerializerSettings { ReferenceLoopHandling = ReferenceLoopHandling.Ignore }));
				}
				catch (DbUpdateConcurrencyException)
				{

				}
				return RedirectToAction(nameof(Index));
			}
			return View(user);
		}

		public async Task<IActionResult> EditExperience(int? id)
		{
			if (id == null)
			{
				return NotFound();
			}

			var experience = await _context.Experiences.FromSqlRaw("Select * from jobfinder.experiences Where experience_id = {0}", id).FirstOrDefaultAsync();

			if (experience == null)
			{
				return NotFound();
			}
			return View(experience);
		}

		[HttpPost]
		[ValidateAntiForgeryToken]
		public async Task<IActionResult> EditExperience(int id, [Bind("ExperienceId,UserId,CompanyName,Position,StartDate,EndDate,Description")] Experience experience)
		{
			if (id != experience.ExperienceId)
			{
				return NotFound();
			}

			if (ModelState.IsValid)
			{
				try
				{
					_context.Database.ExecuteSqlRaw("Update jobfinder.experiences set user_id = {1}, company_name = {2},position = {3},start_date = {4},end_date = {5},description = {6} Where experience_id = {0}",
						experience.ExperienceId, experience.UserId, experience.CompanyName, experience.Position, experience.StartDate, experience.EndDate, experience.Description);
					await _context.SaveChangesAsync();
				}
				catch (DbUpdateConcurrencyException ex)
				{

				}
				return RedirectToAction(nameof(Index));
			}
			return View(experience);
		}

		public async Task<IActionResult> Cancel(int? id)
		{
			if (id == null)
			{
				return NotFound();
			}

			var application = await _context.Applications.FromSqlRaw("Select * from jobfinder.applications Where application_id = {0}", id).FirstOrDefaultAsync();
			application.Job = await _context.Jobs.FromSqlRaw("Select * from jobfinder.jobs Where job_id = {0}", application.JobId).FirstOrDefaultAsync();
			application.User = await _context.Users.FromSqlRaw("Select * from jobfinder.users Where user_id = {0}", application.UserId).FirstOrDefaultAsync();
			if (application == null)
			{
				return NotFound();
			}

			return View(application);
		}

		[HttpPost, ActionName("Cancel")]
		[ValidateAntiForgeryToken]
		public async Task<IActionResult> CancelConfirmed(int id)
		{
			var application = await _context.Applications.FromSqlRaw("Select * from jobfinder.applications Where application_id = {0}", id).FirstOrDefaultAsync();

			if (application != null)
			{
				var job = await _context.Jobs.FromSqlRaw("Select * from jobfinder.jobs Where job_id = {0}", application.JobId).FirstOrDefaultAsync();
				job.ApplicationCount--;
				if (job.ApplicationCount < 0)
					job.ApplicationCount = 0;

				_context.Database.ExecuteSqlRaw("Update jobfinder.jobs set application_count ={1} Where job_id = {0}", job.JobId, job.ApplicationCount);

				_context.Database.ExecuteSqlRaw("Delete from jobfinder.applications Where application_id = {0}", id);
			}

			await _context.SaveChangesAsync();
			return RedirectToAction(nameof(Index));
		}
	}
}
