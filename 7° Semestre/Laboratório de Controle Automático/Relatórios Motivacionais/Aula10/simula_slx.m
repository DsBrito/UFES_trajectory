function [Y,t] = simula_slx(arquivo,Tempo)
% Versao: 2/8/2021
if strcmp(arquivo,'aula10_R2018.slx')
    out=sim(arquivo,Tempo); % Matlab 2018
    Y=out.X(:,[ 2 3 4 5]);
    t=out.tout;
elseif strcmp(arquivo,'aula10_R2015.slx')
    sim(arquivo,Tempo); % Matlab anterior 2018
    Y=X(:,[ 2 3 4 5]);
    t=X(:,1);
elseif strcmp(arquivo,'aula10_R2019.slx')
    out=sim(arquivo,Tempo); % Matlab 2019 e posterior
    Y=out.X(:,[ 2 3 4 5]);
    t=out.tout;
else
    y=[];u=[];t=[];
end

end

