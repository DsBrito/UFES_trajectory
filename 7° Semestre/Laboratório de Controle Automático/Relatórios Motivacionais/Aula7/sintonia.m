% function [ C, iae ] = sintonia(G, tipo, metodo, lambda)
% Data: 20/10/2020
% Entradas:
% G é a FT, definida via comando tf
% tipo = P, PI, PID (entre aspas)
% metodo = cohen, chr, chr20, zie, IAE otimo, lam (entre aspas)', ordem2
% lambda = constante de tempo de malha fechada se usado metodo lambda
%
function [ C, iae ] = sintonia(G, tipo, metodo, lambda)
if nargin==0
    disp('Chamada da função: sintonia( G,tipo, metodo) ');
    disp('G é a FT, definida via comando tf');
    disp('tipo = P, PI, PID (entre aspas)');
    disp('Metodo = cohen, chr, chr20, zie, IAE otimo, lam (entre aspas), ordem2');
    return;
elseif nargin==3
        lambda=0;
end;
K=G.num{1}(2);
theta=G.InputDelay;
tau=G.den{1}(1);
a=K*theta/tau;
ki=0;
kd=0;
kp=0;

switch metodo
    case 'cohen'
        switch tipo
            case 'P'
                kp=(1.03/K)*(tau/theta+0.340);
            case 'PI'
                kp=(0.9/K)*(tau/theta+0.092);
                Ti=3.33*theta*(tau+0.092*theta)/(tau+2.22*theta);
                ki=1/Ti;
            case 'PID'
                kp=(1.35/K)*(tau/theta+0.185);
                Ti=2.5*theta*(tau+0.185*theta)/(tau+0.611*theta);
                kd=0.37*theta*tau/(tau+.185*theta);
                ki=1/Ti;
            otherwise
                kp=[];
        end;
                
    case 'chr20' % 20% de sobre sinal - problema servo
         switch tipo
            case 'P'
                kp=0.7/a;
            case 'PI'
                kp=0.6/a;
                Ti=tau;
                ki=1/Ti;
            case 'PID'
                kp=0.95/a;
                Ti=1.357*tau;
                kd=0.473*theta;
                ki=1/Ti;
            otherwise
                kp=[];
        end;
    case 'chr' % Sem sobresinal - problema servo
         switch tipo
            case 'P'
                kp=0.3/a;
            case 'PI'
                kp=0.35/a;
                Ti=1.16*tau;
                ki=1/Ti;
            case 'PID'
                kp=0.6/a;
                Ti=tau;
                kd=theta/2;
                ki=1/Ti;
            otherwise
                kp=[];
        end;
    case 'zie'
         switch tipo
            case 'P'
                 kp=1/a;
            case 'PI'
                kp=0.9/a;
                Ti=3.33*theta;
                ki=1/Ti;
            case 'PID'
                 kp=1.2/a;
                 Ti=2*theta;
                 kd=theta/2;
                 ki=1/Ti;
            otherwise
                kp=[];
        end;
    case 'lam'
         switch tipo
            case 'PI'
                 kp=(2*tau+theta)/(K*2*lambda);
                 Ti=tau+theta/2;
                 ki=1/Ti;
            case 'PID'
                kp=(2*tau+theta)/(K*(2*lambda+theta));
                Ti=tau+theta/2;
                kd=(tau*theta)/(2*tau+theta);
                ki=1/Ti;
        
            otherwise
                kp=[]; % Não foi escolhido P, PI ou PID
        end;
    case 'iae'
    t=tau/theta;        
         switch tipo
            case 'PI'
                kp=(0.7589/K)*(t^0.861);
                Ti=tau/(1.02-0.323/t);
                ki=1/Ti;
            case 'PID'
                 kp=(1.086/K)*(t^0.869);
                 Ti=tau/(0.74-0.130/t);
                 kd=0.348*tau*(t^0.914);
                 ki=1/Ti;
            otherwise
                kp=[];
        end;
    case 'ordem2'
        g2=G;
        [~,z,w]=damp(g2);
        zeta=min(z);
        w=prod(w);
        K=freqresp(g2,0);
        if zeta<1
            den=g2.Denominator{1}/g2.Denominator{1}(3);
            tau=sqrt(den(1));
            kp=(2*zeta*tau)/(K*lambda);
            Ti=2*zeta*tau;
            kd=tau/(2*zeta);
            ki=1/Ti;
        else
            tau=-1./pole(g2);
            kp=(sum(tau))/(K*lambda);
            Ti=sum(tau);
            kd=prod(tau)/sum(tau);
            ki=1/Ti;
        end
        p=pole(g2);
        K=G.num{1}(3);
        den=G.den{1};
        K=K/den(3);
        den=den/den(3);
        tau=sqrt(den(1));
        zeta=den(2)/(2*tau);
        kp=(2*zeta*tau)/(K*lambda);
        Ti=2*zeta*tau;
        kd=tau/(2*zeta);
        ki=1/Ti;
     
    otherwise
        ki=[]; % Metodo de projeto não reconhecido
end;
if isempty(kp) % Não foi escolhido P, PI ou PID
    disp('Definir tipo: P, PI, ou PID');
    C=[];
elseif isempty(ki) % Não foi escolhido um dos métodos
    disp('Metodo não reconhecido');
    C=[];
else
    C=pid(kp,kp*ki,kp*kd);
end;

% C.Tf=1/50;

if (nargout==0)&(not(isempty(C)))
    step(feedback(G*C,1));
    title('Simulação ao degrau','Fontsize',14);
    xlabel('Tempo(s)','Fontsize',14);
elseif not(isempty(C))
    [y,t]=step(feedback(G*C,1));
    iae=trapz(t,abs(1-y)); % Calcula IAE via meetodo do trapézio
else 
    iae=[];
end;
end

