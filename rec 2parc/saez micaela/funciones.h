//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "funciones.h"
#include "arraylist.h"

typedef struct
{
    int numero;
    char nombre[51];
    int par;
    int impar;
    int primo;

} numeroNatural;


/** \brief imprime las opciones del menu
 *
 * \param void
 * \return int  opcion elegida
 *
 */
int menu(void);

numeroNatural* newNumero();

void leerArchivo(ArrayList* lista);
void altaNumero(ArrayList* lista);
void modificarNumero(numeroNatural* numero);
int borrarNumero(numeroNatural* numero, ArrayList* lista);

int completarDatos(ArrayList* lista);

void lista1(ArrayList* lista);
void lista2(ArrayList* lista);
void printNum(numeroNatural* numero);
void esPar(numeroNatural* numero);
void esPrimo(numeroNatural* numero);
int comparaNums(void* num1, void* num2);
