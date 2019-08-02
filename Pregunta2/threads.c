#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"

volatile int counter = 0; 
puerta la_puerta;
float v;


void *hilo1() {
    float y = 350;
    float z = 25;
 
    cerrar_puerta(la_puerta);
    sleep(2);
    v=z/y;
    abrir_puerta(la_puerta);
    
}

void *hilo2() {
    float x=1250;
    
    cerrar_puerta(la_puerta);
    v=x*v;
    abrir_puerta(la_puerta);
    
}

int main(int argc, char *argv[]) {
	
	crear_puerta(la_puerta);
    pthread_t p1, p2;
    Pthread_create(&p1, NULL, hilo1, NULL); 
    Pthread_create(&p2, NULL, hilo2, NULL);
    printf("V inicial : %.4f\n", v);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("V final   : %.4f\n", v);
    destruir_puerta(la_puerta);

    return 0;
}
