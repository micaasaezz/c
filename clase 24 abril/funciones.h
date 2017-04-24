#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int idSerie;
    char titulo[50];
    int temporadas;
    char genero[50];
    int estado;

}eSerie;

typedef struct
{
    int idCliente;
    int nombre[50];
    int idSerie;
    int estado;

}eCliente;

typedef struct
{
    int idSerie;
    int contador;

}eContador;

void cargarSeries(eSerie series[]);
void cargarClientes(eCliente clientes[]);
void mostrarSerie(eSerie series[], int tam);
void mostrarCliente(eCliente cliente[], eSerie serie[], int tamS, int tamC);
void mostarSeriesConClientes(eSerie serie[], eCliente cliente[], int tamS, int tamC);
int clientesVenTBBT(eSerie serie[], int tamS);
void inicializarContador(eSerie serie[], int tamSyC, eContador cont[]);
void serieMenosPopular(eSerie serie[], int tamS, eCliente cliente[], int tamC, eContador cont[]);

