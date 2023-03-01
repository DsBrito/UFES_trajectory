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
        self.botao.bind("<Button-1>", self.addList)

        #cria/insere widget entry | bd é o campo que trata a largura da borda do campo Entry
        self.e1 = Entry(self.frame1, bd = 2)
        self.e1.pack(side = TOP)

        #cria uma treeview
        self.tree = ttk.Treeview(toplevel)

        #cria duas colunas no treeview com ids one e two
        self.tree["columns"] = ("one","two")
        self.tree.column("one", width = 100 )
        self.tree.column("two", width = 100)

        #seta os labels das colunas
        self.tree.heading("one", text = "Data de Criação")
        self.tree.heading("two", text = "Data Limite")

        #insere elemento na treeview
        #insert(parent, index, id)
        self.tree.insert("" , END, "Tarefa 1", text = "Tarefa 1", values = ("01/04/2016","05/10/2018"))

        #insere grupo na treeview
        self.id2 = self.tree.insert("", END, "dir2", text = "Projeto 2")
        #insere elemento no grupo criado anteriormente na treeview
        self.tree.insert(self.id2, END, "dir 2", text = "Tarefa 1", values = ("20/05/2016","10/09/2018"))

        #alternativa de criar grupo e elementos na treeview
        self.tree.insert("", 3, "dir3", text = "Projeto 3")
        self.tree.insert("dir3", END, text = "Tarefa 1",values = ("25/01/2015"," 23/10/2016"))

        #insere treeview no toplevel
        self.tree.pack()

    def addList(self, event):
        #tratando exceções no tkinter
        #verifica se erro de elementos com mesmo nome será lançado pelo Treeview
        try:
            tarefa = self.e1.get()
            self.addTree()
        #captura erro do tkinter e trata de maneira correta
        except tkinter.TclError as err:
            #em caso de erro, exibe popup com erro
            self.showErrorBox(err)
        else:
            #em caso de sucesso, exibe popup com mensagem de sucesso
            self.showMsgBox(tarefa)

    #tratador de evento para inserção no treeview
    def addTree(self):
        #itemSelecionado = self.tree.focus()
        #print self.tree.item(itemSelecionado)
        self.tree.insert("dir2", "end", self.e1.get(), text = self.e1.get())

    #método que exibe popup de sucesso
    def showMsgBox(self, tarefa):
        tkMessageBox.showinfo("Sucesso!", "Você adicionou com sucesso a tarefa: " + tarefa)

    #método que exibe popup de erro
    def showErrorBox(self, err):
        tkMessageBox.showerror("Erro!", "Você adicionou uma tarefa que já existe! \n Erro: " + err.message)


#Inicialização do ambiente tkinter
raiz = Tk()
#instanciação do objeto Janela com todos os widgets e event handlings da interface
Janela(raiz)
#Muda o titulo da janela raiz
raiz.wm_title("Interface 7")
raiz.mainloop()
