% 
% Eliminação de Gauss SEM pivoteamento parcial
% 
% Input: Matriz A de coeficientes, b vetor de constantes
% Output: vetor solucao
%
%  Usage   elimGaussSemPivot( A, b )
%
function [x] = elimGaussSemPivot( A, b )
	disp('---Eliminacao de Gauss  SEM Pivotemento ---')

% Verificação das dimensões da matriz e do vetor
    	[row,col] = size(A); rowb = length(b);
	if row ~= col || row ~= rowb
			disp('Erro de dimensao de matriz e/ou vetor');
			return;
	endif
	n = row;
  disp('---Dados  de entrada ----')
  %n
	A
  btranposto=b'

% Eliminacao
% triangularizacao
 for k = 1:(n-1)  % etapa k
		for i = k+1:n
			m = A(i,k) / A(k,k);
			A(i,k) = 0.0; % para a visualizacao
			for j=k+1:n
			 	 A(i,j) = A(i,j) - m * A(k,j);
			endfor
			b(i) = b(i) - m * b(k);
		 endfor
     printf('--- Apos a  %d etapa, a matriz eh ',k)
     A    
     pause     
	endfor % fim do for k (fim das etapas )
% fim triangularizacao  

% Resolvendo o sistema via substituicao regressiva
        x(n)= b(n)/ A(n,n);
        for i = (n-1):-1:1
          s = 0;
          for j = (i+1):n
             s = s + A(i,j)*x(j);
          endfor
          x(i)=( b(i) - s)/ A(i,i);
        endfor %for for i
% fim subs.  regressiva

%fim Elimincao

endfunction



