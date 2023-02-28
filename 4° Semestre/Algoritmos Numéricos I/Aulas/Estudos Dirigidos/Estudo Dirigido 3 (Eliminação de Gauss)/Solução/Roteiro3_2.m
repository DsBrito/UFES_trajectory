
n=3;
function [A,b] = geraexemploRAND(n);
  
   A= zeros(n,n); %coloca zeros em todas as posiçoes
  
    for i=1:n
       for j=1:n
         A(i,j)=rand;
       endfor
    endfor
  
    b = A*ones(n,1);


endfunction %fim funcao



%%
% Eliminação de Gauss com pivoteamento parcial
% 
% Input: Matriz A de coeficientes, b vetor de constantes
% Output: vetor solucao
% usage   elimGaussCOMPivot( A, b )
%
%%
P=elimGaussCOMPivot( A, b )
  %clc
	disp('---Eliminacao de Gauss  COM Pivotemento ---')

	% Verificação das dimensoes da matriz e do vetor
    	[row,col] = size(A); rowb = length(b);
	if row ~= col || row ~= rowb
			disp('Erro de dimensao de matriz e/ou vetor');
			return;
	endif
	n = row;
  %format short
  %disp('---Dados  de entrada ---')
	%A
  %btranposto=b'
  %disp('-------------------------')

 % Eliminacao
    for k = 1:(n-1)  % etapa k
            % fase do pivoteamento
            % determinar linha do pivô na coluna k
            maxlin = k;
            for i = k+1:n
	             if abs(A(i,k)) > abs(A(maxlin,k)) maxlin = i; endif
            end
            if maxlin ~= k % a troca deve ser feita 
             %fprintf('Na etapa %d, permuta-se as linhas %d e %d, pivo em (%d,%d)=%.4f\n',k, k, maxlin, maxlin, k, A(maxlin,k) );
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
	  	A(i,k) = 0.0; % não necessaria
		  for j=k+1:n
		      A(i,j) = A(i,j) - m * A(k,j);
		  end
		  b(i) = b(i) - m * b(k);
	   endfor %fim do for i
     %printf('--- Apos a  %d etapa, a matriz eh ',k)
     %A 
 
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

H= elimGaussSemPivot( A, P )
	disp('---Eliminacao de Gauss  SEM Pivotemento ---')

% Verificação das dimensões da matriz e do vetor
    	[row,col] = size(A); rowb = length(P);
	if row ~= col || row ~= rowb
			disp('Erro de dimensao de matriz e/ou vetor');
			return;
	endif
	n = row;

% Eliminacao
% triangularizacao
 for k = 1:(n-1)  % etapa k
		for i = k+1:n
			m = A(i,k) / A(k,k);
			A(i,k) = 0.0; % para a visualizacao
			for j=k+1:n
			 	 A(i,j) = A(i,j) - m * A(k,j);
			endfor
			P(i) = P(i) - m * P(k);
		 endfor
     %printf('--- Apos a  %d etapa, a matriz eh ',k)
     %A          
	endfor % fim do for k (fim das etapas )
% fim triangularizacao  

% Resolvendo o sistema via substituicao regressiva
        w(n)= P(n)/ A(n,n);
        for i = (n-1):-1:1
          s = 0;
          for j = (i+1):n
             s = s + A(i,j)*w(j);
          endfor
          w(i)=( P(i) - s)/ A(i,i);
        endfor %for for i
% fim subs.  regressiva
disp('Valor do erro relativo usando a matriz resultado do processo com pivoteamento ')
erro_relativoSEM_PIVOR= abs ( (w-(1))/ 1)
%fim Elimincao




