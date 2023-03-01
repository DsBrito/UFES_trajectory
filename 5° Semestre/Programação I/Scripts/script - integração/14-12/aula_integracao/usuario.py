class Usuario(object):
    """docstring for """
    def __init__(self, nickname, nome, email, senha):
        self.id_usuario = 0
        self.nickname = nickname
        self.nome = nome
        self.email = email
        self.senha = senha
        self.projetos = []

    def addProjeto(self, projeto):
        self.projetos.append(projeto)
        return 0
