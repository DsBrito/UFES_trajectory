

disp("\n1 - Resolver o problema 1.")
disp("\n2 - Resolver o problema 2.")
disp("\n3 - Resolver o problema 3.")
disp("\n4 - Sair.")
  
x= input ("\nEscolha:");    

switch x
  case 1
    disp("1 - Resolver o problema 1 (validacao).")
    x0=input ("\nInsira o x0: "); 
    x1=input ("\nInsira o x1: "); 
    tol=input("\nInsira o tol: "); 
    NumMaxIte=input("\nInsira o NumMaxIte: ");
    Q4Secante( x0 ,x1, tol, NumMaxIte)
    
    
 %%substituindo a raiz encontrada pela função, na equação é possivel obter um valor aproximado de 25m².
  case 2
    disp("2 - Resolver o problema 2 (do tanque esferico)")
    x0=input ("\nInsira o x0: "); 
    x1=input ("\nInsira o x1: "); 
    tol=input("\nInsira o tol: "); 
    NumMaxIte=input("\nInsira o NumMaxIte: ");
    Q4SecanteTanque( x0 ,x1, tol, NumMaxIte)
    

  case 3
    disp("\n\n3 - Resolver o problema 3 (um exemplo qualquer escolhido pelo aluno).")
    x0=input ("\nInsira o x0: "); 
    x1=input ("\nInsira o x1: "); 
    tol=input("\nInsira o tol: "); 
    NumMaxIte=input("\nInsira o NumMaxIte: ");
    Q4SecanteAluno( x0 ,x1, tol, NumMaxIte); 
    
    
  case 4
    disp("sair")
    return
    
  otherwise
    disp("\n O valor esta fora do intervalo! ")

 
 
endswitch



 

   
   