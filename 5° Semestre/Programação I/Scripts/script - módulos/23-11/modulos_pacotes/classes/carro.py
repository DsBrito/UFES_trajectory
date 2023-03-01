class Carro:

    def __init__(self, cor, marca, modelo, ano, km_rodados):
        self.cor = cor
        self.marca = marca
        self.modelo = modelo
        self.ano = ano
        self.km_rodados = km_rodados
        
    def detalhes(self):
        print 'cor:', self.cor
        print 'marca:', self.marca
        print 'modelo:', self.modelo
        print 'ano:', self.ano
        print 'km rodados:', self.km_rodados
