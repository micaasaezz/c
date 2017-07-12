#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "arraylist.h"
int menu()
{
    int opcion=0;

    printf("1- Altas.\n");
    printf("2- Modificar.\n");
    printf("3- Baja.\n");
    printf("4- Completar.\n");
    printf("5- Listar.\n");
    printf("6- Salir.\n");
    scanf("%d",&opcion);

    return opcion;
}
numeroNatural* newNumero()
{
    numeroNatural* retAux;
    retAux = (numeroNatural*) malloc(sizeof(numeroNatural));
    return retAux;
}
void leerArchivo(ArrayList* lista)
{
    FILE* archivo;
    numeroNatural* auxNum;
    char numero[20], nombre[51], par[2], impar[2], primo[2];

    if((archivo = fopen("datos.csv","r")) == NULL)
    {
        if((archivo = fopen("datos.csv","w")) == NULL)
        {
            printf("No se pudo generar el archivo!\n");
        }
    }
    else
    {
        fscanf(archivo, "%[^;];%[^;];%[^;];%[^;];%[^\n]",numero, nombre, par, impar, primo);
        while(!feof(archivo))
        {
            auxNum = newNumero();
            fscanf(archivo, "%[^;];%[^;];%[^;];%[^;];%[^\n]",numero, nombre, par, impar, primo);
            auxNum->numero = atoi(numero);
            strcmp(auxNum->nombre, nombre);
            auxNum->par = atoi(par);
            auxNum->impar = atoi(impar);
            auxNum->primo = atoi(primo);

            lista->add(lista, auxNum);

        }
        printf("Se cargaron %d numeros del archivo.\n", lista->len(lista));
    }

    fclose(archivo);


}

void altaNumero(ArrayList* lista)
{
    numeroNatural* auxnum = newNumero();

    printf("Ingrese el numero: ");
    scanf("%d", &auxnum->numero);
    while(auxnum->numero < 0)
    {
        printf("Ingrese numero valido: ");
        scanf("%d", &auxnum->numero);
    }
    printf("Ingrese el nombre del numero: ");
    gets(auxnum->nombre);

    auxnum->par = 0;
    auxnum->impar = 0;
    auxnum->primo = 0;

    if(lista!=NULL)
    {
        lista->add(lista, auxnum);
    }
}


void modificarNumero(numeroNatural* numero)
{
    int opcion;

    printf("1- modificar numero.\n2- modificar nombre.\n");
    scanf("%d", &opcion);

    switch(opcion)
    {
    case 1:
        printf("Ingrese el nuevo numero: ");
        scanf("%d", &numero->numero);
        while(numero->numero < 0)
        {
            printf("Ingrese numero valido: ");
            scanf("%d", &numero->numero);
        }
        break;

    case 2:
        printf("Ingrese el nuevo nombre del numero: ");
        gets(numero->nombre);
        break;
    default:
        printf("Opcion invalida, cancelado!\n");
        break;
    }

}

int borrarNumero(numeroNatural* numero, ArrayList* lista)
{
    int  auxInt=1, i;
    numeroNatural* auxNum = newNumero();

    for(i=0; i<lista->len(lista); i++)
    {
        auxNum = lista->get(lista, i);
        if(auxNum == numero)
        {
            lista->deleteArrayList(lista, numero);
            auxInt = 0;
            break;
        }
    }

    return auxInt;
}
void esPar(numeroNatural* numero)
{
    if((numero->numero % 2) == 0)
    {
        numero->par = 1;
        numero->impar = 0;
    }
    else
    {
        numero->par = 0;
        numero->impar = 1;
    }

}
void esPrimo(numeroNatural* numero)
{
    int j, auxCont=0;
    for(j=0; j<numero[i]->numero; j++)
    {
        if((numero[i]->numero % i) == 0)
        {
            auxCont++;
        }
    }
    if(auxCont>2)
    {
        numero->primo = 0;
    }
    else
    {
        numero->primo = 1;
    }
}

int completarDatos(ArrayList* lista)
{
    int retAux = 0, i;
    numeroNatural* numero = newNumero();

    if(lista != NULL)
    {
        for(i=0; i< lista->len(lista); i++)
        {
            numero = lista->get(lista, i);
            esPar(numero);
            esPrimo(numero);

            retAux++;
        }

        printf("Se cargaron datos de %d numeros correctamente.\n", retAux);
        retAux = 1;
    }

    return retAux;
}

void printNum(numeroNatural* numero)
{
    printf("%s\t%d\t%d\t%d\t%d\n", numero->nombre, numero->numero, numero->impar, numero->par, numero->primo);
}


int comparaNums(void* num1, void* num2)
{
    numeroNatural* numero1;
    numeroNatural* numero2;
    int retAux;
    numero1 = (numeroNatural*) num1;
    numero2 = (numeroNatural*) num2;
    if(numero1>numero2)
    {
        retAux = 1;
    }
    else if(numero1<numero2)
    {
        retAux = -1;
    }
    else
    {
        retAux = 0;
    }

    return retAux;
}

void lista1(ArrayList* lista)
{
    numeroNatural* numero = newNumero();
    ArrayList* nuevalista = al_newArrayList();
    int i, j;
    int contador=0;

    for(i=0; i< lista->len(lista); i++)
    {
        numero = lista->get(lista, i);
        for(j=0; j<lista->len(lista); j++)
        {
            if(numero == lista[j]->get(lista, j))
            {
                if(!( nuevalista->contains(lista, numero)))
                {
                    nuevalista->add(numero);
                }
                if(!( nuevalista->contains(lista, lista[j]->get(lista, j))))
                {
                    nuevalista->add(lista[j]->get(lista, j));
                }
            }
        }
    }

    printf("NOMBRE\tNUMERO\tIMPAR\tPAR\tPRIMO\n");
    nuevalista->sort(nuevalista, comparaNums, 1);
    for(i=0; i<nuevalista->len(nuevalista) ; i++)
    {
        numero = nuevalista->get(nuevalista, i);
        printNum(numero);
    }

    printf("\n\n1- cantidad de ceros: ");
    for(i=0; i< nuevalista->len(nuevalista); i++)
    {
        numero = nuevalista->get(nuevalista, i);
        if(numero->numero == 0)
        {
            contador++;
        }
    }
    printf("%d", &contador);

    printf("\n\n2- cantidad de pares: ");
    for(i=0; i< nuevalista->len(nuevalista); i++)
    {
        numero = nuevalista->get(nuevalista, i);
        if(numero->pares == 1)
        {
            contador++;
        }
    }
    printf("%d", &contador);

    printf("\n\n3- cantidad de impares: ");
    for(i=0; i< nuevalista->len(nuevalista); i++)
    {
        numero = nuevalista->get(nuevalista, i);
        if(numero->impar == 1)
        {
            contador++;
        }
    }
    printf("%d", &contador);

    printf("\n\n2- cantidad de primos: ");
    for(i=0; i< nuevalista->len(nuevalista); i++)
    {
        numero = nuevalista->get(nuevalista, i);
        if(numero->primo == 1)
        {
            contador++;
        }
    }
    printf("%d\n", &contador);

}
void lista2(ArrayList* lista)
{
    numeroNatural* numero = newNumero();
    numeroNatural* aux = newNumero();
    ArrayList* nuevalista = al_newArrayList();
    int i, j, flagRep = 0;


    for(i=0; i< lista->len(lista); i++)
    {
        numero = lista->get(lista, i);
        for(j=0; j<nuevalista->len(nuevalista); j++)
        {
            aux = nuevalista->get(nuevalista, j)
            if(numero->numero == aux->numero)
            {
                flagRep = 1;
                break;
            }
        }
        if(flagRep == 0)
        {
            nuevalista->add(numero);
        }

    }

    printf("NOMBRE\tNUMERO\tIMPAR\tPAR\tPRIMO\n");
    nuevalista->sort(nuevalista, comparaNums, 0);
    for(i=0; i<nuevalista->len(nuevalista) ; i++)
    {
        numero = nuevalista->get(nuevalista, i);
        printNum(numero);
    }
}
