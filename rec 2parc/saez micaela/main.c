#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "arraylist.h"

int main()
{
    char seguir = 's';
    ArrayList* lista = al_newArrayList();
    int opcion, numero,i ;

    numeroNatural* auxNum = newNumero();

    do
    {
        opcion = menu();
        switch(opcion)
        {
            case 1:
                leerArchivo(lista);
                altaNumero(lista);
                break;

            case 2:
                printf("Ingrese el numero a modificar: ");
                scanf("%d", &numero);
                for(i=0; i<lista->len(lista); i++)
                {
                    auxNum = lista->get(lista, i);
                    if(auxNum->numero == numero)
                    {
                         modificarNumero(auxNum);
                         numero = -1;
                    }
                }
                if(numero != -1){
                    printf("No se encontro ese numero!\n");
                }
                break;

            case 3:
                printf("Ingrese el numero a borrar: ");
                scanf("%d", &numero);
                for(i=0; i<lista->len(lista); i++)
                {
                    auxNum = lista->get(lista, i);
                    if(auxNum->numero == numero)
                    {
                         numero = borrarNumero(auxNum, lista);
                         if(numero == 0)
                         {
                             printf("Se borro correctamente.\n");
                             numero = -1;
                         }
                         else
                         {
                             printf("No se pudo borrar.\n");
                             numero = -1;
                         }
                    }
                }
                if(numero != -1){
                    printf("No se encontro ese numero!\n");
                }
                break;

            case 4:
                i = completarDatos(lista);
                if(i!=0)
                {
                    printf("No se pudieron completar los datos correctamente.\n");
                }
                break;

            case 5:
                printf("1- nuevo arraylist descendente.\2- nuevo arraylist descendente.\n");
                scanf("%d", &opcion);
                switch(opcion)
                {
                    case 1:
                        lista1(lista);
                        break;
                    case 2:
                        lista2(lista);
                        break;
                    default:
                        printf("Opcion incorrecta!\n");
                        break;
                }
                break;


            case 6:
                seguir = 'n';
                break;

            default:
                printf("Error opcion incorrrecta!\n");
                break;

        }
        system("pause");
        system("cls");
    }while(seguir == 's');
    return 0;
}
