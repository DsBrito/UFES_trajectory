/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"PROFESSOR.h"

struct professor{
    int siape;
    char* nome;
    float salario;
};


tProfessor* IniciaProfessor(int siape,char* nome, float salario){

    tProfessor* Novo;
    
    Novo= (tProfessor*)malloc(sizeof(tProfessor));
    
    Novo->nome=strdup(nome);
    Novo->salario=salario;
    Novo->siape=siape;


    return Novo;
};


void ImprimeProfessor(tProfessor* p){
    printf("\nsiape: %d, nome: %s, salario %.2f",p->siape, p->nome, p->salario);

};

int RetornaSiape (tProfessor* p){
    return p->siape;
};

char* RetornaNomeProfessor (tProfessor* p){
    return p->nome;
};

float RetornaSalario (tProfessor* p){
    return p->salario;
};

void DestroiProfessor (tProfessor* p){
    free(p->nome);
    free(p);

};