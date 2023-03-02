%% Aula 1 - Arquivo de teste

wn=10;
arq='aula1_R2015.slx'; % Para Matlab 2015 a 2017
arq='aula1_R2018.slx'; % Para Matlab 2018 em diante

% Abaixo, comentar as linhas que nao usar e manter apenas as de sua versao do Matlab

% Matlab 2018 em diante
out=sim(arq,1);
Y=out.X(:,[2,3]);
t=out.tout;

% Matlab anterior a 2018
% sim(arq,Tempo);
% Y=X(:,[2,3]);
% t=X(:,1);

plot(t,Y);legend('Degrau','Saída');xlabel('Tempo(s)');title('Fig.1 - Atividade 1');
shg