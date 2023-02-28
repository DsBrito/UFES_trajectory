% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Calculando a aproximacao para e^1 
%  versao com  " o for Crescente"
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   
N=input('Digite o valor de N: ');

%printf('Calculando uma aproximacao para  e^1 \n' );
%
  s=1.0;
  for i = 1:1:N
     termo= 1/( factorial(i))
     % para mostar os termos
     % printf('%.16f   \n ------', termo );
     s = s + termo;
  endfor %i


erro_rel= abs ( (s-(e^1)) )/ (e^1);
%printf('Pela versao Crescente \n o valor de e: %.16f e erro rel. %e   \n', s, erro_rel );
printf('Pela versao    Crescente \nO valor de e: %.16f ;  ', s);
erro_rel= abs ( (s-(e^1)) )/ (e^1)
printf(' e do octave: %.16f \n  ', e);








