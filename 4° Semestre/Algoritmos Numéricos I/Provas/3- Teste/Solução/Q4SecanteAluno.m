function fx=Q4SecanteAluno(x0,x1,tol,NumMaxIte)

qteIter=1;
erro=1; 

% processo iterativo;

while (erro > tol) && ( qteIter <= NumMaxIte)   
     
   
   fx0=5*exp(-x0)-sqrt(x0);
   fx1=5*exp(-x1)-sqrt(x1);
   x2=(x0*fx1 - x1*fx0)/(fx1-fx0);
   
   
   erro= abs((x2-x1)/x2);
     
     
     
   if erro >tol
     x0=x1;
     x1=x2;
     
     
   endif
   qteIter=qteIter+1;
 end
disp("raiz"),disp(x2)
disp("Numero de interacoes"),disp(qteIter)

endfunction