/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   progZoo.c
 * Author: diona
 *
 * Created on 21 de Março de 2021, 10:34
 */

#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>
#include "listaZooDPL.h"

int main()
{
    // criando a lista vazia
	TipoListaDPL *lista;
        lista= IniciaLista();
        int id;

	// criando alguns animais apenas para testar
        
         TipoZoo*  Tubarao_tigre  = InicializaAnimal("Tubarao_tigre","peixes", "macho",1);
	 TipoZoo* gaviao_carijo = InicializaAnimal("gaviao_carijo","aves", "macho",2);
	 TipoZoo* Macaco_sem_nariz = InicializaAnimal("Macaco_sem_nariz","primata","macho",3);
         
         
         TipoZoo* Dragao_de_komodo   = InicializaAnimal("Dragao_de_komodo","reptil", "femea",4);
	 TipoZoo* Polvo_dumbo  = InicializaAnimal("Polvo_dumbo", "molusco","femea",5);
	 TipoZoo* Arara_azul  = InicializaAnimal("Arara_azul","aves", "femea",6);
         
       
         
         
	

	 //Insere os animais na lista
	 lista = InsereLista( lista,Tubarao_tigre);
	 lista = InsereLista(lista,gaviao_carijo);
	 lista = InsereLista(lista,Macaco_sem_nariz);
         
	 lista = InsereLista(lista,Dragao_de_komodo);
	 lista = InsereLista(lista,Polvo_dumbo);
         lista = InsereLista(lista,Arara_azul);
         
	 


	 //Imprime a lista com todos os animais do zoologico
         printf("\n-Animais presentes no Zoologico:\n");
	 ImprimeLista(lista);
         
         printf("\n-Animal a ser retirado:\n");
         printf("Insira o id correspondente:");
         scanf("%d",&id);
         
	 lista = RetiraLista(lista,id);      
         printf("\nLista atualizada dos animais do zoologico:\n");
	 ImprimeLista(lista);

         DestroiLista (lista);
         
         return 0;

}

