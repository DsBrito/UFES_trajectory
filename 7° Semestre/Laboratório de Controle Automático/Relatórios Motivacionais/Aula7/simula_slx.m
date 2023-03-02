function [Y,t] = simula_slx(arquivo,Tempo)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
if strcmp(arquivo,'motor_cc_R2018.slx')
    out=sim(arquivo,Tempo); % Matlab 2018 e posterior
    Y=out.X(:,[ 2 3 4]);
    t=out.tout;
elseif strcmp(arquivo,'motor_cc_R2015.slx')
    sim(arquivo,Tempo); % Matlab anterior 2018
    Y=X(:,[ 2 3 4]);
    t=X(:,1);
else
    y=[];u=[];t=[];
end

end

