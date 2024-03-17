#include <iostream>
#include <stdarg.h>

#include "unit.h"
#include "lengthunits.h"
#include "item.h"

#define REQUIRED_PARAMETER_COUNT			( 3)

#define ERROR_SUCCESS						( 0)
#define ERROR_INVALID_PARAMETER_COUNT 	(-1)
#define ERROR_INVALID_SOURCE_UNIT 		(-2)
#define ERROR_INVALID_SOURCE_VALUE		(-3)
#define ERROR_INVALID_TARGET_UNIT		(-4)
#define ERROR_INVALID_COMMAND				(-5)
#define SHOW_HELP_SCREEN					(-6)
#define ERROR_UNEXPECTED_PARAMETER		(-7)

#define MAX_COMMAND 							(8 + MAX_UNITNAME)
#define MAX_PARAMETER 						(20)
#define __is_validchar(C) 					(((C)=='S')||((C)=='V')||((C)=='T'))

#define MAX_FORMAT_BUFFER					(260)

const \
	TItem Items[] = \
	{
		// -------------------------------------------------------------------------
		// 	Metric Units
		// =========================================================================
		item_t( L"Attometer", 			(const PUnit)&LengthUnits::Attometer 			),
		item_t( L"Femtometer", 			(const PUnit)&LengthUnits::Femtometer 			),
		item_t( L"Pikometer", 			(const PUnit)&LengthUnits::Pikometer 			),
		item_t( L"Nanometer", 			(const PUnit)&LengthUnits::Nanometer 			),
		item_t( L"Micrometer", 			(const PUnit)&LengthUnits::Micrometer 			),
		item_t( L"Millimeter", 			(const PUnit)&LengthUnits::Millimeter 			),
		item_t( L"Centimeter", 			(const PUnit)&LengthUnits::Centimeter 			),
		item_t( L"Decimeter", 			(const PUnit)&LengthUnits::Decimeter 			),
		item_t( L"Meter", 				(const PUnit)&LengthUnits::Meter 				),
		item_t( L"Decameter", 			(const PUnit)&LengthUnits::Decameter 			),
		item_t( L"Hectometer", 			(const PUnit)&LengthUnits::Hectometer 			),
		item_t( L"Kilometer", 			(const PUnit)&LengthUnits::Kilometer 			),
		item_t( L"Megameter", 			(const PUnit)&LengthUnits::Megameter 			),
		item_t( L"Gigameter", 			(const PUnit)&LengthUnits::Gigameter 			),
		item_t( L"Terameter", 			(const PUnit)&LengthUnits::Terameter 			),
		item_t( L"Petameter", 			(const PUnit)&LengthUnits::Petameter 			),
		item_t( L"Exameter", 			(const PUnit)&LengthUnits::Exameter 			),
		// -------------------------------------------------------------------------
		// 	Imperial Units
		// =========================================================================
		item_t( L"Inch", 					(const PUnit)&LengthUnits::Inch 					),
		item_t( L"Foot", 					(const PUnit)&LengthUnits::Foot 					),
		item_t( L"Yard", 					(const PUnit)&LengthUnits::Yard 					),
		item_t( L"Chain", 				(const PUnit)&LengthUnits::Chain 				),
		item_t( L"Furlong", 				(const PUnit)&LengthUnits::Furlong 				),
		item_t( L"Mile", 					(const PUnit)&LengthUnits::Mile 					),
		item_t( L"League", 				(const PUnit)&LengthUnits::League 				),
		item_t( L"Cubit", 				(const PUnit)&LengthUnits::Cubit 				),
		item_t( L"NauticalLeague",		(const PUnit)&LengthUnits::NauticalLeague		),
		// -------------------------------------------------------------------------
		// 	Light's Units
		// =========================================================================
		item_t( L"LightSeconds", 		(const PUnit)&LengthUnits::LightSeconds 		),
		item_t( L"LightMinutes", 		(const PUnit)&LengthUnits::LightMinutes 		),
		item_t( L"LightHours", 			(const PUnit)&LengthUnits::LightHours 			),
		item_t( L"LightDays", 			(const PUnit)&LengthUnits::LightDays 			),
		item_t( L"LightYears", 			(const PUnit)&LengthUnits::LightYears 			),
		// -------------------------------------------------------------------------
		// 	Astronomical Unit
		// =========================================================================
		item_t( L"AstronomicalUnit", 	(const PUnit)&LengthUnits::AstronomicalUnit	),
		// -------------------------------------------------------------------------
		// 	Other Units
		// =========================================================================
		item_t( L"Parsecs", 				(const PUnit)&LengthUnits::Parsecs 				),
		item_t( L"Rod", 					(const PUnit)&LengthUnits::Rod 					),
		item_t( L"Mil", 					(const PUnit)&LengthUnits::Mil 					),
		item_t( L"NauticalMile",	 	(const PUnit)&LengthUnits::NauticalMile 		),
		item_t( L"Angstrom", 			(const PUnit)&LengthUnits::Angstrom 			),
		item_t( L"Pole", 					(const PUnit)&LengthUnits::Pole 					),
		item_t( L"Planck", 				(const PUnit)&LengthUnits::Planck 				),
		item_t( L"BohrRadius", 			(const PUnit)&LengthUnits::BohrRadius 			),
		item_t( L"ElectronRadius",		(const PUnit)&LengthUnits::ElectronRadius 	),
	};

char \
	*g_strAppName = NULL;

char *_getmodulename( const char *inFileFullPathName, bool inIsExtensionRequired = false )
{
	char
		*l_strResult;
	int
		l_iLen = strlen( inFileFullPathName );
		
	while ((--l_iLen > 1) && (inFileFullPathName[ l_iLen - 1 ] != '\\'));
	
	if (((l_iLen = strlen( l_strResult = strdup( &inFileFullPathName[ l_iLen ] ) )) != 0) && (!inIsExtensionRequired))
	{
		while ((l_iLen > 0) && (l_strResult[ --l_iLen ] != '.'));			
		l_strResult[ l_iLen ] = (char)0;
	}
	
	return l_strResult;	
}

size_t _ansitowidestr( const char *inString, wchar_t* outString )
{
	size_t 
		l_iResult;
		
	outString[ (l_iResult = mbstowcs( outString, inString, strlen( inString ) )) ] = (wchar_t)0;
	
	return l_iResult;
}

void DisplayUnits()
{	
	int 
		i = 0;
	wchar_t
		l_arrUnit[ 48 ];
	TUnit
		l_varUnit;
	
	for (item_t l_varItem : Items)
	{
		l_varUnit = l_varItem;
		
		wcscat( wcscat( wcscat( wcscpy( l_arrUnit, l_varItem.UnitName ), L" (" ), 
				  l_varUnit.Symbol ), L")" );
				  
		printf( "\t%-24S", l_arrUnit );
		
		if (((++i) % 3) == 0)
		{
			printf( "\r\n" );
		}
	}
	
	printf( "\r\n" );
}

void About()
{
	printf( "METRIC LENGTH UNIT CONVERTER (%s), Version 1.0\r\n\r\n", g_strAppName );
	printf( "The example program was written by Hakan E. Kartal in 2024 using C++\r\n" );
	printf( "https://github.com/AIntelligent, hek@nula.com.tr\r\n" );
}

void HowToUse()
{
	printf( "What does it to?\r\n\r\n" );
	printf( "\tThis program converts the specified length unit measurement value to other length unit values.\r\n" );
	printf( "\r\nHow to usage:\r\n\r\n" );
	printf( "\t%s -S[--source]:[Source Unit] -V[--value]:[Value] ", g_strAppName );
	printf( "-t[--target]:[Target Unit] -H|--help\r\n" );
	printf( "\r\nParameters:\r\n\r\n" );
	printf( "\t-S[--source]: Source Unit (see: Defined Units)\r\n" );
	printf( "\t-V[--value]: Value (etc: 3.14)\r\n" );
	printf( "\t-T[--target]: Target Unit (see: Defined Units)\r\n" );
	printf( "\t-H[--help]: This screen\r\n" );
	printf( "\r\nDefined Units:\r\n\r\n" );
	
	DisplayUnits();
	
	printf( "\r\nExamples:\r\n\r\n" );
	printf( "\t%s -S:Parsecs -V:3.14 -T:Kilometer\r\n\r\n", g_strAppName );
	printf( "\t%s --source:inch -V:3.14 --target:meter\r\n\r\n", g_strAppName );
	printf( "\t%s -S:lightyears --value:3.14 -T:Megameter\r\n\r\n", g_strAppName );
}

bool ParseCmdLine( const char *inArgument, char *outCommand, char *outParameter )
{
	char
		l_arrCommand[ MAX_COMMAND + 1 ] = { 0 },
		l_arrParameter[ MAX_PARAMETER + 1 ] = { 0 };
	int
		i = 0, j,
		l_iLen = strlen( inArgument );

	while (l_iLen > i)
	{
		while ((l_iLen > i) && (inArgument[ i ] != '-')) i++;
		
		j = 0;
		while ((l_iLen > i) && (inArgument[ i + j ] == '-')) j++;
		
		if (!__is_validchar(toupper( inArgument[ i + j ] )))
		{
			break;
		}
		
		for (j = 0; (l_iLen > i) && (inArgument[ i ] != ':'); j++, i++)
		{
			if (MAX_COMMAND > j) 
			{
				l_arrCommand[ j ] = toupper( inArgument[ i ] );
			}
		}
		
		for (j = 0; (l_iLen > ++i); j++)
		{
			if (MAX_PARAMETER > j)
			{
				l_arrParameter[ j ] = toupper( inArgument[ i ] );
			}
		}
	}
		
	return ((strlen( strncpy( outCommand, l_arrCommand, MAX_COMMAND ) ) != 0)
					&& (strlen( strncpy( outParameter, l_arrParameter, MAX_PARAMETER ) ) != 0));
}

bool IsSourceUnit( const char *inString )
{
	return ((strncmp( inString, "-S", MAX_COMMAND ) == 0) || (strncmp( inString, "--SOURCE", MAX_COMMAND ) == 0));
}

bool IsValue( const char *inString )
{
	return ((strncmp( inString, "-V", MAX_COMMAND ) == 0) || (strncmp( inString, "--VALUE", MAX_COMMAND ) == 0));
}

bool IsTargetUnit( const char *inString )
{
	return ((strncmp( inString, "-T", MAX_COMMAND ) == 0) || (strncmp( inString, "--TARGET", MAX_COMMAND ) == 0));
}

bool IsHelp( const char *inString )
{
	return ((strncmp( inString, "-H", MAX_COMMAND ) == 0) || (strncmp( inString, "--HELP", MAX_COMMAND ) == 0));
}

bool TryGetUnit( const char *inParameter, TItem &outItem )
{
	wchar_t
		l_arrUnitName[ MAX_UNITNAME + 1 ];

	if (_ansitowidestr( inParameter, l_arrUnitName ) == 0) 
	{
		return false;
	}
	
	for (TItem l_varItem : Items)
	{
		if (l_varItem == l_arrUnitName)
		{
			outItem = l_varItem;
			return true;
		}
	}
	
	return false;
}

bool TryGetValue( const char *inParameter, double *outValue )
{
	try
	{
		*outValue = std::stof( inParameter );
		return true;
	}
	catch( ... )
	{
		return false;
	}	
}

void PrintError( const char *inFormatMessage, ... )
{
	va_list 
		l_ptrArguments;
	char
		l_arrBuffer[ MAX_FORMAT_BUFFER ];
		
	l_arrBuffer[ 0 ] = (char)0;
	
	va_start( l_ptrArguments, inFormatMessage ),
	vsnprintf( l_arrBuffer, MAX_FORMAT_BUFFER, inFormatMessage, l_ptrArguments );
	va_end( l_ptrArguments );
	
	printf( "\r\nERROR: %s!\r\n\r\n", l_arrBuffer );
}

void Convert( TItem &inSourceItem, double inSourceValue, TItem &inTargetItem )
{
	double
		l_fTargetUnitValue;
	TOperand
		l_varSource( inSourceItem, inSourceValue ),
		l_varTarget( inTargetItem );
	char
		l_arrFloatToStr[ 64 ];
		
	printf( "\r\n\t*** Question:\r\n\r\n\t\t%.18G:%S = %S?\r\n\r\n\t*** Answer:\r\n\r\n", 
			  inSourceValue, inSourceItem.UnitName, inTargetItem.UnitName );
	
	for (TItem l_varItem : Items)
	{		
		if (l_varItem == inSourceItem)
		{
			continue;
		}
	
		if (l_varItem == inTargetItem)
		{
			printf( "\r\n" );
		}
	
		l_fTargetUnitValue = ((l_varTarget = ((TUnit&)l_varItem)) << (l_varSource << inSourceValue));
		
		sprintf( &l_arrFloatToStr[ 0 ], "%.18G", l_fTargetUnitValue );
		
		printf( "\t\t%G %-20S = (%24s) %-20S", inSourceValue, inSourceItem.UnitName, 
				  l_arrFloatToStr, l_varItem.UnitName );
					
		if (l_varItem == inTargetItem)
		{
			printf( " <---\r\n" );
		}
		
		printf( "\r\n" );
	}
}

int ProcessCmdLine( int inArgCount, char **inArgVector )
{
	char 
		l_arrCommand[ MAX_COMMAND ],
		l_arrParameter[ MAX_PARAMETER ];
	TItem
		l_varSourceItem,
		l_varTargetItem;
	double
		l_fSourceUnitValue = 0.0;
		
	for (int i = 1; i < inArgCount; i++)
	{
		l_arrCommand[ 0 ] = l_arrParameter[ 0 ] = '\0';
		
		if (ParseCmdLine( inArgVector[ i ], l_arrCommand, l_arrParameter ))
		{
			if (IsHelp( l_arrCommand ))
			{
				HowToUse();
				return SHOW_HELP_SCREEN;
			}
			
			if (IsSourceUnit( l_arrCommand ))
			{
				if (!TryGetUnit( l_arrParameter, l_varSourceItem ))
				{
					PrintError( "Invalid source unit: '%s'", l_arrParameter );
					
					HowToUse();
					
					return ERROR_INVALID_SOURCE_UNIT;
				}
			}
			else if (IsValue( l_arrCommand )) 
			{
				if (!TryGetValue( l_arrParameter, &l_fSourceUnitValue ))
				{
					PrintError( "Invalid value" );
					
					HowToUse();
					
					return ERROR_INVALID_SOURCE_VALUE;
				}
			}
			else if (IsTargetUnit( l_arrCommand ))
			{
				if (!TryGetUnit( l_arrParameter, l_varTargetItem ))
				{
					PrintError( "Invalid target unit: '%s'", l_arrParameter );
					
					HowToUse();
					
					return ERROR_INVALID_TARGET_UNIT;
				}
			}
			else 
			{
				PrintError( "Invalid parameter: '%s' or command: '%s'", l_arrCommand, l_arrParameter );
				
				HowToUse();
				
				return ERROR_INVALID_COMMAND;
			}
		}
		else
		{
			PrintError( "Unexpected parameter %d: '%s'", i, inArgVector[ i ] );
			
			HowToUse();
			
			return ERROR_UNEXPECTED_PARAMETER;
		}
	}

	Convert( l_varSourceItem, l_fSourceUnitValue, l_varTargetItem );	

	return ERROR_SUCCESS;   
}

int main( int inArgCount, char** inArgVector ) 
{	
	g_strAppName = _getmodulename( inArgVector[ 0 ] );
	
	About();

	if (REQUIRED_PARAMETER_COUNT > inArgCount)
	{
		HowToUse();
		return ERROR_INVALID_PARAMETER_COUNT;
	}
	
	return ProcessCmdLine( inArgCount, inArgVector );
}