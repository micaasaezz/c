#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

#define IDEVENTO 1000

int menu()
{
    int opcion=0;

    printf("1- Agregar evento.\n");
    printf("2- Borrar evento.\n");
    printf("3- Modificar evento.\n");
    printf("4- Informes.\n");
    printf("5- Salir.\n");
    scanf("%d",&opcion);

    return opcion;
}



int getString(char* input,char message[],char errorMessage[], int lowLimit, int hiLimit)
{
    int respuesta = 0;
    int pudoLeer;

    if(input == NULL)
    {
        respuesta = -1;
        return respuesta;
    }

    printf("%s", message);
    fflush(stdin);
    pudoLeer = scanf("%s", input);
    if(pudoLeer == 0)
    {
        respuesta = -1;
    }
    else if(strlen(input) > hiLimit || strlen(input) < lowLimit)
    {
        printf("%s", errorMessage);
        respuesta = -1;
    }

    return respuesta;
}

int getFloat(float* input,char message[],char errorMessage[], float lowLimit, float hiLimit)
{
    int respuesta = 0;
    int pudoLeer;

    if(input == NULL)
    {
        respuesta = -1;
        return respuesta;
    }
    fflush(stdin);
    printf("%s", message);
    pudoLeer = scanf("%f", input);
    if(pudoLeer == 0)
    {
        respuesta = -1;
    }
    else if(*input > hiLimit || *input < lowLimit)
    {
        printf("%s", errorMessage);
        respuesta = -1;
    }

    return respuesta;

}


int getInt(int* input,char message[],char errorMessage[], int lowLimit, int hiLimit)
{
    int respuesta = 0;
    int pudoLeer;

    if(input == NULL)
    {
        respuesta = -1;
        return respuesta;
    }
    fflush(stdin);
    printf("%s", message);
    pudoLeer = scanf("%d", input);
    if(pudoLeer == 0)
    {
        respuesta = -1;
    }
    else if(*input > hiLimit || *input < lowLimit)
    {
        printf("%s", errorMessage);
        respuesta = -1;
    }

    return respuesta;
}



eFecha* newFecha()
{
    eFecha* aux;
    aux = (eFecha*) malloc(sizeof(eFecha));
    return aux;
}

eEvento* newEvento()
{
    eEvento* aux;
    aux = (eEvento*) malloc(sizeof(eEvento));
    return aux;
}

eEvento* newEventoParametrizado(eFecha* fecha, char tipoEvento[], float presupuesto, float pagado, int invitados, int estado, int idEvento)
{
    eEvento* auxEvent;
    auxEvent = newEvento();
    if(auxEvent != NULL)
    {
        auxEvent->fecha = *fecha;
        strcpy(auxEvent->tipoEvento, tipoEvento);
        auxEvent->presupesto = presupuesto;
        auxEvent->pagado = pagado;
        auxEvent->invitados = invitados;
        if(auxEvent->presupesto <= auxEvent->pagado)
        {
            auxEvent->estado = 1;
        }
        else
        {
            auxEvent->estado = 0;
        }
        auxEvent->estado = estado;
        auxEvent->idEvento = idEvento;

    }
    return auxEvent;
}

int tiposEvento()
{
    int opcion=0;

    printf("1- Casamiento.\n");
    printf("2- Fiesta de 15.\n");
    printf("3- Despedida de a%co.\n", 164);
    printf("4- Cumplea%cos de adulto.\n", 164);
    printf("5- Evento empresarial.\n");
    scanf("%d",&opcion);

    return opcion;

}


void nuevoEvento(ArrayList* listaEventos)
{
    int auxInt, i;
    eEvento* miEvento;
    eEvento* auxevent = newEvento();

    int idEvento;
    eFecha* fecha = newFecha();
    char tipoEvento[100];
    float presupesto;
    float pagado; //seña
    int invitados;
    int estado; // 1 pagado / 0 señado

    do
    {
        printf("Seleccione el tipo de evento a realizar:\n");
        auxInt = tiposEvento();
    }while(auxInt == 0);
    switch(auxInt)
    {
        case 1:
            strcpy(tipoEvento, "casamiento");
            break;
        case 2:
            strcpy(tipoEvento, "quince");
            break;
        case 3:
            strcpy(tipoEvento, "despedida");
            break;
        case 4:
            strcpy(tipoEvento, "cumple");
            break;
        case 5:
            strcpy(tipoEvento, "empresarial");
            break;
    }

    do
    {
        auxInt = getInt(&invitados, "Ingrese la cantidad de invitados del evento: ", "Cantidad posible de 30 a 350!\n", 30, 350);
    }while(auxInt == -1);

    do
    {
        printf("Ingrese el dia del evento: ");
        scanf("%d", &auxInt);
    }while(auxInt<1 || auxInt>31);
    fecha->dia = auxInt;
    do
    {
        printf("Ingrese el mes del evento: (en numero)");
        scanf("%d", &auxInt);
    }while(auxInt<1 || auxInt>12);
    fecha->mes = auxInt;
    do
    {
        printf("Ingrese el a%co del evento: ", 164);
        scanf("%d", &auxInt);
    }while(auxInt<2017);
    fecha->year = auxInt;

    do
    {
        auxInt = getFloat(&presupesto, "Ingrese el presupuesto total del evento: ", "Ingrese un numero positivo!", 0, 1000000000000000000);

    }while(auxInt == -1);

    do
    {
        auxInt = getFloat(&pagado, "Ingrese el monto de seña del evento: ", "Ingrese un valor valido!", 0, presupesto);
    }while(auxInt == -1);

    idEvento = IDEVENTO + listaEventos->len(listaEventos);
    for(i=0; i<listaEventos->len(listaEventos); i++)
    {
        auxevent = listaEventos->get(listaEventos, i);
        if(idEvento == auxevent->idEvento)
        {
            idEvento++;
        }
    }

    if(pagado>=presupesto)
    {
        estado = 1;
    }
    else
    {
        estado = 0;
    }

    miEvento = newEventoParametrizado(fecha, tipoEvento, presupesto, pagado, invitados, estado, idEvento);
    if(miEvento!=NULL)
    {
        auxInt = listaEventos->add(listaEventos, miEvento);
        if(auxInt!=-1)
        {printf("\nEvento registrado correctamente!\n");
        }
        else
        {
        printf("\nSe produjo un error no se pudo guadar el evento!\n");
        }
    }
    else
    {
        printf("\nSe produjo un error no se pudo guadar el evento!\n");
    }
}

void printEventos(ArrayList* lista)
{
    int i;
    eEvento* event = newEvento();
    printf("ID\tTIPO EVENTO\tPRESUPUESTO\n");
    for(i=0; i< lista->len(lista); i++)
    {
        event = lista->get(lista, i);
        printf("%d\t%s\t%.2f\n", event->idEvento, event->tipoEvento, event->presupesto);
    }
}

void borrarEvento(ArrayList* listaEventos)
{
    eEvento* event = newEvento();
    int auxInt, i, flag = 0;
    char auxChar;

    printf("Escriba el id del evento a borrar:\n");
    printEventos(listaEventos);
    printf("\n");
    scanf("%d", &auxInt);

    for(i=0; i<listaEventos->len(listaEventos); i++)
    {
        event = listaEventos->get(listaEventos, i);
        if(event->idEvento == auxInt)
        {
            printf("\nEsta seguro de borrarlo? (s/n) ");
            auxChar = getche();
            if(auxChar == 's' || auxChar == 'S')
            {
                auxInt = listaEventos->remove(listaEventos, i);
                if(auxInt == 0)
                {
                    printf("Borrado correctamente.\n");
                }
                else
                {
                    printf("No se pudo borrar.\n");
                }
            }
            else
            {
                printf("Cancelado!\n");
            }

            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("Id no encontrado!\n");
    }


}

void modificarEvento(ArrayList* lista)
{
    eEvento* event = newEvento();
    int auxInt, i, flag = 0, idAux;
    float nuevaSena;
    char auxChar;

    printf("Escriba el id del evento a modificar:\n");
    printEventos(lista);
    printf("\n");
    scanf("%d", &idAux);

    for(i=0; i<lista->len(lista); i++)
    {
        event = lista->get(lista, i);
        if(event->idEvento == idAux)
        {
            printf("\nElija que desea moficar:\n1- Fecha\n2- Invitados\n3- Se%ca\n", 164);
            scanf("%d", &auxInt);
            switch(auxInt)
            {
                case 1:
                    do
                    {
                        auxInt = getInt(&event->fecha.dia, "Ingrese el nuevo dia: ", "Ese numero no es un dia! Reingrese: ", 1, 31);
                    }while(auxInt == -1);
                    do
                    {
                        auxInt = getInt(&event->fecha.mes, "Ingrese el nuevo mes: (en numero) ", "Ese numero no es un mes! Reingrese: ", 1, 12);
                    }while(auxInt == -1);
                    do
                    {
                        auxInt = getInt(&event->fecha.year, "Ingrese el nuevo año: ", "Ese numero no es un año valido! Reingrese: ", 2016, 2100);
                    }while(auxInt == -1);

                    break;
                case 2:
                    do
                    {
                        auxInt = getInt(&event->invitados, "Ingrese la nueva cantidad de invitados: ", "Cantidad entre 30 a 350! Reingrese: ", 30, 350);
                    }while(auxInt == -1);
                    break;
                case 3:
                    do
                    {
                        auxInt = getFloat(&nuevaSena, "Ingrese lo que desea sumar al monto pagado: ", "Error! Reingrese: ", 0, event->presupesto);
                    }while(auxInt == -1);
                    event->pagado += nuevaSena;
                    if(event->pagado >= event->presupesto)
                    {
                        event->estado = 1;
                    }
                    break;
                default:
                    printf("Error! Cancelado!\n");
                    break;

            }

            printf("Esta seguro de hacer ese cambio? (s/n) ");

            auxChar = getche();
            if(auxChar == 's' || auxChar == 'S')
            {
                auxInt = lista->set(lista, i, event);
                if(auxInt == 0)
                {
                    printf("Modificado correctamente.\n");
                }
                else
                {
                    printf("No se pudo modificar.\n");
                }
            }
            else
            {
                printf("Cancelado!\n");
            }

            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("Id no encontrado!\n");
    }
}


void informes(ArrayList* lista)
{
    int opcion, i;
    eEvento* event = newEvento();
    printf("Seleccione que desea ver: \n1- Eventos registrados.\n2- Eventos se%cados.\n3- Eventos pagados.\n", 164);
    scanf("%d", &opcion);
    switch(opcion)
    {
        case 1:
            printf("1- Ordenados por fecha.\n2- Ordenados por tipo de evento.\n3- Ordenados por cant de invitados.\n");
            scanf("%d", &opcion);
            switch(opcion)
            {
                case 1:
                    printf("\n");
                    lista->sort(lista, ordenarPorFecha, 1);
                    printf("FECHA\tTIPO DE EVENTO\tINVITADOS\tPRESUPUESTO\tSE%cA\n", 165);
                    for(i=0; i<lista->len(lista); i++)
                    {
                        event = lista->get(lista, i);
                        printEvento(event);
                    }
                    break;
                case 2:
                    printf("\n");
                    lista->sort(lista, ordenarPorTipoEvento, 1);
                    printf("FECHA\tTIPO DE EVENTO\tINVITADOS\tPRESUPUESTO\tSE%cA\n", 165);
                    for(i=0; i<lista->len(lista); i++)
                    {
                        event = lista->get(lista, i);
                        printEvento(event);
                    }
                    break;
                case 3:
                    printf("\n");
                    lista->sort(lista, ordenarPorInvitados, 1);
                    printf("FECHA\tTIPO DE EVENTO\tINVITADOS\tPRESUPUESTO\tSE%cA\n", 165);
                    for(i=0; i<lista->len(lista); i++)
                    {
                        event = lista->get(lista, i);
                        printEvento(event);
                    }
                    break;
                default:
                    printf("Error! Cancelado!\n");
                    break;

            }
            break;
        case 2:
            printf("FECHA\tTIPO DE EVENTO\tINVITADOS\tPRESUPUESTO\tSE%cA\n", 165);
            for(i=0; i<lista->len(lista); i++)
            {
                event = lista->get(lista, i);
                if(event->estado == 0)
                {
                    printEvento(event);
                }
            }
            break;
        case 3:
            printf("FECHA\tTIPO DE EVENTO\tINVITADOS\tPRESUPUESTO\tSE%cA\n", 165);
            for(i=0; i<lista->len(lista); i++)
            {
                event = lista->get(lista, i);
                if(event->estado == 1)
                {
                    printEvento(event);
                }
            }
            break;
        default:
            printf("Error! Cancelado!\n");
            break;

    }
}


int ordenarPorInvitados(void* evento1, void* evento2)
{
    int returnAux;
    eEvento* event1 = newEvento();
    eEvento* event2 = newEvento();
    event1 = (eEvento*) evento1;
    event2 = (eEvento*) evento2;
    if(event1->invitados > event2->invitados)
    {
        returnAux = 1;
    }
    else if(event1->invitados < event2->invitados)
    {
        returnAux = -1;
    }
    else
    {
         returnAux = 0;
    }

    return returnAux;
}
int ordenarPorTipoEvento(void* evento1, void* evento2)
{
    int returnAux;
    eEvento* event1 = newEvento();
    eEvento* event2 = newEvento();
    event1 = (eEvento*) evento1;
    event2 = (eEvento*) evento2;

    returnAux = strcmp(event1->tipoEvento, event2->tipoEvento);

    return returnAux;
}
int ordenarPorFecha(void* evento1, void* evento2)
{
    int returnAux;
    eEvento* event1 = newEvento();
    eEvento* event2 = newEvento();
    event1 = (eEvento*) evento1;
    event2 = (eEvento*) evento2;
    if(event1->fecha.mes > event2->fecha.mes)
    {
        returnAux = 1;
    }
    else if(event1->fecha.mes < event2->fecha.mes)
    {
        returnAux = -1;
    }
    else
    {
         returnAux = 0;
    }

    return returnAux;
}

void printEvento(eEvento* event)
{
    printf("%d/%d/%d\t%s\t%d\t%.2f\t%.2f\n", event->fecha.dia, event->fecha.mes, event->fecha.year, event->tipoEvento, event->invitados, event->presupesto, event->pagado);
    //printf("%d/%d/%d\t%s\t%d\t\n", event->fecha.dia, event->fecha.mes, event->fecha.year, event->tipoEvento, event->invitados);

}


int parserArchivoEvento(ArrayList* lista)
{
    eEvento* event;
    eFecha* fecha = newFecha();
    char tipoEvento[100], presupesto[100], pagado[100], invitados[100], estado[100], dia[30], mes[30], year[30], id[30];
    int invit, est, idEvento;
    float pres;
    float pago;
    FILE* archivoEventos = fopen("listaeventitos.csv", "r");

    if(archivoEventos!=NULL && lista!=NULL)
    {
        fscanf(archivoEventos, "%[^,],%[^/],%[^/],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", id, dia, mes, year, presupesto, pagado, invitados, estado, tipoEvento);
        while(!feof(archivoEventos))
        {
            fscanf(archivoEventos, "%[^,],%[^/],%[^/],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", id, dia, mes, year, presupesto, pagado, invitados, estado, tipoEvento);
            idEvento = atoi(id);
            fecha->dia = atoi(dia);
            fecha->mes = atoi(mes);
            fecha->year = atoi(year);
            pres = atof(presupesto);
            pago = atof(pagado);
            invit = atoi(invitados);
            if(strcmp(estado, "true") == 0)
            {
                est = 1;
            }
            else{
                est = 0;
            }

            event = newEventoParametrizado(fecha, tipoEvento, pres, pago, invit, est, idEvento);

            if(event!=NULL)
            {
                lista->add(lista, event);
            }

        }
    }
    fclose(archivoEventos);

    return 0;
}

/*


int leerArchivo(ArrayList* lista)
{
    FILE* archivo;

    int dia, mes, year, idEvento;
    eFecha* fecha = newFecha();
    char tipoEvento[100];
    float presupesto;
    float pagado; //seña
    int invitados;
    int estado;
    char tipoEvento[100], presupesto[100], pagado[100], invitados[100], estado[100], dia[30], mes[30], year[30], id[30];

    if(fopen("listaeventitos.csv", "r") == NULL)
    {
        if(fopen("listaeventitos.csv", "w") == NULL)
        {
            printf("Error no se genero el archivo!\n");
        }
    }
    else
    {
        while(!feof(archivo))
        {
            fscanf(archivo, "%[^,],", )

            fscanf(archivoEventos, "%[^,],%[^/],%[^/],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", id, dia, mes, year, presupesto, pagado, invitados, estado, tipoEvento);


        }
    }

}


*/
