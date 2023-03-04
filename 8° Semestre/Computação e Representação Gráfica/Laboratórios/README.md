## Laboratórios da Disciplina de Computação Gráfica


 É necesário ter os seguites itens instalados na máquina:

`sudo apt install freeglut3 freeglut3-dev binutils-gold`

## Execução

Os projetos podem ser executados entrando na pasta relacionada e executando

```
make
make run
```

Em geral, o target `run` executa o binário associado. 
Alguns laboratórios possuem mais de um arquivo, e nesse caso é necessário usar o target apropriado especificado no Makefile, ou apenas executar um

`make all`

e rodar o binário gerado.
