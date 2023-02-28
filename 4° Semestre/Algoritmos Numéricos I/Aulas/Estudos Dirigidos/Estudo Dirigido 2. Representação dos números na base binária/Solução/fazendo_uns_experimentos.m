%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Script associado ao Roteiro 2 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear
clc
disp( 'Fazendo  experimentos...')
% exp 1
disp( 'Experimento 1: comparando (raiz quadrada de 3)^2) com  3.0 ')
  r =  sqrt(3.0); 
  if  ( (r^2) == 3.0 )
      disp('iguais')
  else  
   disp('Veja que  (raiz de 3^2) e 3.0  sao distintos')
  endif
 
% exp 2
disp('------------------ ')
disp( 'Experimento 2 : somando 0.1 até chegar a 1.0 ')
% objetivo do codigo: partindo de x=0.0  e ir somando  0.1  até que ele seja igual a 1.0 
% rode a versao com a condicao  que estah feita 
% em seguida mude a condicao do while  para ( x !=1.0 )
x = 0.0
while ( x !=1.0)  
    x = x + 0.1;
    printf('o valor de x eh: %.20f \n',  x);
endwhile


disp ('--FIM--')


