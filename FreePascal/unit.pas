unit &Unit;

interface

type
  PUnit = ^TUnit;
  TUnit = packed record
  public var
    Factor : Double;
    Symbol : string;
  public
    constructor Create( const inBase : TUnit ); overload;
    constructor Create( const inFactor : Double; const inSymbol : string ); overload;
    function Convert( const inValue : Double; const inReference : TUnit ) : Double;
    function Equals( const inRight : TUnit ) : Boolean;
  end;

  POperand = ^TOperand;
  TOperand = packed record
  private var
    m_fValue : Double;
    m_varBase : TUnit;
  private
    function GetValue() : Double; inline;
    function GetBase() : TUnit; inline;
  public
    constructor Create( const inBase : TUnit; const inValue : Double = 0.0 );
    procedure SetValue( const inValue : Double; const inReference : TUnit );
  public
    property Value : Double read GetValue;
    property Base : TUnit read GetBase;
  end;

implementation

{$REGION ' TUnit '}

function TUnit.Equals( const inRight : TUnit ) : Boolean;
begin
  Result := (Factor = inRight.Factor);
end;

constructor TUnit.Create( const inBase : TUnit );
begin
  Factor := inBase.Factor;
  Symbol := inBase.Symbol;
end;

constructor TUnit.Create( const inFactor : Double; const inSymbol : string );
begin
  Factor := inFactor;
  Symbol := inSymbol;
end;

function TUnit.Convert( const inValue : Double; const inReference : TUnit ) : Double;
begin
  Result := (inValue * (Factor / inReference.Factor));
end;

{$ENDREGION}

{$REGION ' TOperand '}

// Private

function TOperand.GetValue() : Double;
begin
  Result := m_fValue;
end;

function TOperand.GetBase() : TUnit;
begin
  Result := m_varBase;
end;

// Public

constructor TOperand.Create( const inBase : TUnit; const inValue : Double );
begin
  m_varBase := inBase;
  m_fValue := inValue;
end;

procedure TOperand.SetValue( const inValue : Double; const inReference : TUnit );
begin
  m_fValue := inReference.Convert( inValue, m_varBase );
end;

{$ENDREGION}

end.