unit LengthUnits;

interface

uses
  &Unit;

{$REGION ' Length Units '}

const
  LIGHT_SECONDS         = 299792458.0;
  LIGHT_MINUTES         = LIGHT_SECONDS * 60.0;
  LIGHT_HOURS           = LIGHT_MINUTES * 60.0;
  LIGHT_DAYS            = LIGHT_HOURS * 24.0;
  LIGHT_YEARS           = LIGHT_SECONDS * LIGHT_DAYS * 365.2425;

{$REGION ' Metric Units '}
  Attometer             : TUnit = (Factor : 0.000000000000000001;       Symbol : 'am');
  Femtometer            : TUnit = (Factor : 0.000000000000001;          Symbol : 'fm');
  Pikometer             : TUnit = (Factor : 0.000000000001;             Symbol : 'pm');
  Nanometer             : TUnit = (Factor : 0.000000001;                Symbol : 'nm');
  Micrometer            : TUnit = (Factor : 0.000001;                   Symbol : 'mi');
  Millimeter            : TUnit = (Factor : 0.001;                      Symbol : 'mm');
  Centimeter            : TUnit = (Factor : 0.01;                       Symbol : 'cm');
  Decimeter             : TUnit = (Factor : 0.1;                        Symbol : 'dm');
  Meter                 : TUnit = (Factor : 1.0;                        Symbol : 'm');
  Decameter             : TUnit = (Factor : 10.0;                       Symbol : 'dam');
  Hectometer            : TUnit = (Factor : 100.0;                      Symbol : 'hm');
  Kilometer             : TUnit = (Factor : 1000.0;                     Symbol : 'km');
  Megameter             : TUnit = (Factor : 1000000.0;                  Symbol : 'Mm');
  Gigameter             : TUnit = (Factor : 1000000000.0;               Symbol : 'Gm');
  Terameter             : TUnit = (Factor : 1000000000000.0;            Symbol : 'Tm');
  Petameter             : TUnit = (Factor : 1000000000000000.0;         Symbol : 'Pm');
  Exameter              : TUnit = (Factor : 1000000000000000000.0;      Symbol : 'Em');
{$ENDREGION}

{$REGION ' Imperial Units '}
  Inch                  : TUnit = (Factor : 0.0254;                     Symbol : 'in');
  Foot                  : TUnit = (Factor : 0.3048;                     Symbol : 'ft');
  Yard                  : TUnit = (Factor : 0.9144;                     Symbol : 'yd');
  Chain                 : TUnit = (Factor : 20.1168;                    Symbol : 'ch');
  Furlong               : TUnit = (Factor : 201.168;                    Symbol : 'fur');
  Mile                  : TUnit = (Factor : 1609.344;                   Symbol : 'mi');
  League                : TUnit = (Factor : 4828.032;                   Symbol : 'lea');
  Cubit                 : TUnit = (Factor : 0.4572;                     Symbol : 'cu');
  NauticalLeague        : TUnit = (Factor : 5559.552;                   Symbol : 'Nlea');
{$ENDREGION}

{$REGION ' Light's Unit '}
  LightSeconds          : TUnit = (Factor : LIGHT_SECONDS;              Symbol : 'li:s');
  LightMinutes          : TUnit = (Factor : LIGHT_MINUTES;              Symbol : 'li:m');
  LightHours            : TUnit = (Factor : LIGHT_HOURS;                Symbol : 'li:h');
  LightDays             : TUnit = (Factor : LIGHT_DAYS;                 Symbol : 'li:D');
  LightYears            : TUnit = (Factor : LIGHT_YEARS;                Symbol : 'li:Y');
{$ENDREGION}

{$REGION ' Astronomical Unit '}
  AstronomicalUnit      : TUnit = (Factor : 1.495979E+11;               Symbol : 'AU');
{$ENDREGION}

{$REGION ' Other Units '}
  Parsecs               : TUnit = (Factor : 30856775812799588.0;        Symbol : 'pc');
  Rod                   : TUnit = (Factor : 5.0292;                     Symbol : 'rod');
  Mil                   : TUnit = (Factor : 0.0000254;                  Symbol : 'mil');
  NauticalMile          : TUnit = (Factor : 1852.0;                     Symbol : 'Nmi');
  Angstrom              : TUnit = (Factor : 1E-10;                      Symbol : 'an');
  Pole                  : TUnit = (Factor : 5.0292;                     Symbol : 'po');
  Planck                : TUnit = (Factor : 1.616049999E-35;            Symbol : 'p');
  BohrRadius            : TUnit = (Factor : 5.29177249E-11;             Symbol : 'b,a.u.');
  ElectronRadius        : TUnit = (Factor : 2.81794092E-15;             Symbol : 'eR');
{$ENDREGION}

{$ENDREGION}

implementation

end.
