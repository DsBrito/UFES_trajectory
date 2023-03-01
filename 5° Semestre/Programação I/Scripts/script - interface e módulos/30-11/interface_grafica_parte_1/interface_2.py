# -*- coding: utf-8 -*-

#Exemplo de uso frame, widgets e pack
from Tkinter import *

#Classe janela que implementará todos os frames, widgets e event_handlers da interface
class Janela:
    def __init__(self, toplevel):

        #inserir widget janela
        self.frame = Frame(toplevel)
        self.frame.pack()

        #Inserir widget botao
        self.botao = Button(self.frame, text = "Botão")
        self.botao.pack()


raiz = Tk()
Janela(raiz)
raiz.mainloop()
