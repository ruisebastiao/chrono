#ifndef CHAPIPYTHON_H
#define CHAPIPYTHON_H

//////////////////////////////////////////////////
//  
//   ChApiPYTHON.h
//
//   Base header for all headers that have symbols
//   that can be exported.
//
//   HEADER file for CHRONO,
//	 Multibody dynamics engine
//
// ------------------------------------------------
// 	 Copyright:Alessandro Tasora / DeltaKnowledge
//             www.deltaknowledge.com
// ------------------------------------------------
///////////////////////////////////////////////////

//#pragma warning(disable: 4251)

#include "core/ChPlatform.h"


// Chrono::Engine unit PYTHON version
//
// This is an integer, as 0xaabbccdd where
// for example version 1.2.0 is 0x00010200

#define CH_VERSION_UNIT_PYTHON 0x00010200


// When compiling this library, remember to define CH_API_COMPILE_UNIT_MPI
// (so that the symbols with 'ChApiMPI' in front of them will be
// marked as exported). Otherwise, just do not define it if you 
// link the library to your code, and the symbols will be imported.

#if defined(CH_API_COMPILE_UNIT_PYTHON)
	#define ChApiPYTHON ChApiEXPORT
#else
	#define ChApiPYTHON ChApiINPORT	
#endif




#endif  // END of header