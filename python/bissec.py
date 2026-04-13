import math
epsilon = 0.00001

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

def bissec(inf, sup, precisao, fun): 
    a = inf #definimos o limite inferior do intervalo inicial
    b = sup #limite superior
    x = 0   
    funcao = fun # f(x)

    while((b-a)/2 < precisao): # testamos se o intervalo e suficienttemente pequeno
        x = (a+b)/2 # definimos um x no meio do intervalo
        y = funcao(x)

        if(y*funcao(a) < 0): # se f(x)*f(a) for negativo:
            b = x            #  trocamos b por x fazendo o intervalo [a,x]
        else:                # caso contrario: 
            a = x            #  trocamos a por x fazendo o intervalo [x,b]

        if(abs(y) < precisao): #testamos se f(x) e proximo suficiente de 0
            break
    
    return x 

intervalos = isolamento(0, 3,funcaoTrig)#[0,3]-funcao trig/[-3.5,2.0] - funcaoPoli

i = 0

print("Raizes:\n")
while(i < len(intervalos)):
    raiz = bissec(intervalos[i], intervalos[i+1],epsilon, funcaoTrig)
    
    print(raiz)
    i+=2