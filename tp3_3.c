#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char **nombres;
    char *buffer;

    nombres = (char**)malloc(5*sizeof(buffer));
    
    buffer = (char*)malloc(30*sizeof(char));


    for (int i = 0; i < 5; i++)
    {
        gets(buffer);
        nombres[i] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
        strcpy(nombres[i], buffer);
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("Nombre %d: ", (i+1));
        puts(nombres[i]);
    }
    

    return 0;
}