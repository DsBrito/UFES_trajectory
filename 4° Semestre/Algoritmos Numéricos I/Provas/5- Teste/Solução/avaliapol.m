function  x=avaliapol(x, y, b, z);
  
  N=length(y);  %pegando o tamanho da dimensão
  C=b(1,N);     %armazenano o c=b (ultimos)
  

  %aqui irá caminhar de ordem decrescente
  %ex:
  % x=[-2 0 1];
  % y=[3 -1 -1];
  % z= -1;
  % b= (resultado da funcao DifDivididasAsc "vetB") = [3 -1 -0.333]
  
  % c3=C= -0.3333
  % c2=C= b(3-1)+((-1)-x(3-1))* -0.3333 = -1+(-1-(0))*-0.3333 = -0.6667
  % c1= b(3-2) + ((-1-x(3-2))* -0.6667 = 3+(-1-(-2))*-0.6667 = 2.3333
  
  
  
  %Generalizando:
  %       ci=bi-(z-xi)*c1+1
  
  for i = N:-1:2
   C=b(i-1)+(z-x(i-1))*C;
  
  endfor;
  printf('P(%.2f) = %.2f\n',z,C);