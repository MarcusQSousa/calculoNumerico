epsilon = 0.000001

def fx(x):
    return(x**3 - 9*x + 3)

def dfx(x):
    return(3*x**2 - 9)

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

def newtonHalphson(f, dfdx, xinicial,precisao):
    
    x = xinicial;

    maximo = 10000
    passos = 0
    while(abs(f(x)) > precisao):
        novoX = x - f(x)/dfdx(x)

        if(abs(novoX - x) < precisao):
            break
        if(passos > maximo):
            print("Nao convergiu!")
            return

        x = novoX
        passos +=1
    
    return x

intervalos = isolamento(-3.5, 3,fx)#[0,3]-funcao trig/[-3.5,2.0] - funcaoPoli

print(intervalos)

print("Raizes:\n")
i = 0
while(i < len(intervalos)):
    x0 = (intervalos[i]+intervalos[i+1])/2
    raiz = newtonHalphson(fx,dfx,x0,epsilon)
    
    print(raiz)
    i+=2