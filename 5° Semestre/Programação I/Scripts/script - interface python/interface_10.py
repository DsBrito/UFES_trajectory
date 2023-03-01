# -*- coding: utf-8 -*-

#import dos módulos tkinter
from Tkinter import *
#import necessário para utilizar o Treeview
import ttk
#import necessário para utilizar os popups
import tkMessageBox

class Janela(object):

    def __init__(self, toplevel):

        self.projetos = []

        #cria/insere widget janela
        self.frame1 = Frame(toplevel)
        self.frame1.pack(side = RIGHT)

        #cria/insere widget botao
        self.botao = Button(self.frame1, text="Adicionar Tarefa")
        self.botao.pack(side = BOTTOM)
        self.botao.bind("<Button-1>", self.addTarefa)

        #cria uma treeview
        self.tree = ttk.Treeview(toplevel)

        #cria duas colunas no treeview com ids one e two
        self.tree["columns"] = ("one","two")
        self.tree.column("one", width = 100 )
        self.tree.column("two", width = 100)

        #seta os labels das colunas
        self.tree.heading("one", text = "Descrição")
        self.tree.heading("two", text = "Data Limite")

        #insere treeview no toplevel
        self.tree.pack()

        projTeste = self.tree.insert("", 1, "Projeto 2", text = "Projeto 2")
        self.projetos.append(projTeste)

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
        textProjeto = StringVar()
        textProjeto.set("Projeto: ")

        self.labelNome = Label(self.frameLabel, textvariable = textNome, pady = 5)
        self.labelDescricao = Label(self.frameLabel, textvariable = textDescricao, pady = 4)
        self.labelDt = Label(self.frameLabel, textvariable = textDt, pady = 4)
        self.labelProjeto = Label(self.frameLabel, textvariable = textProjeto, pady = 4)

        self.labelNome.pack()
        self.labelDescricao.pack()
        self.labelDt.pack()
        self.labelProjeto.pack()


        self.frameEntry = Frame(self.frameData)
        self.frameEntry.pack(side = RIGHT)

        self.tfNome = Entry(self.frameEntry, bd = 2)
        self.tfDescricao = Entry(self.frameEntry, bd = 2)
        self.tfDataLimite = Entry(self.frameEntry, bd = 2)
        self.projSelecionado = StringVar(self.frameEntry)
        self.projSelecionado.set("-----")
        self.tfProjeto = apply(OptionMenu, (self.frameEntry, self.projSelecionado) + tuple(self.projetos))

        self.tfNome.pack()
        self.tfDescricao.pack()
        self.tfDataLimite.pack()
        self.tfProjeto.pack()


        self.frameButton = Frame(self.top)
        self.frameButton.pack()

        self.botaoCriar = Button(self.frameButton, text = "Criar", command = self.insertDestroy, width = 20)
        self.botaoCriar.pack()


    def insertDestroy(self):
        #tratando exceções no tkinter
        #verifica se erro de elementos com mesmo nome será lançado pelo Treeview
        try:
            nome = self.tfNome.get()
            descricao = self.tfDescricao.get()
            dataLimite = self.tfDataLimite.get()
            projeto = self.projSelecionado.get()
            if projeto == "-----":
                self.tree.insert("", "end", nome, text = nome, values = (descricao, dataLimite))
            else:
                self.tree.insert(projeto, "end", nome, text = nome, values = (descricao, dataLimite))

        #captura erro do tkinter e trata de maneira correta
        except tkinter.TclError as err:
            #em caso de erro, exibe popup com erro
            self.top.destroy()
            self.showErrorBox("Você adicionu uma tarefa que já existe", err)
        else:
            #em caso de sucesso, exibe popup com mensagem de sucesso
            self.showMsgBox("Tarefa adicionado com sucesso: ", nome)
            self.top.destroy()

    #método que exibe popup de sucesso
    def showMsgBox(self, msg, nomeObj):
        tkMessageBox.showinfo("Sucesso!", msg + nomeObj)

    #método que exibe popup de erro
    def showErrorBox(self, msg, err):
        tkMessageBox.showerror("Erro!", msg + " \n Erro: " + err.message)


#Inicialização do ambiente tkinter
raiz = Tk()
#instanciação do objeto Janela com todos os widgets e event handlings da interface
Janela(raiz)
raiz.mainloop()
