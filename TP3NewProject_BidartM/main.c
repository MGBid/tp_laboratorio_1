#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main()
{
    char seguir='s';

    eMovie theFilms[10];//cambiar valor del array por uno mas grande
    initArray(theFilms,10);
    cargarBinario(theFilms,10);

    while(seguir=='s')
    {
        system("cls");

        switch(menuPrincipal())
        {
        case 1:
            system("cls");
            printf("\n\tAGREGAR PELICULA\t\n");
            getDataFilms(theFilms,10);
            guardarBinario(theFilms,10);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("\n\tBORRAR PELICULA\t\n");
            downPelicula(theFilms,10);
            guardarBinario(theFilms,10);
            system("pause");
            break;
        case 3:
            system("cls");
            printf("\n\tMODIFICAR PELICULA\t\n");
            modificarPelicula(theFilms,10);
            guardarBinario(theFilms,10);
            system("pause");
            break;
        case 4:
            system("cls");
            printf("\n\tGENERAR PAGINA WEB\t\n");
            generarPaginaHtml(theFilms,10);
            system("pause");
            break;
        case 5:
            system("cls");
            printf("\n\tLISTAR PELICULAS\t\n");
            listarPeliculas(theFilms,10);
            system("pause");
            break;
        case 6:
            seguir='n';
            break;
        default:
            printf("\n\tOpcion No Valida\n");
            system("pause");
            break;
        }
    }

    printf("\nThank you for your visit!\n");
    return 0;
}
