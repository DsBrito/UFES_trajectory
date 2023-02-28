%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Script associado ao Roteiro 2 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all; % limpa as variaveis
clc;       % limpa a tela
printf ('Visualizando como ficam armazenados alguns  valores  na maquina \n');
% Exemplos
printf ('Representados de forma exata  \n'); 
    x =   10.5;  %  2.0^(3) + 2.0^(1) + 2.0^(-1)  em binário =>(1010.1) 
    y =  -9.5;   %  2.0^(3) + 2.0^(0) + 2.0^(-1)  em binário =>(1001.1) 
    z =  21.78125 ;  
   printf('x = %.20f | y = %.20f | z = %.20f \n \n',  x, y, z);
% Exemplos
printf ('Mais uns...\nRepresentados de forma exata  \n'); 
    x = 128.75;          % 2.0^(7) + 2.0^(-1)+ 2.0^(-2); 
    y = 2.0^(-6);        % 0.015625
    z = 0.7998046875;     % 2.0^(-1)+ 2.0^(-2)  + 2.0^(-5) + 2.0^(-6) + 2.0^(-9)+ 2.0^(-10)
    printf('x = %.20f | y = %.20f | z = %.20f \n \n',  x, y, z);
% 
printf ('NAO representados de forma exata  \n'); 
    r =  sqrt(3);    
    y =  10.1 ;  
    z =  0.6;          
    printf('r = %.20f | y = %.20f | z = %.20f \n \n',  r, y, z);

printf ('------------------------------ \n'); 
printf ('Observem portanto que alguns terao representacao exata e outros não \n'); 
printf ('Mais exemplos   \n'); 
    x= 0.75;             % em binário => (0.11) = 0.5 + 0.25 
    y= 0.796875;         % em binário => (0.110011)= 0.5 + 0.25 + 0.03125 + 0.015625
    z= 0.8;              % em binário => (0.1100 1100 1100 1100 1100 ....) 
    printf('x = %.20f | y = %.20f | z = %.20f \n \n',  x, y, z);
%
%---------------------------
%
disp( 'Alguns valores particulares: O maior, o menor e a precisão)')  
  O_Maior=realmax
  o_menor=realmin
  epsilon_maquina=eps

disp ('--FIM--')


