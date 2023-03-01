clear all
syms z

exp1 = 0.33/(z-1);
exp2 = ( (0.29+0.17i)*(1-z^(-1) ) ) / (1 - (0.6428 + 0.368i)*z^(-1) );
exp3 = ( (0.29-0.17i)*(1-z^(-1) ) ) / (1 - (0.6428- 0.368)*z^(-1) );


Gz = -0.57666+exp1+exp2+exp3;

y=simplify(Gz)
Gsaida=vpa(y)

%Gs()=num/dem
%resposta final:
% k* num / den + k* num

