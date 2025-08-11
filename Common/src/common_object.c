#include "common_object.h"
#include "common_erorrs.h"

typedef void(*function_cb)(void*);

int64_t common_object_construct(void *context, int32_t methods) {
    CHECK_NULL(context);

    size_t ptr_size = sizeof(function_cb);

    for(size_t i = 0; i < methods; i++) {
        CHECK_NULL( context + (ptr_size*i) );
    }

    return ERR_OK;
}