#ifndef UTILS_H
#define UTILS_H

#include "common.h"

// gabs - generic absolute value
#define gabs(value) _Generic((value),       \
    int : abs(value),                       \
    double: fabs(value),                    \
    float: fabsf(value),                    \
    long int: labs(value),                 \
    long double: fabsl(value)               \
    )

#define is_not_close_enough(a, b, error) !(gabs(a - b) <= error)
#define less_or_equal(a,b, error) ((a-b) <= error)

#endif
