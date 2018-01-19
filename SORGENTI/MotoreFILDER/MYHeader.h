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
/**
 *  \file   MYHeader.h
 *  \brief  Header Generico per le mie Librerie
 * 
*
 */
/////////////////////////////////////////DEFENCE  ///////////////////////////////////////////////
#ifndef MYHEADER_H
#define MYHEADER_H

#if _MSC_VER > 1200
#pragma once
#endif

#define __MYHEADER_VERSION           1.00
#define __MYHEADER_MAJOR_VERSION     1
#define __MYHEADER_MINOR_VERSION     00
#define __MYHEADER_PATCHLEVEL        00

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#include <stdlib.h>
#include <stdio.h>

#if defined (_MSC_VER) || defined(_clang_) //SOLO VisualStudio
#pragma warning(disable : 4996)
#pragma warning(disable : 4706)
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// MACRO ///////////////////////////////////////////////////
/** 
 * \def CLRSCR
 * \brief   Macro per la pulizia della console
 */
#if defined(_WIN32)
#   define CLRSCR do{system("cls");}while(0)
#elif defined(__GNUC__) // Include __Cygwin__ e __MigWN__
//Cygwin non supporta system("clear")
#    define CLRSCR do{printf("\e[2J");}while(0)
#endif

/**
 * \def     NEWPAGE
 * \brief   Genera una schermata bianca in una console previa pressione di un tasto
 */
#ifndef  NEWPAGE
#    define NEWPAGE do{ \
   fputs("PRESS ANY KEY FOR NEWPAGE...",stdout); \
   if( getchar()=='\n') {\
   clrscr(); \
   }else \
    delline(); \
   }while(0)
#endif // NEWPAGE

/**
 * \def     ACAPO
 * \brief   Manda in una nuova riga il cursore (Immette un '\\n' nella console)
 */
#define ACAPO do{ \
                 putchar('\n'); \
                 }while(0)

/** 
 *  \def    SBUFFER
 *  \brief  Macro per csvuotare il buffer della tastiera
 */
#define SBUFFER do{while((getchar())!='\n');}while(0)

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// ENUM /////////////////////////////////////
/** 
 * \enum    _BOOL_
 * \brief   Macro per creare una variabile booleana
 **/
#include <stdbool.h>
typedef enum _BOOL_  {
	myfalse = 0,		//!< Variabile booleana FALSE
	mytrue  = !myfalse  //!< Variabile booleana TRUE
} MYBOOL;


////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// TYPEDEF ///////////////////////////////////



//typedef unsigned char UCHAR;
typedef unsigned char INDEX;  //!< Tipo per gli indici fino a 255
typedef unsigned char UASCII; //!< Tipo per caratteri ASCII 0-255


#ifdef __cplusplus
}
#endif // __cplusplus


#endif // MYHEADER_H