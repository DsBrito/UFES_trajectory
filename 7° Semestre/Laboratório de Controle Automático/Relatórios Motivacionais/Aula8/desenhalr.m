function []=desenhalr(c,g2,ts)
a0=-3.85/ts;
zeta=0.78; % (UP=2% )
f1=tan(acos(zeta));
x=linspace(min(pole(g2)),0,100);
y=x*f1;
rlocus(c*g2);hold on
%xline(a0,'Color','c','LineWidth',3);
line([a0 a0],[-10 10], 'Color','c','LineWidth',3); %Matlab 2016, etc
plot(x,y, 'Color','c','LineWidth',3)
plot(x,-y, 'Color','c','LineWidth',3)
m=feedback(c*g2,1);
plot(pole(m),'*');
hold off
title('LR com restrições');
end