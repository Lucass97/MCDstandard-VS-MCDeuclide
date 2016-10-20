/*  Programma per verificare la velocita di calcolo tra MCD con metodo
*   tradizionale e con l' algoritmo di Euclide
*/

#include <stdio.h>
#include <stdbool.h> // Questa libreria permette di utilizzare il true
#include <stdlib.h>
#include <time.h> // Questa libreria permette di utilizzare la funzione per calcolare il tempo

int Euc(int x, int y);
int standard(int x, int y);

int main()
{
    /* Dichiarazione Variabili */
    int a = 0;
    int b = 0;
    char scelta;

    /* Introduzione */
    while(true) {
        printf("|====================================================================|\n");
        printf("| Programma per verificare la velocita di calcolo tra MCD con metodo |\n");
        printf("| tradizionale e con l' algoritmo di Euclide                         |\n");
        printf("|====================================================================|\n\n");

        /*Input controlato*/
        printf("Inserire a ----> ");
        while(scanf("%d", &a) != 1) { // La funzione scanf restituirà un valore diverso da 1 quando non riceverà un numero
            printf("Attenzione! Quello che hai inserito non e' un numero.\n\tRiprova ----> ");
            while(getchar() != '\n'); // Funzione che pulisce il buffer di input
        }
        printf("Inserire b ----> ");
        while(scanf("%d", &b) != 1) { // La funzione scanf restituirà un valore diverso da 1 quando non riceverà un numero
            printf("Attenzione! Quello che hai inserito non e' un numero.\n\tRiprova ----> ");
            while(getchar() != '\n'); // Funzione che pulisce il buffer di input
        }
         printf("\n");
        /* Svolgimento */
        if(b > a) { // In caso b>a si scambiano
            int tran = 0;
            tran = a;
            a = b;
            b = tran;
            // Counter viene utilizzata in standard()!
            printf("\nMCD di Euclide tra b = %d e a = %d e' %d\n\n", a, b, Euc(a, b));
            // quindi si scambiano anche i printf
            printf("MCD normale tra b = %d e a = %d e' %d\n\n", a, b, standard(a, b));

        } else { // Nel caso normale(a>b) si prosegue normalmente
            printf("\nMCD di Euclide tra a = %d e b = %d e' %d\n\n", a, b, Euc(a, b));
            printf("MCD normale tra a = %d e b = %d e' %d\n\n", a, b, standard(a, b));
        }

        while(getchar() != '\n')
            ; // Funzione che pulisce il buffer di input
        printf("Vuoi effetturare un altro calcolo? (y/n) ----> ");
        while(scanf("%c", &scelta) == 1) {
            if(scelta == 121) { // 121 corrisponde a y
                printf("Hai scelto: si\n");
                break;
            } else if(scelta == 110) { // 110 corrisponde a n
                printf("Hai scelto: no\n");
                return 0;
            }
            printf("Attenzione! Risposta non valida.\n\tRiprova ----> ");
            while(getchar() != '\n')
                ;
        }
        system("clear"); // Funzione che pulisce la console
    }
    return 0;
}

/*--------------------------------------------------------------------*/

int Euc(int x, int y)
{
    /* Dichiarazione Variabili */
    // int q = 1;
    int r = 1;
    int mcde = 0;
    int q = 1;
    clock_t time_euclide;

    /* Svolgimento */
    printf("|============================|\n");
    printf("| Calcolo con MCD di euclide |\n");
    printf("|============================|\n");
    printf("Elaborazione...\n");
    
    
    time_euclide = clock(); //Tempo iniziale
    
    if(x == 0 && y == 0)
        return 0;
    else if(x == 0)
        return y;
    else if(y == 0)
        return x;
        
    while(y != 0) {
        mcde = y;
        q = x / y;
        r = x % y;
        printf("%d = %d * %d + %d\n", x, y, q, r);
        x = y;
        y = r;
    }
    time_euclide = clock() - time_euclide; // Tempo finale
    printf("Tempo di esecuzione: %fs \n", (double)time_euclide/CLOCKS_PER_SEC);
    return mcde;
}

/*--------------------------------------------------------------------*/

int standard(int x, int y)
{
    /* Dichiarazione Variabili */
    int mcds = 0;
    int counters = 1;
    clock_t time_standard;

    /* Svolgimento */
    printf("|============================|\n");
    printf("| Calcolo con MCD normale    |\n");
    printf("|============================|\n");
    printf("Elaborazione...\n");
    
    time_standard = clock(); //Tempo iniziale
    
    if(x == 0 && y == 0)
        return 0;
    else if(x == 0)
        return y;
    else if(y == 0)
        return x;
        
    while(counters <= y) {
    //    printf("proviamo con %d\n", counters);
        if(((x % counters) == 0) && ((y % counters) == 0)) {
        //    printf("%d > %d\n", counters, mcds);
            mcds = counters;
        //    printf("(a / %d) e (b / %d) MCD(a,b) = %d\n", counters, counters, counters);
        }

        counters++;
    }
    time_standard = clock() - time_standard; // Tempo finale
    printf("Tempo di esecuzione: %fs \n", (double)time_standard/CLOCKS_PER_SEC);
    printf("\n");
    return mcds;
}
