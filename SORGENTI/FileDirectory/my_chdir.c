/**********************************************************************************//*
 * \license GNU LGPL 3.0
 * \author Michele Cannavo'
 * \date 2018-01-18

Copyright (c) 2017- 2018, Michele Cannavo'
All rights reserved.

This file is part of FILDER.

    FILDER is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FILDER is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with FILDER.  If not, see <http://www.gnu.org/licenses/>.
 ************************************************************************************/
#include "FileDirectory.h"

MYRETURN my_chdir(const char *dirname)
{
    AZZ_ERROR;
//////////////////////////////// VERIFICA INPUT ////////////////////////////////
	if(  dirname == NULL )	  return MYER_STRN(1);
    if( *dirname == '\0' )	  return MYER_STRE(1);
//////////////////////////////// VERIFICA INPUT ////////////////////////////////

#if defined( _MSC_VER) || defined(__clang__)
    if( _chdir( dirname ) == 0 )
        #else
//#elif defined(__linux__)
    if( chdir( dirname ) == 0 )
#endif

        return SUCCESS;
	else
        return INSUCCESS;
}
/*
MYRETURN my_fchdir(const int fd)
{
    if( fd <= 0  )	return MYER_STRN( 1 );
    if( fd >= 27 )	return MYER_STRN( 1 );


	if ( my_fileno()) return SUCCESS;
	else		return INSUCCESS;
}*/
