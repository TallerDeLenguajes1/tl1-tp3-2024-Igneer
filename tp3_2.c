#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "misFunciones.h"
#define M = 5
#define N = 12


int main()
{
    
    srand(time(NULL)); 

    int produccion[M][N];

    //a)
    for(int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            produccion[i][j] = generarNumAleatorio(10000, 50000);
        }
    }

    //b)
    for(int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", produccion[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}