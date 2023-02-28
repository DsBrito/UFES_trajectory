% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Calculando a aproximacao para e^1 
%   versao com  "o for Decrescente"
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
N=input('Digite o valor de N: ');
%printf('\n  ---- Calculando a aproximacao para e^1 ---- \n' );
  s=0;
  for i = N:(-1):1
    termo= 1/( factorial(i))
    % printf('%.16f   \n ------', termo );
    s = s + termo;
  endfor %i
  s= 1.0 + s;
erro_rel= abs ( (s-(e^1)) )/ (e^1);
%printf('Pela versao DEcrescente \n o valor de e: %.16f e erro rel. %e   \n', s, erro_rel );
printf('Pela versao  DECrescente \nO valor de e: %.16f ;  ', s);
erro_rel= abs ( (s-(e^1)) )/ (e^1)



%valor exato com 14 digitos =  2.718 281 828 459 05



