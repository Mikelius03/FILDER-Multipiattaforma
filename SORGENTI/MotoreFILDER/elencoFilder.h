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
// doppia include guard

#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../FileDirectory/FileDirectory.h"
#include "../LinuxFunction/findfirst.h"

//////////////////////////////////// DEFINE ////////////////////////////////////
#define STCDATAF struct _finddata_t

///////////////////////////////////// ENUM /////////////////////////////////////
typedef enum _TYPEF{
    TFOLDER   = 0,           /// RAPPRESENTA UNA CARTELLA
    TFILE     = 1            /// RAPPRESENTA UN FILE
}TYPEF;


//////////////////////////////////// STRUCT ////////////////////////////////////
typedef struct _DIRDATA{
    int        levSubF;      //!< Livello di SubFolder
    bool       recSearch;
   char       szBuf[1024];
    int        nIndent;
    bool       fOk;
    bool       fIsDir;
    STCDATAF  FindData;
} DIRDATA;

typedef struct listFILDER{
//    unsigned IDFILDER;
    char name[260];
 //   long long sizeFile;
    struct listtFILDER *next;
}listFILDER;

///////////////////////////// DEFINIZIONI FUNZIONI /////////////////////////////
MYRETURN searchF( const char* path, bool recSearch );
MYRETURN elencoFilder( DIRDATA* pStcData );
bool IsChildDir( STCDATAF *file );
bool FindNextChildDir( intptr_t hFilder, STCDATAF *lpFindData );
intptr_t FindFirstChildDir( char* pattern, STCDATAF *pStcData );
#endif // !LISTA_H
