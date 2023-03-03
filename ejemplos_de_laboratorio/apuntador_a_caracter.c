#include <stdio.h>
/*
    Este programa crea un apuntador de tipo carácter.
*/
int main () { char *ap, c;
c = 'x'; ap = &c;
    // imprime el carácter de la localidad a la que apunta
printf("Carácter: %c\n",*ap);
// imprime el código ASCII de la localidad a la que apunta printf("Código ASCII: %d\n",*ap);
// imprime la dirección de memoria de la localidad a la que apunta printf("Dirección de memoria: %p\n",ap);
return 0; }