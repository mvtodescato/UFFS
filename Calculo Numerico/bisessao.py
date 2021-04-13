import matplotlib.pyplot as plt


l1 = []
l2 = []
biss = []
fbiss = []
cord = []
fcord = []
newt = []
fnewt = []


a = 9;
b = 10;
e = 2.718281828;


def f(x):
    return ((0.5 * x ** 3) - (5 * x ** 2) + x + 3)

def fLinha(x):
	return 1.5 * x ** 2 - 10 *x + 1

def fDuasLinha(x):
    return 3 * x - 10


def bissecao(a, b, epsilon):
    i=0
    if f(a) * f(b) > 0:
        print("Sem raiz\n")
    else:
        while abs((b - a) / 2) >= epsilon:
            i=i+1
            pontoMedio = (a + b) / 2
            biss.append(pontoMedio)
            fbiss.append(f(pontoMedio))
            if f(pontoMedio) == 0:
                return (pontoMedio, i)  #Achou raiz Exata

            elif f(a) * f(pontoMedio) < 0:  #Aumentando
                b = pontoMedio
            else:
                a = pontoMedio
        return (pontoMedio, i)


def cordas(a,b,epsilon,max=100):
    if f(a) * f(b) > 0:
        #Nao Garante Raiz
        print("Nao garante Raiz, Programa Finalizado")
    else:
        x1= (a*f(b)-b*f(a) / f(b)-f(a))
        cord.append(x1)
        fcord.append(f(x1))
        i = 1
        if abs(f(x1))<= epsilon:
            return x1
        while i<max:
            if f(x1)*f(a) > 0:
                x2=(x1*f(b)-b*f(x1)) / (f(b)-f(x1))
            else:
                x2 = (a * f(x1) - x1 * f(a)) / (f(x1) - f(a))
            cord.append(x2)
            fcord.append(f(x2))
            x1=x2
            i=i+1
            if abs(f(x2)) <= epsilon:
               return (x2, i)
        return(x2, i)


def newton(a,b,epsilon,max=100):
    if f(a) * f(b) > 0:
        print("Sem raiz")
    else:
        if fLinha(a) * fDuasLinha(a) > 0:
            x1 = b - f(b) / fLinha(b)
        else:
            x1 = a - f(a) / fLinha(a)
        newt.append(x1)
        fnewt.append(f(x1))
        i=0
        while i<max:
            x2= x1 - f(x1) / fLinha(x1)
            newt.append(x2)
            fnewt.append(f(x2))
            x1 = x2
            i = i + 1
            if abs(f(x2)) <= epsilon:
                return (x2, i)

        return (x2, i)


zz = 0
while zz<50:
    l1.append(zz)
    l2.append(f(zz))
    zz = zz+0.00001

print ('Bisseção:', bissecao(a , b, 0.0001))
print('Newton:', newton(a , b , 0.0001))
print('Cordas:', cordas(a , b , 0.0001))



plt.plot([0, 0, 0, 0, 0, 0])
plt.axis([-10, 50, -30, 30])
plt.plot(l1,l2)
plt.plot([biss], [fbiss], 'ro')
#plt.plot([cord], [fcord], 'ro')
#plt.plot([newt], [fnewt], 'ro')
plt.show()