#ifndef UTILS_H
#define UTILS_H

#include "common.h"
#include <math.h>


// gabs - generic absolute value
#define gabs(value) _Generic((value), \
    int : abs,                       \
    double: fabs,                    \
    float: fabsf,                    \
    long int: labs                   \
    )

#endif
