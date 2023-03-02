% function [Y,t] = arduino_coleta(obj,U0,Ts,Tempo)
% Data: 13/7/2022
% Rotina no PC
function [Y,t,Yr,tau]  = arduino_coleta(obj,U0,Ts,Tempo)

Y=[];
t=[];
Yr=[];

if (min(U0)<=0)|(max(U0)>255)
    disp('U0 deve ser maior que zero e menor que 255');
    beep;
    return;
end

if (Ts<1)|(Ts>200)
    disp('Ts deve estar entre 1 e 200');
    beep;
    return;
end

N=floor(Tempo*1000/Ts);
if (N>1000)
    ss=sprintf('Tempo máximo para este valor de Ts em segundos: %d',Ts);
    disp(ss);
    beep;
    return;
end

for k=1:length(U0)
    comando=sprintf('%s;%s;%s;%s;','1',num2str(U0(k)),num2str(Ts),num2str(Tempo));
    fprintf(obj,'%s',comando);
    pause(1)
    
    y=[];
    x=0;
    i=1;
    while (x~=10000)
        x=fscanf(obj,'%f');
        y(i,1)=x;
        i=i+1;
    end;
    y(end)=[];
    if (k==1)
        y0=mean(y(1:2));
    else
        y0=mean(Y((end-5):end));
    end
    yn=y-y0;
    tau(k)=(Ts/1000)*sum(yn<0.63*yn(end));
    Y=[Y;y];
    Yr=[Yr;mean(y((end-10):end))];
end
t=((1:length(Y))-1)*Ts/1000;

if nargout==0
    stairs(t,Y);
    yline(U0,'r','LineWidth',3);
    xlabel('Tempo(s)');
    ylabel('Resposta');
end

end

