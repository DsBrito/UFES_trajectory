function [erro,Overshoot,SettlingTime, iae,G2] = desempenho(Y,t,Ref, t0)
u=Y(:,1);
y=Y(:,2);
i1=sum(t<=2)+1;
i2=length(y);

iae=trapz(t(i1:i2),abs(Ref-y(i1:i2)));
yinf=mean(y((i2-20):i2));
erro=(100*abs(Ref-yinf))/Ref;
ii=i1-5:i2;
y0=y(ii);y0=y0-y0(1);
u0=u(ii);u0=u0-u0(1);
u0=sign(u0);
datx=iddata(y0,u0,0.01);
G2=tfest(datx,2,0);
S=stepinfo(G2);
Overshoot=S.Overshoot;
SettlingTime=S.SettlingTime;
end

