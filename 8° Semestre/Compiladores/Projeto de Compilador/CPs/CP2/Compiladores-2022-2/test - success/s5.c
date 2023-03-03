#include <stdio.h>

int main() {
  char c;
  
  printf("Insira qualquer letra para escutar a mensagem ou 0 para se despedir: ");
  scanf("%c", &c);
  
  if (c != '0'){
    printf("MENSAGEM");
  } else {
    printf("Ate mais e obrigado pelos peixes.");
  }
  
  return 0;
}
