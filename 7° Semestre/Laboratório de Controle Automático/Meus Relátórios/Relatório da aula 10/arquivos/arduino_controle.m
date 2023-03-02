% function [y,u,t] = arduino_controle(obj,Ref,Ts,Tempo, Kp, Ki, Ref0)
% Controle PI do motor CC
% Data: 15/7/2022
%
function [y,u,t] = arduino_controle(obj,Ref,Ts,Tempo, Kp, Ki, Ref0)

if nargin==6
    Ref0=0;
end

y=[];
u=[];
t=[];

if (Ref0<=0)|(Ref>7000)
    disp('Ref0 deve ser maior que zero e menor que 7000');
    beep;
    return;
end

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

if (Kp<=0)
    disp('Kp deve ser maior que zero');
    beep;
    return;
end

if (Ki<=0)
    disp('Ki deve ser maior que zero');
    beep;
    return;
end

comando=sprintf('%s;%s;%s;%s;%s;%s;%s;','2','0',num2str(Ts),num2str(Tempo),num2str(Ref),num2str(Ref0),num2str(floor(100*Kp)),num2str(floor(100*Kp*Ki)));
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
