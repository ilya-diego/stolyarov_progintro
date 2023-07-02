/* Number of words per line */
#include <stdio.h>

int main()
{
    int c, n, wrd;                      /* n - number of the words */
    n = wrd = 0;                        /* wrd - word's indicator */
    while((c = getchar()) != EOF) {
        if(c == '\n') {
            printf("%d\n", n);
            n = wrd = 0;
            continue;
        } 
        if(c == ' ' || c == '\t') {
            wrd = 0;
            continue;
        }
        if(!wrd) {
            wrd = 1;                    /* new word begins */
            n++;
        }
    }
    return 0;
}
