#include <stdio.h>
#include <stdlib.h>


float sumar(float a,float b)
{
    float suma;
    suma = a+b;
    return suma;
}


float restar(float a,float b)
{
    float resta;
    resta = a-b;
    return resta;
}


float dividir(float dividendo,float divisor)
{
    float division;
    division = dividendo/divisor;
    return division;
}


float multiplicar(float a,float b)
{
    float producto;
    producto = a*b;
    return producto;
}


//creo que está malll
//int factorial(float a)
//{
//    int valor;
//    if(a==0)
//    {
//
//    }
//    else{
//        valor = n*factorial(n-1);
//        return valor;
//    }
//}




void mostrarResultado(char texto[],float resultado)
{
    printf("%s %.2f \n",texto, resultado);

}





int validarDivisor(float b)
{
    if(b==0)
    {
        printf("\nNo se puede dividir un numero por cero.\n");
        return 0;
    }

}


int validarFactorial(float a)
{
    if(a==0)
    {
        printf("\nEl factorial vale 1.\n");
         return 1;
    }
    else if(a<0){
            printf("\nNo se puede calcular el factorial de un numero negativo.\n");
             return 1;
    }
    else if(a-(int)a > 0)
    {
        printf("\nNo se puede calcular el factorial de un numero con decimales.\n");
         return 1;
    }

}

long long int factorial(int a)
{
    long long int factor;

    if(a == 0)
    {
        return 1;
    }
    else
    {
        factor = a*factorial(a-1);
        return factor;
    }
}







void calcularTodasOperaciones(float a,float b)
{
    mostrarResultado("\nLa suma de los números es: ",sumar(a,b));
    mostrarResultado("\nLa resta de los numeros da: ",restar(a,b));

    if(validarDivisor(b)==0)
    {
    }
    else{
        mostrarResultado("\nLa division de los numeros da: ",dividir(a,b));
    }

    mostrarResultado("\nLa multiplicacion entre los numeros es: ",multiplicar(a,b));

    if(validarFactorial(a)==1)
    {
    }
    else{
        printf("\nEl factorial del numero ingresado es: %lld\n",factorial(a));
    }

}







