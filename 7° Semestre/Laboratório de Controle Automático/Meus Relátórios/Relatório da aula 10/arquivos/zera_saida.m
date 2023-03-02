% function [] = zera_saida(obj)
%   15/7/2022
% Zera a velocidade do motor: '0;0;
%
function [] = zera_saida(obj)
comando='0;0;0;0;0;';
fprintf(obj,'%s',comando);
end