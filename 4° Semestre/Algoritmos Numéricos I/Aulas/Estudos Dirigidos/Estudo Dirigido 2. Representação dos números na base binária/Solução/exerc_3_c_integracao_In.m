%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Algoritmo  para calcular o valor da Integral I_n
%   via a recorrencia I = 1 - k* I
% 
%   I_n eh a Integral de (x^n . e^(x-1) , (de 0 ateg 1)
%   Dados de Entrada: 
%    n 
%    I_1= e^(-1)
% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
clear all;
disp(' Calcula o valor da integral I_n via a recorrencia I = 1 - k*I' )
disp("\n Versao feita para n fixo (n=9), isto eh, calcula I_9 ----------- ");  
n=9;
k=1;
% Sabe que o valor de I_1  eh = e^(-1)= 0.367 879 441 171...;
I = 0.367879;       % usando I com 6 digitos
%I = 0.367879441;   % usando I com 9 digitos
%I = e^(-1);         % usando I da maquina
%
disp("\n --------  Valores de I -----------");
printf(' "Sequencia com o valor de partida" \n I(%d)= %14.12f \n \n', k,  I ); 
% processo iterativo
for k = 2:n;
    I= 1-k*I;
    printf('I(%d)= %.12f  \n', k,  I );
endfor





