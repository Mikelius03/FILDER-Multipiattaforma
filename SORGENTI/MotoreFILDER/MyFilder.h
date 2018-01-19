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

#ifndef ELENCOFILDER_H
#define ELENCOFILDER_H
#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#ifdef  _MSC_VER
#include <io.h>
#include <direct.h>
#endif //  _MSC_VER


#include "MyFilder.h"
#include "MYErrno.h"

#include "../FileDirectory/FileDirectory.h"
#if defined(__linux__) || defined(__CYGWIN__)
#include "../LinuxFunction/findfirst.h"
#endif

//////////////////////////////////// DEFINE ////////////////////////////////////
#ifndef STCDATAF
#define STCDATAF struct _finddata_t
#endif

#define ARRAY_SIZE(Array) \
   (sizeof(Array) / sizeof((Array)[0]))

#define BOOL short
#define TRUE 1
#define FALSE 0

///////////////////////////////////// ENUM /////////////////////////////////////
typedef enum _TYPEF{
    TFOLDER   = 0,           /// RAPPRESENTA UNA CARTELLA
    TFILE     = 1            /// RAPPRESENTA UN FILE
}TYPEF;

/////////////////////////////////////////////////////////////
typedef struct _DIRDATA {

    char     szBuf[1024];
    int      levelSubFolder;
    int      fRecurse;
    BOOL     fOk;
    BOOL     fIsDir;
    STCDATAF FindData;
} DIRDATA;

typedef struct SettFILDER{
    char dirWork[MY_MAXPATH]; //< Cartella dove cercare File e Directory
    char dirSave[MY_MAXPATH]; //< Cartella dove salvare la lista di File e Directory
    char   patternFILDER[10]; //< Patter di ricerca per i file
    BOOL          recSearch; //< Ricorsione Att/Disatt
}SettFILDER;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////

SettFILDER* inizializeConsole();
SettFILDER* inizializeCommandLine(char* argv[]);

MYRETURN searchF( SettFILDER* myFILDER );

void MotoreFILDER( SettFILDER* settBase, DIRDATA* h );
MYBOOL IsChildDir( STCDATAF *file );
MYBOOL FindNextChildDir( intptr_t hFilder, STCDATAF *lpFindData );
intptr_t FindFirstChildDir( char* pattern, STCDATAF *pStcData );


#endif // !LISTA_H
