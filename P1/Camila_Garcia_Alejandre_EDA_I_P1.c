#include<stdio.h>
#include<stdlib.h>
int i, j, x, y;
int pedirOpcion(int opMaxima)
{
   int opcion;
   char opChar[10];

   fflush(stdin);
  do
  {
   gets(opChar);
   opcion=atoi(opChar);
   if(opcion < 1)
   printf("Esta opcion no es valida\n");
   else
   if(opcion > opMaxima)
   printf("Opcion NO valida. El maximo de opciones es %d\n", opMaxima);

  }
  while (opcion < 1 || opcion > opMaxima);
  fflush(stdin);

  return opcion;
}

int menuSimuladores()
{
   system("cls");

   printf("---> MENU DE SIMULACION PIEZAS DE AJEDREZ <---\n");
   printf("Selecciona el numero de simulacion que quieres hacer \n");
   printf("1)Alfil  2)Torre  3)Salir \n\n");

   return pedirOpcion(3);
}

int menuReturnOpcion()
{
   printf("---> OPCIONES DE RETORNO <---\n");
   printf("Selecciona el numero de opcion a donde te quieres dirigir");
   printf("1)returnSimulacion  2)returnMenu  3)Salir\n\n");

   return pedirOpcion(3);
}

void simuladorAlfil()
{
   int tableroajedrez[9][9];

   printf("Ingresa la posicion de tu alfil en formato de coordenada x,y: ");
   scanf("%d,%d",&x,&y);

   for(i=1;i<9;i++)
   {
    for(j=1;j<9;j++)
    {
      tableroajedrez[i][j]=0;
    }
   } 

    for(i=x, j=y; (j<9 && i>=1); i--, j++)
    {
      tableroajedrez[i][j]=1;
    }

    for(i=x, j=y; (i>=1 && j<9); i++,j++)
    {
      tableroajedrez[i][j]=1;
    }

    for(i=x, j=y; (i>1 && j>=1); i++, j--)
    {
      tableroajedrez[i][j]=1;
    }

    for(i=x, j=y; (i>=1 && j>=1); i--, j--)
    {
      tableroajedrez[i][j]=1;
    }
    
    tableroajedrez[x][y]=8;

    printf("El alfil se encuentra en %d,%d\n",x,y);
    
    for(j=1;j<9;j++)
    {
     for(i=1;i<9;i++)
     {
      if(tableroajedrez[i][j]==0)
      {
         printf("*\t");
      }
       if(tableroajedrez[i][j]==1)
       {
         printf("-A-\t");
       }
       if(tableroajedrez[i][j]==8)
       {
         printf("A\t");
       }
     }
      printf("\n\n");
    } 
}

void simuladorTorre()
{
   int tableroajedrez[9][9];
    printf("Ingresa la posicion de tu torre en formato de coordenada x,y: ");
   scanf("%d,%d",&x,&y);

   for(i=1;i<9;i++)
   {
    for(j=1;j<9;j++)
    {
      tableroajedrez[i][j]=0;
    }
   } 

    for(i=x, j=y; (i<9 && j>=1); j--)
    {
      tableroajedrez[i][j]=1;
    }

    for(i=x, j=y; (i<9 && j>=1); i++)
    {
      tableroajedrez[i][j]=1;
    }

    for(i=x, j=y; (i>0 && j>=1); i--)
    {
      tableroajedrez[i][j]=1;
    }

    for(i=x, j=y; (i>0 && j<9); j++)
    {
      tableroajedrez[i][j]=1;
    }

    tableroajedrez[x][y]=8;

    printf("La torre se encuentra en %d,%d\n",x,y);
    
    for(j=1;j<9;j++)
    {
     for(i=1;i<9;i++)
     {
      if(tableroajedrez[i][j]==0)
      {
         printf("*\t");
      }
       if(tableroajedrez[i][j]==1)
       {
         printf("-T-\t");
       }
       if(tableroajedrez[i][j]==8)
       {
         printf("T\t");
       }
     }
      printf("\n\n");
    }
}

int main()
{
   int op;

   inicio:
      op=menuSimuladores();

     seleccion:
       system("cls");

       switch(op)
       {
         case 1: simuladorAlfil(); 
         break;

         case 2: simuladorTorre();
         break;

         default: goto salir;
         break;
       }

       switch(menuReturnOpcion())
       {
         case 1: goto seleccion;
         break;

         case 2: goto inicio;
         break;

         default: break;
       }

       salir:{
        printf("Programa Terminado. Gracias \n\n");
        
        printf(":)");}
    }