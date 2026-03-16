import math
epsilon = 0.0000001

def funcaoPoli(x):
    grau = 5
    coeficientes = [0.5,1.5,-2,-5,1,2]
    y = coeficientes[grau]
    for i in range(grau):
        y+=coeficientes[i]*x**(grau-i)
    
    return y

def funcaoTrig(x):
    y = 2-x- 2*math.sin(2*x)
    return y

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

def posFalsa(inf, sup, precisao, fun):
    a = inf
    b = sup
    x = 0
    funcao = fun

    while(True):
        x = (a*funcao(b) - b*funcao(a))/(funcao(b)-funcao(a))
        y = funcao(x)

        if(y*funcao(a) > 0):
            a = x
        else:
            b = x

        if((b-a) < precisao):
            x = (a+b)/2
            break
        elif(abs(y) < precisao):
            break
    
    return x

intervalos = isolamento(0, 3,funcaoTrig)#[0,3]-funcao trig/[-3.5,2.0] - funcaoPoli

i = 0

print("Raizes:\n")

while(i < len(intervalos)):
    raiz = posFalsa(intervalos[i], intervalos[i+1],epsilon, funcaoTrig)
    
    print(raiz)
    i+=2