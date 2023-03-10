#include<stdio.h>
#include<stdlib.h>
int i, j, x, y;
int pedirOpcion(int opMaxima)
{
   int opcion;
   int *op; //*apuntador de opcion 
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
   printf("1)Reina  2)Rey  3)Salir \n\n");

   return pedirOpcion(3);
}

int menuReturnOpcion()
{
   printf("---> OPCIONES DE RETORNO <---\n");
   printf("Selecciona el numero de opcion a donde te quieres dirigir");
   printf("1)returnSimulacion  2)returnMenu  3)Salir\n\n");

   return pedirOpcion(3);
}

void simuladorReina()
{
	//*La reina la representare con una Q para diferenciarla del rey*//
   int tableroajedrez[9][9];

   printf("Ingresa la posicion de tu Reina en formato de coordenada x,y: ");
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
    
    printf("la Reina se encuentra en %d,%d\n",x,y);
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
         printf("-Q-\t");
       }
       if(tableroajedrez[i][j]==8)
       {
         printf("Q\t");
       }
     }
      printf("\n\n");
    } 
     tableroajedrez[x][y]=8;
}

void simuladorTorre()
{
	//*El rey se representará con una Q para que se note la diferencia*//
   int tableroajedrez[9][9];
    printf("Ingresa la posicion de tu rey en formato de coordenada x,y: ");
   scanf("%d,%d",&x,&y);

   for(i=1;i<9;i++)
   {
    for(j=1;j<9;j++)
    {
      tableroajedrez[i][j]=0;
    }
   } 

    
     for(i=x-1;i<=x+1;i++)
   {
    for(j=y-1;j<=y+1;j++)
    {
      tableroajedrez[i][j]=1;
    }
   } 
    tableroajedrez[x][y]=8;
    printf("El rey se encuentra en %d,%d\n",x,y);
    
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
         printf("-K-\t");
       }
       if(tableroajedrez[i][j]==8)
       {
         printf(" K\t");
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
         case 1: simuladorReina(); 
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