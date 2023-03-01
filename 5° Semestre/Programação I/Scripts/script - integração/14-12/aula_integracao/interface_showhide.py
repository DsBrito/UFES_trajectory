# -*- coding: utf-8 -*-

#import dos módulos tkinter
from Tkinter import *

#import necessário para utilizar os popups
import tkMessageBox

#import do backend
from usuario import *

class Janela(object):

    def __init__(self, toplevel):

        #cria/insere widget janela
        self.frame1 = Frame(toplevel)
        self.frame1.pack(side = RIGHT)

        #cria/insere widget botao
        self.botao_projeto = Button(self.frame1, text="Exibir")
        self.botao_projeto.pack(side = TOP)
        self.botao_projeto.bind("<Button-1>", self.show)

        #cria/insere widget botao
        self.botao_projeto = Button(self.frame1, text="Esconder")
        self.botao_projeto.pack(side = TOP)
        self.botao_projeto.bind("<Button-1>", self.hide)

        self.check = True



    def hide(self, event):
        if not self.check:
            #Esconde o toplevel por um tempo
            self.top.withdraw()

    def show(self, event):
        if self.check:
            self.top = Toplevel()
            self.top.title("Tela!")
            self.msg = Message(self.top, text="Tela de teste!", width = 300)
            self.msg.pack()
            self.check = False

        #Exibe o toplevel novamente
        self.top.deiconify()

#Inicialização do ambiente tkinter
raiz = Tk()
#instanciação do objeto Janela com todos os widgets e event handlings da interface
Janela(raiz)
raiz.mainloop()
