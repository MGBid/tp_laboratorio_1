#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
typedef struct
{
    int idMovie;
    char title[50];
    char genre[50];
    int duracion;
    char description[200];
    int points;
    char linkImage[400];
    int isEmpty;
} eMovie;

int esSoloLetras(char*);
int esNumerico(char*);
void getString(char*,char*);
int getStringLetras(char*,char*);
int getStringNumeros(char*,char*);
void getValidString(char*,char*,char*);
int getValidInt(char*,char*,int,int );
int getIntRango(int,int,int );
int menuPrincipal();
int menuModificar();
void listarPeliculas(eMovie*,int );
int buscarPrimerOcurrencia(eMovie*,int,int );
int buscarPorID(eMovie*,int,int );




int initArray(eMovie*,int );
int getDataFilms(eMovie*,int );
int setMovieData(eMovie*,int,char*,char*,char*,int,int,char*,int );
int downPelicula(eMovie*,int );
int modificarPelicula(eMovie*,int );




int cargarBinario(eMovie*,int );
void guardarBinario(eMovie*,int );
void generarPaginaHtml(eMovie*,int );

#endif // LIB_H_INCLUDED
