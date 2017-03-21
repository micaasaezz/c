#include <stdio.h>
#include <stdlib.h>

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
    int sumai=0 // suma de todos los numeros anteriores a sumanumimpares.

    do{
        printf("Ingrese un numero." );
        scanf("%d" , &numero);

        while(numero<0)
        {
            printf("Ingrese un numero." );
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
            printf("\nLos números hasta la unidad son %d\n" , i');
        }



        cantnumeros++;

        printf("Desea seguir?");
        scanf("%d" , &seguir);
    }while(seguir == 's');

    promedio = (float)sumanumeros/cantnumeros;
    printf("\nEl promedio de numeros es %f" , promedio);

    printf("\nLa cantidad de numeros pares es %d" , contadorPares);
    printf("\nLa cantidad de numeros impares es %d" , contadorImpares);
    printf("\nLa sumatoria de todos los números impares es %d" , sumanumImpares);
    printf("\nEl El mayor numero ingresado es %d" , max);
    printf("\n El menor número impar  ingresado es %d" , menorImpar);
    printf("\nNúmeros que están entre 3-15: %d" , cont3a15);
    printf("\Números que están entre 16-29: %d" , cont16a29);
    printf("\nNúmeros 30 o más: %d" , contmas30);
    printf("\n La sumatoria de todos los números que le anteceden a la cantidad de numeros impares es: %d" , sumai);
    printf("\n números hasta la cantidad de numeros impares son: %d , ")


    return 0;
}
