#include "mycommon.h"
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include <time.h>

puerta la_puerta;
volatile int counter = 0; 
int loops;

clock_t tiempo_inicio, tiempo_final;
double segundos;

void *worker(void *arg) {
    int i;
     tiempo_inicio = clock();
     
    for (i = 0; i < loops; i++) {
		cerrar_puerta(la_puerta);
        counter++;
        abrir_puerta(la_puerta);   
    }
    
    tiempo_final = clock();
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) { 
	fprintf(stderr, "usage: threads <loops>\n"); 
	exit(1); 
    }
    crear_puerta(la_puerta);
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);
    Pthread_create(&p1, NULL, worker, NULL); 
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("Final value   : %d\n", counter);
    segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC;
    printf("%f \n",segundos); 
    destruir_puerta(la_puerta);
    return 0;
}
