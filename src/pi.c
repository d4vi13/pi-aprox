#include "common.h"
#include "utils.h"
#include "calc.h"

int main(){

    double tolerance;
    result aprox_down, aprox_up;

    scanf("%lf", &tolerance);
    
    init_result(&aprox_up, FE_UPWARD, tolerance);
    init_result(&aprox_down, FE_DOWNWARD, tolerance);

    calculate_result(&aprox_down);
    calculate_result(&aprox_up);

    //show_result(&aprox_down,&aprox_up);

    return 0;
}
