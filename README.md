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
        LightYear (li:Y)                AstronomicalUnit (AU)           Parsecs (pc)
        Rod (rod)                       Mil (mil)                       NauticalMile (Nmi)
        Angstrom (an)                   Pole (po)                       Planck (p)
        BohrRadius (b,a.u.)             ElectronRadius (eR)

# Examples:

        metric_cnv -S:Parsecs -V:3.14 -T:Kilometer

        metric_cnv --source:inch -V:3.14 --target:meter

        metric_cnv -S:lightyear --value:3.14 -T:Megameter

# Test:

        metric_cnv -S:lightyear --value:3.14 -T:Megameter

# Output:

METRIC LENGTH UNIT CONVERTER (metric_cnv), Version 1.0

The example program was written by Hakan E. Kartal in 2024 using C++
https://github.com/AIntelligent, hek@nula.com.tr

        *** Question:

                3.1400001049041748 LightYear = Megameter?

        *** Answer:

                3.14 LightYear            = ( 2.97060846826433116E+34) Attometer
                3.14 LightYear            = ( 2.97060846826433108E+31) Femtometer
                3.14 LightYear            = ( 2.97060846826433135E+28) Pikometer
                3.14 LightYear            = ( 2.97060846826433127E+25) Nanometer
                3.14 LightYear            = ( 2.97060846826433135E+22) Micrometer
                3.14 LightYear            = ( 2.97060846826433126E+19) Millimeter
                3.14 LightYear            = ( 2.97060846826433126E+18) Centimeter
                3.14 LightYear            = (      297060846826433152) Decimeter
                3.14 LightYear            = (       29706084682643316) Meter
                3.14 LightYear            = (      2970608468264331.5) Decameter
                3.14 LightYear            = (     297060846826433.125) Hectometer
                3.14 LightYear            = (     29706084682643.3125) Kilometer

                3.14 LightYear            = (     29706084682.6433144) Megameter            <---

                3.14 LightYear            = (      29706084.682643313) Gigameter
                3.14 LightYear            = (     29706.0846826433153) Terameter
                3.14 LightYear            = (     29.7060846826433149) Petameter
                3.14 LightYear            = (   0.0297060846826433141) Exameter
                3.14 LightYear            = ( 1.16953089301745331E+18) Inch
                3.14 LightYear            = (       97460907751454432) Foot
                3.14 LightYear            = (       32486969250484816) Yard
                3.14 LightYear            = (     1476680420476582.25) Chain
                3.14 LightYear            = (      147668042047658.25) Furlong
                3.14 LightYear            = (     18458505255957.2812) Mile
                3.14 LightYear            = (     6152835085319.09375) League
                3.14 LightYear            = (       64973938500969632) Cubit
                3.14 LightYear            = (     5343251521461.31836) NauticalLeague
                3.14 LightYear            = (     99088832.5904560089) LightSeconds
                3.14 LightYear            = (     1651480.54317426682) LightMinutes
                3.14 LightYear            = (     27524.6757195711143) LightHours
                3.14 LightYear            = (     1146.86148831546302) LightDays
                3.14 LightYear            = (     198572.872230447858) AstronomicalUnit
                3.14 LightYear            = (    0.962708640099909418) Parsecs
                3.14 LightYear            = (        5906721681906329) Rod
                3.14 LightYear            = (  1.1695308930174533E+21) Mil
                3.14 LightYear            = (     16040002528425.1152) NauticalMile
                3.14 LightYear            = ( 2.97060846826433127E+26) Angstrom
                3.14 LightYear            = (        5906721681906329) Pole
                3.14 LightYear            = ( 1.83819094093779436E+51) Planck
                3.14 LightYear            = ( 5.61363602437173485E+26) BohrRadius
                3.14 LightYear            = (  1.0541769868845693E+31) ElectronRadius
