#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../tiempo.h"


int busquedaBinaria(int *arr, int n, int x)
{
    int anterior = 0;
    int siguiente = n - 1;
    int centro;

    while (anterior <= siguiente)
    {
        centro = anterior + (siguiente - anterior) / 2;
        if (arr[centro] == x)
            return centro;
        if (arr[centro] < x)
            anterior = centro + 1;
        else
            siguiente = centro - 1;
    }

    return -1;
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
    numEncontrado = busquedaBinaria(Arreglo, n, num);
    
    if (numEncontrado == -1)
        printf("Elemento no encontrado");
    else
        printf("El elemento %d se encontro en la posicion: %d\n", num, numEncontrado);
    
    
    
    // Evaluar los tiempos de ejecución
    uswtime(&utime1, &stime1, &wtime1);

    // Cálculo del tiempo de ejecución del programa
    /*printf("-- Tiempos con %d elementos ---\n", n);
    printf("Tiempo real (Tiempo total): %.10f segundos\n", wtime1 - wtime0);

    // Mostrar los tiempos en formato exponencial
    printf("Tiempo real (Tiempo total): %.10e segundos\n", wtime1 - wtime0);
    printf("\n");*/

    printf("%.10f\n", wtime1 - wtime0);

    free(Arreglo);
    // Terminar programa normalmente
    exit(0);
}