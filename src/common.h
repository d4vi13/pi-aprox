#ifndef COMMON_H
#define COMMON_H

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fenv.h>
#include <string.h>

struct _result{
    long double pi;
    long double last_aprox;
    long double abs_error;
    long double aprox_abs_error;
    int ULP;
    int iteration_count;
    
    double tolerance;
    int rounding_method;
};

typedef struct _result result, *presult;

void init_result(presult r, int rounding_method, double tolerance);

#endif      
