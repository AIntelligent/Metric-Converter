//
// item.h
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
#ifndef __ITEM_H
#define __ITEM_H

#define MAX_UNITNAME (20 + 1)

typedef \
	struct item_t
	{
		
		wchar_t 		UnitName[ MAX_UNITNAME ];
		
	private:
		
		PUnit 		m_ptrUnit;
		
	public:
		
		item_t()
		{
			UnitName[ 0 ] = (wchar_t)0;
			m_ptrUnit = NULL;
		}
		
		item_t( const wchar_t *inComment, const PUnit inUnitPtr )
		{
			wcsncpy( &UnitName[ 0 ], inComment, MAX_UNITNAME );
			m_ptrUnit = inUnitPtr;
		}
		
		operator TUnit&() const 
		{
			return *m_ptrUnit;
		}
		
		operator const wchar_t*() const
		{
			return (const wchar_t*)&UnitName[ 0 ];
		}
		
		bool operator ==( item_t& inRight )
		{
			return operator ==( inRight.UnitName );
		}
		
		bool operator ==( const wchar_t *inUnitName )
		{
			return (wcsnicmp( UnitName, inUnitName, MAX_UNITNAME ) == 0);
		}
	}
	TItem,
	*PItem;


#endif