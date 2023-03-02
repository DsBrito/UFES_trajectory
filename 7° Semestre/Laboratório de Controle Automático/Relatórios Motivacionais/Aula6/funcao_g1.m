%function [delay, erro]=funcao_g1(g)
% Esta função obtem o erro do modelo de ordem 1 em relação ao original para
% diferentes atrasos
function [delay, tau, K,fit, Kp]=funcao_g1(g)
[y,t]=step(g);
t=linspace(0,max(t)*1.1,500);
u=[zeros(50,1);ones(450,1)];
y=lsim(g,u,t);
dat=iddata(y,u,t(2)-t(1));
t0=50*(t(2)-t(1));
f=[0.02:0.015:0.2];
for i=1:length(f)   
    delay(i)=t(sum(y<f(i)*y(end)))-t0;
    g1=tfest(dat,1,0,delay(i));
    tau(i)=1/g1.Denominator(2);
    K(i)=g1.Numerator*tau(i);
    fit(i)=g1.Report.Fit.FitPercent;
    Kp(i)=0.9*tau(i)/(K(i)*delay(i));
end
end