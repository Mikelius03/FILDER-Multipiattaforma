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
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#include <fcntl.h>
#include <sys\types.h>
#include <sys\stat.h>


#include "MYHeader.h"
#include "MYErrno.h"
#include "../LinuxFunction/findfirst.h"


#if defined(_WIN32) || defined(WIN64)
#	include <direct.h>
#	include <io.h>
#elif defined(__GNUC__)
#	include <unistd.h>
#endif

#if defined(WIN32) || defined(WIN64) || defined(__clang__)
#	define STAT  _stat
#	define FSTAT _fstat
#else
#	define STAT  stat
#   define FSTAT fstat
#endif // win

#define MYFILE(x) FILE* x = NULL

#define  MY_ISOPEN(nameFile)  my_rename( nameFile,    nameFile )
#define   MY_TESTF(nameFile)  my_access( nameFile,    EXISTS   )
#define  MY_REWIND(stream)     my_fseek(   stream, 0, SEEK_SET )
#define MY_FORWARD(stream)     my_fseek(   stream, 0, SEEK_END )

#if defined(WIN32) || defined(WIN64) || defined(__clang__)
#    define	_S_ISDIR(m)	 (((m) & _S_IFMT) == _S_IFDIR)
#    define	_S_ISFIFO(m) (((m) & _S_IFMT) == _S_IFIFO)
#    define	_S_ISCHR(m)	 (((m) & _S_IFMT) == _S_IFCHR)
#    define	_S_ISREG(m)	 (((m) & _S_IFMT) == _S_IFREG)
#endif

/////////////////////////////// §FUNCTION_LIST§ ////////////////////////////////
    typedef enum MODEACCESS {
        EXISTS     = 0,
        ONLY_READ  = 2,
        ONLY_WRITE = 4,
        READ_WRITE = 6
    }MODEACCESS;
///////////////////////////////// §FUNCTION_LIST§ //////////////////////////////
    typedef enum MYSEEK {
        MY_SEEKSET = SEEK_SET,
        MY_SEEKCUR = SEEK_CUR,
        MY_SEEKEND = SEEK_END
    }MYSEEK;
///////////////////////////////// §FUNCTION_LIST§ //////////////////////////////

//////////////////////////////////// TYPEDEF ///////////////////////////////////
//typedef unsigned int index;     /// Tipo per indici int di ARRAY
typedef char*        pathF;     /// Tipo per percorsi di File e cartelle
typedef char*        nameF;     /// Tipo per nomi di FILE
typedef const char*  c_pStr;    /// Tipo per nomi di FILE
typedef const char*  c_nameF;   /// Tipo per nomi di FILE const































































/*----------------------------------------------------------------------------*/
    MYRETURN  my_fopen(
        _Inout_	    FILE**		streamF,
        _In_z_	    const char*	name,
        _In_z_	    const char*	mode
    );
/*----------------------------------------------------------------------------*/
    MYRETURN my_fclose(
        	FILE** streamF
    );

/*----------------------------------------------------------------------------*/
    MYRETURN my_ftell(
        FILE*  ptrFile,
        long*  posFile
    );
/*----------------------------------------------------------------------------*/

MYRETURN  my_fseek(FILE** ptrFile, long offset, MYSEEK posFile );
/*----------------------------------------------------------------------------*/
MYRETURN   my_feof(FILE*  stream);
/*----------------------------------------------------------------------------*/
MYRETURN  myRewind(FILE** stream);
/*----------------------------------------------------------------------------*/
MYRETURN myForward(FILE** stream);
/*----------------------------------------------------------------------------*/
MYRETURN  my_rename(const char* oldName, const char* newName);
/*----------------------------------------------------------------------------*/
MYRETURN  my_remove(const char* NomeFile);
/*----------------------------------------------------------------------------*/
MYRETURN   my_access(const char* file, MODEACCESS mode);
/*-----------------------------------------------------------------------*/
MYRETURN myTestFile(const char* NomeFile);
/*----------------------------------------------------------------------------*/
MYRETURN  myIsOpenF(const char* name);
/*----------------------------------------------------------------------------*/
MYRETURN   myCountF(const char* file, int*  count);
/*----------------------------------------------------------------------------*/
MYRETURN  mydimFile(const char* nameFile, long* dimFile);
/*----------------------------------------------------------------------------*/
MYRETURN     mydimF(FILE* ptrFile, long* dimFile);
/*----------------------------------------------------------------------------*/

/*============================================================================*/
    MYRETURN my_fgetpos(
      _In_        FILE* stream,
        fpos_t* count
    );
/*----------------------------------------------------------------------------*/
    MYRETURN my_fsetpos(
       _In_       FILE* stream,
       fpos_t* count
    );
/*============================================================================*/
    MYRETURN my_open(
        const char *filename,
        int oflag,
        int pmode,
        int* fd
    );
/*============================================================================*/
    MYRETURN my_close(
        int fd
    );
/*============================================================================*/
    MYRETURN my_closeS(
        int fd
    );
/*============================================================================*/
    MYRETURN my_fileno(
        FILE* stream,
        int* fd
    );
/*============================================================================*/
    MYRETURN my_stat(
        const char* name,
        struct STAT* strcFile
    );
/*============================================================================*/
    MYRETURN my_fstat(
        int fd,
        struct stat *strcFile);
/*============================================================================*/
#ifdef __linux__
    MYRETURN my_lstat(const char* name, struct STAT* strcFile);
#endif
    MYRETURN my_clearerr(
        FILE* stream
    );
/*============================================================================*/
    MYRETURN   my_ferror(
        FILE* stream
    );
/*============================================================================*/
/*============================================================================*/
/*============================================================================*/
/*============================================================================*/

#ifdef __cplusplus
}
#endif // __cplusplus
