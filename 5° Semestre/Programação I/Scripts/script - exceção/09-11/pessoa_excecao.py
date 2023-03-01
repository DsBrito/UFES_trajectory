# -*- coding: utf-8 -*-

class Pessoa(object):
    def __init__(self, nome, sexo, idade):
        self.nome = nome
        self.sexo = sexo
        self.idade = idade

    def mudaNome(self, tmp):
        try:
            if isinstance(tmp, str):
                self.nome = tmp
            else:
                raise TypeError(tmp)
        except TypeError as e:
            print "O nome %s não é do tipo string" % e.message
            exit()

    def mudaSexo(self, tmp):
        try:
            if tmp != 'M' and tmp != 'F':
                raise ValueError()
            self.sexo = tmp
        except ValueError:
            print "Error! Digite M ou F para o atributo sexo."
            exit()

    def aumentaIdade(self, incremento):
        try:
            self.idade += int(incremento)
        except ValueError:
            print "O incremento na idade é feita apenas com números inteiros."
            exit()
    def adicionaSobrenome(self, sobrenome):
        try:
            self.nome += sobrenome
        except TypeError:
            print "O sobrenome tem que ser do tipo string."
            exit()


joao = Pessoa('João', 'M', 20)
joao.mudaNome('Maria')
print joao.nome
joao.mudaSexo('F')
print joao.sexo
joao.aumentaIdade(20)
joao.adicionaSobrenome(20)
