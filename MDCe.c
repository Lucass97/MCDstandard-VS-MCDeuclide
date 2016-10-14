/*  Programma per verificare la velocita di calcolo tra MCD con metodo
*   tradizionale e con l' algoritmo di Euclide
*/

#include <stdio.h>
#include <stdbool.h>

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

        printf("Inserire a ----> ");
        while(scanf("%d", &a) != 1) {
            printf("Attenzione! Quello che hai inserito non e' un numero.\n\tRiprova ----> ");
            while(getchar() != '\n')
                ;
        }
        printf("Inserire b ----> ");
        while(scanf("%d", &b) != 1) {
            printf("Attenzione! Quello che hai inserito non e' un numero.\n\tRiprova ----> ");
            while(getchar() != '\n')
                ;
        }

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
            ;
        printf("Vuoi effetturare un altro calcolo? (y/n) ----> ");
        while(scanf("%c", &scelta) == 1) {
            if(scelta == 121) {
                printf("Hai scelto: si\n");
                break;
            } else if(scelta == 110) {
                printf("Hai scelto: no\n");
                return 0;
            }
            printf("Attenzione! Risposta non valida.\n\tRiprova ----> ");
            while(getchar() != '\n')
                ;
        }
        system("cls");
    }
    return 0;
}

/*--------------------------------------------------------------------*/

int Euc(int x, int y)
{
    /* Dichiarazione Variabili */
    int q = 1;
    int r = 1;
    int mcde = 0;

    /* Svolgimento */
    printf("\nElaborazione...\n");
    while(y != 0) {
        mcde = y;
        q = x / y;
        r = x % y;
        printf("%d = %d * %d + %d\n", x, y, q, r);
        x = y;
        y = r;
    }

    if(x == 0 && y == 0)
        return 0;
    else if(x == 0)
        return y;
    else if(y == 0)
        return x;
    return mcde;
}

/*--------------------------------------------------------------------*/

int standard(int x, int y)
{
    /* Dichiarazione Variabili */
    int mcds = 0;
    int counters = 1;

    printf("Elaborazione...\n");

    while(counters <= y) {
        printf("proviamo con %d\n", counters);
        if(((x % counters) == 0) && ((y % counters) == 0)) {
            printf("%d > %d\n", counters, mcds);
            mcds = counters;
            printf("(a / %d) e (b / %d) MCD(a,b) = %d\n", counters, counters, counters);
        }

        counters++;
    }
    printf("\n");

    if(x == 0 && y == 0)
        return 0;
    else if(x == 0)
        return y;
    else if(y == 0)
        return x;
    return mcds;
}
