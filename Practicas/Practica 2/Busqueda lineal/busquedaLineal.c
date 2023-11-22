#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../tiempo.h"

int busquedaLineal(int *Arreglo, int tam, int num){
    for (int i = 0; i < tam; i++) {
        if (Arreglo[i] == num) {
            return i;  // Devuelve el índice donde se encontró el elemento
        }
    }
    return -1; //Devuelve -1 si no encontro el elemento
}

// PROGRAMA PRINCIPAL
int main(int argc, char *argv[])
{
    
    // Variables del main
    double utime0, stime0, wtime0, utime1, stime1, wtime1; // Variables para medición de tiempos
    int i; //variables para los ciclos
    int n; //variable para el tamaño del arreglo
    int tam, num, numEncontrado; //Variables para el algoritmo
  
    // Recepción y decodificación de argumentos
    if (argc >= 2)// Si se introducen 2 o mas argumentos, el numero a buscar y el tamaño del arreglo
    {
        n = atoi(argv[1]); //tamaño del arreglo
        if (argc > 2)
        {
            num = atoi(argv[2]); //a la variable num, le asignamos el numero a buscar
        }
        else
        {
           scanf("%d", &num);
        }
    }
    else
    {
        scanf("%d", &n);
        scanf("%d", &num);
    }

    //  Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    uswtime(&utime0, &stime0, &wtime0);
    

    int *Arreglo = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &Arreglo[i]);
    }

    
    // Algoritmo
    tam = n / sizeof(Arreglo[0]);

    numEncontrado = busquedaLineal(Arreglo, tam, num);
     
    
    // Evaluar los tiempos de ejecución
    uswtime(&utime1, &stime1, &wtime1);

    // Cálculo del tiempo de ejecución del programa
    /*printf("-- Tiempos con %d elementos ---\n", n);
    printf("Tiempo real (Tiempo total): %.10f segundos\n", wtime1 - wtime0);
    printf("Tiempo real (Tiempo total): %.10e segundos\n", wtime1 - wtime0);
    printf("\n");


    //Se imprimen los resultados
    if (numEncontrado == -1) {
        printf("El elemento %d no se encuentra en el arreglo.\n", num);
    } else {
        printf("El elemento %d se encuentra en la posicion %d del arreglo.\n", num, numEncontrado);
    }*/
    printf("%.10f\n", wtime1 - wtime0);


    /*for (int w = 0; w < n; w++)
    {
        printf("%d\n", Arreglo[w]);
    }*/

    free(Arreglo);
    // Terminar programa normalmente
    exit(0);
}