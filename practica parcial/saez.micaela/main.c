#include <stdio.h>
#include <stdlib.h>
#include "estacionamiento.h"

#define FIAT 1
#define PEUGEOT 2
#define FORD 3
#define OTRO 4

 #define CANTPROFESORES 10
 #define CANTAUTOS 5
 #define CANTLUGARPLAYAEST 10

int main()
{
    int flagAux=0;
    char seguir = 's';
    int opcion;
    int posicionLibre, flagPrimerAlta=0;
    eProfesor profesores[CANTPROFESORES];
    eAutomovil automovil[CANTAUTOS];
    int lugaresOcupados =0;
    hardcodeaProfesores(profesores);

    do
    {
        printf("1- Dar de alta un automovil.\n");
        printf("2- Dar de baja un automovil.\n");
        printf("3- Ingreso a la playa de estacionaiento.\n");
        printf("4- Egreso de un automovil.\n");
        printf("5- Informes.\n\n");
        printf("6- Salir.\n\n");

        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                if(flagPrimerAlta == 0)
                {
                    iniciarEstadosA(automovil, CANTAUTOS);
                    iniciarEstadosP(profesores, CANTPROFESORES);
                    flagPrimerAlta =1;
                    flagAux = 1;
                }
                posicionLibre = buscarLugar(automovil, CANTAUTOS);
                if(posicionLibre == -1)
                {
                    printf("\nNo se encontr%c lugar libre!", 162);
                    break;
                }
                altaAutomovil(automovil, posicionLibre, profesores, CANTPROFESORES);
                lugaresOcupados++;

                break;

            case 2:
                if(flagAux == 0)
                {
                    printf("\n\nNo se ingresaron altas todavia!!");
                    break;
                }
                bajaAutomovil(automovil, CANTAUTOS, profesores, CANTPROFESORES);
                lugaresOcupados--;
                break;

            case 3:
                if(flagAux == 0)
                {
                    printf("\n\nNo se ingresaron altas todavia!!");
                    break;
                }
                if(lugaresOcupados<CANTLUGARPLAYAEST)
                {
                    ingresoPlayaEstacionamiento(profesores, CANTPROFESORES, lugaresOcupados);
                }
                else
                {
                    printf("No hay lugar en playa de estacionamiento!");
                }
                break;

            case 4:
                if(flagAux == 0)
                {
                    printf("\n\nNo se ingresaron altas todavia!!");
                    break;
                }
                egresoPlayaEstacionamiento(profesores, CANTPROFESORES);
                lugaresOcupados--;
                break;

            case 5:
                if(flagAux == 0)
                {
                    printf("\n\nNo se ingresaron altas todavia!!");
                    break;
                }
                listarAutos(automovil, CANTAUTOS, profesores, CANTPROFESORES);
                break;
            case 6:
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
