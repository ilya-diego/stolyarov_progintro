/* Number of words with an odd/even number of letters */
#include <stdio.h>

int main()
{
    int c, wrd, letters, odd, even;
    wrd = letters = odd = even = 0;
    while((c = getchar()) != EOF) {
        if(c != '\n' && c != ' ' && c != '\t') { /*non-whitespace char*/
            if(!wrd)
                wrd = 1;                         /* word indicator */
            letters++;
            continue;                            /* next char */
        }
        if(wrd)                                  /* the word is over  */    
            letters % 2 == 0 ? even++ : odd++;   /* counting letters  */
        if(c == '\n') {              /* end of the line, print result */
            printf("odd: %d, even: %d\n", odd, even); 
            wrd = letters = odd = even = 0;
        } else {                                 /* whitespace or tab */
            wrd = letters = 0;
        }
    }
    return 0;
}
