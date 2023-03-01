# -*- coding: utf-8 -*-

#FunÃ§Ã£o que retorna o valor da coroa central entre duas circunferÃªncias de raio r1 e r2
def coroa(r1,r2):
    return (3.14*r1**2) - (3.14*r2**2)

#InÃ­cio do programa
retorno = coroa(4,2)

print retorno