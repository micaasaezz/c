#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void cargarSeries(eSerie series[])
{
   int idSerie[5]={100,101,102,103,104};
    int estado[5]={1,1,1,1,1};
     char titulo[5][30]={"TBBT","BB","GOT","AHS","SCD"};
    int temporadas[5]={9,7,7,6,1};
    char genero[5][30]={"Comedia","Policial","Ciencia Ficcion","Terror","Comedia"};

    int i;
     for(i=0; i<5;i++)
    {
        series[i].idSerie = idSerie[i];
        strcpy(series[i].titulo, titulo[i]);
        series[i].estado = estado[i];
        series[i].temporadas = temporadas[i];
        strcpy(series[i].genero, genero[i]);
    }

}
void cargarClientes(eCliente clientes[])
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombres[10][30]={"juan","maria","pedro","luis","romina","jose","andrea","patricia","luciano","camila"};
    int estado[10]={1,1,1,1,1,1,1,1,1,1};
    int idSerie[10]={100,100,101,103,103,101,102,103,100,102};
    int i;

    for(i=0; i<10;i++)
    {
        clientes[i].idCliente = id[i];
        strcpy(clientes[i].nombre, nombres[i]);
        clientes[i].estado = estado[i];
        clientes[i].idSerie = idSerie[i];
    }

}

void mostrarSerie(eSerie serie[], int tam)
{
    int i;
    printf("SERIES: \n\n");
    printf("ID\tTITULO\tTEMPORADAS\tGENERO\n\n");
    for(i=0; i<tam; i++)
    {
        printf("%d\t%s\t\t%d\t%s\n", serie[i].idSerie, serie[i].titulo, serie[i].temporadas, serie[i].genero);

    }
}

void mostrarCliente(eCliente cliente[], eSerie serie[], int tamS, int tamC)
{
    int i,j;
    char titulo[50];
    printf("\nCLIENTES: \n");
    printf("\nID CLIENTE\tNOMBRE\t\tID SERIE\n\n");

    for(i=0; i<tamC; i++) //recorre los clientes
    {
        for(j=0; j<tamS; j++) //recorre las series
        {
            if(cliente[i].idSerie==serie[j].idSerie)
            {
                strcpy(titulo, serie[j].titulo);
                break;
            }

        }

        printf("%d\t\t%s\t\t%s\n", cliente[i].idCliente, cliente[i].nombre, titulo);
    }

}

void mostarSeriesConClientes(eSerie serie[], eCliente cliente[], int tamS, int tamC)
{
    int i, j;

    printf("\n\nSERIE: \t\t CLIENTES:\n");

    for(i=0; i<tamS;i++)
    {
        printf("%s\t\t\n", serie[i].titulo);

        for(j=0; j<tamC; j++)
        {
             if(cliente[j].idSerie == serie[i].idSerie)
             {
                printf("\t\t   %s \n", cliente[j].nombre);
             }
        }
        printf("\n");
    }



}

int clientesVenTBBT(eSerie serie[], int tamS)
{
    int cont=0;
    int i;

    for(i=0; i<tamS; i++)
    {
        if(serie[i].titulo == "TBBT")
        {
            cont++;
        }
    }
    printf("La cantidad de personas que ven The Big Bang Theory es: %d\n", cont);
}

void inicializarContador(eSerie serie[], int tamSyC, eContador cont[])
{
    int i;
    for(i=0; i<tamSyC; i++)
    {
        strcpy(cont[i].idSerie, serie[i].idSerie);
        cont[i].contador = 0;
    }
}
void serieMenosPopular(eSerie serie[], int tamS, eCliente cliente[], int tamC, eContador cont[])
{
    int i, j;
    char menosVista[50];

    for(i=0; i<tamC; i++)
    {
        for(j=0; j<tamS;j++)
        {
            if(cliente[i].idSerie == serie[i].idSerie)
            {
                cont[i].contador++;
            }
        }
    }
    printf("La serie menos vista es: %s", menosVista);
}


void iniciareClienteSerie(eSerie serie[], eCliente cliente[], int tamSyC, eClienteSerie clienteSerie[])
{
    int i;
    for(i=0; i<tamSyC; i++)
    {
       clienteSerie[i].idSerie = serie[i].idSerie;
       clienteSerie[i].idCliente = cliente[i].idCliente;
    }
}
