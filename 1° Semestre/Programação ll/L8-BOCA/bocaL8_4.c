#include <stdio.h>

int main(){
int n1,n2,n3;

    scanf("%d%d%d", &n1,&n2,&n3);

    if(n1>99 && n1<999999){ //condicoes para o numero ter a casa das centenas
    n1=n1/100;
}   else{ n1=0; 
}
     if(n2>99 && n2<999999){//condicoes para o numero ter a casa das centenas
     n2=n2/100;
}   else{ n2=0; 
}
     if(n3>99 && n3<999999){//condicoes para o numero ter a casa das centenas
     n3=n3/100;
}   else{ n3=0; 
}
    if(n1%10<=n2%10 && n2%10<=n3%10){ //se essas duas condicoes forem verdadeira o programa avaliara todas as outras condicoes dentro desse if
    if(n1){
    printf("N1");
} else if(n2){
    printf("N2");
} else if(n3){
    printf("N3");
}else{
    printf("Nenhum");
}
}

else if(n1%10<=n3%10 && n3%10<=n2%10){ //se essas duas condicoes forem verdadeira o programa avaliara todas as outras condicoes dentro desse if
    if(n1){
    printf("N1");
} else if(n3){
    printf("N3");
} else if(n2){
    printf("N2");
}else{
    printf("Nenhum");
}
}

else if(n2%10<=n1%10 && n1%10<=n3%10){ //se essas duas condicoes forem verdadeira o programa avaliara todas as outras condicoes dentro desse if
    if(n2){
    printf("N2");
} else if(n1){
    printf("N1");
} else if(n3){
    printf("N3");
}else{
    printf("Nenhum");
}
}

else if(n2%10<=n3%10 && n3%10<=n1%10){ //se essas duas condicoes forem verdadeira o programa avaliara todas as outras condicoes dentro desse if
    if(n2){
    printf("N2");
} else if(n3){
    printf("N3");
} else if(n1){
    printf("N1");
}else{
    printf("Nenhum");
}
}

else if(n3%10<=n1%10 && n1%10<=n2%10){ //se essas duas condicoes forem verdadeira o programa avaliara todas as outras condicoes dentro desse if
    if(n3){
    printf("N3");
} else if(n1){
    printf("N1");
} else if(n2){
    printf("N2");
} else{
    printf("Nenhum");
}
}

else if(n3%10<=n2%10 && n2%10<=n1%10){ //se essas duas condicoes forem verdadeira o programa avaliara todas as outras condicoes dentro desse if
    if(n3){
    printf("N3");
} else if(n2){
    printf("N2");
} else if(n1){
    printf("N1");
} else{
    printf("Nenhum");
}
}
return 0;
}
    
