#ifndef __UNIT_H
#define __UNIT_H

#define MAX_SYMBOL_NAME	(8 + 1)

typedef \
	struct unit_t
	{
	public:
		
		double 	Factor;
		wchar_t	Symbol[ MAX_SYMBOL_NAME ];
		
	public:
		
		unit_t()
		{
			Factor = 0.0;
			Symbol[ 0 ] = (wchar_t)0;
		}
		
		unit_t( const unit_t& inBase )
		{
			Factor = inBase.Factor;
			wcsncpy( &Symbol[ 0 ], &inBase.Symbol[ 0 ], MAX_SYMBOL_NAME );
		}
		
		unit_t( double inFactor, const wchar_t *inSymbol )
		{
			Factor = inFactor;
			wcsncpy( &Symbol[ 0 ], inSymbol, MAX_SYMBOL_NAME );
		}	
		
		double Convert( double inValue, const unit_t& inReference )
		{
			return(inValue * (Factor / inReference.Factor));	
		}	
		
		bool operator ==( unit_t& inReference )
		{
			return inReference.Factor == Factor;
		}
		
		bool operator !=( unit_t& inReference )
		{
			return inReference.Factor != Factor;
		}
	}
	TUnit,
	*PUnit;
	
typedef \
	struct operand_t
	{
	private:
		
		double m_fValue;
	
	public:
		
		struct unit_t Base;
		
		operand_t() : m_fValue(0.0)
		{}
		
		operand_t( const unit_t& inBase, double inValue = 0.0 ) : Base( inBase ), m_fValue(inValue)
		{}
		
		double GetValue( unit_t& inReference )
		{
			return (Base == inReference) ? m_fValue : Base.Convert( m_fValue, inReference );
		}
		
		void SetValue( double inValue, struct unit_t& inReference )
		{
			m_fValue = (inReference == Base) ? inValue : inReference.Convert( inValue, Base );
		}		
		
		void SetValue( double inValue )
		{
			m_fValue = inValue;
		}
		
		operator double()
		{
			return m_fValue;
		}
		
		operand_t& operator <<( double inRight )
		{
			m_fValue = inRight;
			return *this;
		}
		
		operand_t& operator <<( operand_t& inRight )
		{
			m_fValue = inRight.GetValue( Base );
			return *this;
		}		
	}
	TOperand,
	*POperand;

#endif