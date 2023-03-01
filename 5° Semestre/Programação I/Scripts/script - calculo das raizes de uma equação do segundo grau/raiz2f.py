# Cálculo de raizes de uma equação de segunda grau

from math import sqrt

def raiz2(a,b,c):
    # calcula discriminante
    d = b**2 - 4*a*c

    if d<0:
        return None
    else:
        x1 = (-b + sqrt(d))/(2*a)
        x2 = (-b - sqrt(d))/(2*a)
        return (x1,x2)




import sys
import argparse

# buscar coeficientes na linha de comando

parser = argparse.ArgumentParser(description="Calcula raizes da equação de segundo grau")
parser.add_argument("a",type=float,help="Coeficiente a")
parser.add_argument("b",type=float,help="Coeficiente b")
parser.add_argument("c",type=float,help="Coeficiente c")
args = parser.parse_args()

a = args.a
b = args.b
c = args.c

x = raiz2(a,b,c)

if not x:
    print("Não existem raízes reais")
    sys.exit()

x1 = x[0]
x2 = x[1]

#versão antiga de formatação
print("x1=%f x2=%f"%(x1,x2))

#versão moderna de formatação
print("x1={0} x2={1}".format(x1,x2))

#versão ainda mais moderna de formatação. Observar o f antes de string
print(f"x1={x1} x2={x2}")
