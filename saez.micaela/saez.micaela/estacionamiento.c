#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estacionamiento.h"

void hardcodeaProfesores(eProfesor profesor[])
{
    int i;
    int id[10] = {1111,2222,3333,4444,5555,6666,7777,8888,9999,1000};
    char nombre[10][30]= {"juan","maria","pedro","octavio","romina","german","andrea","patricia","luciano","mario"};
    //int estado[10]= {1,1,1,1,1,1,1,1,1,1};

    for(i=0; i<10; i++)
    {
        profesor[i].idIdentificacion = id[i];
        strcpy(profesor[i].nombre, nombre[i]);
        //profesor[i].estado = estado[i];

    }

}



void hardcodea6altasAutomoviles(eAutomovil automoviles[], eProfesor profesores[])
{
    int i, j;
    char patente[6][8] = {"abc123", "def456", "gh789ij", "jkl101", "mn212op", "qr093tw"};
    int marca[6] = {3,1,4,1,2,2};
    char modelo[6][30] = {"fiesta", "uno", "polo", "palio", "308", "305"};
    int idProfesor[6] = {1111,2222,3333,4444,5555,6666};
    int estado[6] = {1,1,1,1,1,1};


    for(i=0; i<6; i++)
    {
        automoviles[i].idProfesor = idProfesor[i];
        automoviles[i].estado = estado[i];
        automoviles[i].marca = marca[i];
        strcpy(automoviles[i].patente, patente[i]);
        strcpy(automoviles[i].modelo, modelo[i]);
    }

    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            if(automoviles[i].idProfesor == profesores[j].idIdentificacion)
            {
                profesores[i].estado = 1;
                profesores[i].estacionadoAhora = 0;
            }
        }
    }
}



void hardcodea4estacionamientos(eProfesor profesores[])
{
    profesores[0].estacionadoAhora = 1;
    profesores[2].estacionadoAhora = 1;
    profesores[3].estacionadoAhora = 1;
    profesores[5].estacionadoAhora = 1;

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

int validaPatente(char patenteaValidar[])
{
    int respuesta =1, i, tamPat;

    tamPat = strlen(patenteaValidar);

    if(tamPat < 6 || tamPat > 7)
    {
        respuesta = 0;
    }
    else
    {
        for(i=0; i<tamPat; i++)
        {
            if(i<2)
            {
                if(patenteaValidar[i] < 'a' || patenteaValidar[i] > 'z')
                {
                    respuesta = 0;
                    break;
                }
            }
            else if(i== 2 || i==5)
            {
                if((patenteaValidar[i] < 'a' || patenteaValidar[i] > 'z') && (patenteaValidar[i] < '0' || patenteaValidar[i] > '9'))
                {
                    respuesta = 0;
                    break;
                }
            }
            else if(i==3 || i==4)
            {
                if(patenteaValidar[i] < '0' || patenteaValidar[i] > '9')
                {
                    respuesta = 0;
                    break;
                }
            }
            else if(i==6)
            {
                if(patenteaValidar[i] < 'a' || patenteaValidar[i] > 'z')
                {
                    respuesta = 0;
                    break;
                }
            }

        }


    }

    return respuesta;
}

int altaAutomovil(eAutomovil automovil[], int posicion, eProfesor profesor[], int tamP)
{
    int marca, i, auxId, encontroId=0, validaPat, marcaValida=0;
    int respuesta = 1;

    printf("Ingrese patente del auto (en minuscula y sin espacios):");
    fflush(stdin);
    gets(automovil[posicion].patente);
    validaPat = validaPatente(automovil[posicion].patente);
    while(validaPat == 0)
    {
        printf("\nIngrese patente v%clida!\n", 160);
        fflush(stdin);
        gets(automovil[posicion].patente);
        validaPat = validaPatente(automovil[posicion].patente);
    }


    while(marcaValida == 0)
    {   printf("Ingrese marca del auto:");
        printf("\n1- Fiat");
        printf("\n2- Peugeot");
        printf("\n3- Ford");
        printf("\n4- Otro");
        scanf("%d", &marca);
        switch(marca)
        {
            case 1:
                automovil[posicion].marca = 1;
                marcaValida = 1;
                break;
            case 2:
                automovil[posicion].marca = 2;
                marcaValida = 1;
                break;
            case 3:
                automovil[posicion].marca = 3;
                marcaValida = 1;
                break;
            case 4:
                automovil[posicion].marca = 4;
                marcaValida = 1;
                break;
            default:
                printf("Marca no encontrada!");
                break;
        }
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

                if(profesor[i].estado == 0)
                {
                    profesor[i].estado = 1;
                    automovil[posicion].estado = 1;
                    encontroId = 1;
                    printf("\nAlta realizada con %cxito!\n", 130);
                    break;
                }
                else
                {
                    printf("\nEl auto de ese profesor ya fue ingresado!\n\nAlta cancelada!\n");
                    encontroId = 1;
                }
            }

    }

    if(encontroId == 0)
    {
        printf("\nEl Id ingresado no corresponde con ningun profesor registrado en el sistema!\n\nAlta cancelada\n");
        respuesta = 0;
    }

    return respuesta;

}

void bajaAutomovil(eAutomovil automovil[], int tamA, eProfesor profesores[], int tamP)
{
    int j, i;
    char auxNombre[30];
    char opcion;
    int encontroNombre =0;

    printf("Ingrese nombre para dar de baja:");
    fflush(stdin);
    gets(auxNombre);


    for(j=0; j<tamP; j++)
    {

          if(strcmp(auxNombre, profesores[j].nombre) == 0)
          {
               encontroNombre = 1;
               printf("\nEsta seguro que desea borrar el auto de %s? (s/n)", profesores[j].nombre);
               scanf("%c", &opcion);
               if(opcion == 's')
               {
                   for(i=0; i<tamA; i++)
                   {
                       if(profesores[j].idIdentificacion == automovil[i].idProfesor)
                       {
                           automovil[i].estado = 0;
                           break;
                       }
                   }

                   profesores[j].estado = 0;
                   profesores[j].estacionadoAhora = 0;
                   printf("Borrado con %cxito\n", 130);
                   break;
                }
                else
                {
                     printf("Cancelado!\n");
                }
            }
    }

    if(encontroNombre==0)
    {
        printf("\nNo se encontro el nombre solicitado!\n");
    }
}



void ingresoPlayaEstacionamiento(eProfesor profesores[], int tamP)
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
            if(profesores[i].estado == 0)
            {
                printf("\nEl aut%cmovil de ese profesor no fue dado de alta!\n", 162);
                break;
            }
            printf("Acceso consedido.\n");
            printf("Todavia hay lugar, puede entrar.\n");
            profesores[i].estacionadoAhora = 1;
            printf("%s: Su auto ahora esta en playa de estacionamiento.\n", profesores[i].nombre);

            break;
        }
    }

    if(encontroNombre == 0)
    {
        printf("Acceso denegado. Ese nombre no pertenece a un profesor registrado en sistema.\n");
    }

}


int egresoPlayaEstacionamiento(eProfesor profesores[], int tamP)
{
    int i, encontroNombre=0;
    char auxNombre[30];
    char sacarAuto;
    int respuesta=1;

    printf("Ingrese su nombre:");
    fflush(stdin);
    gets(auxNombre);

    for(i=0; i<tamP; i++)
    {
        if(strcmp(auxNombre, profesores[i].nombre) == 0)
        {
            encontroNombre = 1;
            if(profesores[i].estacionadoAhora == 0)
            {
                printf("\nEl aut%cmovil de ese profesor no se encuentra en playa de estacionamiento!\n", 162);
                break;
            }
            printf("Acceso consedido.\n");

            printf("%s: esta seguro que desea retirar su auto de la playa de estacionamiento? (s/n)", profesores[i].nombre);
            scanf("%c", &sacarAuto);
            if(sacarAuto == 's')
            {
                profesores[i].estacionadoAhora = 0;
                printf("%s: Su auto ya no est%c en playa de estacionamiento.\n", profesores[i].nombre, 160);
            }
            else
            {
                printf("\nBaja cancelada!\n");
                respuesta=0;
            }

            break;
        }
    }

    if(encontroNombre == 0)
    {
        printf("Acceso denegado.\n");
        respuesta=0;
    }

    return respuesta;

}



void listarAutos(eAutomovil automoviles[], int tamA, eProfesor profesores[], int tamP)
{
    int opcion, i, j;
    int flagCase2=0, flagCase4=0;
    eAutomovil auxStruct;
    int contFiat=0;

    printf("\nElija el criterio por el que los quiere ver:");
    printf("\n1- Autos habilitados para estacionar (por marca y patente):\n");
    printf("2- Autos en playa de estacionamiento:\n");
    printf("3- Autos estacionados de marca fiat :\n");
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

                    if(automoviles[j].marca < automoviles[i].marca)
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
                if(automoviles[i].estado == 1)
                {
                   printf("%s\t", automoviles[i].patente);
                    for(j=0; j<tamP; j++)
                    {
                       if(automoviles[i].idProfesor == profesores[j].idIdentificacion)
                       {
                           printf("%s\n", profesores[j].nombre);
                           break;
                       }
                    }
                }
            }
            break;

        case 2:
            printf("DUE%cO\tPATENTE\tMARCA\tMODELO\tID PROFESOR\n", 165);
            for(i=0; i<tamP; i++)
            {
                if(profesores[i].estacionadoAhora == 1)
                {
                    printf("%s\t", profesores[i].nombre);

                    for(j=0; j<tamA; j++)
                    {
                       if(automoviles[j].idProfesor == profesores[i].idIdentificacion)
                       {
                           printf("%s\t%d\t%s\t%d\n", automoviles[j].patente,  automoviles[j].marca, automoviles[j].modelo, automoviles[j].idProfesor);
                           flagCase2 =1;
                           break;
                       }
                    }

                }

            }
            if(flagCase2 == 0)
            {
                printf("\n\nNo hay autos actualmente en la playa de estacionamiento!!\n");
            }
            break;

        case 3:
            printf("AUTOS FIAT ESTACIONADOS:\n");
            printf("DUE%cO\tPATENTE\tMARCA\tMODELO\n", 165);
            for(i=0; i<tamP; i++)
            {
                if(profesores[i].estacionadoAhora == 1)
                {
                    for(j=0; j<tamA; j++)
                    {
                        if(profesores[i].idIdentificacion == automoviles[j].idProfesor)
                        {
                            if(automoviles[j].marca == 1)
                            {
                                 printf("%s\t%s\tfiat\t%s\n", profesores[i].nombre, automoviles[j].patente, automoviles[j].modelo);
                                 contFiat++;
                                 break;
                            }
                        }
                    }

                }

            }

            if(contFiat == 0)
            {
                printf("\nNo hay ning%cn auto marca fiat en la playa de estacionamiento actualmente!\n", 163);
            }
            else if(contFiat>0)
            {
                printf("\n\nLa cantidad de autos fiat en estacionamiento es %d\n\n", contFiat);
            }
            break;

        case 4:
            printf("AUTOS FUERA DEL ESTACIONAMIENTO:\n");
            printf("DUE%cO\tPATENTE\tMARCA\tMODELO\n", 165);
            for(i=0;i<tamP;i++)
            {
                if(profesores[i].estacionadoAhora == 0 && profesores[i].estado == 1)
                {
                    printf("%s\t", profesores[i].nombre);
                    for(j=0; j<tamA; j++)
                    {
                        if(profesores[i].idIdentificacion == automoviles[j].idProfesor)
                        {
                            printf("%s\t%d\t%s\n", automoviles[j].patente,  automoviles[j].marca, automoviles[j].modelo);
                            flagCase4 =1;
                            break;
                        }
                    }

                }

            }

            if(flagCase4 == 0)
            {
                printf("\n\nNo hay autos fuera del estacionamiento!\n\n");
            }
            break;

        case 5:
            break;

    }
}


