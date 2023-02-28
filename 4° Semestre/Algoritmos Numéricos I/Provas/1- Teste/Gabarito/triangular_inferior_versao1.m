%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Resolve um  sistema linear  triangulares inferior 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all; % limpa as variaveis
clc;       % limpa a tela
format short
% exemplo 1  (sist triangular inferior)
disp("Sistema triangular inferior")
A=[ 2.0 0.0 0.0 0.0; 3.4  7.1  0  0 ; -4.3  0.5  2.0 0.0; 1.0  1.9  0.3  4.0]
b=[ 10; 20; 0; 40]

[n,m]=size(A);
if (n != m)
 disp("*** Atencao a matriz nao eh quadrada ****")
endif

% Resolvendo o sistema
printf('Resolvendo o sistema linear  de dimensao %d \n', n );
xsol(1)= b(1)/A(1,1);
for i = 2:1:n
   s=0;
   for j =1:1:(i-1)
     s = s + A(i,j)*xsol(j);
   endfor 
   xsol(i)=( b(i) - s)/ A(i,i);
endfor

disp("solucao obtida  eh")
xsol

% Verificando a solucao
disp("Testando o valor de A*xsol com a solucao obtida  eh")
prod= A*xsol'


