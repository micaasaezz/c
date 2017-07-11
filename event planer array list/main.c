#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include "funciones.h"

int main()
{
    int opcion;
    char seguir = 's';
    ArrayList* misEventos = al_newArrayList();

    parserArchivoEvento(misEventos);



    printf("Recepciones Carill%cn.\n", 162);

    while(seguir == 's')
    {
        opcion = menu();

        switch(opcion)
        {
            case 1: //agregar
                nuevoEvento(misEventos);
                break;

            case 2: //borrar
                if(misEventos->len(misEventos)<1)
                {
                    printf("No hay eventos para borrar!\n");
                }
                else
                {
                    borrarEvento(misEventos);
                }
                break;

            case 3: //modificar
                if(misEventos->len(misEventos)<1)
                {
                    printf("No hay eventos para modificar!\n");
                }
                else
                {
                    modificarEvento(misEventos);
                }
                break;

            case 4: //informes
                if(misEventos->len(misEventos)<1)
                {
                    printf("No hay eventos para mostrar!\n");
                }
                else
                {
                    informes(misEventos);
                }
                break;

            case 5: //salir
                seguir = 'n';
                break;

            default:
                printf("Opcion no valida!\n");
                break;
        }
        system("pause");
        system("cls");

    }

    return 0;
}
