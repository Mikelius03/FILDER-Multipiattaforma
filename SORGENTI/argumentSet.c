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


#define _CRT_SECURE_NO_WARNINGS 1
#include "./MotoreFILDER/MyFilder.h"

SettFILDER* inizializeCommandLine( char* argv[] )
{
    SettFILDER* settaggi = (SettFILDER*)malloc( sizeof( SettFILDER ) );
    if( settaggi == NULL )
        return NULL;

    strncpy( settaggi->dirWork, argv[1],MY_MAXPATH );
    strncpy( settaggi->patternFILDER, argv[2],4 );
    settaggi->recSearch = TRUE;
    return settaggi;
}

/* Poi in 4° momento li setto da console, ora mi secco XD*/
SettFILDER* inizializeConsole()
{
    SettFILDER* settaggi = (SettFILDER*)malloc( sizeof( SettFILDER ) );
    if( settaggi == NULL )
        return NULL;

    strncpy( settaggi->dirWork, "./",3 );
    strncpy( settaggi->patternFILDER, "*.*",4 );
    settaggi->recSearch = FALSE;
    return settaggi;
}
