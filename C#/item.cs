using System.Diagnostics.CodeAnalysis;

namespace metric_cnv
{
   public struct Item
   {
      public string UnitName { get; }
      public Unit? Unit { get; }

      public Item()
      {
         UnitName = string.Empty;
         Unit = null;
      }

      public Item( string inUnitName, Unit inUnit )
      {
         UnitName = inUnitName;
         Unit = inUnit;
      }

      public static Item Empty => new Item();

      public bool IsEmpty => Unit is null;

      public override bool Equals( [NotNullWhen( true )] object? inObject )
      {
         return inObject as Item? == this;
      }

      public override int GetHashCode()
      {
         return UnitName.GetHashCode() | Unit.GetHashCode();
      }

      public static bool operator ==( Item inLeft, Item inRight ) 
      {
         return string.Compare( inLeft.UnitName, inRight.UnitName, true, System.Globalization.CultureInfo.InvariantCulture ) == 0;
      }

      public static bool operator !=( Item inLeft, Item inRight )
      {
         return string.Compare( inLeft.UnitName, inRight.UnitName, true, System.Globalization.CultureInfo.InvariantCulture ) != 0;
      }

      public static bool operator ==( Item inLeft, string inRight )
      {
         return string.Compare( inLeft.UnitName, inRight, true, System.Globalization.CultureInfo.InvariantCulture ) == 0;
      }

      public static bool operator !=( Item inLeft, string inRight )
      {
         return string.Compare( inLeft.UnitName, inRight, true, System.Globalization.CultureInfo.InvariantCulture ) != 0;
      }
   }
}