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

ddouble falsaPosicao(ddouble inf, ddouble sup, ddouble precisao){
    ddouble a = inf;
    ddouble b = sup;
    ddouble x;
 
    while(true){
        x = (a*polinomio(b) - b*polinomio(a))/(polinomio(b) - polinomio(a));
        ddouble y = polinomio(x);

        if(y*polinomio(a) < 0){
            a = x;
        }else{
            b = x;
        };

        if(b-a < precisao){
            break;
        }else if(abs(y) < precisao){
            break;
        };
        

    };

    return(x);
};

int main(){
    ddouble epsilon = powl(2.L,-32.L);

    std::vector<ddouble> intervalos = isolamento();

    for(size_t i = 0; i <intervalos.size(); i+=2){
        ddouble raiz = falsaPosicao(intervalos[i],intervalos[i+1],epsilon);
        std::cout << std::setprecision(20) << raiz << '\n';
    };


    return 0;
};