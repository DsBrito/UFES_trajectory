% function [y,u,t] = arduino_lead_lag(obj,Ref,Ts,Tempo, a1, T1)
% Controle do motor CC usando controlador avanço-atraso (lead-lag)
% Data: 20/7/2022
%
function [y,u,t] = arduino_lead_lag(obj,Ref,Ts,Tempo, a1, T1, K)

y=[];
u=[];
t=[];

if (Ref<=0)|(Ref>7000)
    disp('Ref deve ser maior que zero e menor que 7000');
    beep;
    return;
end
if (Ts<1)|(Ts>200)
    disp('Ts deve estar entre 1 e 200');
    beep;
    return;
end
N=Tempo*1000/Ts;
if (N>1000)
    ss=sprintf('Tempo máximo para este valor de Ts em segundos: %d',Ts);
    disp(ss);
    beep;
    return;
end

if (a1<=0)
    disp('a1 deve ser maior que zero (estar no SPE)');
    beep;
    return;
end

if (T1<=0)
    disp('T1 deve ser maior que zero (estar no SPE)');
    beep;
    return;
end

if (K<=0)
    disp('K deve ser maior que zero');
    beep;
    return;
end

C=tf(K*[a1*T1 1],[T1 1]);
Cd=c2d(C,Ts/1000);
b1=num2str(round(1000*Cd.Num{1}(1),0));
b2=num2str(round(1000*Cd.Num{1}(2),0));
a1=num2str(round(1000*Cd.Den{1}(2),0));


comando=sprintf('%s;%s;%s;%s;%s;%s;%s;','2','0',num2str(Ts),num2str(Tempo),num2str(Ref),b1,b2,a1);
fprintf(obj,'%s',comando);
pause(2)

y=[];
i=1;
y(i,1)=fscanf(obj,'%f');
while (y(i)~=10000)
    i=i+1;
    y(i,1)=fscanf(obj,'%f');
end;
y(end)=[];


u=[];
i=1;
u(i,1)=fscanf(obj,'%f');
while (u(i)~=10000)
    i=i+1;
    u(i,1)=fscanf(obj,'%f');
end;
u(end)=[];


t=((1:length(y))-1)*Ts/1000;

if nargout==0
    stairs(t,y);hold on;
    stairs(t,u);hold off; shg
    yline(Ref,'r','LineWidth',3);
    legend('Y','U', 'Ref');
end

end
