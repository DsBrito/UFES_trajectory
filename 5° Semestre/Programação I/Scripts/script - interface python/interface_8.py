# -*- coding: utf-8 -*-

#import dos módulos tkinter
from Tkinter import *
#import necessário para utilizar o Treeview
import ttk
#import necessário para utilizar os popups
import tkMessageBox

class Janela(object):

    def __init__(self, toplevel):

        #cria/insere widget janela
        self.frame1 = Frame(toplevel)
        self.frame1.pack(side = RIGHT)

        #cria/insere widget botao
        self.botao = Button(self.frame1, text="Adicionar Tarefa")
        self.botao.pack(side = BOTTOM)
        self.botao.bind("<Button-1>", self.addTarefa)

    #tratador de evento para inserção no treeview
    def addTarefa(self, event):
        self.top = Toplevel()
        self.top.title("Nova tarefa")

        self.msg = Message(self.top, text="Insira os dados da nova tarefa:", width = 300)
        self.msg.pack()

        self.frameData = Frame(self.top)
        self.frameData.pack()

        self.frameLabel = Frame(self.frameData)
        self.frameLabel.pack(side = LEFT)

        textNome= StringVar()
        textNome.set("Nome: ")
        textDescricao = StringVar()
        textDescricao.set("Descrição: ")
        textDt = StringVar()
        textDt.set("Data limite: ")

        self.labelNome = Label(self.frameLabel, textvariable = textNome, pady = 5)
        self.labelDescricao = Label(self.frameLabel, textvariable = textDescricao, pady = 4)
        self.labelDt = Label(self.frameLabel, textvariable = textDt, pady = 4)

        self.labelNome.pack()
        self.labelDescricao.pack()
        self.labelDt.pack()

        self.frameEntry = Frame(self.frameData)
        self.frameEntry.pack(side = RIGHT)

        self.tfNome = Entry(self.frameEntry, bd = 2)
        self.tfDescricao = Entry(self.frameEntry, bd = 2)
        self.tfDataLimite = Entry(self.frameEntry, bd = 2)

        self.tfNome.pack()
        self.tfDescricao.pack()
        self.tfDataLimite.pack()


        self.frameButton = Frame(self.top)
        self.frameButton.pack()

        self.botaoCriar = Button(self.frameButton, text = "Criar", command = self.insertDestroy, width = 20)
        self.botaoCriar.pack()

    def insertDestroy(self):
        pass

#Inicialização do ambiente tkinter
raiz = Tk()
#instanciação do objeto Janela com todos os widgets e event handlings da interface
Janela(raiz)
#Muda o titulo da janela raiz
raiz.wm_title("Interface 8")
raiz.mainloop()
