unit Item;

interface

uses
  SysUtils,
  &Unit;

type
  PItem = ^TItem;
  TItem = packed record
  public var
    UnitName : string;
    UnitPtr  : PUnit;
  public
    function Equals( const inUnitName : string ) : Boolean; overload;
    function Equals( const inRight : TItem ) : Boolean; overload; inline;
  end;

implementation

function TItem.Equals( const inUnitName : string ) : Boolean;
begin
  Result := CompareText( UnitName, inUnitName ) = 0;
end;

function TItem.Equals( const inRight : TItem ) : Boolean;
begin
  Result := Equals( inRight.UnitName );
end;

end.