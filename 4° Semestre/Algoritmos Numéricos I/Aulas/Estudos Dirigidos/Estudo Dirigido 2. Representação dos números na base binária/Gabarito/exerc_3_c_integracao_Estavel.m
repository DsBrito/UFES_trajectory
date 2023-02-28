%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Calcula  Calcula o valor da   Integral In 
%   Integral de  x^n . e^(x-1) , (de 0 até 1)
%   via a recorrencia I(k-1) = (1 - I(k))/ k
% 
%   Dados de Entrada: 
%    n
%    Indice do valor de partida(o N grande)
%    I_Ngrande 
% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all;
disp("\n -------- Versao estavel ----------- "); 

n=1;
Ngrande=19
%  I_Ngrande é o valor de partida
% Ik=0.03125; Ik=0.00;
Ik=0.05;
disp("-------------------------");

fprintf(' "Sequencia com o valor de partida" \n  I(%d)= %14.12f \n', Ngrande,  Ik ); 
% processo estavel
k=Ngrande
while (k > n) 
    Ik= (1-Ik)/k;
    k=k-1;
    fprintf('I(%d)= %14.12f  \n', k,  Ik );
endwhile





