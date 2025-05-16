% function [x,y] = upts_no_lr(xmin,UP, ts)
% UP:sobreelevacao entre 1 e 100%
% ts: tempo em segundos
% xmin: valor mínimo da parte real no LR
%
function [x,y] = upts_no_lr(xmin,UP, ts)
if nargin==2
    ts=[];
end
if UP<1
    beep
    x=[];
    y=[];
    return
end
x=linspace(xmin,0,100);
a=log(UP/100);
zeta=sqrt(a^2/(pi^2+a^2));
teta=acos(zeta);
f=tan(teta);
y=x*f;
if nargout==0
    plot(x,y,'m','LineWidth',3);
    plot(x,-y,'m','LineWidth',3);
    if (~isempty(ts))
        zetawm=-4/ts;
        line(zetawm*[1;1],[xmin;-xmin],'Color','g','LineWidth',3);
    end
end
end

