% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Interpolacao um conjunto de pontos (x,y)
%
%   Calcula a tabela com todas as diferencas divididas ascendentes
%   necessarias para fazer a  interpolacao ude conjunto de pontos (x,y) 
%   armazenando em uma matriz DD
%  Saida: a matriz  todas as diferencas divididas ascendentes 
%         e os coeficientes da interpolacao
%
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function  [DD, vetB] = DifDivididasAsc(x,y);

  N=length(x)
  % N eh o numero de pontos

 % Montando  a tabela de dif divididas
  for i = 1:N;
       DD(i,1) = y(i);   
  endfor;
   
 for k = 2:(N);  
   ord=(k-1); 
   for i = 1:(N -k+1);
     DD(i,k) = ( DD((i+1),(k-1))- DD(i,(k-1)) )/( x(i+(ord))- x(i)) ;   
  endfor;
 endfor;

% vetB  
% Armazena a primeira linha da matriz DD, isto eh, as Dif. Divididas em tormo de y0
% Tem portanto os coeficientes do polinomio interpodaor
%
for k = 1:(N);
      vetB(k)= DD(1,k); 
endfor; 


