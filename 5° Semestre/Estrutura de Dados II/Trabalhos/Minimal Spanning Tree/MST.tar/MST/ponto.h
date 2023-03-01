#ifndef _PONTO_H
#define _PONTO_H


typedef struct ponto tPonto;

tPonto* iniciaPonto(char* nome,int m, double* array, int id);
double distancia(int d,double* vet1, double* vet2);
void imprimePonto(tPonto* p);
int cmpstr(const void* a, const void* b);
void liberaPonto(tPonto* p);
double getTam(tPonto* p);
double* getVet(tPonto* p);
char* getNome(tPonto* p);
int getIDPonto(tPonto* p);


#endif