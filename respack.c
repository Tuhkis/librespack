/* This code, authored by Tuhkis, is released into the public domain. */

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
static unsigned char _RESP_MAGIC_BYTES[4] = { 0xB0, 0x0B, 0x13, 0x50 };

/* Procedures */
RESPACK_API void resp_header_set_magic_bytes(struct resp_header *header)
{
  header->magic[0] = _RESP_MAGIC_BYTES[0];
  header->magic[1] = _RESP_MAGIC_BYTES[1];
  header->magic[2] = _RESP_MAGIC_BYTES[2];
  header->magic[3] = _RESP_MAGIC_BYTES[3];
}

RESPACK_API int resp_header_valid_magic_bytes(struct resp_header *header)
{
  return (
    header->magic[0] == _RESP_MAGIC_BYTES[0] &&
    header->magic[1] == _RESP_MAGIC_BYTES[1] &&
    header->magic[2] == _RESP_MAGIC_BYTES[2] &&
    header->magic[3] == _RESP_MAGIC_BYTES[3]
  );
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

