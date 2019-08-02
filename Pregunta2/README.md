# Pregunta2

para compilar: 

```sh 
gcc threads.c -o thread -lpthread
``` 

para ejecutar:

```sh 
./thread 
``` 

Se utilizó la puerta:
```sh 
puerta la_puerta;
``` 
para la ejecucion eficiente de los threads dentro del programa. 

Se implementaron las puertas en las funciones hilo1 y hilo2 donde se pedia

>El hilo 1 ejecutará la función sleep(2), luego hará la operación de división z/y  y guardará el resultado en la variable v.

```sh 
void *hilo1() {
    float y = 350;
    float z = 25;

    cerrar_puerta(la_puerta);
    sleep(2);
    v=z/y;
    abrir_puerta(la_puerta);
    
}
``` 
>El hilo 2 llevará a cabo la operación de x*v y guardará el resultado en v.

```sh 
void *hilo2() {
    float x=1250;
    
    cerrar_puerta(la_puerta);
    v=x*v;
    abrir_puerta(la_puerta);
    
}
``` 
Al final, ya que nos da un valor no entero, se imprime redondeandolo a 4 cifras con la instrucción:
```sh 
printf("V final   : %.4f\n", v);
``` 
y nos da el resultado 89.2857

como se evidencia en la siguiente imagen:

[Resultado](evidencia1.png)
