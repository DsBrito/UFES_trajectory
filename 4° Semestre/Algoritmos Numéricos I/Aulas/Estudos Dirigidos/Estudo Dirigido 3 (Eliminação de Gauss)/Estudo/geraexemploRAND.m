%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Gera um sistema linear TRIANGULAR inferior Ax=b de dimensao n 
%   cujos elementos são quaisquer, gerados  aleatoreamente  entre 0 e 1
%   usa se a funcao pronta do octave (rand de randomica)
%   O sistema gerando eh tal que a solução eh x=[1.0,1.0,...,1.0,1.0] 
%   
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Input:   dimensao do sistema
%% Output:  matriz A e vetor b 
%
%%   usage  
%   >> [A,b]= geraexemploRAND( );
%
function [A,b] = geraexemploRAND(n);
  
   A= zeros(n,n); %coloca zeros em todas as posiçoes
  
    for i=1:n
       for j=1:n
         A(i,j)=rand;
       endfor
    endfor
    % Gerando um vetor b tal que a solução seja x=[1.0,1.0,...,1.0,1.0] 
    % isto é calculando  b=A*[1.0,1.0,...,1.0,1.0]
    b = A*ones(n,1);

endfunction %fim funcao
  




