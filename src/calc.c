#include "calc.h"

static inline long int fact(int k){
    long int factorial = 1;
    
    for (int i = 2; i <= k; i++)
        factorial *= i;

    return factorial;
}

static inline double calc_kth_element(int k){
    return pow(2,k)*pow(fact(k),2)/fact(2*k+1);
}

static inline double aproximate_pi(double t, int* iter_num){
    double aprox = 0, last_aprox = t+1;
    int k = 0;
    
    printf("%.15e %.15e \n", aprox-last_aprox , t);

    while(!is_equal(aprox, last_aprox, t)){
        last_aprox = aprox; 

        aprox += calc_kth_element(k); 
        printf("%.10e\n", aprox);
        k++;
    }
    
    *iter_num = k;
    return aprox;
}

void calculate_result(presult res){
    fesetround(res->rounding_method);

    res->pi = aproximate_pi(res->tolerance, &res->iteration_count);

   printf("aprox %lf\n", res->pi); 

}

