# -*- coding: utf-8 -*-

#Exemplo de uso do widget Label e alteração dos seus parâmetros
#Mostrar a questão da hierárquia e localização com o pack
from Tkinter import *

#Classe janela que implementará todos os frames, widgets e event_handlers da interface
class Janela:
    def __init__(self, toplevel):

        #inserir widget janela
        self.frame = Frame(toplevel)
        self.frame.pack()

        #Inserir widget botao
        self.botao = Button(self.frame, text="Botão")
        self.botao.pack()

        #Inserir área de texto
        self.texto = Label(self.frame, text = 'Texto')
        self.texto['width'] = 26
        self.texto['height'] = 3
        self.texto.pack()

raiz = Tk()
Janela(raiz)
raiz.mainloop()
