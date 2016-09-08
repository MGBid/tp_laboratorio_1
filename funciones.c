#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**
 * \brief Solicitar al usuario un numero.
 * \param mensaje Es el mensaje a ser mostrado
 * \param auxiliar Donde se guardara el numero solicitado
 * \return El numero que ingreso el usuario
 *
 */
 float getFloat(char mensaje[])
{
    float auxiliar;
    printf("\n  %s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;

}

/**
 * \brief Solicita dos numeros, los suma y retorna el resultado
 * \param x Toma el valor del primer operando
 * \param y Toma el valor del segundo operando
 * \param add Expresa la suma
 * \return El resultado de la operacion
 *
 */
 float addition(float x,float y)
{
    float add;
    add=x+y;
    return add;
}

/**
 * \brief Recibe dos numeros y realiza la resta
 * \param x Toma el valor del primer operando
 * \param y Toma el valor del segundo operando
 * \return El resultado de la resta
 *
 */
 float subtraction(float x,float y)
{
    float substr;
    substr=x-y;
    return substr;
}

/**
 * \brief Recibe dos numeros, calcula el cociente entre ellos
 * \param x Toma el valor del primer operando
 * \param y Toma el valor del segundo operando
 * \return un flotante como resultado
 *
 */
 float division(float x,float y)
{
    float divis;
    divis=x/y;
    return divis;
}

/**
 * \brief Recibe dos valores y calcula el producto de los mismos
 * \param x Toma el valor del primer operando
 * \param y Toma el valor del segundo operando
 * \return El resultado de la operacion
 *
 */
 float multiply(float x,float y)
{
    float multip;
    multip=x*y;
    return multip;
}

/**
 * \brief Recibe un numero, valida que sea > = 1 y calcula su factorial en forma recursiva
 * \param x Toma el valor de la variable ingresada
 * \param f Expresa la operacion
 * \return El factorial del numero recibido
 *
 */
int factorial(int x)
{
   int factor;
   if(x!=1)
   {
       factor=x*factorial(x-1);
   }else{
            factor=1;
        }
    return factor;
}


