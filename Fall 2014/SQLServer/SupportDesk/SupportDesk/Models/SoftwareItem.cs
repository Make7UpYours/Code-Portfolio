//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Manual changes to this file may cause unexpected behavior in your application.
//     Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace SupportDesk.Models
{
    using System;
    using System.Collections.Generic;
    
    public partial class SoftwareItem
    {
        public SoftwareItem()
        {
            this.Equipments = new HashSet<Equipment>();
        }
    
        public long ID { get; set; }
        public string Name { get; set; }
        public string Version { get; set; }
        public string Manufacturer { get; set; }
    
        public virtual ICollection<Equipment> Equipments { get; set; }
    }
}
