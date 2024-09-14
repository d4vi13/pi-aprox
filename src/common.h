#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fenv.h>
#include <string.h>

struct _result{
    double pi;
    double abs_error;
    double aprox_abs_error;
    double tolerance;
    int ULP;
    int iteration_count;
    int rounding_method;
};

typedef struct _result result, *presult;

void init_result(presult r, int rounding_method, double tolerance);

#endif      
