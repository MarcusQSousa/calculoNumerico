#include<iostream>

int main(){
    long double unidade = 1.L;
    long double teste = 1.L;
    int steps = 1;
    while(true){
        unidade = unidade/2;
        std::cout << unidade << '\n';
        std::cout << "steps(2^n)" << steps << '\n';
    

        if(teste == teste+unidade){
            break;
        };
        steps++;
    };

    std::cout << steps;
    return 0;
};