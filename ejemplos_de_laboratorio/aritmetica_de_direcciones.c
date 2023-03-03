#include<stdio.h>
/*Se imprimen 3 valores de un arreglo a través
de aritmética de direcciones.
*/

int main () {
short arr[5] = {91,28,73,46,55};
short *apArr;
apArr = arr;
// apunta al inicio del arreglo
printf("*apArr = %i\n",*apArr);
// suma una localidad al inicio del arreglo e imprime su valor
printf("*(apArr+1) = %i\n",*(apArr+1)); printf("*(apArr+2) = %i\n",*(apArr+2));
return 0;
 }