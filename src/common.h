#ifndef COMMON_H
#define COMMON_H

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fenv.h>
#include <string.h>

struct _result{
    double pi;
    double last_aprox;
    double abs_error;
    double aprox_abs_error;
    int ULP;
    int iteration_count;
    int flops;

    double tolerance;
    int rounding_method;
};

typedef struct _result result, *presult;

union value_visual {
    double db;
    long int lint;
};

extern void init_result(presult r, int rounding_method, double tolerance);

extern void show_result(presult up, presult down);

#endif      
