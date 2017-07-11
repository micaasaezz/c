#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

typedef struct
{
    int dia;
    int mes;
    int year;

} eFecha;

typedef struct
{
    int idEvento;
    eFecha fecha;
    char tipoEvento[100];
    float presupesto;
    float pagado; //seña
    int invitados;
    int estado; // 1 pagado / 0 señado

} eEvento;



int menu(void);

int getInt(int* input,char message[],char errorMessage[], int lowLimit, int hiLimit);
int getString(char* input,char message[],char errorMessage[], int lowLimit, int hiLimit);
int getFloat(float* input,char message[],char errorMessage[], float lowLimit, float hiLimit);

eFecha* newFecha();
eEvento* newEvento();
eEvento* newEventoParametrizado(eFecha* fecha, char tipoEvento[], float presupuesto, float pagado, int invitados, int estado, int idEvento);

int tiposEvento();

void nuevoEvento(ArrayList* listaEventos);
void borrarEvento(ArrayList* listaEventos);

void printEventos(ArrayList* lista);

void modificarEvento(ArrayList* lista);
void informes(ArrayList* lista);

int ordenarPorInvitados(void* evento1, void* evento2);
int ordenarPorTipoEvento(void* evento1, void* evento2);
int ordenarPorFecha(void* evento1, void* evento2);

void printEvento(eEvento* evento);

int parserArchivoEvento(ArrayList* lista);

int leerArchivo(ArrayList* lista);
