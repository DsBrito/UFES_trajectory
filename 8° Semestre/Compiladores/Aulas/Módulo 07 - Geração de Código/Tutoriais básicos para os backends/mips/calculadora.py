x=1

while x!=0:
	op1 = int(input("Digite o primeiro operando:"))
	op2 = int(input("Digite o segundo operando:"))
	x = int(input("\nEscolha a operacao: (1) +, (2) -, (3) *, (4) /\n"))
	
	if x==1:
		res=op1+op2
	
	if x==2:
		res=op1-op2
	
	if x==3:
		res=op1*op2
	
	if x==4:
		res=op1/op2
	
	print("\nResultado:")
	print(res)
	x = int(input("\nDeseja fazer outra operacao? (1) Sim, (0) Nao\n"))

print("Obrigado! Python 2 Mips\n")