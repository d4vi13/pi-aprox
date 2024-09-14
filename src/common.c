#include "common.h"

void init_result(presult r, int rounding_method, double tolerance){
    memset(r, 0, sizeof * r);

    r->rounding_method = rounding_method;
    r->tolerance = tolerance;
}
