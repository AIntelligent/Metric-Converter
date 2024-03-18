//
#ifndef __LENGTHUNITS_H
#define __LENGTHUNITS_H

#define LIGHTSECONDS 299792458.0
#define LIGHTMINUTES (LIGHTSECONDS * 60.0)
#define LIGHTHOURS (LIGHTMINUTES * 60.0)
#define LIGHTDAYS (LIGHTHOURS * 24.0)
#define LIGHTYEAR (LIGHTDAYS * 365.2425) 
   
namespace LengthUnits
{	
   // Metric Units
   const TUnit Attometer( 0.000000000000000001, L"am" );
   const TUnit Femtometer( 0.000000000000001, L"fm" );
   const TUnit Pikometer( 0.000000000001, L"pm" );
   const TUnit Nanometer( 0.000000001, L"nm" );
   const TUnit Micrometer( 0.000001, L"mi" ); // μm
   const TUnit Millimeter( 0.001, L"mm" );
   const TUnit Centimeter( 0.01, L"cm" );
   const TUnit Decimeter( 0.1, L"dm" );
   const TUnit Meter( 1.0, L"m" );
   const TUnit Decameter( 10, L"dam" );
   const TUnit Hectometer( 100, L"hm" );
   const TUnit Kilometer( 1000, L"km" );
   const TUnit Megameter( 1000000, L"Mm" );
   const TUnit Gigameter( 1000000000, L"Gm" );
   const TUnit Terameter( 1000000000000, L"Tm" );
   const TUnit Petameter( 1000000000000000, L"Pm" );
   const TUnit Exameter( 1000000000000000000, L"Em" );
   
   // Imperial Units
   const TUnit Inch( 0.0254, L"in" );
   const TUnit Foot( 0.3048, L"ft" );
   const TUnit Yard( 0.9144, L"yd" );
   const TUnit Chain( 20.1168, L"ch" );
   const TUnit Furlong( 201.168, L"fur" );
   const TUnit Mile( 1609.344, L"mi" );
   const TUnit League( 4828.032, L"lea" );
   const TUnit Cubit( 0.4572, L"cu" );
   const TUnit NauticalLeague( 5559.552, L"Nlea" );

   // Light's Units
   const TUnit LightSeconds( LIGHTSECONDS, L"li:s" );
   const TUnit LightMinutes( LIGHTMINUTES, L"li:m");
   const TUnit LightHours( LIGHTHOURS, L"li:h");
   const TUnit LightDays( LIGHTDAYS, L"li:D" );
   const TUnit LightYear( LIGHTYEAR, L"li:Y" );
   
   // AstronomicalUnit
   const TUnit AstronomicalUnit( 1.495979E+11, L"AU" );
   
   // Other
   const TUnit Parsecs( 30856775814913672.789, L"pc" );
   const TUnit Rod( 5.0292, L"rod" );
   const TUnit Mil( 0.0000254, L"mil" );
   const TUnit NauticalMile( 1852, L"Nmi" );
   const TUnit Angstrom( 1E-10, L"an" );
   const TUnit Pole( 5.0292, L"po" );
   const TUnit Planck( 1.616049999E-35, L"p" );
   const TUnit BohrRadius( 5.29177249E-11, L"b,a.u." );
   const TUnit ElectronRadius( 2.81794092E-15, L"eR" );   
}

#endif