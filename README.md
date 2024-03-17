# METRIC LENGTH UNIT CONVERTER (metric_cnv), Version 1.0

The example program was written by Hakan E. Kartal in 2024 using C++
https://github.com/AIntelligent

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

        metric_cnv -S:lightyears -value:3.14 -T:Megameter
