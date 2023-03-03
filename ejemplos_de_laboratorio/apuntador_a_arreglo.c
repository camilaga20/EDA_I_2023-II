#include <stdio.h>
/*
*/
int main () {
short arr[5], *apArr;
apArr = &arr[0];
// imprime la dirección de memoria del arreglo en la posición [0]
printf("Dirección del arreglo en la primera posición: %x\n",&arr[0]);
// imprime la dirección de memoria del arreglo
// (el nombre del arreglo es un apuntador)
printf("Dirección del arreglo: %x\n",&arr);
// imprime la dirección de memoria del apuntador apArr
printf("Dirección del apuntador: %x\n",apArr);
return 0;
}

 