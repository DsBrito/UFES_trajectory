float hello_world (char* name, int age){
    int i = 3;
    if (i == 3)
    {
      char a;
      i = -3;
    }
    printf("My name is %s, I'm %d years old, Hello World!\n", name, age);
    return 0;
}

int main(void) {
    float x = (12 + 5 * (12-2));
    int y;
    char nome[20];
    y = 0;
    nome[2] = 2;
    scanf ("%s", nome);
    x = hello_world(nome, y);
    return 1;
}
