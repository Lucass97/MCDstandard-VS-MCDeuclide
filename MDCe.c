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
  int tran = 0;
  
  /* Introduzione */
  printf("Programma per verificare la velocita di calcolo tra MCD con metodo\n");
  printf("tradizionale e con l' algoritmo di Euclide\n\n");
    
  printf("Inserire a ----> ");
  scanf( "%d",&a );
  printf("Inserire b ----> ");
  scanf( "%d",&b );
  
  /* Svolgimento */
  if ((a == 0) && (b == 0)){
	   printf("a e b non possono essere 0!");
	   return 0;
  }
  else if (b > a) {				//In caso b>a si scambiano
	  tran = a;
	  a = b;
	  b = tran;
	  tran = 1;			//Counter viene utilizzata in standard()!
  
  printf("\nMCD di Euclide tra b = %d e a = %d e' %d\n\n", a, b, Euc(a,b));
  // quindi si scambiano anche i printf
  printf("MCD normale tra b = %d e a = %d e' %d\n\n",a ,b ,standard(a,b));
   
  }else {// Nel caso normale(a>b) si prosegue normalmente
  printf("\nMCD di Euclide tra a = %d e b = %d e' %d\n\n", a, b, Euc(a,b));
  
  printf("MCD normale tra a = %d e b = %d e' %d\n\n",a ,b ,standard(a,b));
  }
  
  return 0;

}

/*--------------------------------------------------------------------*/

int Euc (int x, int y){
  /* Dichiarazione Variabili */
  int q = 1;
  int r = 1;
  int mcde = 1;
  
  /* Svolgimento */
  
  if ((x == 0) || (y == 0)){
	 mcde = 0;
  }
  else{
    printf("\nElaborazione...\n");
   while (y != 0){
     mcde = y;
     q = x / y;
     r = x % y;
     printf("%d = %d * %d + %d\n",x,y,q,r);
     x = y;
     y = r;
     }
  }
   return mcde;
   
}

/*--------------------------------------------------------------------*/

int standard (int x,int y){
	/* Dichiarazione Variabili */
	int mcds = 1;
	int counters =1;
	
	printf("Elaborazione...\n");

	if ((x == 0) || (y == 0)){
	 mcds = 0;
    }
    else{
	while(counters <= y){
		printf("proviamo con %d\n",counters );
		if (((x % counters) == 0) && ((y % counters) == 0)){
			printf("%d > %d\n",counters ,mcds );
			mcds = counters;
			printf("(a / %d) e (b / %d) MCD(a,b) = %d\n",counters ,counters ,counters);
		}
		
		counters++;
		
	  }
	}
	printf("\n");
	
	return mcds;
	
}
