clear
clc
A=[1 0 0 0 0; 2 3 0 0 0; 4 5 6 0 0; 7 8 9 10 0; -2 -3 -4 -5 -6 ];
b=[ 1; 5; 15; 34; -20];

%%pegando a dimensão de A NxN
[n,n] = size(A);

%%pegando a dimensçao Nx1 de A (para pegar apenas o numero de colunas)
x=zeros(n,1)

%%armazenando o primeiro elemento do vetor solução
x(1)=b(1)/A(1,1);

%%loop para somar e armazenar /gerar a solução
for i = 2:n
    s=0;
    for j=1:n-1
      s = s+ A(i,j)*x(j)    %%para pegar a soma da linha/ mostrando a soma
      
    end
    
    x(i)=(b(i)-s)/A(i,i)    %%para armazenar o X(i)/ mostrando o x(i)

end

x  %%mostrando o vetor solução
