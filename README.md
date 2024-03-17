# METRIC LENGTH UNIT CONVERTER (metric_cnv), Version 1.0

The example program was written by Hakan E. Kartal in 2024 using C++
https://github.com/AIntelligent, hek@nula.com.tr

# What does it to?

        This program converts the specified length unit measurement value to other length unit values.

# How to usage:

        metric_cnv -S[--source]:[Source Unit] -V[--value]:[Value] -t[--target]:[Target Unit] -H|--help

# Parameters:

        -S[--source]: Source Unit (see: Defined Units)
        -V[--value]: Value (etc: 3.14)
        -T[--target]: Target Unit (see: Defined Units)
        -H[--help]: This screen

# Defined Units:

        Attometer (am)                  Femtometer (fm)                 Pikometer (pm)
        Nanometer (nm)                  Micrometer (mi)                 Millimeter (mm)
        Centimeter (cm)                 Decimeter (dm)                  Meter (m)
        Decameter (dam)                 Hectometer (hm)                 Kilometer (km)
        Megameter (Mm)                  Gigameter (Gm)                  Terameter (Tm)
        Petameter (Pm)                  Exameter (Em)                   Inch (in)
        Foot (ft)                       Yard (yd)                       Chain (ch)
        Furlong (fur)                   Mile (mi)                       League (lea)
        Cubit (cu)                      NauticalLeague (Nlea)           LightSeconds (li:s)
        LightMinutes (li:m)             LightHours (li:h)               LightDays (li:D)
        LightYears (li:Y)               AstronomicalUnit (AU)           Parsecs (pc)
        Rod (rod)                       Mil (mil)                       NauticalMile (Nmi)
        Angstrom (an)                   Pole (po)                       Planck (p)
        BohrRadius (b,a.u.)             ElectronRadius (eR)

# Examples:

        metric_cnv -S:Parsecs -V:3.14 -T:Kilometer

        metric_cnv --source:inch -V:3.14 --target:meter

        metric_cnv -S:lightyears --value:3.14 -T:Megameter

# Test:

        metric_cnv -S:lightyears --value:3.14 -T:Megameter

# Output:

METRIC LENGTH UNIT CONVERTER (metric_cnv), Version 1.0

The example program was written by Hakan E. Kartal in 2024 using C++
https://github.com/AIntelligent, hek@nula.com.tr

        *** Question:

                3.1400001049041748:LightYears = Megameter?

        *** Answer:

                3.14 LightYears           = ( 8.90566014456578814E+42) Attometer
                3.14 LightYears           = ( 8.90566014456578738E+39) Femtometer
                3.14 LightYears           = ( 8.90566014456578819E+36) Pikometer
                3.14 LightYears           = ( 8.90566014456578792E+33) Nanometer
                3.14 LightYears           = ( 8.90566014456578867E+30) Micrometer
                3.14 LightYears           = ( 8.90566014456578873E+27) Millimeter
                3.14 LightYears           = ( 8.90566014456578873E+26) Centimeter
                3.14 LightYears           = (  8.9056601445657877E+25) Decimeter
                3.14 LightYears           = ( 8.90566014456578877E+24) Meter
                3.14 LightYears           = ( 8.90566014456578877E+23) Decameter
                3.14 LightYears           = ( 8.90566014456578777E+22) Hectometer
                3.14 LightYears           = ( 8.90566014456578861E+21) Kilometer

                3.14 LightYears           = ( 8.90566014456578867E+18) Megameter            <---

                3.14 LightYears           = (        8905660144565789) Gigameter
                3.14 LightYears           = (     8905660144565.78906) Terameter
                3.14 LightYears           = (     8905660144.56578827) Petameter
                3.14 LightYears           = (     8905660.14456578903) Exameter
                3.14 LightYears           = ( 3.50616541124637363E+26) Inch
                3.14 LightYears           = (  2.9218045093719776E+25) Foot
                3.14 LightYears           = ( 9.73934836457325937E+24) Yard
                3.14 LightYears           = (  4.4269765293514811E+23) Chain
                3.14 LightYears           = ( 4.42697652935148144E+22) Furlong
                3.14 LightYears           = (  5.5337206616893518E+21) Mile
                3.14 LightYears           = ( 1.84457355389645069E+21) League
                3.14 LightYears           = ( 1.94786967291465187E+25) Cubit
                3.14 LightYears           = ( 1.60186650733112826E+21) NauticalLeague
                3.14 LightYears           = (       29706084682643312) LightSeconds
                3.14 LightYears           = (     495101411377388.562) LightMinutes
                3.14 LightYears           = (     8251690189623.14258) LightHours
                3.14 LightYears           = (      343820424567.63092) LightDays
                3.14 LightYears           = (     59530649458085.8984) AstronomicalUnit
                3.14 LightYears           = (     288612789.553389192) Parsecs
                3.14 LightYears           = ( 1.77079061174059244E+24) Rod
                3.14 LightYears           = ( 3.50616541124637355E+29) Mil
                3.14 LightYears           = ( 4.80867178432278036E+21) NauticalMile
                3.14 LightYears           = ( 8.90566014456578908E+34) Angstrom
                3.14 LightYears           = ( 1.77079061174059244E+24) Pole
                3.14 LightYears           = ( 5.51075780457074118E+59) Planck
                3.14 LightYears           = ( 1.68292574206375016E+35) BohrRadius
                3.14 LightYears           = ( 3.16034310065158817E+39) ElectronRadius
