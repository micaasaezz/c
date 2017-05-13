#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estacionamiento.h"

#define FIAT 1
#define PEUGEOT 2
#define FORD 3
#define OTRO 4

 #define CANTPROFESORES 10
 #define CANTAUTOS 5
 #define CANTLUGARPLAYAEST 10

void hardcodeaProfesores(eProfesor profesor[])
{
    int i;
    int id[10] = {1111,2222,3333,4444,5555,6666,7777,8888,9999,1000};
    char nombre[10][30]= {"juan","maria","pedro","luis","romina","jose","andrea","patricia","luciano","camila"};
    int estado[10]= {1,1,1,1,1,1,1,1,1,1};

    for(i=0; i<10; i++)
    {
        profesor[i].idIdentificacion = id[i];
        strcpy(profesor[i].nombre, nombre[i]);
        profesor[i].estado = estado[i];

    }

}


void iniciarEstadosA(eAutomovil automovil[], int tamA)
{
    int i;

    for(i=0; i<tamA; i++)
    {
        automovil[i].estado = 0;
    }
}

void iniciarEstadosP(eProfesor profesores[], int tamP)
{
    int i;

    for(i=0; i<tamP; i++)
    {
        profesores[i].estado = 0;
        profesores[i].estacionadoAhora = 0;
    }
}


int buscarLugar(eAutomovil automovil[], int tamA)
{
    int pocLibre, i, flagEncontro=0;

    for(i=0; i<tamA; i++)
    {
        if(automovil[i].estado == 0)
        {
            pocLibre = i;
            flagEncontro = 1;
            break;
        }
    }
    if(flagEncontro==0)
    {
        pocLibre = -1;
    }

    return pocLibre;
}



void altaAutomovil(eAutomovil automovil[], int posicion, eProfesor profesor[], int tamP)
{
    int marca, i, auxId;

    printf("Ingrese patente del auto:");
    fflush(stdin);
    gets(automovil[posicion].patente);

    printf("Ingrese marca del auto:");
    printf("\n1- Fiat");
    printf("\n2- Peugeot");
    printf("\n3- Ford");
    printf("\n4- Otro");
    scanf("%d", &marca);
    switch(marca)
    {
        case 1:
            automovil[posicion].marca = 1;
            break;
        case 2:
            automovil[posicion].marca = 2;
            break;
        case 3:
            automovil[posicion].marca = 3;
            break;
        case 4:
            automovil[posicion].marca = 4;
            break;
        default:
            printf("Marca no encontrada!");
            break;
    }

    printf("Ingrese el modelo del auto:");
    fflush(stdin);
    gets(automovil[posicion].modelo);

    printf("Ingrese el id del profesor:");
    scanf("%d", &auxId);
    automovil[posicion].idProfesor = auxId;
    for(i=0; i<tamP; i++)
    {
        if(automovil[posicion].idProfesor == profesor[i].idIdentificacion)
        {
            printf("Ingreso el id de identificacion de %s", profesor[i].nombre);
            profesor[i].estado = 1;
            break;
        }
    }

    automovil[posicion].estado = 1;


    printf("\nAlta realizada con %cxito!\n", 130);
}

void bajaAutomovil(eAutomovil automovil[], int tamA, eProfesor profesores[], int tamP)
{
    int i, j;
    char auxNombre[30];
    char opcion;
    int encontroNombre =0;

    printf("Ingrese nombre para dar de baja:");
    fflush(stdin);
    gets(auxNombre);


    for(i=0; i<tamA; i++)
    {
        if(automovil[i].estado == 1)
        {
            for(j=0; j<tamP; j++)
            {

                if(strcmp(auxNombre, profesores[j].nombre) == 0)
                {
                    encontroNombre = 1;
                    printf("%s : %s - %d - %s\nEsta seguro que desea borrar este auto? (s/n)", profesores[j].nombre, automovil[i].patente, automovil[i].marca, automovil[i].modelo);
                    scanf("%c", &opcion);
                    if(opcion == 's')
                    {
                        automovil[i].estado = 0;
                        profesores[j].estado = 0;
                        printf("Borrado con %cxito\n", 130);
                        break;
                    }
                    else
                    {
                        printf("Cancelado!\n");
                    }
                }
            }
        }
    }

    if(encontroNombre==0)
    {
        printf("\nNo se encontro el nombre solicitado!");
    }
}


eProfesor listaDeEspera(eProfesor profesor[], int pos)
{
    eProfesor paraDevolver;
    profesor[pos] = paraDevolver;
    return paraDevolver;
}
void ingresoPlayaEstacionamiento(eProfesor profesores[], int tamP, int lugar)
{
    int i, encontroNombre=0;
    char auxNombre[30];

    eProfesor primeroEnListaDeEspera;

    printf("Ingrese su nombre:");
    fflush(stdin);
    gets(auxNombre);

    for(i=0; i<tamP; i++)
    {
        if(strcmp(auxNombre, profesores[i].nombre) == 0)
        {
            encontroNombre = 1;
            printf("Acceso consedido.\n");

            if(lugar<CANTLUGARPLAYAEST)
            {
                printf("Todavia hay lugar, puede entrar.\n");
                profesores[i].estacionadoAhora = 1;
                printf("Su auto ahora esta en playa de estacionamiento.\n");
            }
            else
            {
                printf("\nNo hay lugares libres en la playa de estacionamiento!");
                printf("\nUsted est%c en lista de espera", 160);
                primeroEnListaDeEspera = listaDeEspera(profesores, i);
                printf("El proximo en lista de espera es %s", primeroEnListaDeEspera.nombre);
            }
            break;
        }
    }

    if(encontroNombre == 0)
    {
        printf("Acceso denegado.\n");
    }

}


void egresoPlayaEstacionamiento(eProfesor profesores[], int tamP)
{
    int i, encontroNombre=0;
    char auxNombre[30];


    printf("Ingrese su nombre:");
    fflush(stdin);
    gets(auxNombre);

    for(i=0; i<tamP; i++)
    {
        if(strcmp(auxNombre, profesores[i].nombre) == 0)
        {
            encontroNombre = 1;
            printf("Acceso consedido.\n");

            profesores[i].estacionadoAhora = 0;
            printf("Su auto ya no est%c en playa de estacionamiento.", 160);

            break;
        }
    }

    if(encontroNombre == 0)
    {
        printf("Acceso denegado.\n");
    }
}



void listarAutos(eAutomovil automoviles[], int tamA, eProfesor profesores[], int tamP)
{
    int opcion, i, j;
    eAutomovil auxStruct;

    printf("\nElija el criterio por el que los quiere ver:");
    printf("\n1- Autos habilitadospara estacionar (por marca y patente):\n");
    printf("2- Autos estacionados:\n");
    printf("3- Autos marca fiat estacionados:\n");
    printf("4- Autos fuera del estacionamiento:\n");
    printf("5- cancelar:\n");
    scanf("%d", &opcion);
    switch(opcion)
    {
        case 1:
            for(i=0; i<tamA-1; i++)
            {
                if(automoviles[i].estado == 0)
                {
                    continue;
                }

                for(j=i+1; j<tamA; j++)
                {
                    if(automoviles[j].estado == 0)
                    {
                        continue;
                    }

                    if(automoviles[j].marca > automoviles[i].marca)
                    {
                        auxStruct = automoviles[i];
                        automoviles[i] = automoviles[j];
                        automoviles[j] = auxStruct;
                    }
                    else if(automoviles[i].marca == automoviles[j].marca)  //si son iguales, los comparo por patente
                    {
                        if(strcmp(automoviles[j].patente, automoviles[i].patente) < 0)
                        {
                            auxStruct = automoviles[i];
                            automoviles[i] = automoviles[j];
                            automoviles[j] = auxStruct;
                        }
                    }
                }


            }
            printf("PATENTE\tDUE%cO\n", 165);
            for(i=0; i<tamA; i++)
            {
                if(automoviles[i].estado == 0)
                    {
                        continue;
                    }
                printf("%s\t%s\n", automoviles[i].patente, profesores[i].nombre);
            }
            break;

        case 2:
            printf("PATENTE\tMARCA\tMODELO\tDUE%cO\n", 165);
            for(i=0; i<tamP; i++)
            {

                if(profesores[i].estacionadoAhora == 1)
                {
                   printf("%s\t%d\t%s\t%s\t\n", automoviles[i].patente,  automoviles[i].marca, automoviles[i].modelo, profesores[i].nombre);

                }

            }
            break;

        case 3:
            printf("AUTOS FIAT ESTACIONADOS:\n");
            printf("PATENTE\tMARCA\tMODELO\tDUE%cO\n", 165);
            for(i=0; i<tamP; i++)
            {
                if(profesores[i].estacionadoAhora == 1)
                {
                    if(automoviles[i].marca == 1)
                    {
                       printf("%s\t%d\t%s\t%s\t\n", automoviles[i].patente,  automoviles[i].marca, automoviles[i].modelo, profesores[i].nombre);
                    }
                }

            }
            break;

        case 4:
            printf("AUTOS FUERA DEL ESTACIONAMIENTO:\n");
            printf("PATENTE\tMARCA\tMODELO\tDUE%cO\n", 165);
            for(i=0;i<tamP;i++)
            {
                if(profesores[i].estacionadoAhora == 0)
                {
                    printf("%s\t%d\t%s\t%s\t\n", automoviles[i].patente,  automoviles[i].marca, automoviles[i].modelo, profesores[i].nombre);

                }

            }
            break;

        case 5:
            break;

    }
}


