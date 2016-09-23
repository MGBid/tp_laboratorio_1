#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/** \brief Presenta al usuario un menu de opciones para que elija la acción a realizar.
 *  \param No recibe
 *  \return El valor elegido por el usuario.
 */

int menuOpciones()
{
    int seleccion;

    printf("\n\n        *- Menu de opciones -*\n\n");
    printf("  * 1-  Agregar una persona\n  * 2-  Borrar una persona\n  * 3-  Imprimir lista ordenada por nombre");
    printf("\n  * 4-  Imprimir grafico de edades\n  * 5-  Salir\n");
    printf("\n\n\tSeleccione una de las opciones: ");
    scanf("%d",&seleccion);

    return seleccion;
}

/**\brief Inicializa un array con el valor recibido
 * \param lista Es el array a ser inicializado
 * \param arrayLenght Indica la logitud del array
 * \param valor Es el valor que sera cargado en cada posición
 * \return void
 */
void initArray(EPersona lista[],int arrayLenght,int valor)
{
    int i;

    for(i=0; i<arrayLenght; i++)
    {
        lista[i].estado=valor;
    }
}

/**\brief Verifica si el valor recibido contiene solo letras
 * \param strinG Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 */
 int isOnlyLetters(char strinG[])
{
    int i=0;

    while(strinG[i]!='\0')
    {
        if((strinG[i]!=' ') && (strinG[i]<'a' || strinG[i]>'z') && (strinG[i]<'A' || strinG[i]>'Z'))
        {
             return 0;
        }
        i++;
    }
    return 1;
}
/**\brief Verifica si el valor recibido es numérico
 * \param strinG Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 */
int isOnlyNumber(char strinG[])
{
    int i=0;

    while(strinG[i]!='\0')
    {
        if(strinG[i]<'0' || strinG[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/**\brief Solicita un texto al usuario y lo devuelve
 * \param message Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char message[],char input[])
{
    printf("%s",message);
    scanf("%s",input);
}

/**\brief Solicita un texto al usuario y lo devuelve
 * \param message Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetters(char message[],char input[])
{
    char auxiliar[256];

    getString(message,auxiliar);
    if(isOnlyLetters(auxiliar))
    {
        strcpy(input,auxiliar);
        return 1;
    }
    return 0;
}

/**\brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumbers(char message[],char input[])
{
    char auxiliar[256];

    getString(message,auxiliar);
    if(isOnlyNumber(auxiliar))
    {
        strcpy(input,auxiliar);
        return 1;
    }
    return 0;
}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param arrayLenght es la longitud del array
 * @param valor es el valor a hallar para saber que esta libre
 * @return el primer indice disponible si lo halla o -1 si no lo encuentra
 */
 int obtenerEspacioLibre(EPersona lista[],int arrayLenght,int valor)
{
    int i;

    for(i=0;i<arrayLenght;i++)
    {
        if(lista[i].estado==valor)
        {
            return i;
        }
    }
    return -1;
}

/**Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[],int arrayLenght,int dni )
{
    int index=-1;
    int i;
    for(i=0;i<arrayLenght;i++)
    {
        if(lista[i].dni==dni)
        {
            index=i;
            break;
        }
    }
    return index;
}

/** \brief Compara dos arrays y los ordena alfabeticamente para listarlos
 *  \param unaPersona Array a ser evaluado para ordenar
 *  \return void
 *
 */
 void listar(EPersona lista[],int lenght)
 {
     int i,j;
     EPersona auxiliarLista;

     for(i=0; i<lenght-1;i++)
     {
         for(j=i+1; j<lenght; j++)
         {
             if(lista[j].estado!=1)
             {
                 if(strcmp(lista[i].nombre,lista[j].nombre)>0)
                 {
                     auxiliarLista=lista[i];
                     lista[i]=lista[j];
                     lista[j]=auxiliarLista;
                 }
             }
         }
     }
     for(i=0; i<lenght; i++)
     {
         if(lista[i].estado==0)
         {
             printf("\n%s -- %d -- %d -- \n",lista[i].nombre,lista[i].edad,lista[i].dni);
         }
     }
     printf("\n\n");
 }



