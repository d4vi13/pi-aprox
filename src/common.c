#include "common.h"

void init_result(presult r, int rounding_method, double tolerance){
    memset(r, 0, sizeof * r);

    r->rounding_method = rounding_method;
    r->tolerance = tolerance;
}

void show_result(presult up, presult down){
    union value_visual piup, pidown, err, abs_err;
    piup.db = up->pi;
    pidown.db = down->pi;
    err.db = up->aprox_abs_error;
    abs_err.db = up->abs_error;

    printf("%d\n", up->iteration_count);
    printf("%.15e %lX\n", err.db, err.lint);
    printf("%.15e %lX\n", abs_err.db, abs_err.lint);
    printf("%.15e %lX\n", pidown.db, pidown.lint);
    printf("%.15e %lX\n", piup.db, piup.lint);
    printf("%ld\n", piup.lint - pidown.lint);
    printf("%d\n", up->flops);
    
}
