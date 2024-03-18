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
