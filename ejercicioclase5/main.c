#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char nombre[30], apellido[30], nombreApellido[60];
    int i;

    printf("Ingrese su nombre: ");
    gets(nombre);

    printf("Ingrese su apellido: ");
    gets(apellido);


//    nombre[0] = toupper(nombre[0]);
//    apellido[0] = toupper(apellido[0]);

    strcat(nombre, " ");
    strcat(nombreApellido, nombre);
    strcat(nombreApellido, apellido);

    nombreApellido[0] = toupper(nombreApellido[0]);

    for(i=0; i<strlen(nombreApellido); i++)
    {
        if(nombreApellido[i]==' ')
        {
            nombreApellido[i+1] = toupper(nombreApellido[i+1]);
        }
    }


    puts(nombreApellido);
    system("color d0");
    printf("                       ,;;;,  ,;;;,\n");
    printf("                      ;;;;;;,;;;;;;;\n");
    printf("              .:::. .::::;;;;;;;;;;;'\n");
    printf("            :::::::.:::::::;;;;;;;;;'\n");
    printf("            :::::::::::::::;;;;;;;'\n");
    printf("            ':::::::::::::';;;;;'\n");
    printf("              ':::::::::'   ';'\n");
    printf("                 ':::::'\n");
    printf("                   ':'\n");

    return 0;
}
