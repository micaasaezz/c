#include <stdio.h>
#include <stdlib.h>

//Calcular el factorial de un numero usando una estructura repetitiva


int main()
{
    int numero=5;
    int i;
    int factorial =1;

    for(i=numero; i>0; i--)
    {
        factorial= factorial*i;

    }

    printf("El factorial es %d", factorial);
    return 0;
}
