namespace metric_cnv
{
   public static class LengthUnits
   {
      public const double
         LIGHT_SECONDS = 299792458.0,
         LIGHT_MINUTES = LIGHT_SECONDS * 60.0,
         LIGHT_HOURS = LIGHT_MINUTES * 60.0,
         LIGHT_DAYS = LIGHT_HOURS * 24.0,
         LIGHT_YEAR = LIGHT_DAYS * 365.2425;
      public static readonly Unit
         // Metric Units
         Attometer = new Unit( 0.000000000000000001, "am" ),
         Femtometer = new Unit( 0.000000000000001, "fm" ),
         Pikometer = new Unit( 0.000000000001, "pm" ),
         Nanometer = new Unit( 0.000000001, "nm" ),
         Micrometer = new Unit( 0.000001, "mi" ), // μm
         Millimeter = new Unit( 0.001, "mm" ),
         Centimeter = new Unit( 0.01, "cm" ),
         Decimeter = new Unit( 0.1, "dm" ),
         Meter = new Unit( 1.0, "m" ),
         Decameter = new Unit( 10, "dam" ),
         Hectometer = new Unit( 100, "hm" ),
         Kilometer = new Unit( 1000, "km" ),
         Megameter = new Unit( 1000000, "Mm" ),
         Gigameter = new Unit( 1000000000, "Gm" ),
         Terameter = new Unit( 1000000000000, "Tm" ),
         Petameter = new Unit( 1000000000000000, "Pm" ),
         Exameter = new Unit( 1000000000000000000, "Em" ),
         // Imperial Units
         Inch = new Unit( 0.0254, "in" ),
         Foot = new Unit( 0.3048, "ft" ),
         Yard = new Unit( 0.9144, "yd" ),
         Chain = new Unit( 20.1168, "ch" ),
         Furlong = new Unit( 201.168, "fur" ),
         Mile = new Unit( 1609.344, "mi" ),
         League = new Unit( 4828.032, "lea" ),
         Cubit = new Unit( 0.4572, "cu" ),
         NauticalLeague = new Unit( 5559.552, "Nlea" ),
         // Light's Units
         LightSeconds = new Unit( LIGHT_SECONDS, "li:s" ),
         LightMinutes = new Unit( LIGHT_MINUTES, "li:m"),
         LightHours = new Unit( LIGHT_HOURS, "li:h"),
         LightDays = new Unit( LIGHT_DAYS, "li:D" ),
         LightYear = new Unit( LIGHT_YEAR, "li:Y" ),
         // AstronomicalUnit
         AstronomicalUnit = new Unit( 1.495979E+11, "AU" ),
         // Other
         Parsecs = new Unit( 30856775814913672.789, "pc" ),
         Rod = new Unit( 5.0292, "rod" ),
         Mil = new Unit( 0.0000254, "mil" ),
         NauticalMile = new Unit( 1852, "Nmi" ),
         Angstrom = new Unit( 1E-10, "an" ),
         Pole = new Unit( 5.0292, "po" ),
         Planck = new Unit( 1.616049999E-35, "p" ),
         BohrRadius = new Unit( 5.29177249E-11, "b,a.u." ),
         ElectronRadius = new Unit( 2.81794092E-15, "eR" )
         ;
   }
}