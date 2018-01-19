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


MYRETURN searchF( SettFILDER* myFILDER )
{
// Variabili di Lavoro

    char* currDirWork=NULL; // Stringa per la cartella corrent
    DIRDATA *l = calloc(1, sizeof( DIRDATA* ) );


    if(my_getcwd( &currDirWork )) return FATALITY;
    if(my_chdir( myFILDER->dirWork )  ) return FATALITY;  // Cartellla di lavoro
    
    l->levelSubFolder = -1;
    MotoreFILDER( myFILDER, l );                   // MOTORE 
    

    if( my_chdir( currDirWork ) ) return FATALITY; // Ritorno alla cartella iniziale
    free( currDirWork );                           // Libero la memoria allocata con my_getcwd()
    currDirWork = NULL;

    return SUCCESS;
}