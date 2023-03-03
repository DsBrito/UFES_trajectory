#include <stdio.h>

void hello_word (char* name, int age){
    int i = 3;
    if (i == 3)
    {
      i = -3;
      char a;
    }
    printf("My name is %s, I'm %d years old, Hello World!\n", name, i);
}

int main() {
  char c;
  
  printf("Insira qualquer letra para escutar a mensagem ou 0 para se despedir: ");
  scanf("%c", &c);
  
  if (c != '0'){
    int i = 0;
    c = '2';
    if (c == '2')
      i = -3;
    printf("MENSAGEM");
  } else {
    printf("Ate mais e obrigado pelos peixes.");
  }

  return 0;
}
