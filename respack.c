/* This code, authored by Tuhkis, is released into the public domain. */
/* Further license information is provided at the end of the file. */

#ifndef RESPACK_IMPLEMENTATION
#include "respack.h"
#endif /* RESPACK_IMPLEMENTATION */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef RESPACK_NO_INCLUDE_STD
#include "stdio.h" /* puts */
#endif /* RESPACK_NO_INCLUDE_STD */

#ifndef RESPACK_PUTS
#define RESPACK_PUTS puts
#endif /* RESPACK_PUTS */

/* Constants */

/* The magic bytes that begin every respack file. */
char _RESP_MAGIC_BYTES[4] = { 0xB0, 0x0B, 0x13, 0x50 };

#ifdef __cplusplus
}
#endif /* __cplusplus */

/*
LICENSE:
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

