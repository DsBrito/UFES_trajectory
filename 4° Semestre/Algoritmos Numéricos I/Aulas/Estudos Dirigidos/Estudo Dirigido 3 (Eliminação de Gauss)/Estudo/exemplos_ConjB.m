%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Arquivos com exemplos de sistemas
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
format short
% -- exemplos de sistemas CHEIOS
%{
A=[ 1.8 10 0.3 4 1.0 1.0;
1.0 0.3 0.5 2.0 4.0 11.0;
5.5 1.1 5.0  0.0 4.7 1.0;
17.0 2.3 3.0 8.2 4.0 1.0;
905.0 0.3 31.0 -6.2 7.0 1.0;
47 7.0 8.0 -2.2 0.0 3.0];
%}

% %}
A=[ 1.8 10 0.3 4 1.0 1.0 3.4;
1.0 0.3 0.5 2.0 4.0 11.0  2.5;
5.5 1.1 5.0  0.0 4.7 1.0 -8.3;
17.0 2.3 3.0 8.2 4.0 1.0 12.5;
905.0 0.3 31.0 -6.2 7.0 1.0 7.8;
7777 7.0 8.0 -2.2 0.0 3.0 4.0;
47   7.0 8.0 -2.2 0.0 3.0 4.0];
% %}

[row,col] = size(A);
if row ~= col 
   disp('Erro de dimensao de matriz e/ou vetor');
   return;
endif
n = row;

% Gerando um vetor b tal que a solução seja x=[1.0,1.0,...,1.0,1.0] 
% isto é calculando  b=A*[1.0,1.0,...,1.0,1.0]
xexato=ones(n,1);
b = A*ones(n,1);

disp("Os dados do sistema")
n
A
btransposto =b'
disp("Soh para efeito didatico, mostra se a solucao  exata")
% so para ajudar a fazer a comparacao 
xex=xexato'

