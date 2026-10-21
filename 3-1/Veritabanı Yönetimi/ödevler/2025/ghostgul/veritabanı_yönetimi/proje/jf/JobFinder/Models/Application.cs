using System;
using System.Collections.Generic;

namespace JobFinder.Models;

public partial class Application
{
    public int ApplicationId { get; set; }

    public int? UserId { get; set; }

    public int? JobId { get; set; }

    public DateOnly? ApplicationDate { get; set; }

    public virtual Job? Job { get; set; }

    public virtual User? User { get; set; }
}
