%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Resolvendo a lista de exercicios 1
%   Professora Cláudia G Varassin
%   5. d INTEGRACAO via Trapezios 
%   versao funcao
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function Int_ret_dir = retangulosDireita(a,b,N);
%clc;       % limpa a tela
%
% Versao para a funcao f(x) definida no aqruivo f.m
disp('--- Resolvendo a lista de exercicios-----')
disp('O espaçamento entre os pontos eh')
h=(b-a)/(N)
x=a;
s= 0; 
%
for i = 1:(N);
   %fprintf('o ponto em que a funcao serah avaliada eh x = %f  \n',  x+h);
   s = s + f(x+h);
   x=x+h; % preparando para o proximo passo
end;
Int_ret = h*s;
fprintf('Com  N=%d, a integral via retangulos eh: %.8f \n' , N ,Int_ret);
disp('----- Fim----  ')





