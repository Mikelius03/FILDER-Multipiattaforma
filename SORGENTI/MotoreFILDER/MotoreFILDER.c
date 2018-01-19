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
#include "MyFilder.h"

void MotoreFILDER( SettFILDER* settBase, DIRDATA* h )
{
    intptr_t hFind; // return _findfirst
    h->levelSubFolder++;
    char* myFILE = NULL;

    my_getcwd( &myFILE );

    if( h->levelSubFolder == 0 )
        printf( "\t\t\tCartella da setacciare \n\t\t\t[%s]\n\n", myFILE );
    else
        printf( "%s\n", myFILE );

    free( myFILE );


    hFind = _findfirst( "*.*", &h->FindData );
    h->fOk = ( hFind != -1L );

    while( h->fOk ) {
        h->fIsDir = IsChildDir( &h->FindData );

        if( !h->fIsDir || ( !settBase->recSearch && IsChildDir( &h->FindData ) ) ) {

            if( (h->FindData.name[0]) != '.' ) {
                if( h->fIsDir ) {
                    printf( "  [%s]\n", h->FindData.name );
                } else {
                    printf( "-> %s\n", h->FindData.name );
                }
            }
        }

        h->fOk = _findnext( hFind, &h->FindData ) == 0 ? TRUE : FALSE;
    }

    if( hFind != -1L )        _findclose( hFind );

        if( settBase->recSearch) {
            hFind = FindFirstChildDir( "*.*", &h->FindData );
            h->fOk = ( hFind != -1L );

            while( h->fOk ) {
                if( my_chdir( h->FindData.name ) == 0 ) {
                    MotoreFILDER( settBase,h );
                    my_chdir( ".." );
                }
                h->fOk = FindNextChildDir((long)hFind, &h->FindData );
            }

            if( hFind != -1L )            _findclose( hFind );
        }

    h->levelSubFolder--;
}
