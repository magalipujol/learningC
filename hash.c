#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

int Hash(char* palabra)
{
    int hasheado = 0;
    for (size_t i = 0; palabra[i] != '\0'; i++)
    {
        hasheado = hasheado + (int)palabra[i];
    }
    return hasheado;
}

void main()
{
    // char tabla[1000][20];

    printf("%d \n", Hash("peco"));
    printf("%d", Hash("pecos"));
}
