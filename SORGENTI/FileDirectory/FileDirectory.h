/**
 * \file FileDirectory.h
 *
 * \brief Header for MyLibrary - File and Directory
 */
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
////////////////////////////////////////////////////////////////////////////////


#include "MYHeader.h"
//#include "mySAL.h"
//#include "MyPrint.h"
#include "MYErrno.h"

#include <limits.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#if defined(_MSC_VER) || defined(__clang__)
#	include <direct.h>
#	include <io.h>
#elif defined(__GNUC__)
#	include <unistd.h>
#endif

////////////////////////////////////////////////////////////////////////////////


#if defined _MSC_VER
#define MY_MAXPATH (_MAX_PATH)
#elif defined(__clang__)
#define MY_MAXPATH (FILENAME_MAX)
#else
#define MY_MAXPATH (PATH_MAX)
#endif // DEBUG


#ifndef FD_SETSIZE
#define FD_SETSIZE 64
#endif // !FD_SETSIZE

#define MY_STAT stat

////////////////////////////////////////////////////////////////////////////////

#define DRIVE_TOCHAR(drive) ( (drive) + ('A') - 1 )
#define DRIVE_TOINT(drive)  ( (drive) - ('A') + 1 )
#define MY_ISOPEN(nameFile) my_rename( nameFile,    nameFile )
#define MY_TESTF(nameFile)  my_access( nameFile,    EXISTS   )
#define MY_REWIND(stream)   my_fseek( stream, 0, SEEK_SET )
#define MY_FORWARD(stream)  my_fseek( stream, 0, SEEK_END )

#    define	MY_ISFIFO(m) (((m) & MY_IFMT) == MY_IFIFO) // Fifo/Pipe
#    define	MY_ISCHR(m)	 (((m) & MY_IFMT) == MY_IFCHR) // Caracter
#    define	MY_ISDIR(m)	 (((m) & MY_IFMT) == MY_IFDIR) // Directory
#    define	MY_ISREG(m)	 (((m) & MY_IFMT) == MY_IFREG) // Regukar File

/////////////////////////////// §FUNCTION_LIST§ ////////////////////////////////

/**
 * \enum MODEACCESS
 * \brief enum per la gestione dei Permessi Lettura/Scrittura
 */
typedef enum {
    EXISTS     = 0, /**< The File Exists                         */
    ONLY_READ  = 2, /**< The File have Read Permission           */
    ONLY_WRITE = 4, /**< The File have Write Permission          */
    READ_WRITE = 6, /**< The File have Read and Write Permission */
}MODEACCESS;
///////////////////////////////// §FUNCTION_LIST§ //////////////////////////////
typedef enum {
    MY_SEEKSET = SEEK_SET,
    MY_SEEKCUR = SEEK_CUR,
    MY_SEEKEND = SEEK_END
}MYSEEK;
///////////////////////////////// §FUNCTION_LIST§ //////////////////////////////
#if defined (_MSC_VER)
    typedef enum FLAG_OPEN {
        MY_RDONLY      = _O_RDONLY,      ///      0
        MY_WRONLY      = _O_WRONLY,      ///      1
        MY_RDWR        = _O_RDWR,        ///      2
        MY_APPEND      = _O_APPEND,      ///      8
        MY_RANDOM      = _O_RANDOM,      ///     16
        MY_SEQUENTIAL  = _O_SEQUENTIAL,  ///     32
        MY_TEMPORARY   = _O_TEMPORARY,   ///     64
        MY_NOINHERIT   = _O_NOINHERIT,   ///    128
        MY_CREAT       = _O_CREAT,       ///    256
        MY_TRUNC       = _O_TRUNC,       ///    512
        MY_EXCL        = _O_EXCL,        ///   1024
        MY_SHORT_LIVED = _O_SHORT_LIVED, ///   4096
        MY_OBTAIN_DIR  = _O_OBTAIN_DIR,  ///   8192
        MY_TEXT        = _O_TEXT,        ///  16384
        MY_BINARY      = _O_BINARY,      ///  32768
        MY_U16TEXT     = _O_U16TEXT,     /// 131072
        MY_U8TEXT      = _O_U8TEXT       /// 262144
    }FLAG_OPEN;
#else
//#elif defined __linux__
    typedef enum FLAG_OPEN {
        MY_RDONLY      = O_RDONLY,     //0
        MY_WRONLY      = O_WRONLY,     //1
        MY_RDWR        = O_RDWR,       //2
        MY_APPEND      = O_APPEND,     //8
       // MY_RANDOM      = O_RANDOM,     //16
      //  MY_SEQUENTIAL  = O_SEQUENTIAL, //32
       // MY_TEMPORARY   = O_TEMPORARY,  //64
      //  MY_NOINHERIT   = O_NOINHERIT,  //128
        MY_CREAT       = O_CREAT,      //256
        MY_TRUNC       = O_TRUNC,      //512
        MY_EXCL        = O_EXCL,       //1024
    //    MY_SHORT_LIVED = O_SHORT_LIVED,//4096
     //   MY_TEXT        = O_TEXT,       //16384
       // MY_BINARY      = O_BINARY,     //32768
    }FLAG_OPEN;
#endif
////////////////////////////////////////////////////////////////////////////////
#if defined (_WIN32)
    typedef enum FLAG_PMODE {
        MY_IWRITE    = _S_IWRITE,
        MY_IREAD     = _S_IREAD,
        MY_READWRITE = _S_IREAD|_S_IWRITE
    }FLAG_PMODE;
    #else
//#elif defined (__linux__)
    typedef enum FLAG_PMODE {
        MY_IWRITE    = S_IWRITE,
        MY_IREAD     = S_IREAD,
        MY_READWRITE = S_IREAD|S_IWRITE
    }FLAG_PMODE;
#endif



////////////////////////////////////////////////////////////////////////////////

#if defined (_WIN32)
typedef enum FLAG_ {
    MY_IFMT   = _S_IFMT,
    MY_FIFO   = _S_IFIFO,
    MY_IFCHR  = _S_IFCHR,
    MY_IFDIR  = _S_IFDIR,
    MY_IFREG  = _S_IFREG,

}FLAG_P;
#else
//#elif defined (__linux__)
typedef enum FLAG_ {
    MY_IFMT   = S_IFMT,
    MY_IFCHR  = S_IFCHR,
    MY_IFDIR  = S_IFDIR,
    MY_IFREG  = S_IFREG,
 //   MY_IBLK   = S_ISBLK,
    MY_FIFO   = S_IFIFO,
    MY_IFLNK  = S_IFLNK,
    MY_IFSOCK = S_IFSOCK
}FLAG_P;
#endif

//////////////////////////////////////////////// DIRECTORY§ ////////////////////////////////////////////////
MYRETURN  my_chdir( const char*  path );               /* Setta la cartella corrente                       */
MYRETURN     isDir( const char*  path, int* typeFile); /*                                                  */
MYRETURN  my_mkdir( const char*  path );               /* Crea una cartella                                */
MYRETURN  my_rmdir( const char*  path );               /* Elimina una cartella                             */
MYRETURN my_getcwd(       char** path );               /* Acquisisce il percorso della cartella corrente   */

//#ifdef _MSC_VER


                                                       /**
 * \fn  MYRETURN  my_chdrive( _In_ int drive )
 * \brief checca il dir
 *
 * \param[in] drive che te ne frega
 */
MYRETURN  my_chdrive( int drive );
MYRETURN my_getdrive( int* drive );
MYRETURN  my_getdcwd( int  drive, char** buffer );
//#endif // _MSC_VER
/*
MYRETURN      deldir( const char* path );   Cancella il contenuto di una cartella
MYRETURN list_Folder( const char* path );
MYRETURN    isFolder( STCDATAF *path );
*/

/////////////////////////////// § FILE § ////////////////////////////////


MYRETURN my_fopen( FILE** streamF, const char* nameFile, const char* mode );
MYRETURN my_fclose( FILE** streamF );
MYRETURN   my_open( const char *nameFile, FLAG_OPEN oflag, FLAG_PMODE pmode, int* fd );
MYRETURN  my_close( int fd );
MYRETURN my_closeS( int fd );
MYRETURN my_fdopen(  int        fd, const char* modeAccess,      FILE**   fp );
MYRETURN my_ftell( FILE*  streamF, long* posFile );
MYRETURN my_fseek( FILE** streamF, long  offset, MYSEEK posFile );
MYRETURN  my_feof( FILE*  streamF );
MYRETURN my_access( const char* nameFile, MODEACCESS modeAccess );
MYRETURN my_remove( const char* nameFile );
MYRETURN my_rename( const char* oldName, const char* newName );
MYRETURN my_dimFileN( const char* nameFile, long* dimFile );
MYRETURN my_dimFileS( FILE*  streamF, long* dimFile );
MYRETURN my_dimFileD( const  int        fd, long* dimFile );
MYRETURN my_fgetpos( FILE* streamF, fpos_t* count );
MYRETURN my_fsetpos( FILE* streamF, fpos_t* count );
MYRETURN  my_dup( int oldfp, int* newfp );
MYRETURN my_dup2( int oldfd, int* newfd );
MYRETURN   my_fileno( FILE* streamF, int* fd );
MYRETURN   my_FDtest(  int  fd );
MYRETURN my_clearerr( FILE* streamF );
MYRETURN   my_ferror( FILE* streamF );



#if defined( _MSC_VER) || defined(__clang__)
MYRETURN my_fstat( int fd, struct _stat *strcFile );
MYRETURN my_stat( const char* nameFile, struct _stat* strcFile );
#elif defined(__GNUC__)
MYRETURN  my_stat( const char* nameFile, struct stat*   strcFile );
MYRETURN my_fstat( const  int        fd, struct stat* strcFile );
#endif

#ifdef __linux__
MYRETURN my_lstat( const char* nameFile, struct MY_STAT* strcFile );
#endif
MYRETURN my_countF( const char* nameFile, int*  count );
////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif // __cplusplus
