/*  Programma per verificare la velocita di calcolo tra MCD con metodo
*   tradizionale e con l' algoritmo di Euclide
*/

#include<stdio.h>

int Euc(int x, int y);

int main(){
  /* Dichiarazione Variabili */
  int a = 0;
  int b = 0;
  
  /* Introduzione */
  printf("Inserire a ----> ");
  scanf( "%d",&a );
  printf("Inserire b ----> ");
  scanf( "%d",&b );
  
  /* Svolgimento */
  printf("\nMCD tra a = %d e b = %d e' %d", a, b, Euc(a,b));
  
  return 0;

}

/*----------------------------------------------------------------------------*/

int Euc (int x, int y){
  /* Dichiarazione Variabili */
  int q = 1;
  int r = 1;
  int mcd = 1;
  
  /* Svolgimento */
    printf("\nElaborazione...\n");
   while (y != 0){
     mcd = y;
     q = x / y;
     r = x % y;
     printf("%d = %d * %d + %d\n",x,y,q,r);
     x = y;
     y = r;
  }
   
   return mcd;
   
}
