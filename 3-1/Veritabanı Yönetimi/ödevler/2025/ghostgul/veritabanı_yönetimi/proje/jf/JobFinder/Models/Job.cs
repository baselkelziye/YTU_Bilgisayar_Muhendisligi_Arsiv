using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;

namespace JobFinder.Models;

public partial class Job
{
    public int JobId { get; set; }

    public string CompanyName { get; set; } = null!;

    public string Position { get; set; } = null!;

    public string Description { get; set; } = null!;

    public DateOnly OpeningDate { get; set; }

    public int ApplicationCount { get; set; }

	[NotMapped]
	public string JobName => CompanyName+ "(" + Position + ")";
    public virtual ICollection<Application> Applications { get; set; } = new List<Application>();
}
