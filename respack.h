/* This code, authored by Tuhkis, is released into the public domain. */

/*
 * This is a library that allows for the packing of multiple files into one.
 * This library is designed to avoid doing allocations itself and leaving
 * allocating buffers and loading files up to the user.
 *
 * This is only concerned with decoding and coding data. Loading, saving and
 * using the data is an issue for the user.
 *
 * This library is written in C89, but also ensures compatibility with C++.
 *
 * The intended way to use this library is by the user copying the source
 * into their own project and compiling it with the project.
 *
 * The best way to compile a C project is via an "unity build." A unity build
 * includes all the other source files inside one file via the #include
 * compiler directive. An unity build reduces build system complexity and
 * in some cases reduces build times because each header needs to be
 * included only once.
 *
 * In your project you can do something along these
 * lines to compile librespack:
 *
 * #include "respack.c"
 * 
 * The library can also be compiled with STB-style includes by doing this in
 * exactly one source file:
 * 
 * #define RESPACK_IMPLEMENTATION
 * #include "respack.h"
 *
 * Compiling librespack as a shared library is not encouraged, but is still
 * supported. Before compilation as a shared library it's better to define
 * the macro RESPACK_SHARED_LIBRARY.
 *
 * Librespack optionally depends on the C standard library for IO.
 * You can tell the library to forgo including any standard library headers
 * by defining the macro RESPACK_NO_INCLUDE_STD before its compilation.
 * If you do this you must also define the following macros:
 *   RESPACK_PUTS - A function that takes a string and print that to the stdio
 *   RESPACK_SIZE_T - A type that is equilevant to size_t.
 *   RESPACK_UINT8 - A type that represents one byte. Override if unsigned char is not one byte
 */

#ifndef RESPACK_H
#define RESPACK_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* I try to avoid platform specific code, but this is needed. */
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#ifdef RESPACK_SHARED_LIBRARY
#define RESPACK_API __declspec(dllexport)
#else
#define RESPACK_API __declspec(dllimport)
#endif /* RESPACK_SHARED_LIBRARY */
#else
#define RESPACK_API
#endif /* _WIN32 */

#ifndef RESPACK_NO_INCLUDE_STD
#include "stddef.h" /* size_t */
#include "inttypes.h" /* uint8_t */
#endif /* RESPACK_NO_INCLUDE_STD */

#ifndef RESPACK_SIZE_T
#define RESPACK_SIZE_T size_t
#endif /* RESPACK_SIZE_T */

#ifndef RESPACK_UINT8
#ifdef uint8_t
#define RESPACK_UINT8 uint8_t
#else
#define RESPACK_UINT8 unsigned char
#endif /* uint8_t */
#endif /* RESPACK_UINT8 */

/* type definitions */

struct resp_file_header
{
  RESPACK_SIZE_T beginning;
  RESPACK_SIZE_T size;
  int name_hash;
};

/**
 * resp_header is always found at the top of a respack file.
 * It describes the amount of files present in the packed file.
 * It also describes a few magic bytes at the top to ensure
 * that the file being decrypted is of the correct type.
 */
struct resp_header
{
  unsigned char magic[4]; /* Magic bytes at beginning, aligned to four bytes */
  RESPACK_SIZE_T packed_files; /* The amount of files in one files (inception) */
  struct resp_file_header *file_headers;
};

/* function prototypes */
RESPACK_API void resp_header_set_magic_bytes(struct resp_header *header);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* RESPACK_H */
#ifdef RESPACK_IMPLEMENTATION
#include "respack.c"
#endif /* RESPACK_IMPLEMENTATION */

