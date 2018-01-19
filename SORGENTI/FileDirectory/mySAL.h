/**
 *  \file MYSal.h
 *  \brief Header contenente nomenclatura SAL semplificata per le mie Librerie
 */
/////////////////////////////////////////////// DEFENCE GUARD ///////////////////////////////////////////////
#ifndef MYSAL_H
#define MYSAL_H


#if _MSC_VER > 1200
#pragma once
#endif

#define __MYHEADER_VERSION           1.00
#define __MYHEADER_MAJOR_VERSION     1
#define __MYHEADER_MINOR_VERSION     00
#define __MYHEADER_PATCHLEVEL        00
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef _MSC_VER
#include <sal.h>
#else
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#define _Reserved_
#define _Const_

// Input parameters --------------------------
#define _In_
#define _In_opt_
#define _In_z_
#define _In_opt_z_

// Output parameters --------------------------
#define _Out_
#define _Out_opt_

// Inout parameters ----------------------------
#define _Inout_
#define _Inout_opt_
#define _Inout_z_
#define _Inout_opt_z_


// Pointer to pointer parameters -------------------------
#define _Outptr_
#define _Outptr_result_maybenull_
#define _Outptr_opt_
#define _Outptr_opt_result_maybenull_
#define _Outptr_result_z_
#define _Outptr_opt_result_z_
#define _Outptr_result_maybenull_z_
#define _Outptr_opt_result_maybenull_z_

// Annotations for _Outptr_ parameters where the output pointer is set to NULL if the function fails->
#define _Outptr_result_nullonfailure_
#define _Outptr_opt_result_nullonfailure_


// Annotations for output reference to pointer parameters->
#define _Outref_
#define _Outref_result_maybenull_


// Annotations for output reference to pointer parameters that guarantee
// that the pointer is set to NULL on failure->
#define _Outref_result_nullonfailure_

#endif
#endif