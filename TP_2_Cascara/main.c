#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 3


int main()
{
    char seguir='s';
    int opcion=0;
    EPersona lista[CANT];
    int espLibre;
    int flagEmpezarEstados=0;

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            if(flagEmpezarEstados==0)
            {
                iniciarEstados(lista, CANT);
                flagEmpezarEstados = 1;
            }

            espLibre = obtenerEspacioLibre(lista, CANT);

            if(espLibre == -1)
            {
                printf("\nNo hay más espacio libre!\n");
                break;
            }

            cargarPersona(lista, CANT, espLibre);

            break;

        case 2:
            borrarPersona(lista, CANT);
            break;

        case 3:
            listarPorNombre(lista, CANT);
            break;

        case 4:
            graficar(lista, CANT);
            break;

        case 5:
            seguir = 'n';
            break;

        default:
            printf("\n\nIngrese una opción válida!\n");
            break;

        }
        system("pause");
        system("cls");

    }


    return 0;
}
