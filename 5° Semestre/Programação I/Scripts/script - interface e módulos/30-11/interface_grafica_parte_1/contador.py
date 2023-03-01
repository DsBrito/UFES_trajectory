# -*- coding: utf-8 -*-

#Exemplo de contador no texto

#Importar módulos do pacote Tkinter
from Tkinter import *

class Janela:
    #contrutor do widget Janela
    def __init__(self,toplevel):
        #variável que armazena o contador
        self.count = 0

        self.frame = Frame(toplevel)
        self.frame.pack()

        self.texto=Label(self.frame, text='Clicou ' + str(self.count) + ' vezes.')
        self.texto['width'] = 26
        self.texto['height'] = 3
        self.texto.pack()

        self.botaoCount = Button(self.frame,text='Clique!')
        self.botaoCount.bind("<Button-1>",self.conta)
        self.botaoCount.pack()

        self.botaoReset = Button(self.frame,text='Resetar!')
        self.botaoReset.bind("<Button-1>",self.reset)
        self.botaoReset.pack()

    def conta(self, event):
        self.count += 1
        self.texto['text']='Clicou ' + str(self.count) + ' vezes.'

    def reset(self, event):
        self.count = 0
        self.texto['text']='Clicou ' + str(self.count) + ' vezes.'

raiz=Tk()
Janela(raiz)
raiz.mainloop()
