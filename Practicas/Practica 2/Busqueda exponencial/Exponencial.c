#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../tiempo.h"
#define min

int busquedaBinaria(int arr[], int, int, int);
 
int obtener_menor(int x, int y)
{
    return (x <= y) ? x : y;
}

int busquedaExponencial(int arr[], int n, int x)
{
     int i = 0;
    if (arr[i] == x)
        return i;
    i = 1;
    while (i < n && arr[i] <= x)
    {
        i = i * 2;
    }

    int anterior = i / 2;
    int siguiente = obtener_menor(i, n - 1);
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

    tam = n / sizeof(Arreglo[0]);
    
    // Algoritmo
    numEncontrado =  busquedaExponencial(Arreglo, tam, num);
    
    /*if (numEncontrado == -1)
        printf("Elemento no encontrado");
    else
        printf("El elemento %d se encontro en la posicion: %d\n", num, numEncontrado);
    */
    
    
    // Evaluar los tiempos de ejecución
    uswtime(&utime1, &stime1, &wtime1);

    printf("%.10f\n", wtime1 - wtime0);

    free(Arreglo);
    // Terminar programa normalmente
    exit(0);
}