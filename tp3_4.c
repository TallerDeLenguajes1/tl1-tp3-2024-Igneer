#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misFunciones.h"

float costoTotal(int cant, float precio)
{
    return(cant*precio);
}

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct Producto Producto;
struct Producto 
{
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}; // CONSULTAR SI PUEDO HACERLO DIRECTAMENTE ASÍ --- NO FUNCIONA BIEN SI LO HAGO ASI

typedef struct Cliente Cliente;
struct Cliente
{
    int ClienteID; // Numerado en el ciclo iterativo
    //char *NombreCliente; // Ingresado por usuario
    char **NombreCliente;
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    struct Producto *Productos //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
};

int main()
{
    int cantidad;
    puts("----------------Gestion de Clientes----------------");
    printf("Ingrese la cantidad de clientes a ingresar: ");
    scanf("%d", &cantidad);

    char *buffer = (char *)malloc(30 * sizeof(char));

    Cliente *clientes = (Cliente*)malloc(cantidad * sizeof(Cliente));

    int cantidadNombres;
    
    for (int i = 0; i < cantidad; i++)
    {
        clientes[i].ClienteID = i+1;


        printf("Ingrese la cantidad de nombres del cliente: ");
        scanf("%d", &cantidadNombres);
        clientes[i].NombreCliente = (char*)malloc(cantidadNombres*sizeof(char*));
        for (int k = 0; k < cantidadNombres; k++)
        {
            printf("Ingrese el nombre %d: ", k);
            fflush(stdin);
            gets(buffer);
            clientes[i].NombreCliente[k] = (char*)malloc((strlen(buffer)+1)*sizeof(char)); 
            strcpy(clientes[i].NombreCliente[k], buffer);
        }
        

        clientes[i].CantidadProductosAPedir = generarNumAleatorio(1, 5);
        clientes[i].Productos = (Producto*)malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID = j+1;
            clientes[i].Productos[j].Cantidad = generarNumAleatorio(1, 10);
            strcpy(buffer, TiposProductos[generarNumAleatorio(0,4)]);
            clientes[i].Productos[j].TipoProducto = (char*)malloc((strlen(buffer)+1)*sizeof(char));
            strcpy(clientes[i].Productos[j].TipoProducto, buffer);
            clientes[i].Productos[j].PrecioUnitario = (float)generarNumAleatorio(10,100);
        }
    }

    int suma;
    for (int i = 0; i < cantidad; i++)
    {
        suma = 0;
        printf("Cliente %d : \n", clientes[i].ClienteID);
        for (int k = 0; k < cantidadNombres; k++)
        {
            printf("- Nombre: %s\n", clientes[i].NombreCliente[k]);
        }
        
        printf("- Cantidad de productos: %d\n", clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("Producto %d\n", clientes[i].Productos[j].ProductoID);
            printf("Cantidad del producto %d: %d unidades\n", clientes[i].Productos[j].ProductoID, clientes[i].Productos[j].Cantidad);
            printf("Tipo de producto: %s\n", clientes[i].Productos[j].TipoProducto);
            printf("Precio Unitario: %f\n", clientes[i].Productos[j].PrecioUnitario);
            printf("Total a pagar: %.2f\n", costoTotal(clientes[i].Productos[j].Cantidad, clientes[i].Productos[j].PrecioUnitario));
            suma += costoTotal(clientes[i].Productos[j].Cantidad, clientes[i].Productos[j].PrecioUnitario);
        }
        printf("Total a pagar del Cliente %d: %d\n", clientes[i].ClienteID, suma);
    }
    
    
    
    return 0;
}
