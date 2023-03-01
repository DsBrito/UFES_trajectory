# -*- coding: utf-8 -*-

#import dos módulos tkinter
from Tkinter import *

#import necessário para utilizar os popups
import tkMessageBox

#import do backend
from usuario import *

import pickle
import os.path

class Janela(object):

    def __init__(self, toplevel):
        self.check = False
        self.toplevel = toplevel
        #Verifica se o usuario clicou no X do toplevel
        self.toplevel.protocol("WM_DELETE_WINDOW", self.ask_quit)
        #Arquivo que simula um banco de dados
        fname = "arq.bd"
        #Verifica se o arquivo de banco de dados existe
        if os.path.isfile(fname):
            #se existe, carrega o usuário com seus projetos e tarefas
            fileObject = open("arq.bd",'rb')
            self.usuario = pickle.load(fileObject)
            fileObject.close()
            self.mainView()
        else:
            self.toplevel.withdraw()
            self.usrCreate()

    def mainView(self):

        #cria/insere widget janela
        self.frame1 = Frame(self.toplevel)
        self.frame1.pack(side = RIGHT)

        self.textUsuario= StringVar()
        self.textUsuario.set("Usuario: " + self.usuario.nome)
        self.labelUsuario = Label(self.frame1, textvariable = self.textUsuario, pady = 5)
        self.labelUsuario.pack(side = TOP)

        #cria/insere widget botao
        self.botao_projeto = Button(self.frame1, text="Instanciar Usuario")
        self.botao_projeto.pack(side = TOP)
        self.botao_projeto.bind("<Button-1>", self.usrCreate)


    def usrCreate(self, event=0):
        self.top = Toplevel()
        self.top.title("Novo Usuario")

        self.msg = Message(self.top, text="Insira os dados do novo usuario:", width = 300)
        self.msg.pack()

        self.frameData = Frame(self.top)
        self.frameData.pack()

        self.frameLabel = Frame(self.frameData)
        self.frameLabel.pack(side = LEFT)

        textNome= StringVar()
        textNome.set("Nome: ")
        textNickname = StringVar()
        textNickname.set("Nickname: ")
        textEmail = StringVar()
        textEmail.set("Email: ")
        textSenha = StringVar()
        textSenha.set("Senha: ")

        self.labelNome = Label(self.frameLabel, textvariable = textNome, pady = 5)
        self.labelNickname = Label(self.frameLabel, textvariable = textNickname, pady = 4)
        self.labelEmail = Label(self.frameLabel, textvariable = textEmail, pady = 5)
        self.labelSenha = Label(self.frameLabel, textvariable = textSenha, pady = 5)

        self.labelNome.pack()
        self.labelNickname.pack()
        self.labelEmail.pack()
        self.labelSenha.pack()


        self.frameEntry = Frame(self.frameData)
        self.frameEntry.pack(side = RIGHT)

        self.tfNome = Entry(self.frameEntry, bd = 2)
        self.tfNickname = Entry(self.frameEntry, bd = 2)
        self.tfEmail = Entry(self.frameEntry, bd = 2)
        self.tfSenha = Entry(self.frameEntry, bd = 2)

        self.tfNome.pack()
        self.tfNickname.pack()
        self.tfEmail.pack()
        self.tfSenha.pack()

        self.frameButton = Frame(self.top)
        self.frameButton.pack()

        self.botaoCriar = Button(self.frameButton, text = "Criar", command = self.insertDestroyUsuario, width = 20)
        self.botaoCriar.pack()

    def insertDestroyUsuario(self):
        #tratando exceções no tkinter
        #verifica se erro de elementos com mesmo nome será lançado pelo Treeview
        try:
            nome = self.tfNome.get()
            nickname = self.tfNickname.get()
            email = self.tfEmail.get()
            senha = self.tfSenha.get()
            self.usuario = Usuario(nickname, nome, email, senha)
        #captura erro do tkinter e trata de maneira correta
        except tkinter.TclError as err:
            #em caso de erro, exibe popup com erro
            self.top.destroy()
            self.showErrorBox("", err)
        else:
            #em caso de sucesso, exibe popup com mensagem de sucesso
            self.showMsgBox("Usuario criado com sucesso: ", nome)
            self.top.destroy()
            self.toplevel.deiconify()
            if not self.check:
                self.mainView()
                self.check = True
            else:
                self.textUsuario.set("Usuario: " + self.usuario.nome)

    #método que exibe popup de sucesso
    def showMsgBox(self, msg, nomeObj):
        tkMessageBox.showinfo("Sucesso!", msg + nomeObj)

    #método que exibe popup de erro
    def showErrorBox(self, msg, err = None):
        if err != None:
            tkMessageBox.showerror("Erro!", msg + " \n Erro: " + err.message)
        else:
            tkMessageBox.showerror("Erro!", msg)

    def ask_quit(self):
        #Exibe popup quando o usuário clica no botão fechar da interface principal
        #O título do popup será "Sair" e a mensagem exibida será "Voce deseja..."
        #Em caso de afirmativo, o arquivo arq.bd será aberto e a informações salvas
        if tkMessageBox.askokcancel("Sair", "Voce deseja realmente sair?"):
            fileObject = open("arq.bd",'wb')
            pickle.dump(self.usuario,fileObject, 2)
            fileObject.close()
            self.toplevel.destroy()

#Inicialização do ambiente tkinter
raiz = Tk()
#instanciação do objeto Janela com todos os widgets e event handlings da interface
Janela(raiz)
raiz.mainloop()
