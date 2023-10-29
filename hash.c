#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

int Hash(char* palabra)
{
    int hasheado = 0;
    // los strings se guardan como el string + \0 que indica que termina
    for (size_t i = 0; palabra[i] != '\0'; i++)
    {
        hasheado = hasheado + (int)palabra[i];
    }
    return hasheado;
}

void InsertIntoTable(char** tabla, char* palabra)
{
    int dondeVa = Hash(palabra);
    char* destino = tabla[dondeVa];
    strcpy(destino, palabra);
}

int main()
{
    char tabla[1000][20];

    for (size_t i = 0; i < 1000; i++)
    {
        strcpy(tabla[i], "\0");
    }

    char* nombrePeco = "peco\0";
    InsertIntoTable((char**)tabla, nombrePeco);

    char* a = tabla[423];
    printf("--%s \n", tabla[423]);


    printf("%d \n", Hash("peco"));
    printf("%d", Hash("pecos"));

    return 0;
}
