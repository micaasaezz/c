#include <stdio.h>
#include <stdlib.h>

// * operador de inacceso
// & operador de direcion

int main()
{
    //declaracion de punteros  tipo* identificador;  ej: int* puntero;

    //int variable = 9;
    //int* puntero;
    //int* otro;

    //asignacion de punteros
    //puntero = &variable; //en 'puntero' esta guardado la direccion de memoria de 'variable'
    //otro = puntero;

    //direcc de memoria
    //printf("%p\n", &variable);
    //printf("%p\n", puntero);
    // valor de la variable
    //printf("%d\n", variable);
    //printf("%d", *puntero);

    //printf("\n%p", &puntero);

    //cambio el valor de la variable desde el puntero
    //*puntero = 17;
    //lee el valor desde el teclado para cambiar el valor de vartiable
    //scanf("%d", puntero);

    //___________________________________

    //punteros y vectores

    int vec[5] = {0};
    int* pvec;
    int i;

    pvec = vec; //le paso la direcc de memoria del vector

    //para mostrar el vector en la pos 2 vec[2] hago el printf con *(pvec+2)
    //para leer el vector en la pos 2 &vec[2] hago el scanf con pvec+2

    for(i=0; i<5; i++) //cargar el vector de manera secuencial
    {
        printf("Ingrese numero para el vector:");
        scanf("%d", pvec+i);

    }

    for(i=0; i<5; i++) //muestro el vector
    {
        printf("%d\t", *(pvec + i));

    }


    //carga ordenamiento y muestreo tarea en funciones














    return 0;
}
