#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estacionamiento.h"

#define FIAT 1
#define PEUGEOT 2
#define FORD 3
#define OTRO 4

#define CANTPROFESORES 10
#define CANTAUTOS 10
#define CANTLUGARPLAYAEST 6

int main()
{
    char seguir = 's';
    int opcion, i;
    int posicionLibre, flagPrimerAlta=0, pudoAlta, pudoEgreso;
    eProfesor profesores[CANTPROFESORES];
    eAutomovil automovil[CANTAUTOS];
    int lugaresOcupados =4;
    char proxEnEspera[30];
    int auxEspera =0;

    hardcodeaProfesores(profesores);
    iniciarEstadosA(automovil, CANTAUTOS);
    iniciarEstadosP(profesores, CANTPROFESORES);
    hardcodea6altasAutomoviles(automovil, profesores);
    hardcodea4estacionamientos(profesores);

    printf("El programa empieza cargado con 10 profesores y 6 altas de automoviles de los cuales 4 estan en playa de estacionamiento.\n");

    while(seguir == 's')
    {
        printf("1- Dar de alta un automovil.\n");
        printf("2- Dar de baja un automovil.\n");
        printf("3- Ingreso a la playa de estacionamiento.\n");
        printf("4- Egreso de la playa de estacionamiento.\n");
        printf("5- Informes.\n\n");
        printf("6- Salir.\n\n");

        scanf("%d", &opcion);
        switch(opcion)
        {

          case 1:

                posicionLibre = buscarLugar(automovil, CANTAUTOS);
                if(posicionLibre == -1)
                {
                    printf("\nNo se encontr%c lugar libre!", 162);
                    break;
                }
                pudoAlta = altaAutomovil(automovil, posicionLibre, profesores, CANTPROFESORES, CANTAUTOS);
                if(flagPrimerAlta == 0 && pudoAlta == 1)
                {
                    flagPrimerAlta =1;
                }

                break;

            case 2:
//                if(flagPrimerAlta == 0)
//                {
//                    printf("\n\nNo se ingresaron altas todavia!!");
//                    break;
//                }
                bajaAutomovil(automovil, CANTAUTOS, profesores, CANTPROFESORES);

                break;

            case 3:
//                if(flagPrimerAlta == 0)
//                {
//                    printf("\n\nNo se ingresaron altas todavia!!");
//                    break;
//                }
                if(lugaresOcupados<CANTLUGARPLAYAEST)
                {
                    ingresoPlayaEstacionamiento(profesores, CANTPROFESORES);
                    lugaresOcupados++;
                }
                else
                {
                    printf("No hay lugar en playa de estacionamiento!\n");
                    printf("Ingrese su nombre para guardarlo en la lista de espera:\n");
                    fflush(stdin);
                    gets(proxEnEspera);

                    for(i=0; i<CANTPROFESORES; i++)
                    {
                        if(strcmp(proxEnEspera, profesores[i].nombre) == 0)
                        {
                            printf("Acceso concedido!\n");
                            printf("%s: su nombre se guardo en lista de espera.\n", proxEnEspera);
                            auxEspera = 1;
                            break;
                        }
                    }
                    if(auxEspera == 0)
                    {
                        printf("Ese nombre no est%c registrado en el sistema!\n", 160);
                    }
                }

                break;

            case 4:
//                if(flagPrimerAlta == 0)
//                {
//                    printf("\n\nNo se ingresaron altas todavia!!");
//                    break;
//                }
                pudoEgreso = egresoPlayaEstacionamiento(profesores, CANTPROFESORES);
                if(pudoEgreso == 1)
                {
                    lugaresOcupados--;
                    if(auxEspera == 1)
                    {
                        printf("\nAhora s%c hay lugar para %s\n", 161, proxEnEspera);
                    }

                }

                break;

            case 5:
//                if(flagPrimerAlta == 0)
//                {
//                    printf("\n\nNo se ingresaron altas todavia!!");
//                    break;
//                }
                listarAutos(automovil, CANTAUTOS, profesores, CANTPROFESORES);
                break;

            case 6:
                seguir = 'n';
                break;

            default:
                printf("Ingrese una opcion valida!\n");
                break;
        }

        system("pause");
        system("cls");

    }

    return 0;
}


