#include <stdio.h>
#include <stdlib.h>
#include "inc/input.h"


int main()
{
    int edad;
    float precio;
    char continuar;
    char nombre[50];
    int r; // Respuesta


    // EJEMPLO DE USO DE getInt
    r = getInt(&edad,"Cual es tu edad?","Rango valido [0 - 100]\n",1,100);
    while(r == -1)
    {
        r = getInt(&edad,"Cual es tu edad?","Rango valido [0 - 100]\n",1,100);
    }
    if(r == 0)
    {
        printf("\nLa edad es: %d\n", edad);
    }



    // EJEMPLO DE USO DE getFloat
    r = getFloat(&precio,"Cual es el precio?","Rango valido [0 - 10000]\n",1,10000);
    while(r == -1)
    {
        r = getFloat(&precio,"Cual es el precio?","Rango valido [0 - 10000]\n",1,10000);
    }
    if(r == 0)
    {
        printf("\nEl precio es: %0.2f\n",precio);
    }


    // EJEMPLO DE USO DE getChar
     r = getChar(&continuar,"Ingrese Opcion [A][B][C]","Solo [A][B][C]\n",'A','C');
     while(r == -1)
     {
         r = getChar(&continuar,"Ingrese Opcion [A][B][C]","Solo [A][B][C]\n",'A','C');
     }
     if(r == 0)
     {
        printf("\nContinuar: %c\n",continuar);
     }


    // EJEMPLO DE USO DE getChar
    r = getString(nombre,"Nombre: ","El largo debe ser entre 2 y 50\n", 2, 50);
    while(r == -1)
    {
       r = getString(nombre,"Nombre: ","El largo debe ser entre 2 y 50\n", 2, 50);
    }
    if(r == 0)
    {
        printf("\nNombre: %s\n",nombre);
    }



    return 0;
}

