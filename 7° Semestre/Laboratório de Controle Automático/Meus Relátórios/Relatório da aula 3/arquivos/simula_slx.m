function [Y,t] = simula_slx(Tempo)
   out=sim('Nivel_R1_R2_2018.slx',Tempo); 
    Y=out.X(:,[ 2 3 4]);
    t=out.tout;
end

