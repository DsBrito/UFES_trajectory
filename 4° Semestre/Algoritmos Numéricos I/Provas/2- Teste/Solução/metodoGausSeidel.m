function [x]=metodoGausSeidel(A,b,x,tol,NumMax)

clc
 n=length(x);
  
  for k=1:NumMax
      w=x;   
      for i=1:n
        
        s=A(i,1:i-1)*x(1:i-1)+A(i,i+1:n)*x(i+1:n);
        x(i)=(b(i)-s)/A(i,i);
      end
      
    if norm(x-w,inf)<tol
        return
      endif   
      
      fprintf('\n a solucao do sistema na interacao %4.0f\n',k)
      
      for i=1:n
        fprintf('\n         x(%1.0f)=%6.8f\n',i,x(i))
        
      end 
      
      
     
  end
        




endfunction