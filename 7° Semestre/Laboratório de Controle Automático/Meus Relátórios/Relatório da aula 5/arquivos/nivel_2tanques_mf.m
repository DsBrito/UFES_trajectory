function dh = nivel_2tanques_mf(t,h,a1,a2,q,Ref,Kp,Ki)
g=981;
A=pi*12.5^2;
erro=Ref-h(1);

du=erro;
u=q + Kp*erro + Ki*h(3); % Controlador PI

dh1=-(a1/A)*sqrt(2*g*h(1))+(a2/A)*sqrt(2*g*h(2));
dh2=-(a2/A)*sqrt(2*g*h(2))+(100/6)*u/A;
dh=[dh1;dh2;du];
end

