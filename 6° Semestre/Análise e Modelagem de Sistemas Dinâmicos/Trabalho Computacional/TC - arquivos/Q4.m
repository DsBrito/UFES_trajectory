% ------- Resposta à rampa -------
num = [50];
den = [1 7 50];

t = 0:0.1:10;
r = t;
y = lsim(num,den,r,t);
plot(t,r,'-',t,y,'o')
grid
title('Resposta à Rampa Unitária Obtida com o Uso do Comando "lsim"')
xlabel('t (s)')
ylabel('Entrada e Saída do sistema')
text(6.3,4.6,'Entrada em Rampa Unitária')
text(4.75,9.0,'Saída')