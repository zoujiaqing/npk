/*

	npk - General-Purpose File Packing Library
	Copyright (c) 2009 Park Hyun woo(ez@amiryo.com)

	base type and definitions of npk

	See README for copyright and license information.

*/
#include "npk_conf.h"

#ifndef _NPK_BASE_H_
#define _NPK_BASE_H_

// Type
typedef int								NPK_RESULT;
typedef void*							NPK_PACKAGE;
typedef void*							NPK_ENTITY;
typedef int								NPK_HANDLE;
typedef unsigned int					NPK_FLAG;
typedef long							NPK_TEAKEY;
typedef char							NPK_CHAR;
typedef const NPK_CHAR*					NPK_CSTR;
typedef NPK_CHAR*						NPK_STR;
typedef int								NPK_SIZE;
typedef unsigned short					NPK_NAMESIZE;
typedef char							NPK_BYTE;
typedef unsigned long long				NPK_64BIT;
typedef int								NPK_TIME;

// NPK
#define NPK_SIGNATURE					"NPK!"
#define NPK_OLD_SIGNATURE				"NPAK"
#define NPK_SIGNATURE_LENGTH			4
#define NPK_MAXFOLDERNFILENAME			512
#define NPK_MIN_SIZE_ZIPABLE			256

// Version Information
#define NPK_VERSION_REFACTORING			21
#define NPK_VERSION_UNIXTIMESUPPORT		22
#define NPK_VERSION_PACKAGETIMESTAMP	23
#define NPK_VERSION_CURRENT				NPK_VERSION_PACKAGETIMESTAMP

// Entity Flag
#define NPK_ENTITY_NULL					0
#define NPK_ENTITY_TEXTFILE				0x00000001	// NOT USED
#define NPK_ENTITY_ENCRYPT				0x00000100	// Encrypted.
#define NPK_ENTITY_COMPRESS				0x00001000	// Zip-compressed.
#define NPK_ENTITY_REVERSE				0x00100000	// Encryption & Compression order.(0=E->C,1=C->E)
#define NPK_ENTITY_INHERIT				0xF0000000

// Callback
#define NPK_ACCESSTYPE_READ				0
#define NPK_ACCESSTYPE_WRITE			1

#define NPK_PROCESSTYPE_FILE			0
#define NPK_PROCESSTYPE_ENTITYHEADER	1
#define NPK_PROCESSTYPE_ENTITY			2
#define NPK_PROCESSTYPE_PACKAGEHEADER	3
#define NPK_PROCESSTYPE_PACKAGE			4

typedef	int( *NPK_CALLBACK )(	int accessType,
								int processType,
								NPK_CSTR identifier,
								NPK_SIZE current,
								NPK_SIZE total
								);

#endif /* _NPK_BASE_H_ */
