#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float numA;
    float numB;
    int flagNumA=0;
    int flagNumB=0;

    while(seguir=='s')
    {
        if(flagNumA == 0){
            printf("\n1- Ingresar 1er operando (A=x)\n");
        }
        else{
            printf("\n1- Ingresar 1er operando (A=%.2f)\n", numA);
        }

        if(flagNumB == 0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else{
            printf("2- Ingresar 2do operando (B=%.2f)\n", numB);
        }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("\nIngrese el primer operando: ");
                scanf("%f",&numA);
                flagNumA = 1;
                break;


            case 2:
                printf("\nIngrese el segundo operando: ");
                scanf("%f",&numB);
                flagNumB = 1;
                break;


            case 3:
                if(flagNumA == 0 || flagNumB == 0)
                {
                   printf("\nNo se ingresaron operandos para realizar la operacion.\n");
                }
                else{
                     mostrarResultado("\nLa suma de los números es: ",sumar(numA,numB));
                }
                break;


            case 4:
                if(flagNumA == 0 || flagNumB == 0)
                {
                    printf("\nNo se ingresaron operandos para realizar la operacion.\n");
                }
                else{
                    mostrarResultado("\nLa resta de los numeros da: ",restar(numA,numB));
                }
                break;


            case 5:
                 if(flagNumA == 0 || flagNumB == 0)
                {
                    printf("\nNo se ingresaron operandos para realizar la operacion.\n");
                }
                else{
                        if(validarDivisor(numB)==0)
                        {
                            break;
                        }
                        else{
                            mostrarResultado("\nLa division de los numeros da: ",dividir(numA,numB));
                        }
                }
                break;


            case 6:
                if(flagNumA == 0 || flagNumB == 0)
                {
                    printf("\nNo se ingresaron operandos para realizar la operacion.\n");
                }
                else{
                mostrarResultado("\nLa multiplicacion entre los numeros es: ",multiplicar(numA,numB));
                }
                break;


            case 7:
                if(flagNumA == 0)
                {
                    printf("\nNo se ingreso el operando para realizar la operacion.\n");
                }
                else{
                     if(validarFactorial(numA)==1)
                     {
                         break;
                     }
                     else{
                     printf("\nEl factorial del numero ingresado es: %lld\n",factorial(numA));
                     }

                }
                break;


            case 8:
                if(flagNumA == 0 || flagNumB == 0)
                {
                    printf("\nNo se ingresaron operandos para realizar la operacion.\n");
                }
                else{
                        calcularTodasOperaciones(numA,numB);
                }
                break;


            case 9:
                seguir = 'n';
                break;

            default:
                printf("\nIngrese una opcion valida.\n");
                break;
        }

    }

    return 0;
}
