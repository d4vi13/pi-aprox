#ifndef UTILS_H
#define UTILS_H

#include "common.h"

// gabs - generic absolute value
#define gabs(value) _Generic((value), \
    int : abs,                       \
    double: fabs,                    \
    float: fabsf,                    \
    long int: labs                   \
    )

#define is_equal(a, b, error) (gabs(a - b) <= error)
#define less_or_equal(a,b, error) ((a-b) <= error)

#endif
