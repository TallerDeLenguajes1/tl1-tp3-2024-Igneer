#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "misFunciones.h"
#define ANIOS 5
#define MESES 12


int main()
{
    
    srand(time(NULL)); 

    int produccion[ANIOS][MESES], i, j;

    //a)
    for(i = 0; i < ANIOS; i++)
    {
        for (j = 0; j < MESES; j++)
        {
            produccion[i][j] = generarNumAleatorio(10000, 50000);
        }
    }

    //b)
    printf("Matriz :\n");
    for(i = 0; i < ANIOS; i++)
    {
        for(j = 0; j < MESES; j++)
        {
            printf("%d ", produccion[i][j]);
        }
        printf("\n");
    }

    //c)
    float promedio = 0;

    for(i = 0; i < ANIOS; i++)
        {
            for (j = 0; j < MESES; j++)
            {
                promedio += produccion[i][j];
            }
            promedio = (float)promedio/12; 
            printf("Promedio de ventas del anio %d: %.2f\n", (i+1), promedio);
        }
    

    return 0;
}