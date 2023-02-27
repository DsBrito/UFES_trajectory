A = zeros(42,42); % matriz com um valor a mais em x e y para suportar a placa e os espa�os em 0 para opera��es
erromax = 9999;
tol= 1e-3;
placa = 10; % dimens�o da placa

%colocando a placa na matriz de forma sim�trica nas bordas
for k =(22-(placa/2)):(21+placa/2)
A(k,1) = 10;
A(k,42) = -10;
end

while erromax > tol 

A0 = A; % Armazenando todos os valores iniciais para serem comparados posteriormente com o erro

for j = 2:41
   for i = 2:41
       A(i,j) = (A(i+1,j)+A(i-1,j)+A(i,j+1)+A(i,j-1))/4; % Calcula o valor do potencial no ponto
   end
end

C = abs(A-A0); % Matriz j� com o valor absoluto do erro
erromax = max(max(C)); % Erro baseado no 
end

x = linspace (1,42,42);
y = linspace (1,42,42);
[X,Y] = meshgrid(x,y);
contourf(X,Y,A,200,'edgecolor','none')
xlabel('Posi��o Horizontal')
ylabel('Posi��o Vertical')
hcb=colorbar
title(hcb,'Potencial El�trico (V)')
set(hcb, 'ylim', [-10 10])