# -*- coding: utf-8 -*-

#FunÃ§Ã£o que retorna o valor da coroa central entre duas circunferÃªncias de raio r1 e r2
def coroa(r1,r2):
    return pi() * exponencial(r1) - pi() * exponencial(r2)

#FunÃ§Ã£o que retorna o exponencial de x em relaÃ§Ã£o a y
#Caso y nÃ£o seja informado, terÃ¡ o valor default de 2
def exponencial(x,y=2):
    return x**y

#FunÃ§Ã£o que retorna o valor de pi
def pi():
    return 3.14

#InÃ­cio do programa
retorno = coroa(4,2)

print retorno