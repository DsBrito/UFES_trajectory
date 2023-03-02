function [k,m] = init(turma,I)
fl=0;
if (turma<0)|(turma>4)
    fl=1;
end
if (I<0)|(I>12)
    fl=1;
end
if fl==1
    k=[];m=[];
    return;
end
z1=1:12;
z2=2:2:24;
Z=[11  2  5  8  1  6  3  4  7 12  9 10
    4 12 11  8  2  7  5  1  9  6  3 10
    12  1  5  9 11 10  2  4  3  7  8  6
    9 10  6  8  1  2  3  5  4  7 11 12];
i=Z(turma,I);
k=z1(i);
m=z2(i);
end

