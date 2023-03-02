% function [y,u,t] = arduino_controle(obj,Ref,Ts,Tempo, Kp, Ki, Ref0)
% Controle PI
% Data: 12/7/2022
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

comando=sprintf('%s;%s;%s;%s;%s;%s;%s;','2',num2str(Ref),num2str(Ts),num2str(Tempo),num2str(floor(100*Kp)),num2str(floor(100*Kp*Ki)),num2str(Ref0));
fprintf(obj,'%s',comando);
pause(2)


y=[];
x=0;
i=1;
while (x~=10000)
    x=fscanf(obj,'%f');
    y(i,1)=x;
    i=i+1;
end;
y(end)=[];


u=[];
x=0;
i=1;
while (x~=10000)
    x=fscanf(obj,'%f');
    u(i,1)=x;
    i=i+1;
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
