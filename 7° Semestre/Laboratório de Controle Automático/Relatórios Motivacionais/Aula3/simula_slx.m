function [y,u,t] = simula_slx(arquivo,Tempo)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
if strcmp(arquivo,'aula3_2018.slx')
    out=sim(arquivo,Tempo); % Matlab 2018 e posterior
    u=out.X(:,2);
    y=out.X(:,3);
    t=out.tout;
elseif strcmp(arquivo,'aula3_2015.slx')
    sim(arquivo,Tempo); % Matlab anterior 2018
    u=X(:,2);
    y=X(:,3);
    t=X(:,1);
else
    y=[];u=[];t=[];
end

end

