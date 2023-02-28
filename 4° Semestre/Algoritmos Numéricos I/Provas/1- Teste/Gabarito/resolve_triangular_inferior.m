%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Resolve um  sistema linear  triangular  inferior 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [x] = resolve_triangular_inferior(A, b );
%clc;       % limpa a tela
format short
[n,n]=size(A);

%disp("Os dados do sistema")
n;
A;
btransposto=b';

% Resolvendo o sistema
%printf('\n Resolvendo o sistema linear TRIANG inferior  de dimensao %d \n', n );
x(1)= b(1)/A(1,1);
for i = 2:1:n
   s=0;
   for j =1:1:(i-1)
     s = s + A(i,j)*x(j);
   endfor 
   x(i)=( b(i) - s)/ A(i,i);
endfor

%disp("solucao obtida  eh")
%x


