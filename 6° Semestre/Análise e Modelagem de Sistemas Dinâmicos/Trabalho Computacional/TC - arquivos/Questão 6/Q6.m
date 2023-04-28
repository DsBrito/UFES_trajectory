num = [2];
den = [1 1 2];
t = 0:0.2:10;
r = 0.5*t.^2;
y = lsim(num,den,r,t);
plot(t,r,'-',t,y,'o',t,y,'-');
grid
title('Resposta � Par�bola')
xlabel('t (s)')
ylabel('Entrada e Sa�da')
text(2.1,27.5,'Entrada em Par�bola')
text(7.2,7.5,'Sa�da')