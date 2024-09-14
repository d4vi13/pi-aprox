#include "calc.h"

static inline long double fact(int k){
    long double factorial = 1;
    
    for (int i = 2; i <= k; i++)
        factorial *= i;

    return factorial;
}

static inline long double calc_kth_element(int k){
    return 2*pow(2,k)*pow(fact(k),2)/fact(2*k+1);
}

static inline long double aproximate_pi(double t, int* iter_num, long double* plast_aprox){
    long double aprox = 0, last_aprox = t+1;
    int k = 0;

    while(is_not_close_enough(aprox, last_aprox, t) ){
        last_aprox = aprox; 
        
        aprox += calc_kth_element(k); 
        
        k++;
    }
    
    *iter_num = k;
    *plast_aprox = last_aprox;
    return aprox;
}

void calculate_result(presult res){
    fesetround(res->rounding_method);

    res->pi = aproximate_pi(
        res->tolerance,
        &res->iteration_count,
        &res->last_aprox
    );

    res->aprox_abs_error = gabs(res->pi-res->last_aprox);
    res->abs_error = gabs(M_PI_L-res->pi);

    res->ULP = (long long int)res->pi - (long long int) res->last_aprox;
}

