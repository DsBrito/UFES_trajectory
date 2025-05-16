function [tau,zeta,wn,teta,p] = init(I)
zeta=linspace(0.1,0.7,40);
wn=linspace(1,10,40);
tau=linspace(0.2,10,40);
teta=tau/2;
p=linspace(40,1,40);
if (I<1)|(I>40)
    disp('Coloque seu numero, entre 1 e 40');
    beep;
    pause(1)
    beep
    tau=[];zeta=[];wn=[];teta=[];p=[];
else
  zeta=zeta(I);
  wn=wn(I);
  tau=tau(I);
  teta=teta(I);
  p=p(I);
end
end

