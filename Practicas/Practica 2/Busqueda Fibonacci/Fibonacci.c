#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../tiempo.h"

int min(int x, int y) { 
    return (x <= y) ? x : y; 
} 
  

int busquedaFibonacci(int *arr, int x, int n) 
{ 
    int ultimo_fibo = 1;
    int penultimo_fibo = 0;
    int siguiente_fibo = penultimo_fibo + ultimo_fibo;

    while (siguiente_fibo < n)
    {
        penultimo_fibo = ultimo_fibo;
        ultimo_fibo = siguiente_fibo;
        siguiente_fibo = penultimo_fibo + ultimo_fibo;
    }

    int limite = 0;

    while (siguiente_fibo > 1)
    {
        int i = min(limite + penultimo_fibo, n) - 1;

        if (arr[i] < x)
        {
            siguiente_fibo = ultimo_fibo;
            ultimo_fibo = penultimo_fibo;
            penultimo_fibo = siguiente_fibo - ultimo_fibo;
            limite = i + 1;
        }
        else
        {
            if (arr[i] > x)
            {
                siguiente_fibo = penultimo_fibo;
                ultimo_fibo = ultimo_fibo - penultimo_fibo;
                penultimo_fibo = siguiente_fibo - ultimo_fibo;
            }
            else
            {
                return i;
            }
        }
    }
    if (ultimo_fibo && arr[limite] == x)
        return limite;
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
    numEncontrado = busquedaFibonacci(Arreglo, tam, num);
    
    /*if (numEncontrado >= 0)
        printf("El elemento %d se encontro en la posicion: %d\n", num, numEncontrado);
    else
        printf("Elemento no encontrado");
    
    */
    
    // Evaluar los tiempos de ejecución
    uswtime(&utime1, &stime1, &wtime1);

    // Cálculo del tiempo de ejecución del programa
    /*printf("-- Tiempos con %d elementos ---\n", n);
    printf("Tiempo real (Tiempo total): %.10f segundos\n", wtime1 - wtime0);
    printf("\n");

    // Mostrar los tiempos en formato exponencial
    printf("Tiempo real (Tiempo total): %.10e segundos\n", wtime1 - wtime0);
    printf("\n");
*/

    printf("%.10f\n", wtime1 - wtime0);
    free(Arreglo);
    // Terminar programa normalmente
    exit(0);
}