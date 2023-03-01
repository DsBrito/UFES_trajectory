# -*- coding: utf-8 -*-

def matmul(A, B):
    if len(A[0]) == len(B):
        C = []
        #percorre linhas de A
        for i in range(len(A)):
            linha = []
            for j in range(len(B[0])):
                prod = 0
                #produto interno
                for x in range(len(A[0])):
                    prod += A[i][x] * B[x][j]
                #equivalente a list.append(linha, prod)
                linha.append(prod)
            C = C + [linha]
        return C
    else:
        print "Erro! As matrizes nÃ£o possuem o mesmo nÃºmero de linhas x colunas."

print matmul([[1,2,3],[4,5,6],[7,8,9]],[[1,2],[4,5],[7,8]])