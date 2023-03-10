#include<stdio.h>
#define TAM 2
#define NUM_DIR 2
struct pelicula{
char nombre[20];
char genero[20];
short anio;
short numDirectores;
char directores[NUM_DIR][20];
};
void llenarArreglo(struct pelicula *);
void imprimirArreglo(struct pelicula *);
int main(){
struct pelicula arreglo[TAM];
llenarArreglo (arreglo);
imprimirArreglo (arreglo);
return 0;
}
void llenarArreglo(struct pelicula arreglo [TAM]){
int iesimo, enesimo;
for (iesimo=0 ; iesimo<TAM ; iesimo++) {
struct pelicula movie;
printf("####### Película %d #######\n", iesimo+1);
printf("Ingrese nombre película:");
setbuf(stdin, NULL);
scanf("%s", movie.nombre);
getchar();
printf("Ingrese género película:");
setbuf(stdin, NULL);
scanf("%s", movie.genero);
getchar();
printf("Ingrese año película:");
setbuf(stdin, NULL);
scanf("%d", &movie.anio);
movie.numDirectores = NUM_DIR;
for (enesimo=0 ; enesimo<NUM_DIR ; enesimo++){
printf("Ingrese director %d:", enesimo+1);
setbuf(stdin, NULL);
scanf("%s", movie.directores[enesimo]);
getchar();
}
arreglo[iesimo] = movie;
}
}
void imprimirArreglo(struct pelicula arreglo [TAM]){
int iesimo, enesimo;
printf("####### Contenido del arreglo #######\n");
for (iesimo=TAM-1 ; iesimo>=0 ; iesimo--) {
printf("####### Película %d #######\n", iesimo+1);
printf("PELÍCULA: %s\n", arreglo[iesimo].nombre);
printf("GÉNERO: %s\n", arreglo[iesimo].genero);
printf("AÑO: %d\n", arreglo[iesimo].anio);
printf("DIRECTOR(ES):\n");
for (enesimo=0 ; enesimo<arreglo[iesimo].numDirectores ;
enesimo++){
printf("%s\n", arreglo[iesimo].directores[enesimo]);
}
}
}