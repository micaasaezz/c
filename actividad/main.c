#include <stdio.h>
#include <stdlib.h>

//    1- Cantidad de n�meros pares.
//    2- Cantidad de n�meros impares.
//    3- Sumatoria de todos los n�meros impares.
//    4- Promedio de todos los n�meros.
//    5- El n�mero mayor ingresado.
//    6- El n�mero impar menor ingresado.
//    7- Cu�ntos n�meros est�n entre 3-15, entre 16-29 y 30 o m�s.
//    8- Dada la sumatoria de todos los n�meros impares (item 3) determinar:
//    a- La sumatoria de todos los n�meros que le anteceden (incluyendolo). Utilizar FOR.
//    b- Mostrar todos los n�meros hasta la unidad. Utilizar FOR.


int main()
{
    char seguir;
    int numero;
    int contadorPares=0;
    int contadorImpares=0;
    int sumanumImpares=0;
    int cantnumeros=0;
    int sumanumeros=0;
    float promedio;
    int max;
    int menorImpar;
    int cont3a15=0;
    int cont16a29=0;
    int contmas30=0;
    int i; // todos los numeros anteriores a sumanumimpares.
    int sumai=0; // suma de todos los numeros anteriores a sumanumimpares.

    do{
        printf("\nIngrese un numero positivo." );
        scanf("%d" , &numero);

        while(numero<=0)
        {
            printf("Ingrese un numero POSITIVO." );
            scanf("%d" , &numero);
        }

        if(numero%2==0)
        {
            contadorPares++;
        }
        else{
            contadorImpares++;
            sumanumImpares = sumanumImpares+numero;

            if(cantnumeros==0)
            {
                menorImpar = numero;
            }
            else{
                if(numero<menorImpar){
                    menorImpar = numero;
                }
            }
        }


        if(cantnumeros==0)
        {
            max = numero;
        }
        else{
            if(numero>max)
            {
                max = numero;
            }
        }

        if(numero>2 && numero<16)
        {
            cont3a15++;
        }
        else{
            if(numero<30)
            {
                cont16a29++;
            }
            else{
                contmas30++;
            }
        }

        for(i=0 ; i<sumanumImpares ; i++)
        {
            sumai+=i;
        }

        cantnumeros++;

        printf("Desea seguir?");
        seguir = tolower(getche());
        //scanf("%d" , &seguir);
    }while(seguir == 's');


    promedio = (float)sumanumeros/cantnumeros;
    printf("\nEl promedio de numeros es %f" , promedio);
    printf("\nLa cantidad de numeros pares es %d" , contadorPares);
    printf("\nLa cantidad de numeros impares es %d" , contadorImpares);
    printf("\nLa sumatoria de todos los n�meros impares es %d" , sumanumImpares);
    printf("\nEl El mayor numero ingresado es %d" , max);
    printf("\n El menor n�mero impar  ingresado es %d" , menorImpar);
    printf("\nN�meros que est�n entre 3-15: %d" , cont3a15);
    printf("\nN�meros que est�n entre 16-29: %d" , cont16a29);
    printf("\nN�meros 30 o m�s: %d" , contmas30);
    printf("\nLa sumatoria de todos los n�meros que le anteceden a la cantidad de numeros impares es: %d" , sumai);
    printf("\nN�meros hasta la cantidad de numeros impares son: %d", i);

    return 0;
}
