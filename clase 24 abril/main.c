#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/*
2- mostrar cada uno
3- mostrar clientes con su serie
4- por cada serie los clientes que la estan viendo
5- todos los clientes que ven TBBT (100)
6- La serie menos popular

Crear una cuarta estructura que permita relacionar un cliente con una serie, de esta manera podremos obtener una relacion
muchos a muchos (Un cliente que ve muchas series)

7- Todas las series que ven los clientes de nombre "Juan"
*/


int main()
{
    eSerie serie[5];
    cargarSeries(serie);

    eContador cont[5];


    eCliente cliente[10];
    cargarClientes(cliente);

    mostrarSerie(serie, 5);
    printf("\n____________________________________________\n");
    mostrarCliente(cliente, serie, 5, 10);

    printf("\n____________________________________________\n");
    mostarSeriesConClientes(serie, cliente, 5, 10);

    int contTBBT = clientesVenTBBT(serie, 5);


    return 0;
}
