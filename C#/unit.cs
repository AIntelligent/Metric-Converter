namespace metric_cnv
{
   public class Unit
   {

      #region ' Public Methods '

      public Unit()
      {
         Factor = 0.0;
         Symbol = string.Empty;
      }

      public Unit( double inFactor, string inSymbol )
      {
         Factor = inFactor;
         Symbol = inSymbol;
      }

      public Unit( Unit inBase )
      {
         Factor = inBase.Factor;
         Symbol = inBase.Symbol;
      }

      public override bool Equals( object? inObject )
      {
         return inObject as Unit == this;
      }

      public override int GetHashCode()
      {
         return Factor.GetHashCode() | Symbol.GetHashCode();
      }

      public double Convert( double inValue, Unit inReference )
      {
         return inValue * (Factor / inReference.Factor);
      }

      public static bool operator ==( Unit inLeft, Unit inRight )
      {
         return inLeft.Factor == inRight.Factor;
      }

      public static bool operator !=( Unit inLeft, Unit inRight )
      {
         return inLeft.Factor != inRight.Factor;
      }

      #endregion

      #region ' Properties '

      public double Factor { get; }
      public string Symbol { get; }

      #endregion
   }

   public class Operand
   {

      public Operand()
      {
         Base = null;
         Value = 0.0;
      }

      public Operand( Unit inBase, double inValue = 0.0 )
      {
         Base = new Unit( inBase );
         Value = inValue;
      }

      public double Convert( Unit inReference ) => Base.Convert( Value, inReference );

      public static explicit operator double( Operand inOperand )
      {
         return inOperand.Value;
      }

      public static Operand operator <<( Operand inLeft, Operand inRight )
      {
         return new Operand( inLeft.Base, inRight.Convert( inLeft.Base ) );
      }

      public static Operand operator <<( Operand inLeft, double inValue )
      {
         return new Operand( inLeft.Base, inValue );
      }

      public Unit Base { get; }
      public double Value { get; private set; }
   }
}