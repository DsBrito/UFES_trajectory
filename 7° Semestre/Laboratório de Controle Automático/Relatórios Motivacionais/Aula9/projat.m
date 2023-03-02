function [ c , at] =projat( g,k,mf )
% function [ c,at ] =projat( g,k,fi )
% Data:9/11/2020
% Entradas
% g = FT
% k = ganho para atender erro em regime
% mf = margem de fase desejada
%
% Saidas:
% c = compensador
% at =[a T]
%
if (mf<0)
    disp('***** ERRO: m<0 ****');
    beep
    c=[];
    return
end;
[m,f,w]=bode(k*g);
for i=1:length(w)
    f1(i)=180+f(:,:,i);
    m1(i)=20*log10(m(:,:,i));
end;
ind=find(f1>mf);
i1=ind(end);
wg=w(i1);
a=10^(-m1(i1)/20);
T=10/(a*wg);
c=k*tf([a*T 1],[T 1]);
at=[a T];
if nargout==0
    figure(1);bode(k*g,c*g);grid;
    figure(2);step(feedback(c*g,1));
end
end