%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%    Calcula novas aproximacoes para a raiz  de 
%    uma funcao f(x) pelo metodo da TANGENTE
% 
%   Dados de Entrada:  o chute inicial (xinicial) 
%		                   precisao  (tol)
%                      A qte maxima de iteracoes (NumiterMAX)
%                      f(x) e f'(x)  (f e sua derivada)

%   Saida: a ultima aproximacao, o vetor com a sequencia de aproximacoes, 
%           a qte de iteracoes e o valor da ultima distancia (relativa)  entre os pontos
% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
function  [raiz, x, qteIter, distrel] = tangente( xinicial , tol, NumMAXiter, f, derf)
%
qteIter=0;
distrel=1.0;
x(1)= xinicial;
printf('\nRodando o metodo da tangente com  tol %e e x0:%f \n', tol, xinicial ); 
% processo iterativo;
k=1;
while (distrel > tol) && ( qteIter < NumMAXiter)   
     % avaliando a funcao e a sua derivada  
    fk = f(x(k));
    derfk = derf(x(k));   
   % gerando o novo ponto
   dist= (fk/derfk);   
   x(k+1)= x(k)- dist;
   raiz=  x(k+1);
   % calculando a dist relativa
   distrel= abs( dist/x(k+1) );
   % atualizando os contadores 
   k= k+1;
   qteIter= qteIter+1;
end
x;
qteIter;
endfunction
