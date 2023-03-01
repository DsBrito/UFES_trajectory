num = [6.3223 18 12.811];
den = [1 6 11.3223 18 12.811];
t = 0:0.02:20;
[y,x,t] = step(num,den,t);
plot(t,y)
grid
title('Resposta ao Degrau Unitário')
xlabel('t (s)')
ylabel('Saída y(t)')
r1 = 1; while y(r1) < 0.1, r1 = r1+1; end;
r2 = 1; while y(r2) < 0.9, r2 = r2+1; end;
rise_time = (r2-r1)*0.02; %tempo de subida 
[ymax,tp] = max(y);
peak_time = (tp-1)*0.02; %tempo de pico 
max_overshoot = ymax-1;
s = 1001; while y(s) > 0.98 & y(s) < 1.02; s = s-1; end;
settling_time = (s-1)*0.02; %tempo de acomodação

%determinar a função transferencia de segunda ordem que se aproxima do
%sistema de quarta ordem A5.10