N=input('Digite o valor de N: ')
printf('Calculando uma aproximacao para e  Crescente\n' );
s=1;
for i = 1:1:N
termo= 1/( factorial(i))
s = s + termo
endfor
printf('Pela versao crescente o valor eh: %.14f ', s );
erro_rel= abs ( (s-(e^1)) )/ (e^1)
x=abs(s-(e^1))
porcentagem= (100*x)/e^1