function [wn,pwm] = init(I,turma)
M=[
     5  8 12  1  7  3  4  11 2 6  10  9
     7  4 11  8 12  9  3  2  5 1  6  10
     6  7  5  3  9  2  8 12  4 10 11  1
     8 11  6  7  4  3 12  10 9  5  1  2
     4  6  10  9 3  11 2  1  7  8  5 12];
 wn=M(turma,I);
 pwm=20+10*M(turma,I);
end

