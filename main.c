#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float number1;
    float number2;
    float result;
    int auxNumber1;
    int flag1=0;
    int flag2=0;

    while(seguir=='s')
    {
        system("cls");
        printf("\n\n*****************************************************\n");
        printf("\t\t** CALCULATOR **\n");
        printf("\n*****************************************************\n");
        if(flag1==1){
                printf("1- Ingresar 1er operando (A= %.2f)\n",number1);
                    }
            else{
                printf("1- Ingresar 1er operando (A=x)\n");
                }
        if(flag2==1){
                printf("2- Ingresar 2do operando (B= %.2f)\n",number2);
                    }
            else{
                printf("2- Ingresar 2do operando (B=y)\n");
                }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("\n\n*****************************************************\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                number1=getFloat("Enter a number: ");
                flag1=1;
                break;
            case 2:
                number2=getFloat("Enter a number: ");
                flag2=1;
                break;
            case 3:
                if(flag1!=1)
                {
                    printf("\nError.First number is empty.\n");
                    system("pause");
                }else if(flag2!=1)
                {
                    printf("\nError.Second number is empty.\n");
                    system("pause");
                }
                result=addition(number1,number2);
                printf("\n\tLa suma de (A+B)= %.2f\n\n",result);
                system("pause");
                break;
            case 4:
                if(flag1!=1)
                {
                    printf("\nError.First number is empty. \n");
                    system("pause");
                }else if(flag2!=1)
                {
                    printf("\nError.Second number is empty.\n");
                    system("pause");
                }else{
                    result=subtraction(number1,number2);
                    printf("\n\tLa resta de (A-B)= %.2f\n\n",result);
                    system("pause");
                     }
                break;
            case 5:
                if(flag1!=1)
                {
                    printf("\nError.First number is empty. \n");
                    system("pause");
                }else if(flag2!=1)
                {
                    printf("\nError.Second number is empty.\n");
                    system("pause");
                }else if(number2==0)
                {
                    printf("\nError.Debe ingresar valor distinto de cero.\n");
                    system("pause");
                }else{
                    result=division(number1,number2);
                    printf("\n\tLa division de (A/B)= %.2f\n\n",result);
                    system("pause");
                     }
                break;
            case 6:
                if(flag1!=1)
                {
                    printf("\nError.First number is empty. \n");
                    system("pause");
                }else if(flag2!=1)
                {
                    printf("\nError.Second number is empty.\n");
                    system("pause");
                }else{
                    result=multiply(number1,number2);
                    printf("\n\tEl producto de (A*B)= %.2f\n\n",result);
                    system("pause");
                     }
                break;
            case 7:
                 if(flag1!=1)
                {
                    printf("\nError.First number is empty. \n");
                    system("pause");
                }
                auxNumber1=number1;
                result=factorial(auxNumber1);
                printf("\n\tEl factorial de A= %.0f\n\n",result);
                system("pause");
                break;
            case 8:
                result=addition(number1,number2);
                    printf("\tLa suma de (A+B)= %.2f\n\n",result);
                result=subtraction(number1,number2);
                    printf("\tLa resta de (A-B)= %.2f\n\n",result);
                result=division(number1,number2);
                    printf("\tLa division de (A/B)= %.2f\n\n",result);
                result=multiply(number1,number2);
                    printf("\tEl producto de (A*B)= %.2f\n\n",result);
                result=factorial(auxNumber1);
                    printf("\tEl factorial de A= %.0f\n\n",result);
                    system("pause");
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                printf("\nIngreso erroneo. El valor debe ser entre 1 y 9.\n\n");
                system("pause");
                break;
        }
    }
    return 0;
}











