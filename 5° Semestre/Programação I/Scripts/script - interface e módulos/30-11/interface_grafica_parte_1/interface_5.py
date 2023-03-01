# -*- coding: utf-8 -*-

#Exemplo de uso do bind, event(<Button-1>) e event_handlers(mudaTexto)
from Tkinter import *

#Classe janela que implementará todos os frames, widgets e event_handlers da interface
class Janela:
    def __init__(self, toplevel):

        #inserir widget janela
        self.frame = Frame(toplevel)
        self.frame.pack()

        #Inserir área de texto
        self.texto = Label(self.frame, text = 'Bem vindo!')
        self.texto['width'] = 26
        self.texto['height'] = 3
        self.texto.pack()

        #Inserir widget botao
        self.botao = Button(self.frame, text="Botão")
        self.botao.bind("<Button-1>",self.mudaTexto)
        self.botao.pack()

    def mudaTexto(self, event):
        self.texto['text'] = 'Você clicou no botão!'

raiz = Tk()
Janela(raiz)
raiz.mainloop()
