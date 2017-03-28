#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main()
{
    int sumatoria;
    sumatoria = sumar(4,6);

    int resta;
    resta = restar(11,1);

    int multiplicacion;
    multiplicacion = multiplicar(10,1);

    float division;
    division = dividir(100,10);

    printf("La suma da: %d \nLa resta da: %d \nLa multiplicacion da: %d \nLa division da: %f", sumatoria, resta, multiplicacion, division);

    return 0;
}
