#include<iostream>
#include<math.h>
#include<limits>

typedef long double valor;
struct intervalo{
    float inf;
    float sup;
};

valor polinomio(int grau,float* coeficientes,valor x){
    valor y = 0;
    for(int i = 0;i < grau; i++){
        y+=coeficientes[i]*pow(x,grau-i);
    };
    y+= coeficientes[grau];
    return y;
}

int main(){ 
    long double limite = std::numeric_limits<long double>::min();
    std::cout << sizeof(long double) << '\n';
    std::cout << limite << '\n';
    std::cout << "long double digits: " << std::numeric_limits<long double>::digits10 << std::endl;
    std::cout << "---Teste----" << '\n';

    intervalo intervalo = {-1.5f,-0.5f};
    float moduloIntervalo = intervalo.sup - intervalo.inf;
    int divisoes = 20;
    valor delta = moduloIntervalo/divisoes;

    float coef[6] = {0.5,1.5,-2,-5,1,2};

    for(int i = 0; i <= divisoes; i++){
        valor x = intervalo.inf+i*delta;
        std::cout<< x <<','<< polinomio(5,coef, x) << '\n';
    };


    return 0;
}