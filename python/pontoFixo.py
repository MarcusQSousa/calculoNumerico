import math
epsilon = 0.0000001

def funcaoTeste(x):
    return (x**3-4*x+2)

def gx(x):
    return((4*x-2)**(1/3))

def isolamento(limInf, limSup, fun):
    delta = 0.1
    minimo = limInf
    maximo = limSup

    funcao = fun
    anterior = funcao(minimo)
    intervalos = [];
    
    passo = minimo

    while(passo <= maximo):
        passo += delta
        y = funcao(passo)
        if(anterior*y < 0):
            intervalos.append(passo-delta)
            intervalos.append(passo)
        anterior = y
    
    return intervalos

def pontofixo(X0, precisao, g):
    maximo = 100
    x = X0
    passos = 0
    while(passos < maximo):
        xn = g(x)
        if(abs(xn-x) < precisao):
            return xn
        
        x = xn
        passos+=1


intervalos = isolamento(-3, 2,funcaoTeste)#[0,3]-funcao trig/[-3.5,2.0] - funcaoPoli
print(intervalos)
i = 0

print("Raizes:\n")
while(i < len(intervalos)):
    chute = (intervalos[i] + intervalos[i+1])/2
    raiz = pontofixo(chute,epsilon,gx);
    
    print(raiz)
    i+=2