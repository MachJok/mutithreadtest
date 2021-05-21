#ifndef __DATAREFS_H__
#define __DATAREFS_H__
#include "include.h"
#include "structs.h"



state_t state_global;
mutex_t state_lock;

void find_datarefs();

void get_datarefs();

template <typename T>
inline T
state_get(const T *field)
{
        T tmp;
        mutex_enter(&state_lock);
        tmp = *field;
        mutex_exit(&state_lock);
        return (tmp);
}

#endif