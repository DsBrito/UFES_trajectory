% function [] = zera_saida(obj,U0)
%   15/7/2022
% Zera a velocidade do motor para entrada U0: '0;0;
%
function [] = seta_saida(obj,U0)
comando=sprintf('0;0;10;1;%d;',round(U0,0));
fprintf(obj,'%s',comando);
pause(3);
end