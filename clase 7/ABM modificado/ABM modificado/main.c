#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Biblio.h"

#define A 5

int main()
{
    int i, j;
    char nombres[A][15];
    int legajos[A];
    int estados[A]={0};
    char auxCadena[15];
    int auxInt;
    int opcion;
    char seguir='s';

    do
    {

        printf("1. Alta\n");
        printf("2. Baja\n");
        printf("3. Modificacion\n");
        printf("4. Mostrar\n");
        printf("5. Ordenar\n");
        printf("6. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                cargarDatos(legajos, nombres, estados, A);
                break;
            case 2:
                bajaDatos(legajos, nombres, estados, A);
                break;
            case 3:
                modificarDatos(legajos, nombres, estados, A);
                break;
            case 4:
                mostrarDatos(legajos, nombres , estados, A);
                break;
            case 5:
                ordenarPorNombre(legajos, nombres , estados, A);
                break;
            case 6:
                seguir='n';
                break;
            default:
                printf("Ingrese una opcion valida!");
                break;

        }

    }while(seguir=='s');





    return 0;
}

