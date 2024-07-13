/* This code, authored by Tuhkis, is released into the public domain. */
/* Further license information is provided at the end of the file. */

/*
 * This is a library that allows for the packing of multiple files into one.
 * This library is designed to avoid doing allocations itself and leaving
 * allocating buffers and loading files up to the user.
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
 */

#ifndef RESPACK_H
#define RESPACK_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* type definitions */

/**
 * resp_header is always found at the top of a respack file.
 * It describes the amount of files present in the packed file.
 * It also describes a few magic bytes at the top to ensure
 * that the file being decrypted is of the correct type.
 */
struct resp_header
{
  char magic[4];
  int packed_files;
};
typedef struct resp_header resp_Header;

/* function prototypes */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* RESPACK_H */
#ifdef RESPACK_IMPLEMENTATION
#include "respack.c"
#endif /* RESPACK_IMPLEMENTATION */

/*
LICENSE (unlicense):
This is free and unencumbered software released into the public domain.
Anyone is free to copy, modify, publish, use, compile, sell, or distribute this
software, either in source code form or as a compiled binary, for any purpose,
commercial or non-commercial, and by any means.
In jurisdictions that recognize copyright laws, the author or authors of this
software dedicate any and all copyright interest in the software to the public
domain. We make this dedication for the benefit of the public at large and to
the detriment of our heirs and successors. We intend this dedication to be an
overt act of relinquishment in perpetuity of all present and future rights to
this software under copyright law.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

