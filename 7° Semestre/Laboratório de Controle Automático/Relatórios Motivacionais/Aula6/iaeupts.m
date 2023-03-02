function [iae,UP,ts] = iaeupts(m,t)
y=step(m,t);
s=stepinfo(m);
UP=s.Overshoot;
ts=s.SettlingTime;
iae=trapz(t,abs(1-y));
end

