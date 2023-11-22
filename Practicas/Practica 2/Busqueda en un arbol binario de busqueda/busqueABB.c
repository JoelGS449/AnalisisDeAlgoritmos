#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../tiempo.h"

//Estructuras
struct nodo {
    int dato;
    struct nodo *izq, *der;
};
 
struct nodo* nuevoNodo(int dato) //creamos un nuvo nodo del arbol
{
    struct nodo* temp = (struct nodo*)malloc(sizeof(struct nodo));
    temp->dato = dato;
    temp->izq = temp->der = NULL;
    return temp;
}
 
struct nodo* insertar(struct nodo* nodo, int dato) //Insertar un dato
{
    if (nodo == NULL)
        return nuevoNodo(dato); //si esta vacio, sera la raiz
 
    
    if (dato < nodo->dato) //si el dato es menor al nodo padre, se inserta a la izquierda
        nodo->izq = insertar(nodo->izq, dato);
    else if (dato > nodo->dato)//si el dato es mayor al nodo padre, se inserta a la derecha
        nodo->der = insertar(nodo->der, dato);
 
    return nodo;
}
 

struct nodo* buscar(struct nodo* nodo, int dato) //Buscar en el arbol
{
    
    if (nodo == NULL || nodo->dato == dato) //Si el nodo esta vacio o el dato a buscar es el mismo al dato en que se encuentra
        return dato; //Retornamos el mismo dato
 
    if (nodo->dato < dato) //Si el dato del nodo padre es menor al dato ingresado, buscamos por la derecha
        return buscar(nodo->der, dato);
 
    return buscar(nodo->izq, dato); //Si no se cumple lo anterior, buscamos por la izquierda
}



// PROGRAMA PRINCIPAL
int main(int argc, char *argv[])
{
    
    // Variables del main
    double utime0, stime0, wtime0, utime1, stime1, wtime1; // Variables para medición de tiempos
    int i; //variables para los ciclos
    int n; //variable para el tamaño del arreglo
    int num; //variable para guardar el numero a buscar
    int tmp, numEncontrado;
    struct nodo* arbol = NULL;
  
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
    

   
    for (i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        insertar(arbol,tmp);
    }

    // Algoritmo
    
    /*if (buscar(arbol, num) == NULL)
        printf("Dato %d, no entontrado\n", num);
    else
        printf("Dato %d encontrado\n", num);
    */
     
    
    // Evaluar los tiempos de ejecución
    uswtime(&utime1, &stime1, &wtime1);

    printf("%.10f\n", wtime1 - wtime0);
    


    // Terminar programa normalmente
    exit(0);
}