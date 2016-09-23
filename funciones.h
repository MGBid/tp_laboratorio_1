#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

int menuOpciones();//
int isOnlyLetters(char strinG[]);//
int isOnlyNumber(char strinG[]);//


void getString(char mensaje[],char input[]);//
int getStringLetters(char message[],char input[]);//
int getStringNumbers(char message[],char input[]);//


void initArray(EPersona lista[],int arrayLenght,int valor);//
int obtenerEspacioLibre(EPersona lista[],int arrayLenght,int valor);//
int buscarPorDni(EPersona lista[],int arrayLenght,int dni );
void listar(EPersona lista[],int lenght);//



#endif // FUNCIONES_H_INCLUDED
