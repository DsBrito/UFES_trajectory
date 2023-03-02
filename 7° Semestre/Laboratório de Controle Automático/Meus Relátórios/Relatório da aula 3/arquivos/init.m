function [h10,h20,q,a1,a2]=init(turma,I)

if (turma<0)|(turma>4)
    disp('Turma entre 1 e 4');
    return;
end

if (I<0)|(I>12)
    disp('I entre 1 e 12');
    return;
end

Q=40:2:62;
H10=40:2:62;
H20=60:-2:38;
Z=[Q;H10;H20];
%size(Z)
P=[10 11  2 3  8  2  4  7 5 12  2 9
 3  6 10  2  6 11 4 12  8  1 7 12
  11 7  6  5  8  3  9  12  4  1  2 10
  9  4 12  1  2  5 10 7  3  6  11  8];
ii=P(turma,I);
q=Z(1,ii);
h10=Z(2,ii);
h20=Z(3,ii);
a1=q*(100/6)./(sqrt(2*981*h10));
a2=q*(100/6)./(sqrt(2*981*h20));

end

