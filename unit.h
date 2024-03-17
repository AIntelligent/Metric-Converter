//
// unit.h
//
// Author:
//       Hakan E. Kartal <hek@nula.com.tr>
//
// Copyright (c) 2024 Hakan E. Kartal
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
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