#include "calc.h"

static inline void update_components(psum_components comp, int k){
    comp->pow_of_two *= 2;
    comp->fact *= k;
    comp->fact_2k *= 2*k;
    comp->fact_2k *= 2*k + 1;

}

static inline double fact(int k){
    double factorial = 1;
    
    for (int i = 2; i <= k; i++)
        factorial *= i;

    return factorial;
}

static inline double calc_kth_element(int k, psum_components comp){
    return 2*comp->pow_of_two*comp->fact*comp->fact/comp->fact_2k;
}

static inline double aproximate_pi(double t, int* iter_num, double* plast_aprox, int* flops){
    long double aprox = 0, last_aprox = t+1;
    sum_components comp = {1 , 1 , 1}; 
    int k = 0;

    while(is_not_close_enough(aprox, last_aprox, t) ){
        last_aprox = aprox; 
        
        aprox += calc_kth_element(k, &comp); 
        
        *flops += 11;
        printf("t %.15e\n", gabs(aprox - last_aprox));
        k++; 
        update_components(&comp, k);
    }
    
    *iter_num = k;
    *plast_aprox = last_aprox;
    return aprox;
}

void calculate_result(presult res){
    union value_visual pi, last;
    fesetround(res->rounding_method);

    res->pi = aproximate_pi(
        res->tolerance,
        &res->iteration_count,
        &res->last_aprox,
        &res->flops
    );

    res->aprox_abs_error = gabs(res->pi-res->last_aprox);
    res->abs_error = gabs(M_PI_L-res->pi);
    
    pi.db = res->pi;
    last.db = res->last_aprox;
    res->ULP = pi.lint - last.lint;
    
}

