#include<iostream>
#include<math.h>
#include<thread>

long double fun(long double x){
    return std::expl(-1*(x*x));
};

int main(){
    const long double delta = powl(2,-30);
    long unsigned int mil = 10000000;
    long double soma = 0;
    long double intervalo = 6.L;
    unsigned long long int passos = ceil(intervalo/delta);
    std::cout<< passos << '\n';

    for(unsigned long long int i = 0; i < passos; i++){
        soma += delta*fun(-3.L+delta*i);
        if(i%mil == 0){
            std::cout << (long double)i/passos*100 << '%' << '\n';
            std::cout << i << '\n';
            std::cout << soma << '\n';

        };
    };
    std::cout << soma;
    return 0;
};