A = [0 1 0; 0 0 1; -2 -2 -4];
B = [0; 0 ; 1];
C = [1 0 0];
D =[0];

[num,den]=ss2tf(A,B,C,D,1);

step(num,den);
grid