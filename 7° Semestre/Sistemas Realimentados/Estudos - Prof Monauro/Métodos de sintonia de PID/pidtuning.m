% function [C, iae, c, P ] = pidtuning(varargin)
% Date: 17/6/2023   prof. Celso J. Munaro (DEE-CT-UFES)
% 
% Inputs:
% G: model obtained via tf commad: foptd, first ordem, second order (real or complex poles)
% Models, methods, types
% ----------------------------------------------------------------
% |  Model G | Methods             | Types    | Parameters       |
% |--------------------------------------------------------------|
% |  foptd   | zie,chr,chr20,cohen | P,PI,PID |     -            |
% |  foptd   | iaeot               | PI, PID  |     -            |
% |  foptd   | lambda              | PI, PID  |  lambda          |
% |  order 1 | lambda              | PI       |  lambda          |
% |  order 1 | polealoc            | PI       |  UP,ts           |
% |  order 2 | lambda              | PID      |  lambda          |
% |  order 2 | polealoc            | PI       |  UP,ts           |
% |--------------------------------------------------------------|
% 
% Parameters:
% lambda : for lambda tuning
% UP, ts : for pole allocation
% 
% Outputs:
% C = pid controller (C=pid(kp,kp*ki,kp*kd))
% iae = integral of absolute error
% 
% Examples:
%  [C, iae]=pidtuning(g1,'method','lambda','type','PID','param',1)
%  [C, iae]=pidtuning(g1,'method','polealoc','type','PID','param',[UP ts]) 
%  [C, iae]=pidtuning(g1,'method','zie','type','PI')
% 
%  Only two input parameters: assume lambda tuning:
%  Example: pidtuning(g1,0.5) % g1=tf with lambda=0.5
%
function [ C, iae, c, P ] = pidtuning(varargin)
C=[];
iae=[];

check = (varargin);
if length(varargin)==1
    disp('Insufficient number of input arguments');beep;return;
    
elseif length(varargin)==2 % G1 ou G2 with lambda without delay
    G=check(1);
    G=G{1};
    npoles=length(pole(G));
    lambda=check(2);
    lambda=lambda{1};
    method='lambda';
    if (npoles==2)&(G.InputDelay>0)
        disp('Order 2 TF with delay is not supported');beep;return;
    end
    if npoles==1
        tipo='PI';
        if G.InputDelay>0
            Model=1; % FOPTD
        else
            Model=2; % First order without delay
        end
        
    elseif npoles==2
        tipo='PID';
        [~,z,w]=damp(G);
        zeta=min(z);
        if zeta<1Model=3; % order 2: complex poles
        else
            Model=4; % order 2: real poles
        end
    else
        disp('The TF for lambda tuning must be order 1 or 2');beep;return;
    end
    
else
    %detect_g = find(strcmp(check, 'G'));
    G=check(1);
    G=G{1};
    detect_method = find(strcmp(check, 'method'));
    detect_type = find(strcmp(check, 'type'));
    detect_lambda = find(strcmp(check, 'lambda'));
%    if isempty(detect_g)
%        disp('Provide the transfer function');beep;return;
%    elseif isempty(detect_method)
    if isempty(detect_method)
        disp('Provide method:zie,chr,chr20,cohen, iaeot, lambda,polealoc');beep;return;
    elseif isempty(detect_type)
        disp('Provide controller type: P,PI,PID');beep;return;
    end
    
    if length(varargin)<5
        disp('Provide model, method, type and their parameters');beep; return
    end
    
    if ~isempty(detect_lambda)
        detect_param = find(strcmp(check, 'param'));
        if (isempty(detect_param))|(length(varargin)<7)
            disp('Provide lambda and its values');beep;return;
        else
            lambda=check(detect_param+1);
            lambda=lambda{1};
        end
    end
    
%     G=check(detect_g+1);
%     G=G{1};
    
    method=check(detect_method+1);
    method=method{1};
    
    tipo=check(detect_type+1);
    tipo=tipo{1};
    
    npoles=length(pole(G));
    if (G.InputDelay>0)&(npoles==1)
        Model=1;
    end
    if (G.InputDelay==0)&(npoles==1)
        Model=2;
    end
    if (G.InputDelay==0)&(npoles==2)
        [~,z,w]=damp(G);
        zeta=min(z);
        if (zeta<1) Model=3; % complex poles
        else
            Model=4;  % real poles
        end
    end
    if (G.InputDelay>0)&(npoles==2)
        disp('Order 2 TF cannot have time delay');beep; return
    end
    
end

kp=[];ki=0;kd=0;

switch Model
    case 1    %foptd
        K=freqresp(G,0);
        tau=1/abs(pole(G));
        theta=G.InputDelay;
        a=K*theta/tau;
        switch method
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
                
            case 'chr20' % 20% overshoot - servo problem
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
            case 'chr' % No overshoot - servo problem
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
            case 'lambda'            
                switch tipo
                    case 'P'
                        kp=[];
                        disp('Lambda tuning allows  PI or PID');
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
                        kp=[]; %P, PI or PID was not selected
                end;
            case 'iaeot'
                t=tau/theta;
                switch tipo
                    case 'P'
                        kp=[];
                        disp('IAE method allows PI or PID');
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
            case 'polealoc'
                    disp('Pole allocation is not implemented for FOPTD');beep;
                    kp=[];
            otherwise
                    disp('Select of the methods:zie,chr,chr20,cohen, iaeot');beep;
                             
                
        end % switch method
        
    case 2    %switch Model: ordem 1
        switch method;
            case 'lambda'
            K=freqresp(G,0);
            tau=1/abs(pole(G));
                switch tipo
                    case 'P'
                        kp=[];
                        disp('Lambda method for order 1 works only with PI');
                    case 'PI'
                        kp=tau/(K*lambda);
                        ki=1/tau;
                    case 'PID'
                        kp=[];
                        disp('Lambda method for order 1 works only with PI');
                end
            case 'polealoc'
                    K=freqresp(G,0);
                   tau=1/abs(pole(G));
                if strcmp(tipo,'PI')
                    detect_param = find(strcmp(check, 'param'));
                    if (isempty(detect_param))|(length(varargin)<7)
                        disp('Provide lambda and its values');beep;return;
                    else
                        lambda=check(detect_param+1);
                        lambda=lambda{1};
                        if length(lambda)<2
                             disp('Provide lambda =[ UP ts]');beep;return;
                        end
                    end
                    UP=lambda(1);
                    a=log(UP/100);
                    zeta=sqrt(a^2/(pi^2+a^2));
                    ts=lambda(2);
                    wo=4/(ts*zeta);
                    kp=(2*zeta*wo*tau-1)/K;
                    ki=(wo*K)/(2*zeta*wo*tau-1);
                else
                    disp('Pole allocation for order 1 works only with PI');
                    kp=[];
                end
                
        end
        
        
    case 3    % switch Model: order 2 complex poles
        if strcmp(method,'lambda')
            [~,z,w]=damp(G);
            zeta=min(z);
            w=prod(w);
            K=freqresp(G,0);
            if strcmp(tipo,'PID')
                den=G.Denominator{1}/G.Denominator{1}(3);
                tau=sqrt(den(1));
                kp=(2*zeta*tau)/(K*lambda);
                Ti=2*zeta*tau;
                kd=tau/(2*zeta);
                ki=1/Ti;
            else
                kp=[];
                disp('Lambda method for order 2 works only with PID');
            end
        else
            disp('2nd-order model with complex poles: use lambda method only');beep;
            kp=[];
        end
        
    case 4    % switch Model: ordem 2 polos reais
        switch method
            case 'lambda'
                if strcmp(tipo,'PID')
                    K=freqresp(G,0);
                    tau=-1./pole(G);
                    kp=(sum(tau))/(K*lambda);
                    Ti=sum(tau);
                    kd=prod(tau)/sum(tau);
                    ki=1/Ti;
                else
                    kp=[];
                    disp('Order 2 lambda method works only with PID');
                end
            case 'polealoc'
                if strcmp(tipo,'PI')
                    detect_param = find(strcmp(check, 'param'));
                    if (isempty(detect_param))|(length(varargin)<7)
                        disp('Provide lambda and its values');beep;return;
                    else
                        lambda=check(detect_param+1);
                        lambda=lambda{1};
                        if length(lambda)<2
                             disp('Provide lambda =[ UP ts]');beep;return;
                        end
                    end
                    UP=lambda(1);
                    a=log(UP/100);
                    zeta=sqrt(a^2/(pi^2+a^2));
                    ts=lambda(2);
                    [kp,ki]=polealoc2(G,UP,ts);
                else
                    disp('Pole allocation for order 2 model works only with PI');
                    kp=[];
                end
        end
end  % end switch tipo

%end % end switch model

[y,t]=step(G);
T=max(t)/100; % Obtendo um tempo de amostragem T para discretizar

if isempty(kd)|(kd==0)
    cpi=true;
else
    cpi=false;
end

if isempty(kp) % 
else
    if cpi
        C=pid(kp,kp*ki);
        c=tf(kp*[1 ki],[1 0]);
        Cd=c2d(c,T);
    else
        C=pid(kp,kp*ki,kp*kd);
        c=tf([kp*kd kp kp*ki],[1 0]);
        Cd=tf(kp*[1+kd/T T*ki-1-2*kd/T kd/T],[1 -1 0],T);
    end
    Gd=c2d(G,T);
    My=feedback(Cd*Gd,1);
    Mu=feedback(Cd,Gd);
    [y,t]=step(My);
    u=step(My,t);
    iae=trapz(t,abs(1-y)); % Computes IAE
    cefort=sum(abs(diff(u)));
    S=stepinfo(My);
    P.iae=iae;
    P.cef=cefort;
    P.UP=S.Overshoot;
    P.ts=S.SettlingTime;
end;


if (nargout==0)&(not(isempty(C)))
    if (G.InputDelay>0)&(kd>0)
        G=pade(G);
    end
    M=feedback(G*C,1);
    step(M);
    S=stepinfo(M);
    ss=sprintf('Step response: UP = %3.2f  ts = %3.2f',S.Overshoot, S.SettlingTime);
    title(ss);shg
end;
end


function [kp,ki,C,erro, ts_i]=polealoc2(G,UP,ts)
% Pole allocation for second order TF with real poles
t12=1./abs(pole(G));
K=freqresp(G,0);
a=log(UP/100);
zeta=sqrt(a^2/(pi^2+a^2));
wn=4/(zeta*ts);
g0=tf(wn^2,[1 2*zeta*wn wn^2]); % Mref
[y0,t0]=step(g0);
a=linspace(0.1,5,50); % Works?
for i=1:length(a)
    w0=sum(t12)/(prod(t12)*(a(i)+2*zeta));
    kp=((1+2*a(i)*zeta)*prod(t12)*w0^2-1)/K;
    ki=prod(t12)*a(i)*w0^3/(K*kp);
    C=pid(kp,kp*ki);
    M=feedback(G*C,1);
    y1=step(M,t0);
    erro(i)=norm(y1-y0);
    S=stepinfo(M);
    ts_i(i)=S.SettlingTime; 
end;
[~,i]=min(erro);
a=a(i);
w0=sum(t12)/(prod(t12)*(a+2*zeta));
kp=((1+2*a*zeta)*prod(t12)*w0^2-1)/K;
ki=prod(t12)*a*w0^3/(K*kp);
C=pid(kp,kp*ki);
M=feedback(C*G,1);
S=stepinfo(M);
%den=[1 1/t12(1)+1/t12(2) (1+K*kp)/prod(t12) (K*kp*ki)/prod(t12)];
if nargout==0
    M=feedback(G*C,1);
    S=stepinfo(M);
    ss=sprintf('Step response: UP=%3.0f  ts=%3.2f',S.Overshoot,S.SettlingTime);
    step(g0,M);title(ss);
    legend('Mref','MF');shg
end
end




