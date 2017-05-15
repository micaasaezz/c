#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(int* input,char message[],char errorMessage[], int lowLimit, int hiLimit)
{
    int respuesta = 0;
    int pudoLeer;

    if(input == NULL)
    {
        respuesta = -1;
        return respuesta;
    }
    fflush(stdin);
    printf("%s", message);
    pudoLeer = scanf("%d", input);
    if(pudoLeer == 0)
    {
        respuesta = -1;
    }
    else if(*input > hiLimit || *input < lowLimit)
    {
        printf("%s", errorMessage);
        respuesta = -1;
    }

    return respuesta;
}

int getFloat(float* input,char message[],char errorMessage[], float lowLimit, float hiLimit)
{
    int respuesta = 0;
    int pudoLeer;

    if(input == NULL)
    {
        respuesta = -1;
        return respuesta;
    }
    fflush(stdin);
    printf("%s", message);
    pudoLeer = scanf("%f", input);
    if(pudoLeer == 0)
    {
        respuesta = -1;
    }
    else if(*input > hiLimit || *input < lowLimit)
    {
        printf("%s", errorMessage);
        respuesta = -1;
    }

    return respuesta;

}


int getChar(char* input,char message[],char errorMessage[], char lowLimit, char hiLimit)
{
    int respuesta = 0;
    int pudoLeer;

    if(input == NULL)
    {
        respuesta = -1;
        return respuesta;
    }
    fflush(stdin);
    printf("%s", message);
    pudoLeer = scanf("%c", input);
    if(pudoLeer == 0)
    {
        respuesta = -1;
    }
    else if(*input > hiLimit || *input < lowLimit)
    {
        printf("%s", errorMessage);
        respuesta = -1;
    }

    return respuesta;
}


int getString(char* input,char message[],char errorMessage[], int lowLimit, int hiLimit)
{
    int respuesta = 0;
    int pudoLeer;

    if(input == NULL)
    {
        respuesta = -1;
        return respuesta;
    }

    printf("%s", message);
    fflush(stdin);
    pudoLeer = scanf("%s", input);
    if(pudoLeer == 0)
    {
        respuesta = -1;
    }
    else if(strlen(input) > hiLimit || strlen(input) < lowLimit)
    {
        printf("%s", errorMessage);
        respuesta = -1;
    }

    return respuesta;
}
