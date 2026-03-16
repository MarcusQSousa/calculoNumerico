#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>

typedef long double ddouble;


ddouble polinomio(ddouble x){
    int grau =5;
    float coeficientes[grau+1] = {0.5,1.5,-2,-5,1,2};
    ddouble y = 0;
    for(int i = 0;i < grau; i++){
        y+=coeficientes[i]*powl(x,grau-i);
    };
    y+= (ddouble)coeficientes[grau];
    return y;
};

std::vector<ddouble> isolamento(){
    const float delta = 0.5f;
    float minimo = -3.5f;
    float maximo = 2.f;
    ddouble anterior = polinomio(minimo);
    std::vector<ddouble> intervalos;
    for(float i = minimo; i <=maximo; i+=delta){
        ddouble y = polinomio((ddouble)i);
        if(anterior*y < 0){
            intervalos.push_back(i-delta);
            intervalos.push_back(i);
        };
        anterior = y;
    };

    return intervalos;
};

ddouble bissec(ddouble inf, ddouble sup, ddouble precisao){
    ddouble a = inf;
    ddouble b = sup;
    ddouble x;
    unsigned int passos = 0;
    while(true){
        x = (a+b)/2;
        ddouble y = polinomio(x);

        // condicoes de parada
        if(b-a <= precisao){
            std::cout << "caso A: " <<'\n';
            break;
        }if(abs(y) <= precisao){
            std::cout << "caso B: " <<'\n';
            break;
        }if(passos > 50){
            break;
        }

        //------------

        if(polinomio(a)*y > 0){
            a=x;
        }else{
            b = x;
        }

    };

    return(x);
};

int main(){
    std::cout << "Teste" << '\n';
    ddouble epsilon = powl(2.L,-32.L);

    std::vector<ddouble> intervalos = isolamento();
    std::cout << "intervalos" << '\n';

    std::cout << "raizes" << '\n';

    for(size_t i = 0; i <intervalos.size(); i+=2){
        ddouble raiz = bissec(intervalos[i],intervalos[i+1],epsilon);
        std::cout << std::setprecision(20) << raiz << '\n';
    };

    std::cout <<epsilon;


    return 0;
};