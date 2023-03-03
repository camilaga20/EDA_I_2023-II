#include<stdio.h>
/*Se recorre un arreglo unidimensional a través de un apuntador
*/
int main(){
short nums[] = {55,44,33,22,11};
short *ap, cont;
ap = nums;
for (cont = 0; cont < 5 ; cont++)
printf("%x\n",(ap+cont));
return 0;
}