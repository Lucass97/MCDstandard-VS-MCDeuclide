/*  Programma per verificare la velocita di calcolo tra MCD con metodo
*   tradizionale e con l' algoritmo di Euclide
*/

#include<stdio.h>

int Euc(int x, int y);
int standard (int x,int y);

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
  printf("\nMCD di Euclide tra a = %d e b = %d e' %d\n", a, b, Euc(a,b));
  
  printf("MCD normale tra a = %d e b = %d e' %d\n",a ,b ,standard(a,b));
  
  return 0;

}

/*--------------------------------------------------------------------*/

int Euc (int x, int y){
  /* Dichiarazione Variabili */
  int q = 1;
  int r = 1;
  int mcde = 1;
  
  /* Svolgimento */
    printf("\nElaborazione...\n");
   while (y != 0){
     mcde = y;
     q = x / y;
     r = x % y;
     printf("%d = %d * %d + %d\n",x,y,q,r);
     x = y;
     y = r;
  }
   
   return mcde;
   
}

/*--------------------------------------------------------------------*/

int standard (int x,int y){
	/* Dichiarazione Variabili */
	int mcds = 1;
	int counter = 1;
	
	while(counter >= x){
		if ((x % counter) == 0 && (y % counter)){
				mcds = counter;
				counter++;
		}
	}
	
	return mcds;
}
