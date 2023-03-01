#ifndef _SUBCONJUNTO_H
#define _SUBCONJUNTO_H

typedef struct sub tSub;

tSub* criaSubconjunto(int pai, int id);
void liberaSubconjunto(tSub* sub);
int getPai(tSub* s);
int getRank(tSub* s);
int find(tSub** vetSub, int i);
void Union(tSub** vetSub, int x, int y);
#endif