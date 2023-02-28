function x=resolvePenta(A,b)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% pentsolve.m
%
% Código para aa questão  4 do teste 2.
% 
% [x]= resolvePenta(A,b)
%
% IDEIA= refazer a matriz, zerando as colunas a atribuindo elemento por elemento
% da matriz antiga e fazendo os devidos calculos, assim teremos controle em quais 
% posições o calculo irá ocorrer e não iremos ter o problema operar/acessar em 
% elementos nulos 
%
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Checagem de dimensao da matriz e vetor 
[M,N]=size(A);

if M~=N
    error('Erro, a matriz deve ser quadrada!.');
    return; 
end
if length(b)~=M
    error('Erro, a matriz e vetor devem possuir o mesmo numero de linhas!.');
    return;
end

%zerando o vetor X.
    x=zeros(N,1);

    
    Dp=diag(A);                      %pegando o a11 =4
    dC=diag(A,1);                    %pegando o a12 =12
    dD=diag(A,2);                    %pegando o a13 =-15.5
    dB=[0;diag(A,-1)];               %pegando o a21 =-6
    dA=[0;0;diag(A,-2)];             %pegando o a31  =15
     
  
%zerando
    A=zeros(N,1);       %N zeros
    B=zeros(N-1,1);      %N-1 zeros
    C=zeros(N-2,1);      %N-2 zeros
    D=zeros(N,1);        %N zeros
    VetorC=zeros(N,1);  %N zeros
  
           
    % Fatores
    A(1)=Dp(1);              
    B(1)=dC(1)/A(1);         
    C(1)=dD(1)/A(1);  
    
    D(2)=dB(2);                   
    A(2)=Dp(2)-D(2)*B(1);   
    B(2)=( dC(2)-D(2)*C(1) )/A(2);
    C(2)=dD(2)/A(2);                

    
    %loop para o preenchimento dos valores
    for k=3:N-2
     
        D(k)=dB(k)-dA(k)*B(k-2);
        A(k)=Dp(k)-dA(k)*C(k-2)-D(k)*B(k-1);
        B(k)=( dC(k)-D(k)*C(k-1) )/A(k);
        C(k)=dD(k)/A(k);
    end
    
    
    #preenchimento a posição manualmente
    D(N-1)=dB(N-1)-dA(N-1)*B(N-3);
    A(N-1)=Dp(N-1)-dA(N-1)*C(N-3)-D(N-1)*B(N-2);
    B(N-1)=( dC(N-1)-D(N-1)*C(N-2) )/A(N-1);
    D(N)=dB(N)-dA(N)*B(N-2);
    A(N)=Dp(N)-dA(N)*C(N-2)-D(N)*B(N-1);


    %b vetor de entrada
    VetorC(1)=b(1)/A(1);
    VetorC(2)=(b(2)-D(2)*VetorC(1))/A(2);
    
    %preenchemento do vetorC
    for k=3:N
        VetorC(k)=( b(k)-dA(k)*VetorC(k-2)-D(k)*VetorC(k-1) )/A(k);
    end
    
    
    %Colocando os valores que estavam em C no vetor X resultado;
    x(N)=VetorC(N)
    x(N-1)=VetorC(N-1)-B(N-1)*x(N);
    
    for k=N-2:-1:1
        x(k)=VetorC(k)-B(k)*x(k+1)-C(k)*x(k+2);  
    end
   
end %fim da função