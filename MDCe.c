/*  Programma per verificare la velocita di calcolo tra MCD con metodo
*   tradizionale e con l' algoritmo di Euclide
*/

#include <stdio.h>
#include <stdbool.h> // Questa libreria permette di utilizzare il true
#include <stdlib.h>
#include <time.h> // Questa libreria permette di utilizzare la funzione per calcolare il tempo

int Euc(int x, int y, bool mostraPassaggi);
int standard(int x, int y, bool mostraPassaggi);

int main()
{
    /* Dichiarazione Variabili */
    int a = 0;
    int b = 0;
    char scelta;
    bool mostraPassaggiMCDe;
    bool mostraPassaggiMCDs;

    /* Introduzione */
    while(true) {
        printf("|====================================================================|\n");
        printf("| Programma per verificare la velocita di calcolo tra MCD con metodo |\n");
        printf("| tradizionale e con l' algoritmo di Euclide                         |\n");
        printf("|====================================================================|\n\n");

        /*Input controlato*/
        printf("Inserire a ----> ");
        do{
            while(scanf("%d", &a) != 1) { // La funzione scanf restituirà un valore diverso da 1 quando non riceverà un numero
                printf("Attenzione! Quello che hai inserito non e' un numero.\n\tRiprova ----> ");
                while(getchar() != '\n'); // Funzione che pulisce il buffer di input
            }
            if(a>0)
                break;
            printf("Attenzione! Attenzione il numero che hai inserito non e' valido.\n\tRiprova ----> ");
        }while(true);
        printf("Inserire b ----> ");
         do{
            while(scanf("%d", &b) != 1) { // La funzione scanf restituirà un valore diverso da 1 quando non riceverà un numero
                printf("Attenzione! Quello che hai inserito non e' un numero.\n\tRiprova ----> ");
                while(getchar() != '\n'); // Funzione che pulisce il buffer di input
            }
            if(b>0)
                break;
            printf("Attenzione! Attenzione il numero che hai inserito non e' valido.\n\tRiprova ----> ");
        }while(true);
        
        /* Robe */
        while(getchar() != '\n'); // Funzione che pulisce il buffer di input
        printf("Mostrare i passaggi per MCD di euclide? (y/n) ----> ");
        while(scanf("%c", &scelta) == 1) {
            if(scelta == 121) { // 121 corrisponde a y
                printf("Hai scelto: si\n");
                mostraPassaggiMCDe = true;
                break;
            } else if(scelta == 110) { // 110 corrisponde a n
                printf("Hai scelto: no\n");
                mostraPassaggiMCDe = false;
                break;
            }
            printf("Attenzione! Risposta non valida.\n\tRiprova ----> ");
            while(getchar() != '\n');
        }
        
        while(getchar() != '\n'); // Funzione che pulisce il buffer di input
        printf("Mostrare i passaggi per MCD standard? (y/n) ----> ");
        while(scanf("%c", &scelta) == 1) {
            if(scelta == 121) { // 121 corrisponde a y
                printf("Hai scelto: si\n");
                mostraPassaggiMCDs = true;
                break;
            } else if(scelta == 110) { // 110 corrisponde a n
                printf("Hai scelto: no\n");
                mostraPassaggiMCDs = false;
                break;
            }
            printf("Attenzione! Risposta non valida.\n\tRiprova ----> ");
            while(getchar() != '\n');
        }
        
         printf("\n");
        /* Svolgimento */
        if(a==0 && b==0)
            printf("\nMCD tra a = %d e b = %d non e' definito\n", a, b);
        else
        {
            printf("\nMCD di Euclide tra a = %d e b = %d e' %d\n\n", a, b, Euc(a, b, mostraPassaggiMCDe));
            printf("\nMCD normale tra a = %d e b = %d e' %d\n\n", a, b, standard(a, b,mostraPassaggiMCDs));
        }

        while(getchar() != '\n'); // Funzione che pulisce il buffer di input
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
            while(getchar() != '\n');
        }
        //system("clear"); // Funzione che pulisce la console
        #ifdef _WIN32
            system("cls");
        #else
            // Assume POSIX
            system ("clear");
        #endif
    }
    return 0;
}

/*--------------------------------------------------------------------*/

int Euc(int x, int y, bool mostraPassaggi)
{
    /* Scambio valori Variabili */
    if(y>x){
        int appo = x;
        x = y;
        y = appo;
    }
    
    /* Dichiarazione Variabili */
    int q = 1;
    int r = 1;
    int mcde = 0;
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
        if(mostraPassaggi)
            printf("%d = %d * %d + %d\n", x, y, q, r);
        x = y;
        y = r;
    }
    
    time_euclide = clock() - time_euclide; // Tempo finale
    printf("\nTempo di esecuzione: %fs \n", (double)time_euclide/CLOCKS_PER_SEC);
    
    return mcde;
}

/*--------------------------------------------------------------------*/

int standard(int x, int y, bool mostraPassaggi)
{
     /* Scambio valori Variabili */
    if(y>x){
        int appo = x;
        x = y;
        y = appo;
    }
    
    /* Dichiarazione Variabili */
    int mcds = 0;
    int counters = y;
    clock_t time_euclide;

    /* Svolgimento */
    printf("|============================|\n");
    printf("| Calcolo con MCD normale    |\n");
    printf("|============================|\n");
    printf("Elaborazione...\n");
    
    time_euclide = clock(); //Tempo iniziale
    
    if(x == 0 && y == 0)
        return 0;
    else if(x == 0)
        return y;
    else if(y == 0)
        return x;
        
    while(counters != 0) {
        if(mostraPassaggi)
            printf("proviamo con %d\n", counters);
        if(((x % counters) == 0) && ((y % counters) == 0)) {
            mcds = counters;
            if(mostraPassaggi)
                printf("(a / %d) e (b / %d) MCD(a,b) = %d\n", counters, counters, counters);
            break;
        }
        counters--;
    }
    
    time_euclide = clock() - time_euclide; // Tempo finale
    printf("\nTempo di esecuzione: %fs \n", (double)time_euclide/CLOCKS_PER_SEC);
    
    return mcds;
}
