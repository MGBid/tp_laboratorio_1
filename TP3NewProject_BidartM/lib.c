#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

/**\brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char *str)
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}
/**\brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
/**\brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets (input);
}
/**\brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char *mensaje,char *input)
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
/**\brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
/**\brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return void
 *
 */
void getValidString(char *requestMessage,char *errorMessage, char *input)
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        system("cls");
        break;
    }
}
/**\brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario o -1 si es error
 *
 */
int getValidInt(char* requestMessage,char* errorMessage, int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    //int retorno=-1;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxInt;
    }
    return -1;
}

/**\brief Valida que un numero se encuentre dentro de un rango
 * \param number número que se ingresa
 * \param lowLimit limite inferior
 * \param hiLimit límite superior
 * \return si no essta dentro del limite -1 o 0 si es ok
 *
 */
int getIntRango(int number,int lowLimit,int hiLimit)
{
    int retorno=-1;
    if(number>=lowLimit && number<=hiLimit)
    {
        retorno=0;
    }
    return retorno;
}
/**\brief Muestra las opciones del menu
 * \param void
 * \return La opcion seleccionada
 *
 */
int menuPrincipal()
{
    int option;

    printf("\t######     MENU PRINCIPAL     ######\n\n");
    printf("\t1**\tAGREGAR PELICULA\n\t2**\tBORRAR PELICULA\n\t3**\tMODIFICAR PELICULA\n\t4**\tGENERAR PAGINA WEB\n\t5**\tLISTAR PELICULAS\n\t6**\tSALIR\n");
    printf("\nSeleccione opcion: ");
    fflush(stdin);
    scanf("%d",&option);
    getIntRango(option,1,6);
    return option;
}
/** \brief Muestra las opciones del menu modificar
 * \param void
 * \return La opcion seleccionada
 *
 */
int menuModificar()
{
    int option;
    printf("\t######     MENU MODIFICAR     ######\n\n");
    printf("\t1**\tID PELICULA\n\t2**\tTITULO\n\t3**\tGENERO\n\t4**\tPUNTUACION\n\t5**\tDESCRIPCION\n\t6**\tDURACION\n\t7**\tLINK IMAGEN\n\t8**\tSALIR");
    printf("\nSeleccione opcion: ");
    fflush(stdin);
    scanf("%d",&option);
    getIntRango(option,1,8);
    return option;
}



/**********    FUNCIONES DEL ARRAY   **********/
/**********************************************/

/**\brief Inicializa un array de peliculas
 * \param pelis puntero al array a inicializar
 * \param length longitud del array a inicializar
 * \return 0 si se inicializo ok -1 si no lo logró
 *
 */
int initArray(eMovie* pelis, int length)
{
    int retorno=-1;
    int i;
    if(pelis!=NULL && length>0)
    {
        for(i=0; i<length; i++)
        {
            pelis[i].isEmpty=1;
        }
    }
    return retorno;
}
/**\brief Encuentra la primer ocurrencia de un valor solicitado
* \param pelisArray puntero al array en el cual buscar
* \param cantidadDeElementos Longitud del array
* \param valor Es el valor a ser hallado
* \return -1 en caso de Error o la posicion del array buscada
*
*/
int buscarPrimerOcurrencia(eMovie* pelisArray,int cantidadDeElementos,int valor)
{
    int i;
    if(pelisArray!=NULL && cantidadDeElementos>0)
    {
        for(i=0; i < cantidadDeElementos; i++)
        {
            if(pelisArray[i].isEmpty == valor)
            {
                return i;
            }
        }
    }
    return -1;
}
/**\brief Busca un elemento en el array por su Id
 * \param pelis array a recorrer
 * \param arrayLength largo del array
 * \return -1 si no lo encuentra o el indice del mismo si es hallado
 *
 */
int buscarPorID(eMovie* pelis,int arrayLenght,int id )
{
    int index=-1;
    int i;

    if(pelis!=NULL && arrayLenght>0)
    {
        for(i=0; i<arrayLenght; i++)
        {
            if(pelis[i].idMovie==id && pelis[i].isEmpty==0) //que exista y que este activa
            {
                index=i;
                break;
            }
        }
    }
    return index;
}
/** \brief Setea los datos de una pelicula
 * \param pelis Array de estructuras movies
 * \param length longitud del array
 * \param title campo de la estructura que recibe el titulo
 * \param genre campo de la estructura que recibe el genero
 * \param description campo de la estructura que recibe la descripcion de la pelicula
 * \param duracion campo de la estructura que recibe la duracion de la pelicula en minutos
 * \param puntaje campo de la estructura que recibe el valor otorgado al puntaje
 * \param linkImage campo de la estructura que recibe el link de la imagen de la misma
 * \param idMovie campo de la estructura que recibe el id de la pelicula a setear
 * \return -1 en caso de error 0 si todo Ok
 *
 */
int setMovieData(eMovie* pelis,int length,char* title,char* genre,char* description,int duracion,int puntaje,char* linkImage,int idMovie)
{
    int retorno=-1;
    int index;

    if(pelis!=NULL && length>0)
    {
        index=buscarPrimerOcurrencia(pelis,length,1);
        if(index==-1)
        {
            printf("\nNo queda espacio\n");
            system("pause");
            return retorno;
        }
        else
        {
            pelis[index].idMovie=idMovie;
            strcpy(pelis[index].title,title);
            strcpy(pelis[index].genre,genre);
            pelis[index].duracion=duracion;
            strcpy(pelis[index].description,description);
            pelis[index].points=puntaje;
            strcpy(pelis[index].linkImage,linkImage);
            pelis[index].isEmpty=0;
            retorno=0;
            printf("\nCarga y seteo exitosos!!");
        }
    }
    return retorno;
}
/** \brief Solicita los datos de la pelicula a ingresar
 * \param puntero a la estructura a cargar
 * \param longitud del array de estructuras
 * \return 0 si todo Ok -1 en caso de Error
 *
 */
int getDataFilms(eMovie* pelis,int length)
{
    int auxPuntaje,auxId,auxDuracion,retorno=-1,flag=0,todoOk=-1;
    char auxTitulo[500],auxLinkImage[500],auxGenero[500],auxDescripcion[500];

    printf("\nIngrese titulo de la Pelicula: \n");
    fflush(stdin);
    gets(auxTitulo);
    while(strlen(auxTitulo)>50)
    {
        printf("\nEl largo del titulo supera el limite.Reingrese no mas de 50 caracteres: ");
        fflush(stdin);
        gets(auxTitulo);
    }
    while(flag==0)
    {
        getValidString("\nIngrese el genero de la pelicula: ","\nError genero solo debe contener letras. ",auxGenero);
        if(strlen(auxGenero)>49)
        {
            printf("\nEl genero es demasiado extenso.Reingrese: \n");
            fflush(stdin);
            system("pause");
            continue;
        }
        flag=1;
    }
    printf("\nIngrese descripcion de la Pelicula: \n");
    fflush(stdin);
    gets(auxDescripcion);
    while(strlen(auxDescripcion)>200)
    {
        printf("\nLa descripcion es demasiado extensa.Reingrese: \n");
        fflush(stdin);
        gets(auxDescripcion);
        system("pause");
        continue;
    }
    fflush(stdin);
    auxPuntaje=getValidInt("Ingrese puntaje 1-10: ","Error en el ingreso.Reingrese",1,10);
    auxId=getValidInt("Ingrese ID de pelicula(1000-9999): ","Error en el ingreso.Reingrese",1000,9999);
    printf("Ingrese Link de imagen: ");
    fflush(stdin);
    gets(auxLinkImage);
    while(strlen(auxLinkImage)>400)
    {
        printf("\nEl link ingresado es demasiado extenso.Reingrese");
        fflush(stdin);
        gets(auxLinkImage);
        system("pause");
        continue;
    }
    auxDuracion=getValidInt("Ingrese duracion en minutos 20-360: ","Error en el ingreso.Reingrese",20,360);
    printf("\n\nUsted ingreso: \n\nPelicula: %s \nGenero: %s \nDescripcion: %s \nPuntaje: %d \nLink de Imagen: %s \nDuracion: %d\n",auxTitulo,auxGenero,auxDescripcion,auxPuntaje,auxLinkImage,auxDuracion);
    system("pause");
    todoOk=setMovieData(pelis,length,auxTitulo,auxGenero,auxDescripcion,auxDuracion,auxPuntaje,auxLinkImage,auxId);
    retorno=todoOk;//REVISAR QUE ESTE TODO OK

    return retorno; //VERIFICAR QUE DEVUELVA BIEN LOS RETORNOS
}
/** \brief Muestra un listado de peliculas activas
 * \param pelis Array de peliculas a listar
 * \param length Longitud del array
 * \return void
 *
 */
void listarPeliculas(eMovie* pelis,int length)
{
    int i;
    if(pelis!=NULL && length>0)
    {
        for(i=0; i<length; i++)
        {
            if(pelis[i].isEmpty==0)
            {
                printf("\n\tTitulo: %s\n\tIdPelicula: %d\n\tGenero: %s\n\tDuracion: %d\n\tPuntaje: %d\n\tDescripcion: %s\n\tLink de Imagen: %s\n",pelis[i].title,pelis[i].idMovie,pelis[i].genre,pelis[i].duracion,pelis[i].points,pelis[i].description,pelis[i].linkImage);
            }
        }
    }
}
/**\brief Da de baja a una pelicula ingresada por id
 * \param pelis Puntero al array donde buscar la pelicula
 * \param length Longitud del array
 * \return -1 ante error 0 si la baja fue exitosa
 *
 */
int downPelicula(eMovie* pelis,int length)
{
    int i,respuesta,retorno=-1;
    int auxId;

    //PRIMERO TIRAR UN LISTADO CON TODAS LAS PELICULAS CARGADAS
    if(pelis!=NULL && length>0)
    {
        printf("ID PELICULA  TITULO          GENERO\n\n");
        for(i=0; i<length; i++)
        {
            if(pelis[i].isEmpty==0)
            {
                printf("%6d %15s %10s\n",pelis[i].idMovie,pelis[i].title,pelis[i].genre);
            }
        }
        auxId=getValidInt("Ingrese ID a dar de baja: ","Error en el ingreso.Reingrese: ",1000,9999);
        retorno=buscarPorID(pelis,length,auxId);
        if(retorno==-1)
        {
            printf("\nError.No se encontro la pelicula ");
        }
        else
        {
            printf("\nUsted dara de baja a la Pelicula: %s Id Movie: %d\n Confirma la baja? 1=Si 2=No\n",pelis[retorno].title,pelis[retorno].idMovie);
            fflush(stdin);
            scanf("%d",&respuesta);
            if(respuesta==1)
            {
                pelis[retorno].isEmpty=1;
                printf("\nBaja exitosa\n");
                system("pause");
            }
            else
            {
                printf("\nLa pelicula no se dio de baja\n\n");
                system("pause");
            }
        }
    }
    return retorno;
}
/**\brief Permite modificar los campos de una estructura eMovie
 * \param pelis Puntero al array de estructuras
 * \param length Longitud del array
 * \return -1 en caso de error y 0 si esta todo Ok
 *
 */
int modificarPelicula(eMovie* pelis,int length)
{
    int i,index,auxId,auxPuntaje,auxDuracion,retorno=-1;
    char auxTitle[100],auxDescripcion[200],auxGenero[20],auxLinkImagen[200];

    if(pelis!=NULL && length>0)
    {
        printf("ID PELICULA  TITULO          GENERO\n\n");
        for(i=0; i<length; i++)
        {
            if(pelis[i].isEmpty==0)
            {
                printf("%6d %15s %10s\n",pelis[i].idMovie,pelis[i].title,pelis[i].genre);
            }
        }
        auxId=getValidInt("\nIngrese ID de pelicula a modificar: ","Error.Ingreso invalido",1000,9999);
        index=buscarPorID(pelis,length,auxId);
        system("cls");
        printf("\nPelicula a modificar: %s Id de pelicula: %d \n",pelis[index].title,pelis[index].idMovie);

        switch(menuModificar())
        {
        case 1: //id
            printf("\n\t**MODIFICAR ID**\n");
            auxId=getValidInt("\nIngrese nuevo Id de Pelicula: ","Ingreso erroneo.Reingrese",1000,9999);
            while(buscarPorID(pelis,length,auxId)!=-1)
            {
                printf("El id ya se encuentra usado.Reingrese\n");
                auxId=getValidInt("Ingrese nuevo Id de Pelicula: ","Ingreso erroneo.Reingrese",1000,9999);
                system("pause");
                continue;
            }
            pelis[index].idMovie=auxId;
            printf("\nPelicula modificada: %s Id de pelicula: %d \n",pelis[index].title,pelis[index].idMovie);
            break;
        case 2://titulo
            system("cls");
            printf("\n\t**MODIFICAR TITULO**\n");
            printf("\nTitulo actual. %s",pelis[index].title);
            printf("\nIngrese titulo de la Pelicula: \n");
            fflush(stdin);
            gets(auxTitle);
            while(strlen(auxTitle)>50)
            {
                printf("\nEl largo del titulo supera el limite.Reingrese no mas de 50 caracteres: ");
                fflush(stdin);
                gets(auxTitle);
            }
            for(i=0; i<length; i++)
            {
                if(pelis[i].isEmpty==0 && strcmp(pelis[i].title,auxTitle)==0)
                {
                    printf("\nEl titulo ingresado ya existe\n");
                    system("pause");
                    break;
                }
                else
                {
                    strcpy(pelis[index].title,auxTitle);
                    printf("\nPelicula modificada\nNuevo Titulo: %s Id de pelicula: %d\t\n",pelis[index].title,pelis[index].idMovie);
                    system("pause");
                    break;
                }
            }
            break;
        case 3://genero
            system("cls");
            printf("\n\t**MODIFICAR GENERO**\n");
            printf("\nGenero actual: %s",pelis[index].genre);
            getValidString("\nIngrese el nuevo genero de la pelicula: ","\nError genero solo debe contener letras. ",auxGenero);
            if(strlen(auxGenero)>49)
            {
                printf("\nEl genero es demasiado extenso.Reingrese: \n");
                fflush(stdin);
            }
            else
            {
                strcpy(pelis[index].genre,auxGenero);
                printf("\nPelicula modificada\nTitulo: %s Id de pelicula: %d Genero: %s\t\n",pelis[index].title,pelis[index].idMovie,pelis[index].genre);
            }
            system("pause");
            break;
        case 4://puntuacion
            system("cls");
            printf("\n\t**MODIFICAR PUNTUACION**\n");
            printf("\nPuntuacion actual: %d",pelis[index].points);
            auxPuntaje=getValidInt("\nIngrese nuevo puntaje: ","Error.Ingreso invalido",1,10);
            pelis[index].points=auxPuntaje;
            printf("\nPelicula modificada: %s Id de pelicula: %d Puntaje: %d\n",pelis[index].title,pelis[index].idMovie,pelis[index].points);
            system("pause");
            break;
        case 5://descripcion
            system("cls");
            printf("\n\t**MODIFICAR DESCRIPCION**\n");
            printf("\nDescripcion actual: %s",pelis[index].description);
            printf("\nIngrese Nueva descripcion de la Pelicula: \n");
            fflush(stdin);
            gets(auxDescripcion);
            while(strlen(auxDescripcion)>200)
            {
                printf("\nLa descripcion es demasiado extensa.Reingrese: \n");
                fflush(stdin);
                gets(auxDescripcion);
                system("pause");
                continue;
            }
            strcpy(pelis[index].description,auxDescripcion);
            printf("\nPelicula modificada: %s Id de pelicula: %d Descripcion: %s\n",pelis[index].title,pelis[index].idMovie,pelis[index].description);
            system("pause");
            break;
        case 6://duracion
            system("cls");
            printf("\n\t**MODIFICAR DURACION**\n");
            printf("\nDuracion actual: %d",pelis[index].duracion);
            auxDuracion=getValidInt("\nIngrese nueva duracion: ","Error.Ingreso invalido",20,360);
            pelis[index].duracion=auxDuracion;
            printf("\nPelicula modificada: %s Id de pelicula: %d Duracion: %d\n",pelis[index].title,pelis[index].idMovie,pelis[index].duracion);
            system("pause");
            break;
        case 7://link Imagen
            system("cls");
            printf("\n\t**MODIFICAR LINK DE IMAGEN**\n");
            printf("\nLink de Imagen actual: %s",pelis[index].linkImage);
            printf("Ingrese Link de imagen: ");
            fflush(stdin);
            gets(auxLinkImagen);
            while(strlen(auxLinkImagen)>400)
            {
                printf("\nEl link ingresado es demasiado extenso.Reingrese");
                fflush(stdin);
                gets(auxLinkImagen);
                system("pause");
                continue;
            }
            strcpy(pelis[index].linkImage,auxLinkImagen);
            printf("\nPelicula modificada: %s Id de pelicula: %d Link de Imagen: %d\n",pelis[index].title,pelis[index].idMovie,pelis[index].linkImage);
            system("pause");
            break;
        case 8://salir
            printf("\nUsted esta por salir del menu modificar\n");
            system("pause");
            break;
        default:
            printf("\nERROR.Ingreso invalido\n");
            system("pause");
            break;
            retorno=0;
        }
    }
    return retorno;
}


/*********   FUNCIONES DE ARCHIVOS BINARIOS Y OTROS    *************************/
/******************************************************************************/
/** \brief Carga los archivos desde un archivo binario leido
 * \param pelis Estructura donde se cargan
 * \param length Longitud del array
 * \return 0 si Ok -1 por error
 *
 */
int cargarBinario(eMovie* pelis,int length)
{
    int retorno=-1;
    FILE* pFile;
    pFile=fopen("bin.dat","rb");
    if(pFile==NULL)
    {
        pFile=fopen("bin.dat","wb");
        if(pFile==NULL)
        {
            printf("No se pudo abrir el archivo");
            system("pause");
            return retorno;
        }
    }
    fread(pelis,sizeof(eMovie),length,pFile);
    retorno=0;
    printf("\n Archivo cargado con exito!\n\n");
    system("pause");
    fclose(pFile);
    return retorno;
}
/**\brief Guarda los datos cargados en un archivo binario
 * \param pelis puntero al array a guardar
 * \param length longitud del array
 * \return void
 *
 */
void guardarBinario(eMovie* pelis,int length)
{
    FILE* pFile;
    pFile=fopen("bin.dat","wb");
    if(pFile==NULL)
    {
        printf("Error al abrir el archivo binario\n");
        exit(1);
    }
    fwrite(pelis,sizeof(eMovie),length,pFile);
    printf("\nArchivo binario guardado con exito!\n");
    fclose(pFile);
}
void generarPaginaHtml(eMovie* pelis,int length)
{
    int i;
    FILE* pFile;
    pFile=fopen("index.html","w");
    if(pFile==NULL)
    {
        printf("\nError al abrir el archivo\n");
        exit(1);
    }
    for(i=0; i<length; i++)
    {
        if(pelis[i].isEmpty==0)
        {
            fprintf(pFile,"<img class='img-responsive img-rounded' src='%s' width=178 heigth=180 border=4 alt=''>",pelis[i].linkImage);
            fprintf(pFile,"</a><h3><a href='#'> %s</a></h3><ul>",pelis[i].title);
            fprintf(pFile,"<li>Id Pelicula: %d</li><li>Genero: %s</li><li>Puntaje: %d</li><li>Duracion: %d minutos</li></ul>",pelis[i].idMovie,pelis[i].genre,pelis[i].points,pelis[i].duracion);
            fprintf(pFile,"<p> %s</p></article>",pelis[i].description);
        }
    }
    fclose(pFile);
    printf("\nArchivo creado con exito!");
}

