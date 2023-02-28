function  solucao=RK4(f)

%Inicialmente para que o programa funcione, a funcao do arquivo funcoesRK4 deve ser chamada/ativada com o comando:
%   f=funcoesRK4
%
%nesse arquivo contém uma funcao handle @(x,y)
%Em seguida deve ser chamada a funcao que realmente calcula o RK4 com os valores de a,b,h,y0 pré definidos, pelo comando:
% solucao=RK4(f)
%
% valores das variaveis definidas internamente

  a=0   %inicio do intervalo
  b=0.3 %final do intervalo
  h=0.1 %passo
  y0=2  %PVI y(a)=y0
  
  puts("\n O intervalo dessa funcao eh: [0.0, 0.3]\n");
  
  %vetor x, no intervalo [a,b] com passos h
  x=(a:h:b)';
  
  %incilizando vetores y/k1/k2/k3/k4 com zero
  y=[y0; zeros(length(x)-1,1)];
  k1=zeros(length(x),1);
  k2=zeros(length(x),1);
  k3=zeros(length(x),1);
  k4=zeros(length(x),1);

  %realizando o método de RK de quarta ordem, preenchendo os vetores Ks
  for i =1: length(x)-1
    k1(i)= f(x(i,1),y(i,1));
    k2(i)= f(x(i,1)+h/3,y(i,1)+h*k1(i)/3);
    k3(i)= f(x(i,1)+2*h/3,y(i,1)-h*k1(i)/3+h*k2(i));
    k4(i)= f(x(i,1)+h,y(i,1)+h*k1(i)-h*k2(i)+h*k3(i));
    
    %calculando o y(i+1)
    y(i+1)= y(i)+h*(k1(i)+3*(k2(i)+k3(i))+k4(i))/8;    
  endfor
  
  %vetor solucao
  solucao=[x y];
  
  plot(a,y);