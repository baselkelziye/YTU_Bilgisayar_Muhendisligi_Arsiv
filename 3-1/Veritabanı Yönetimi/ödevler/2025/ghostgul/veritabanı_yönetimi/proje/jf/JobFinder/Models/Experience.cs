using System;
using System.Collections.Generic;

namespace JobFinder.Models;

public partial class Experience
{
    public int ExperienceId { get; set; }

    public int? UserId { get; set; }

    public string CompanyName { get; set; } = null!;

    public string Position { get; set; } = null!;

    public DateOnly StartDate { get; set; }

    public DateOnly? EndDate { get; set; }

    public string? Description { get; set; }

    public virtual User? User { get; set; }
}
