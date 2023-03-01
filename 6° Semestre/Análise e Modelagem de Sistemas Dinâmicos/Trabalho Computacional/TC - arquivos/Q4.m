% ------- Resposta � rampa -------
num = [50];
den = [1 7 50];

t = 0:0.1:10;
r = t;
y = lsim(num,den,r,t);
plot(t,r,'-',t,y,'o')
grid
title('Resposta � Rampa Unit�ria Obtida com o Uso do Comando "lsim"')
xlabel('t (s)')
ylabel('Entrada e Sa�da do sistema')
text(6.3,4.6,'Entrada em Rampa Unit�ria')
text(4.75,9.0,'Sa�da')