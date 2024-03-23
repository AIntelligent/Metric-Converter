namespace metric_cnv;

class Program
{
   static readonly int
      REQUIRED_PARAMETER_COUNT = 3,
      ERROR_SUCCESS = 0,
      ERROR_INVALID_PARAMETER_COUNT = -1,
      ERROR_INVALID_SOURCE_UNIT = -2,
      ERROR_INVALID_SOURCE_VALUE = -3,
      ERROR_INVALID_TARGET_UINT = -4,
      ERROR_INVALID_COMMAND = -5,
      SHOW_HELP_SCREEN = -6,
      ERROR_UNEXPECTED_PARAMETER = -7,
      MAX_UNITNAME = 20,
      MAX_COMMAND = 8 + MAX_UNITNAME,
      MAX_PARAMETER = 20;

   static readonly Item[]
      Items =
      {
		   // -------------------------------------------------------------------------
		   // 	Metric Units
		   // =========================================================================
         new Item( "Attometer", LengthUnits.Attometer ),
         new Item( "Femtometer", LengthUnits.Femtometer ),
         new Item( "Pikometer", LengthUnits.Pikometer ),
         new Item( "Nanometer", LengthUnits.Nanometer ),
         new Item( "Micrometer", LengthUnits.Micrometer ),
         new Item( "Millimeter", LengthUnits.Millimeter ),
         new Item( "Centimeter", LengthUnits.Centimeter ),
         new Item( "Decimeter", LengthUnits.Decimeter ),
         new Item( "Meter", LengthUnits.Meter ),
         new Item( "Decameter", LengthUnits.Decameter ),
         new Item( "Hectometer", LengthUnits.Hectometer ),
         new Item( "Kilometer", LengthUnits.Kilometer ),
         new Item( "Megameter", LengthUnits.Megameter ),
         new Item( "Gigameter", LengthUnits.Gigameter ),
         new Item( "Terameter", LengthUnits.Terameter ),
         new Item( "Petameter", LengthUnits.Petameter ),
         new Item( "Exameter", LengthUnits.Exameter ),
			// -------------------------------------------------------------------------
			// 	Imperial Units
			// =========================================================================
			new Item( "Inch", LengthUnits.Inch ),
         new Item( "Foot", LengthUnits.Foot ),
         new Item( "Yard", LengthUnits.Yard ),
         new Item( "Chain", LengthUnits.Chain ),
         new Item( "Furlong", LengthUnits.Furlong ),
         new Item( "Mile", LengthUnits.Mile ),
         new Item( "League", LengthUnits.League ),
         new Item( "Cubit", LengthUnits.Cubit ),
         new Item( "NauticalLeague", LengthUnits.NauticalLeague ),
			// -------------------------------------------------------------------------
			// 	Light's Units
			// =========================================================================
			new Item( "LightSeconds", LengthUnits.LightSeconds ),
         new Item( "LightMinutes", LengthUnits.LightMinutes ),
         new Item( "LightHours", LengthUnits.LightHours ),
         new Item( "LightDays", LengthUnits.LightDays ),
         new Item( "LightYear", LengthUnits.LightYear ),
			// -------------------------------------------------------------------------
			// 	Astronomical Unit
			// =========================================================================
			new Item( "AstronomicalUnit", LengthUnits.AstronomicalUnit ),
			// -------------------------------------------------------------------------
			// 	Other Units
			// =========================================================================
			new Item( "Parsecs", LengthUnits.Parsecs ),
         new Item( "Rod", LengthUnits.Rod ),
         new Item( "Mil", LengthUnits.Mil ),
         new Item( "NauticalMile", LengthUnits.NauticalMile ),
         new Item( "Angstrom", LengthUnits.Angstrom ),
         new Item( "Pole", LengthUnits.Pole ),
         new Item( "Planck", LengthUnits.Planck ),
         new Item( "BohrRadius", LengthUnits.BohrRadius ),
         new Item( "ElectronRadius", LengthUnits.ElectronRadius ),
      };

   static string
      g_strAppName = null;

   static string _getmodulename( bool inIsExtensionRequired = false )
   {
      return inIsExtensionRequired
                  ? Path.GetFileName( Environment.ProcessPath )
                  : Path.GetFileNameWithoutExtension( Environment.ProcessPath );
   }

   static void DisplayUnits()
   {
      int
         i = 0;

      foreach (Item l_varItem in Items)
      {
         Console.Write( string.Format( "\t{0,-24}", l_varItem.UnitName + "(" + l_varItem.Unit.Symbol + ")" ) );

         if (++i % 3 == 0)
         {
            Console.WriteLine();
         }
      }

      Console.WriteLine();
   }

   static void About()
   {
      Console.WriteLine( $"METRIC LENGTH UNIT CONVERTER ({g_strAppName}), Version 1.0" );
      Console.WriteLine();
      Console.WriteLine( "The example program was written by Hakan Emre Kartal in 2024 using C#" );
      Console.WriteLine( "https://github.com/AIntelligent, hek@nula.com.tr" );
   }

   static void HowToUse()
   {
      Console.WriteLine();
      Console.WriteLine( "What does it do" );
      Console.WriteLine();
      Console.WriteLine( "\tThis program converts the specified length unit measurement value to other length values." );
      Console.WriteLine();
      Console.WriteLine( "How to usage:" );
      Console.WriteLine();
      Console.WriteLine( $"\t{g_strAppName} -S[--source]:[Source Unit] -V[--value]:[Value] -T[--target]:[Target Unit] -H[--help]" );
      Console.WriteLine();
      Console.WriteLine( "Parameters:" );
      Console.WriteLine();
      Console.WriteLine( "\t-S[--source]: Source Unit (see: Defined Units)" );
      Console.WriteLine( "\t-V[--value]: Value (etc: 3.14)" );
      Console.WriteLine( "\t-T[--target]: Target Unit (see: Defined Units)" );
      Console.WriteLine( "\t-H[--help]: This screen" );
      Console.WriteLine();
      Console.WriteLine( "Defined Units:" );
      Console.WriteLine();

      DisplayUnits();

      Console.WriteLine();
      Console.WriteLine( "Examples:" );
      Console.WriteLine();
      Console.WriteLine();
      Console.WriteLine( $"\t{g_strAppName} -S:Parsecs -V:3.14 -T:Kilometer" );
      Console.WriteLine();
      Console.WriteLine( $"\t{g_strAppName} --source:inch -V:3.14 --target:meter" );
      Console.WriteLine();
      Console.WriteLine( $"\t{g_strAppName} -S:lightyear -V:3.14 -T:Megameter" );
      Console.WriteLine();
   }

   static bool ParseCmdLine( string inArgument, out string outCommand, out string outParameter )
   {
      string[]
         l_arrParts = inArgument.ToUpperInvariant().Split( ':' );
      string
         l_strCommand = string.Empty,
         l_strParameter = string.Empty;

      if (l_arrParts.Length == 2)
      {
         l_strCommand = l_arrParts[ 0 ];
         l_strParameter = l_arrParts[ 1 ];
      }

      outCommand = l_strCommand;
      outParameter = l_strParameter;

      return !string.IsNullOrEmpty( l_strCommand ) && !string.IsNullOrEmpty( l_strParameter );
   }

   static bool IsSourceUnit( string inString ) 
      => (inString == "-S") || (inString == "--SOURCE");

   static bool IsValue( string inString ) 
      => (inString == "-V") || (inString == "--VALUE");

   static bool IsTargetUnit( string inString ) 
      => (inString == "-T") || (inString == "--TARGET");

   static bool IsHelp( string inString ) 
      => (inString == "-H") || (inString == "--HELP");

   static bool TryGetUnit( string inString, ref Item outItem )
   {
      foreach (Item l_varItem in Items)
      {
         if (l_varItem == inString)
         {
            outItem = l_varItem;
            return true;
         }
      }

      return false;
   }

   static bool TryGetValue( string inString, ref double outValue ) 
      => double.TryParse( inString, System.Globalization.CultureInfo.InvariantCulture, out outValue );

   static void PrintError( string inFormatMessage, params object[] inArguments )
   {
      Console.WriteLine();
      Console.WriteLine( "ERROR: " + string.Format( inFormatMessage, inArguments ) );
      Console.WriteLine();
   }

   static void Convert( Item inSourceItem, double inSourceValue, Item inTargetItem )
   {
      double
         l_fTargetUnitValue;
      Operand
         l_varSource = new Operand( inSourceItem.Unit, inSourceValue );

      Console.WriteLine();
      Console.WriteLine( "\t*** Question:" );
      Console.WriteLine();
      Console.WriteLine( string.Format( "\t\t{0:G} {1} = {2}?", inSourceValue, inSourceItem.UnitName, inTargetItem.UnitName ) );
      Console.WriteLine();
      Console.WriteLine( "\t*** Answer:" );
      Console.WriteLine();

      foreach (Item l_varItem in Items)
      {
         if (l_varItem == inSourceItem)
         {
            continue;
         }

         if (l_varItem == inTargetItem)
         {
            Console.WriteLine();
         }

         Operand
            l_varTarget = new Operand( l_varItem.Unit );

         l_fTargetUnitValue = (l_varTarget << l_varSource).Value;

         Console.Write( string.Format( "\t\t{0:F} {1,-20:S} = ({2,24:S}) {3,-20:S}",
                                       inSourceValue, inSourceItem.UnitName,
                                       l_fTargetUnitValue.ToString( "G" ), l_varItem.UnitName ) );

         if (l_varItem == inTargetItem)
         {
            Console.WriteLine( " <---" );
         }

         Console.WriteLine();
      }
   }

   static int ProcessCmdLine( string[] inArguments )
   {
      Item
         l_varSourceItem = Item.Empty,
         l_varTargetItem = Item.Empty;
      double
         l_fSourceUnitValue = default;

      for (int i = 0; i < inArguments.Length; i++)
      {
         if (ParseCmdLine( inArguments[ i ], out string l_strCommand, out string l_strParameter ))
         {
            if (IsHelp( l_strCommand ))
            {
               HowToUse();
               return SHOW_HELP_SCREEN;
            }

            if (IsSourceUnit( l_strCommand ))
            {
               if (!TryGetUnit( l_strParameter, ref l_varSourceItem ))
               {
                  PrintError( "Invalid source unit: '{0}'", l_strParameter );

                  HowToUse();

                  return ERROR_INVALID_SOURCE_UNIT;
               }
            }
            else if (IsValue( l_strCommand ))
            {
               if (!TryGetValue( l_strParameter, ref l_fSourceUnitValue ))
               {
                  PrintError( "Invalid value" );

                  HowToUse();

                  return ERROR_INVALID_SOURCE_VALUE;
               }
            }
            else if (IsTargetUnit( l_strCommand ))
            {
               if (!TryGetUnit( l_strParameter, ref l_varTargetItem ))
               {
                  PrintError( "Invalid target unit: '{0}'", l_strParameter );

                  HowToUse();

                  return ERROR_INVALID_TARGET_UINT;
               }
            }
            else
            {
               PrintError( "Invalid command: '{0}' or parameter: '{1}'", l_strCommand, l_strParameter );

               HowToUse();

               return ERROR_INVALID_COMMAND;
            }
         }
         else
         {
            PrintError( "Unexpected parameter {0}: '{1}'", i, inArguments[ i ] );

            HowToUse();

            return ERROR_UNEXPECTED_PARAMETER;
         }
      }

      Convert( l_varSourceItem, l_fSourceUnitValue, l_varTargetItem );

      return ERROR_SUCCESS;
   }

   static int Main( string[] inArguments )
   {
      g_strAppName = _getmodulename();

      About();

      if (REQUIRED_PARAMETER_COUNT > inArguments.Length)
      {
         HowToUse();
         return ERROR_INVALID_PARAMETER_COUNT;
      }

      return ProcessCmdLine( inArguments );
   }
}
