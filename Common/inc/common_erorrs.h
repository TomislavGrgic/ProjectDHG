#ifndef _COMMON_ERRORS_H__
#define _COMMON_ERRORS_H__

#include <stddef.h>

typedef enum {
    ERR_OK = 0,
    ERR_FAIL = -1,
    ERR_INVALID_PARAMETER = -2,
    ERR_NULL_PTR = -3,
    ERR_OBJ_SIZE = -4
} Common_Error_E;

#define CHECK_ERROR(expression)     do{ int ret = (expression); if(ret != ERR_OK) return ret; }while(0)
#define CHECK_NULL(ptr)             do{ if(ptr == NULL) return ERR_NULL_PTR; }while(0);

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /*_COMMON_ERRORS_H__*/