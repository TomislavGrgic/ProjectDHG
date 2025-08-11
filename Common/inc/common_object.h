#ifndef _COMMON_OBJECT_H__
#define _COMMON_OBJECT_H__

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int64_t common_object_construct(void *context, int32_t methods);

#ifdef __cplusplus
}
#endif

#endif /*_COMMON_OBJECT_H__*/