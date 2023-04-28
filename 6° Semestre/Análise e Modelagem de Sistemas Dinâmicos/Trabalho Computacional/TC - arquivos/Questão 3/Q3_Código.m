%% zeta = ?
%% w = 7.07

%Função
num = [50];
den = [1 7 50];


t = 0:0.005:7.07;

[y,x,t] = step(num,den,t);%plota para ver o erro em regime com a entrada degrau

r = 1; while y(r) < 1.0001; r = r + 1; end;
rise_time = (r - 1)*0.005;
[ymax,tp] = max(y);
peak_time = (tp - 1)*0.005;
max_overshoot = ymax-1;
s = 1415; while y(s) > 0.98 & y(s) < 1.02; s = s - 1; end; %-.98 - 1.02 se refere aos 2%
settling_time = (s - 1)*0.005;

%Resultado:
%settling_time =1.1450 [correto] - tempo de acomodação
%peak_time =0.5100 [correto] - tempo de pico
%Wn= 7.07 [correto] - Wn
%max_overshoot =0.1670 [correto] - máximo sobre sinal
%rise_time = 0.3400 [correto] - tempo de subida 
 
