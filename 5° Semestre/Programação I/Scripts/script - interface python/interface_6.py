# -*- coding: utf-8 -*-

#import dos módulos tkinter
from Tkinter import *

class Janela(object):

    def __init__(self, toplevel):

        #cria/insere widget janela
        self.frame1 = Frame(toplevel)
        self.frame1.pack(side = TOP)

        #cria variável StringVar
        #Variável do Tkinter
        #Dessa forma o tkinter pode rastrear mudanças na variável e
        #alterar diretamente na interface
        self.text= StringVar()
        self.text.set("Seu texto aqui!")

        #cria/insere widget label
        self.label = Label(self.frame1, textvariable = self.text, width = 20)
        self.label.pack(side = LEFT)
        #cria/insere widget entry | bd é o campo que trata a largura da borda do campo Entry
        self.e1 = Entry(self.frame1, bd = 2)
        self.e1.pack(side = LEFT)

        #cria/insere widget botao
        self.botao = Button(self.frame1, text = "Mudar texto")
        self.botao.pack(side = RIGHT)
        self.botao.bind("<Button-1>", self.mudaTexto)

    def mudaTexto(self, event):
        self.text.set(self.e1.get())


#Inicialização do ambiente tkinter
raiz = Tk()
#instanciação do objeto Janela com todos os widgets e event handlings da interface
Janela(raiz)
#Muda o titulo da janela raiz
raiz.wm_title("Interface 6")
raiz.mainloop()
