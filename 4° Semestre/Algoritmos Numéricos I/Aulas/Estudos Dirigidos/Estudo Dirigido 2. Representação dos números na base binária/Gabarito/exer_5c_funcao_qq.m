%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Resolvendo a lista de exercicios 1
%   Professora Cláudia G Varassin
%   5 c
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all; % limpa as variaveis
clc;       % limpa a tela
%
% Versao para a funcao f(x) definida no arquivo f.m
disp('--- Resolvendo a lista de exercicios-----')
% Dados iniciais
a=input('Digite o limite inferior (a): ')
b=input('Digite o limite inferior (b): ')
N=input('Digite a qte de subintervalos (N): ')
%
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






