function dh = nivel_2tanques(t,h,a1,a2,q)
g=981;
A=pi*12.5^2;
dh1=-(a1/A)*sqrt(2*g*h(1))+(a2/A)*sqrt(2*g*h(2));
dh2=-(a2/A)*sqrt(2*g*h(2))+(100/6)*q/A;
dh=[dh1;dh2];
end

