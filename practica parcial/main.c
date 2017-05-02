#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

//motivos
#define FALLA_3G 1
#define FALLA_4G 2
#define FALLA_EQUIPO 3

//estados problemas
#define INDETERMINADO 1
#define EN_CURSO 2
#define SIN_RESOLVER 3
#define RESUELTO 4

//estados abonados
#define DISPONIBLE 0
#define NO_DISPONIBLE 1

//cant de abonados
#define CANT 5

int main()
{
    char seguir = 's';
    int opcion;
    eAbonado abonado[CANT];

    do{
        printf("1- Dar de alta a un abonado.\n");
        printf("2- Modificar nombre de un abonado.\n");
        printf("3- Dar de baja a un abonado.\n");
        printf("4- Registrar nueva llamada.\n");
        printf("5- Informar fin de llamada.\n");
        printf("6- Informes.\n\n");
        printf("7- Cerrar.\n");

        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                seguir = 'n';
                break;
            default:
                printf("Ingrese una opcion valida!");
                break;
        }

        system("pause");
        system("cls");

    }while(seguir == 's');

    return 0;
}
