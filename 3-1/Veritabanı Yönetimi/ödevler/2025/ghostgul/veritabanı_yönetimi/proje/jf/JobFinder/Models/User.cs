using System;
using System.Collections.Generic;

namespace JobFinder.Models;

public partial class User
{
    public int UserId { get; set; }

    public string Username { get; set; } = null!;

    public string Password { get; set; } = null!;

    public string FullName { get; set; } = null!;

    public string Email { get; set; } = null!;

    public int? ExperienceYears { get; set; }

    public string? Education { get; set; }

    public string Phone { get; set; } = null!;

    public string Address { get; set; } = null!;

    public bool? Status { get; set; }

    public virtual ICollection<Application> Applications { get; set; } = new List<Application>();

    public virtual ICollection<Experience> Experiences { get; set; } = new List<Experience>();
}
