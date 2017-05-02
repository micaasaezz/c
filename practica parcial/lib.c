#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

void cargarAbonados(eAbonado abonados[], int tamA)
{
    int idAbonado[5]= {1,2,3,4,5};
    char nombre[5][50]= {"jose","luisa","maria","jorge","luis"};
    char apellido [5][50]= {"Perez","Lopez","Gimenez","Ruiz","Mornan"};
    int flagEstado[5]= {1,1,1,1,1};
    int i;

    for(i=0; i<tamA; i++)
    {
        abonados[i].idAbonado=idAbonado[i];
        abonados[i].flagEstado=flagEstado[i];
        strcpy(abonados[i].nombre, nombre[i]);
        strcpy(abonados[i].apellido, apellido[i]);
    }
}


void iniciarReclamos(eReclamo reclamo[], int tamR)
{
    int i;

    for(i=0; i<tamR; i++)
    {
        reclamo[i].estado = INDETERMINADO;
        reclamo[i].flagEstado = DISPONIBLE;
    }
}


int crearReclamo(sReclamo reclamos[] , int tamR, int , sAbonado abonados[], int tamA)
{

}
