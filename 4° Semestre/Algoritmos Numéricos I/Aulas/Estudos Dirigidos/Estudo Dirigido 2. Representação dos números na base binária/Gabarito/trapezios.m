%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Resolvendo a lista de exercicios 1
%   Professora Cláudia G Varassin
%   5. d INTEGRACAO via Trapezios 
%       versao funcao
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function Int_trap = trapezios(a,b,N);
%clc;       % limpa a tela
%
% usa a funcao f(x) definida no aqruivo f.m
disp('O espaçamento entre os pontos eh')
h=(b-a)/(N)
x=a;
s= 0; 
%
for i = 1:(N);
   %fprintf('No passo %d, os pontos em que a funcao serah avaliada sao x: %f  e x+h = %f  \n--- \n', i, x, x+h);
   trap = h*( f(x) + f(x+h) )/2;
   s = s + trap;
   x=x+h; % preparando para o proximo passo
end;
Int_trap = s;
fprintf('Com  N=%d, a integral via Trapezios eh: %.8f \n' , N ,Int_trap);
disp('----- Fim----  ')

endfunction





