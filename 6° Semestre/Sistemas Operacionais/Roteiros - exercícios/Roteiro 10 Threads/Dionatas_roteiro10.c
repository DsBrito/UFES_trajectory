

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //biblioteca PTHREADS
#include <unistd.h>
#include <stdbool.h>

#define TAM 500

pthread_mutex_t mutex;
bool terminou = false;
int buffer[TAM];    //array int buffer[500]


void* routine(void* args) {
	int id = *(int*)args;
	int qtdId = 0;

//~Problema dessa minha implementação -> todos os 500 componentes  de buffer estão com zero, logo vai inserir TAM vezes o id do primeiro Thread.

	for (int i = 0; i < TAM; i++){  //preencher cada posição x do array com seu identificador. 
		if (buffer[i] == 0){		//achar uma posição que ainda não tenha sido preenchida, se o buffer for igual a 0, quer dizer que nada foi escrito nele, entao é inserido os Ids.
			buffer[i]=id;		
			qtdId ++;   			//quantidade de id's que ela conseguiu inserir no buffer[]
		}
		else
			continue
	}
	pthread_mutex_lock(&mutex);
	if (!terminou) {
		*(int*)args = qtdId;
		terminou = true;
	} else {
		*(int*)args = -1;
	}
	pthread_mutex_unlock(&mutex);

	return args;
}


int main(int argc, char** argv) {
	pthread_mutex_init(&mutex, NULL);

	//inicializado com valores 0 (zero)
	for (int i = 0; i < TAM; i++)
		buffer[i] = 0;
	
	//São criadas 5 threads 
	//Para cada thread, é passado como parâmetro na função de execução da thread um valor "int id" diferente (um identificador de 1 a 5)
	pthread_t th[5];
	for (int i = 0; i < 5; i++) {
		int* id = malloc(sizeof(int));
		*id= i+1;
		if (pthread_create(&th[i], NULL, &routine, id) != 0) return i+1;  // Cada thread deverá, de forma concorrente, varrer o array tentando preencher cada posição x do array com seu identificador.
	}

	//Aguarda finalização de todas as threads
	for (int i = 0; i < 5; i++) {
		int* r;
		if (pthread_join(th[i], (void**) &r) != 0) return 11;
		//confere o retorno da thread e imprime mensagem se este for diferente de -1
		if (*r != -1) 
			printf("Thread %d vencedora  que conseguiu inserir um total de %d id's no buffer[].\n", i, *r); //deve imprimir uma mensagem identificando quem foi a thread vencedora (i.e. aquela que conseguiu inserir mais id's no buffer[]).
		
		free(r);
	}

	pthread_mutex_destroy(&mutex);
	
	return 0;
}