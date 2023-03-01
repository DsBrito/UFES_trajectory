# Cálculo de raizes de uma equação de segunda grau

from math import sqrt
import sys

# buscar coeficientes na linha de comando

if len(sys.argv) != 4:
    print("Parametros insuficientes")
    sys.exit()

a = sys.argv[1]
b = sys.argv[2]
c = sys.argv[3]

# input retorna string. converter então ..
a = float(a)
b = float(b)
c = float(c)

d = b**2 - 4*a*c

if d<0:
    print("Não existem raízes reais")
else:
    x1 = (-b + sqrt(d))/(2*a)
    x2 = (-b - sqrt(d))/(2*a)

    #versão antiga de formatação
    print("x1=%f x2=%f"%(x1,x2))

    #versão moderna de formatação
    print("x1={0} x2={1}".format(x1,x2))

    #versão ainda mais moderna de formatação. Observar o f antes de string
    print(f"x1={x1} x2={x2}")
