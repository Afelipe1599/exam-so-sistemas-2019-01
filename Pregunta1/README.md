# Pregunta1

para compilar 
```sh 
gcc threads.c -o thread -lpthread
``` 

para ejecutar

```sh 
./thread <valor>
``` 

Se utilizo el include 
```sh 
#include <time.h> 
``` 
Para obtener las funciones de 
```sh 
clock_t
```  
Cuando se ejecuto 5 veces el programa con 

>Cerrar la puerta antes del ciclo for donde se incrementa la variable compartida y abrir la puerta una vez finalizado este ciclo for.

se observaron los siguientes tiempos 

[Evidencia1](Captura de pantalla -2019-08-02 11-36-05.png)


Cuando se ejecuto 5 veces el programa con 

>Ubicado dentro del ciclo for, cerrar la puerta justo antes de incrementar la variable compartida y abrir la puerta justo después de haberla incrementado.

se observaron los siguientes tiempos

[Evidencia2](Captura de pantalla -2019-08-02 11-42-10.png)

El incremento de los tiempos es dado ya que cuando se instala la puerta dentro del ciclo for, este procedimiento tiene que esperar a que el ciclo for se complete para terminar por eso se demora su ejecucion.
