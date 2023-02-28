%%
%% Eliminação de Gauss com pivoteamento parcial
%%
%% Input: Matriz A de coeficientes, b vetor de constantes
%% Output: vetor solucao
%% usage   elimGaussCOMPivot( A, b )
%
%%
function [x] = elimGaussCOMPivot( A, b );
  %clc
	disp('---Eliminacao de Gauss  COM Pivotemento ---')

	% Verificação das dimensoes da matriz e do vetor
    	[row,col] = size(A); rowb = length(b);
	if row ~= col || row ~= rowb
			disp('Erro de dimensao de matriz e/ou vetor');
			return;
	endif
	n = row;
  format short
  %disp('---Dados  de entrada ---')
	A
  btranposto=b'
  disp('-------------------------')

 % Eliminacao
    for k = 1:(n-1)  % etapa k
            % fase do pivoteamento
            % determinar linha do pivô na coluna k
            printf('\n Etapa %d \n ',k)
            maxlin = k;
            for i = k+1:n
	             if abs(A(i,k)) > abs(A(maxlin,k)) maxlin = i; endif
            end
            if maxlin ~= k % a troca deve ser feita 
             printf('Na etapa %d, permuta-se as linhas %d e %d, pivo em (%d,%d)=%.4f\n',k, k, maxlin, maxlin, k, A(maxlin,k) );
             % troca as linhas  k e maxlin de A
             for j = k:n
	              aux = A(k,j);
                A(k,j) = A(maxlin,j);
                A(maxlin,j)= aux;
             endfor
             aux = b(k);
             b(k) = b(maxlin);
             b(maxlin) = aux;
             endif; % fim troca linhas 

	   for i = k+1:n
	  	m = A(i,k) / A(k,k);
	  	A(i,k) = 0.0;
		  for j=k+1:n
		      A(i,j) = A(i,j) - m * A(k,j);
		  end
		  b(i) = b(i) - m * b(k);
	   endfor %fim do for i
     printf('--- Apos a  %d etapa, a matriz eh ',k)
     A 
     pause
 
   endfor  % fim do for k (fim das etapas )

% Resolvendo o sistema via substituicao regressiva
     x(n)= b(n)/ A(n,n);
     for i = (n-1):-1:1
       s = 0;
       for j = (i+1):n
          s = s + A(i,j)*x(j);
       endfor %j
       x(i)=( b(i) - s)/ A(i,i);
    endfor %for for i
    printf('A solucao eh ')
    x
% fim subs.  regressiva
end



