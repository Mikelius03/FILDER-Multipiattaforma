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
#include "./MotoreFILDER/MyFilder.h"


int main( int argc, char* argv[] )
{

    SettFILDER* settaggi=calloc(1,sizeof(SettFILDER*));


    if( argc >= 3  )
        /*3= Nome Eseguibile, Percorso cartella, Pattern */
        settaggi = inizializeCommandLine( argv);
    else
        settaggi = inizializeConsole();

    if( settaggi )
        searchF( settaggi );
    else
        printf( "\n\n\t\t problemi\n\n" );

    getchar();

    return 0;

}
