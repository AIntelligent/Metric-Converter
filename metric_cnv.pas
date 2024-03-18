program MetricCnv(input, output);

uses
  SysUtils,
  &Unit,
  LengthUnits,
  Item;

const
  REQUIRED_PARAMETER_COUNT      = 3;

  ERROR_SUCCESS                 = 0;
  ERROR_INVALID_PARAMETER_COUNT = -1;
  ERROR_INVALID_SOURCE_UNIT     = -2;
  ERROR_INVALID_SOURCE_VALUE    = -3;
  ERROR_INVALID_TARGET_UNIT     = -4;
  ERROR_INVALID_COMMAND         = -5;
  SHOW_HELP_SCREEN              = -6;
  ERROR_UNEXPECTED_PARAMETER    = -7;

  MAX_COMMAND                   = 20;
  MAX_PARAMETER                 = 40;

const
  MAX_ITEM                      = 41;
  Items : array[ 0..(MAX_ITEM - 1) ] of TItem = (
      // ----------------------------------------------------------------
      //   Metric Units
      // ================================================================
      (UnitName : 'Attometer';            UnitPtr : @Attometer          ),
      (UnitName : 'Femtometer';           UnitPtr : @Femtometer         ),
      (UnitName : 'Pikometer';            UnitPtr : @Pikometer          ),
      (UnitName : 'Nanometer';            UnitPtr : @Nanometer          ),
      (UnitName : 'Micrometer';           UnitPtr : @Micrometer         ),
      (UnitName : 'Millimeter';           UnitPtr : @Millimeter         ),
      (UnitName : 'Centimeter';           UnitPtr : @Centimeter         ),
      (UnitName : 'Decimter';             UnitPtr : @Decimeter          ),
      (UnitName : 'Meter';                UnitPtr : @Meter              ),
      (UnitName : 'Decameter';            UnitPtr : @Decameter          ),
      (UnitName : 'Hectometer';           UnitPtr : @Hectometer         ),
      (UnitName : 'Kilometer';            UnitPtr : @Kilometer          ),
      (UnitName : 'Megameter';            UnitPtr : @Megameter          ),
      (UnitName : 'Gigameter';            UnitPtr : @Gigameter          ),
      (UnitName : 'Terameter';            UnitPtr : @Terameter          ),
      (UnitName : 'Petameter';            UnitPtr : @Petameter          ),
      (UnitName : 'Exameter';             UnitPtr : @Exameter           ),
      // ----------------------------------------------------------------
      //   Imperial Units
      // ================================================================
      (UnitName : 'Inch';                 UnitPtr : @Inch               ),
      (UnitName : 'Foot';                 UnitPtr : @Foot               ),
      (UnitName : 'Yard';                 UnitPtr : @Yard               ),
      (UnitName : 'Chain';                UnitPtr : @Chain              ),
      (UnitName : 'Furlong';              UnitPtr : @Furlong            ),
      (UnitName : 'Mile';                 UnitPtr : @Mile               ),
      (UnitName : 'League';               UnitPtr : @League             ),
      (UnitName : 'Cubit';                UnitPtr : @Cubit              ),
      (UnitName : 'NauticalLeague';       UnitPtr : @NauticalLeague     ),
      // ----------------------------------------------------------------
      //   Light's Units
      // ================================================================
      (UnitName : 'LightSeconds';         UnitPtr : @LightSeconds       ),
      (UnitName : 'LightMinutes';         UnitPtr : @LightMinutes       ),
      (UnitName : 'LightHours';           UnitPtr : @LightHours         ),
      (UnitName : 'LightDays';            UnitPtr : @LightDays          ),
      (UnitName : 'LightYears';           UnitPtr : @LightYears         ),
      // ----------------------------------------------------------------
      //   Astronomical Unit
      // ================================================================
      (UnitName : 'AstronomicalUnit';     UnitPtr : @AstronomicalUnit   ),
      // ----------------------------------------------------------------
      //   Other Units
      // ================================================================
      (UnitName : 'Parsecs';              UnitPtr : @Parsecs            ),
      (UnitName : 'Rod';                  UnitPtr : @Rod                ),
      (UnitName : 'Mil';                  UnitPtr : @Mil                ),
      (UnitName : 'NauticalMile';         UnitPtr : @NauticalMile       ),
      (UnitName : 'Angstrom';             UnitPtr : @Angstrom           ),
      (UnitName : 'Pole';                 UnitPtr : @Pole               ),
      (UnitName : 'Planck';               UnitPtr : @Planck             ),
      (UnitName : 'BohrRadius';           UnitPtr : @BohrRadius         ),
      (UnitName : 'ElectronRadius';       UnitPtr : @ElectronRadius     )
    );

var
  g_strAppName : string = '';

function __is_validchar( inChar : Char ) : Boolean; inline;
begin
  Result := (inChar in [ 'S', 'V', 'T' ]);
end;

function _getmodulename( const inFileFullPathName : string; inIsExtensionRequired : Boolean = False ) : string;
begin
  Result := ExtractFileName( inFileFullPathName );

  if (not inIsExtensionRequired) then
    SetLength( Result, Pos( ExtractFileExt( inFileFullPathName ), Result ) - 1 );
end;

procedure DisplayUnits();
var
  i : Integer;
  l_varItem : TItem;
  l_strUnitInfo : string;
begin
  i := 0;

  for l_varItem in Items do
  begin
    l_strUnitInfo := l_varItem.UnitName + ' (' + l_varItem.UnitPtr^.Symbol + ')';

    Write( #9, l_strUnitInfo, '':(24 - Length(l_strUnitInfo)) );

    i := (i + 1);

    if ((i mod 3) = 0) then WriteLn;
  end;

  WriteLn;
end;

procedure About();
begin
  WriteLn( 'METRIC LENGTH UNIT CONVERTER (', g_strAppName, '), Version 1.0' );
  WriteLn;
  WriteLn( 'The example program was written by Hakan E. Kartal in 2024 using FreePascal' );
  WriteLn( 'https://github.com/AIntelligent, hek@nula.com.tr' );
end;

procedure HowToUse();
begin
  WriteLn;
  WriteLn( 'What does it to?' );
  WriteLn;

  WriteLn( #9'This program converts the specified length unit measurement value to other length values.' );
  WriteLn;
  WriteLn( 'How to usage:' );
  WriteLn;
  WriteLn( #9, g_strAppName, ' -S[--source]:[Source Unit] -V[--value]:[Value] -T[--target]:[Target Unit] -H[--help]' );

  WriteLn;
  WriteLn( 'Parameters: ');
  WriteLn;

  WriteLn( #9'-S[--source]: Source Unit (see: Defined Units)' );
  WriteLn( #9'-V[--value]: Value (etc: 3.14)' );
  WriteLn( #9'-T[--target]: Target Unit (see: Defined Units)' );
  WriteLn( #9'-H[--help]: This screen' );

  WriteLn;
  WriteLn( 'Defined Units:' );
  WriteLn;

  DisplayUnits();

  WriteLn;
  WriteLn( 'Examples:' );
  WriteLn;

  WriteLn( #9, g_strAppName, ' -S:Parsecs -V:3.14 -T:Kilometer' );
  WriteLn;
  WriteLn( #9, g_strAppName, ' --source:inch -V:3.14 --target:meter' );
  WriteLn;
  WriteLn( #9, g_strAppName, ' -S:lightyears --value:3.14 -T:Megameter' );
  WriteLn;
end;

function ParseCmdLine( const inArgument : string; var outCommand, outParameter : string ) : Boolean;
var
  l_strCommand,
  l_strParameter : string;
  i, j, l_iLen : Integer;
begin
  l_strCommand := '';
  l_strParameter := '';

  l_iLen := Length( inArgument );
  i := 1;

  while (l_iLen > i) do
  begin
    while ((l_iLen > i) and (inArgument[ i ] <> '-')) do Inc(i);

    j := 0;
    while ((l_iLen > i) and (inArgument[ i + j ] = '-')) do Inc(j);

    if (not __is_validchar( UpCase( inArgument[ i + j ] ) )) then
      Break;

    j := 0;
    while ((l_iLen > i) and (inArgument[ i ] <> ':')) do
    begin
      if (MAX_COMMAND > j) then
        l_strCommand := l_strCommand + UpCase( inArgument[ i ] );

      Inc(j);
      Inc(i);
    end;

    j := 0;
    while (l_iLen > i) do
    begin
      Inc(i);

      if (MAX_PARAMETER > j) then
        l_strParameter := l_strParameter + UpCase( inArgument[ i ] );

      Inc(j);
    end;
  end;

  outCommand := l_strCommand;
  outParameter := l_strParameter;

  Result := ((Length(l_strCommand) > 0) and (Length(l_strParameter) > 0));
end;

function IsSourceUnit( const inString : string ) : Boolean;
begin
  Result := ((inString = '-S') or (inString = '--SOURCE'));
end;

function IsValue( const inString : string ) : Boolean;
begin
  Result := ((inString = '-V') or (inString = '--VALUE'));
end;

function IsTargetUnit( const inString : string ) : Boolean;
begin
  Result := ((inString = '-T') or (inString = '--TARGET'));
end;

function IsHelp( const inString : string ) : Boolean;
begin
  Result := ((inString = '-H') or (inString = '--HELP'));
end;

function TryGetUnit( const inParameter : string; var outItem : TItem ) : Boolean;
var
  l_varItem : TItem;
begin
  for l_varItem in Items do
    if (l_varItem.Equals( inParameter )) then
    begin
      outItem := l_varItem;
      Exit(True);
    end;

  Result := False;
end;

function TryGetValue( const inParameter : string; var outValue : Double ) : Boolean;
var
  l_varFormatSettings : TFormatSettings;
begin
  l_varFormatSettings := FormatSettings;
  try
    try
      // Set invariant culture format.
      FormatSettings.ThousandSeparator := ',';
      FormatSettings.DecimalSeparator  := '.';

      outValue := StrToFloat( inParameter );
      Result := True;
    except
      Result := False;
    end;
  finally
    FormatSettings := l_varFormatSettings;
  end;
end;

procedure PrintError( const inMessage : string ); overload;
begin
  WriteLn;
  WriteLn( 'ERROR: ', inMessage, '!' );
  WriteLn;
end;

procedure PrintError( const inFormatMessage : string; const inArguments : array of const ); overload;
begin
  PrintError( Format( inFormatMessage, inArguments ) );
end;

procedure Convert( inSourceItem : TItem; inSourceValue : Double; inTargetItem : TItem );
var
  l_fTargetUnitValue : Double;
  l_varTarget : TOperand;
  l_varItem : TItem;
begin
  WriteLn;
  WriteLn( #9'*** Question:' );
  WriteLn;
  WriteLn( Format( #9'%f %s = %s?', [ inSourceValue, inSourceItem.UnitName, inTargetItem.UnitName ] ) );
  WriteLn;
  WriteLn( #9'*** Answer:' );
  WriteLn;

  for l_varItem in Items do
  begin
    if (l_varItem.Equals( inSourceItem )) then
      Continue;

    if (l_varItem.Equals( inTargetItem )) then
      WriteLn;

    l_varTarget := TOperand.Create( l_varItem.UnitPtr^ );
    l_varTarget.SetValue( inSourceValue, inSourceItem.UnitPtr^ );
    l_fTargetUnitValue := l_varTarget.Value;

    Write( Format( #9#9'%f %-20s = (%24s) %-20s', [ inSourceValue, inSourceItem.UnitName,
                                                    Format( '%g', [ l_fTargetUnitValue ] ),
                                                    l_varItem.UnitName ] ) );

    if (l_varItem.Equals( inTargetItem )) then
      WriteLn( ' <---' );

    WriteLn;
  end;
end;

function ProcessCmdLine() : Integer;
var
  l_strCommand, l_strParameter : string;
  l_varSourceItem, l_varTargetItem : TItem;
  l_fSourceUnitValue : Double;
  i : Integer;
begin
  for i := 1 to ParamCount() do
  begin
    l_strCommand := '';
    l_strParameter := '';

    if (not ParseCmdLine( ParamStr( i ), l_strCommand, l_strParameter )) then
    begin
      PrintError( 'Unexpected parameter %d: "%s"', [ i, ParamStr( i ) ] );

      HowToUse();

      Exit(ERROR_UNEXPECTED_PARAMETER);
    end;

    if (IsHelp( l_strCommand )) then
    begin
      HowToUse();

      Exit(SHOW_HELP_SCREEN);
    end;

    if (IsSourceUnit( l_strCommand )) then
      begin
        if (not TryGetUnit( l_strParameter, l_varSourceItem )) then
        begin
          PrintError( 'Invalid source unit: "%s"', [ l_strParameter ] );

          HowToUse();

          Exit(ERROR_INVALID_SOURCE_UNIT);
        end;
      end
    else if (IsValue( l_strCommand )) then
      begin
        if (not TryGetValue( l_strParameter, l_fSourceUnitValue )) then
        begin
          PrintError( 'Invalid value' );

          HowToUse();

          Exit(ERROR_INVALID_SOURCE_VALUE);
        end;
      end
    else if (IsTargetUnit( l_strCommand )) then
      begin
        if (not TryGetUnit( l_strParameter, l_varTargetItem )) then
        begin
          PrintError( 'Invalid target unit: "%s"', [ l_strParameter ] );

          HowToUse();

          Exit(ERROR_INVALID_TARGET_UNIT);
        end;
      end
    else
      begin
        PrintError( 'Invalid parameter: "%s" or command: "%s"', [ l_strCommand, l_strParameter ] );

        HowToUse();

        Exit(ERROR_INVALID_COMMAND);
      end;
  end;

  Convert( l_varSourceItem, l_fSourceUnitValue, l_varTargetItem );

  Result := ERROR_SUCCESS;
end;


begin
  g_strAppName := _getmodulename( ParamStr( 0 ) );

  About();

  if (REQUIRED_PARAMETER_COUNT > ParamCount()) then
  begin
    HowToUse();

    Halt(ERROR_INVALID_PARAMETER_COUNT);
  end;

  Halt(ProcessCmdLine());
end.
