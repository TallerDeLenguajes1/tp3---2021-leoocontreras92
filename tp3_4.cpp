#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>


struct producto
{
    int productoID;
    int cantidad;
    char *tipoProducto;
    float precioUnitario;
};

typedef struct producto producto;

struct cliente 
{
    int clienteID;
    char *nombreCliente;
    int cantidadProductosAPedir;
    producto *productos;
};

typedef struct cliente cliente;

float calcularPrecioProd(producto **pProd, int cant);

int main()
{

    srand(time(NULL));
    char tiposProductos[5][20]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int cantClientes,control1, cantProd;
    char nombre[100];
    

    do
    {
        control1=0;
        printf("Ingrese la cantidad de clientes: ");
        scanf("%d",&cantClientes);
        fflush(stdin);
        if((cantClientes<=0)||(cantClientes>=6))
        {
        control1=1;
        printf("\nCantidad incorrecta. Debe ingresar entre 1 y 5 clientes\n\n");

        }
    }
    while(control1==1);

    cliente *pCliente = (cliente*)malloc(sizeof(cliente)*cantClientes);
   

    
    printf("\n------------- Clientes --------------------\n");

    for (int i = 0; i < cantClientes; i++)
    {
       pCliente[i].clienteID = i+1;
        printf("\ningrese el nombre del %d cliente: ",i+1);
        gets(nombre);

        fflush(stdin);

        pCliente[i].nombreCliente=nombre;
        pCliente[i].cantidadProductosAPedir = ((rand()%4)+1);

        printf("\nCliente n %d: ",i+1);
        printf("\nNonbre del cliente: %s",pCliente[i].nombreCliente);
        printf("\nCantidad de productos: %d", pCliente[i].cantidadProductosAPedir);
         printf("\n-----------------------\n");
        printf("\nProductos solicitados: \n");
        
        producto *pProd = (producto*)malloc(sizeof(producto) * pCliente[i].cantidadProductosAPedir);
        cantProd = pCliente[i].cantidadProductosAPedir;

        for (int j = 0; j < cantProd; j++)
        {
            pProd[j].productoID = j+1;
            pProd[j].cantidad = ((rand()%9)+1);

            int x = ((rand()%4)+1);

            pProd[j].tipoProducto = tiposProductos[x];
            pProd[j].precioUnitario = (float)((rand()%90)+10);

            printf("\nProducto n %d:\n",j+1);
            printf("Tipo de producto: %s\n",pProd[j].tipoProducto);
            fflush(stdin);
            printf("Cantidad de unidades: %d\n",pProd[j].cantidad);
            printf("Precio por unidad: %.2f\n",pProd[j].precioUnitario);
        }

        printf("\n---------------------------------------------\n");
        printf("\n---------------------------------------------\n");

        float precioProd = calcularPrecioProd(&pProd, cantProd);
       if(precioProd!=0){printf("%.2f\n",precioProd);} 
        printf("\n---------------------------------------------\n");

        free(pProd);

    }

    


    free(pCliente);
      
    printf("\n------------- Fin del Programa --------------\n");

    getchar();
    return 0;
}

float calcularPrecioProd(producto **pProd, int cant){
    producto *aux = *pProd;
    int i =0,cond = 0;
    float prec=0,precTotal=0;
    char producto1[50];
    printf("Ingrese el tipo de producto al que desea calcularle el costo total: ");
    gets(producto1);
    fflush(stdin);
    producto1[0] = toupper(producto1[0]); //corrige error de mayusculas
    for (int i = 0; i < cant; i++)
    {
        if(strcmp(producto1,aux[i].tipoProducto)==0)
        {
            prec = aux[i].cantidad * aux[i].precioUnitario;
            precTotal = precTotal + prec;
            cond = 1;
        }

    }
    if(cond ==1)
    {
        printf("\nEl precio total del producto %s es : ",producto1);
    }
    else
    {
        printf("\nEl producto seleccionado no existe\n");
    }


    return(precTotal);
}

