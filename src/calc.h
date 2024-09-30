#ifndef CALC_H
#define CALC_H

#include "common.h"
#include "utils.h"

#define M_PI_L 3.141592653589793238462643383279502984L

struct sum_components{
    double fact;
    double fact_2k;
    long int pow_of_two;
};

typedef struct sum_components sum_components, *psum_components;

extern void calculate_result(presult res);

#endif
