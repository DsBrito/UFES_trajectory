function [ c,a,T ] =projav( g,k,fi )
% function [ c,a, T ] =projav( g,k,fi )
% Data:22/07/2022
% Entradas
% g = FT
% k = ganho para atender erro em regime
% fi = fase a adicionar a margem de fase
%
% Saidas:
% c = compensador
% a, T
%
if ((fi>88)|(fi<1))
    disp('***** ERRO: (fi>89)|(fi<1) ****');
    beep
    c=[];
    return
end;
fi=fi*pi/180;
a=(1+sin(fi))/(1-sin(fi));
ad=10*log10(a);
[m,f,w]=bode(k*g);
for i=1:length(m)
    m1(i)=20*log10(m(:,:,i));
end;
ind=find(m1>-ad);
wg=w(ind(end));
T=1/(sqrt(ad)*wg);
c=k*tf([a*T 1],[T 1]);
if nargout==0
    figure(1);bode(k*g,c*g);grid;
    figure(2);step(feedback(c*g,1));
end
end
