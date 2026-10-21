using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace GeziRehberi.Models
{
    public class BlogCardViewModel
    {       
       public int Id { get; set; }
       public string Title { get; set; }
       public DateTime? CreatedDate { get; set; }
       public string Article { get; set; }
       public string Author { get; set; }
       public string CoverPhoto { get; set; }

    }
}