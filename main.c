/* *****************************************************************************************
* Programa: Trabajo practico Nº 2
*
* Objetivos:
*   -Definir una estructura que represente una persona, con los campos
*    nombre, edad, dni y un flag de estado.
*
.
 -Hacer un programa que defina un array de 20 ítems de esta estructura y con un
*    menú como el siguiente:
*           1. Agregar una persona
*           2. Borrar una persona
*           3. Imprimir lista ordenada por nombre
*           4. Imprimir gráfico de edades
*    Se utilizará el campo de estado para indicar si el ítem del array esta
*    ocupado o no.
*    El gráfico deberá ser un gráfico de barras en donde se agruparán 3 barras:
*            • Menores de 18
*            • De 19 a 35
*            • Mayores de 35.
*
* Version 1.0 23/09/16
* Autora: Monica G. Bidart
* ******************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define QUANTITY 20

int main()
{
     EPersona arrayPeople[QUANTITY];
     char auxName[50];
     char auxAge[4];
     char auxDni[9];
     int ageAuxiliar;
     int dniAuxiliar;
     int option=0,flag=0;
     int counter1=0,counter2=0,counter3=0;
     int mayor,i;
     int freeIndex,indexAux;


     initArray(arrayPeople,QUANTITY,-1);
     while(option!=5)
     {
        system("cls");
        option=menuOpciones();
        switch(option)
         {
         case 1:
          freeIndex=obtenerEspacioLibre(arrayPeople,QUANTITY,-1);
          if(freeIndex==-1)
            {
            printf("\nNO QUEDA ESPACIO DISPONIBLE!\n");
            system("pause");
            break;
            }
          printf("\n * AGREGAR UNA PERSONA *\n");
          if(!getStringLetters("\nIngrese el nombre: ",auxName))
            {
            printf("\nEl nombre debe estar compuesto solo por Letras! ");
            system("pause");
            break;
            }
          if(!getStringNumbers("Ingrese el DNI: ",auxDni))
            {
            printf("El DNI debe ser numerico!  ");
            system("pause");
            break;
            }
          if(strlen(auxDni)<7 || strlen(auxDni)>8)
            {
            printf("Error el DNI Debe contener entre 7 y 8 digitos\n");
            system("pause");
            break;
            }
          dniAuxiliar=atoi(auxDni);
          if(buscarPorDni(arrayPeople,QUANTITY,dniAuxiliar)!=-1)
            {
            printf("\nEl DNI ya existe!\n ");
            system("pause");
            break;
            }
          if(!getStringNumbers("Ingrese la edad: ",auxAge))
            {
            printf("\nLa edad debe ser numerica!");
            system("pause");
            break;
            }
          ageAuxiliar=atoi(auxAge);
          if(!(ageAuxiliar>0 && ageAuxiliar<99))
            {
            printf("La edad debe estar comprendida entre 0 y 99\n");
            system("pause");
            break;
            }
          if(ageAuxiliar<=18)
            {
            counter1++;
            }else if(ageAuxiliar>18 && ageAuxiliar<=35)
                    {
                    counter2++;
                    }else
                        {
                        counter3++;
                        }
          strcpy(arrayPeople[freeIndex].nombre,auxName);
          arrayPeople[freeIndex].edad=ageAuxiliar;
          arrayPeople[freeIndex].dni=dniAuxiliar;
          arrayPeople[freeIndex].estado=0;
          printf("\n  CARGA EXITOSA  \n");
          system("pause");
          break;
         case 2:
          system("cls");
          if(!getStringNumbers("\nIngrese el DNI: ",auxDni))
            {
            printf("El DNI debe ser numerico! ");
            system("pause");
            break;
            }
          if(strlen(auxDni)<7 || strlen(auxDni)>8)
            {
            printf("Error el DNI Debe contener entre 7 y 8 digitos\n");
            system("pause");
            break;
            }
          dniAuxiliar=atoi(auxDni);
          indexAux=buscarPorDni(arrayPeople,QUANTITY,dniAuxiliar);
          if(indexAux==-1)
            {
            printf("\n El DNI ingresado no existe!\n");
            system("pause");
            break;
            }
          if(arrayPeople[indexAux].edad<=18)
            {
            counter1--;
            }else if(arrayPeople[indexAux].edad>35)
                    {
                    counter3--;
                    }else
                        {
                        counter2--;
                        }
          arrayPeople[indexAux].estado=-1;
          printf("\nBAJA EXITOSA \n ");
          system("pause");
          break;
         case 3:
          system("cls");
          printf("-IMPRIMIR LISTADO ORDENADO-\n");
          listar(arrayPeople,QUANTITY);
          system("pause");
          break;
         case 4:
          system("cls");
          printf("\n\n\n\n\n\n");
          if(counter1>=counter2 && counter1>=counter3)
            {
            mayor=counter1;
            }
            else if(counter2>=counter1 && counter2>=counter3)
                   {
                    mayor=counter2;
                   }
                   else
                      {
                      mayor=counter3;
                      }
          for(i=mayor; i>0; i--)
             {
             if(i<10)
               {
               printf("%02d| ",i);
               }
             else
               {
               printf("%02d| ",i);
               }
             if(i<= counter1)
               {
             printf(" *");
               }
             if(i<= counter2)
               {
               flag=1;
               printf("\t  *");
               }
             if(i<= counter3)
               {
               if(flag==0)
                 {
                 printf("\t\t*");
                 }
               if(flag==1)
                 {
                 printf("\t*");
                 }
               }
             printf("\n");
             }
          printf("\n   <18\t19-35\t>35\n\n");
          printf("\n    %d\t  %d\t%d\n\n", counter1, counter2, counter3);
          system("pause");
          break;
          }
     }
     return 0;
}
