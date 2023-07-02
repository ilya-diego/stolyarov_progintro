/* The number of words with > than 7 letters and <= than 2 letters */
#include <stdio.h>

int main()
{
    int c, wrd, letters, more_7, less_2;
    wrd = letters = more_7 = less_2 = 0;
    while((c = getchar()) != EOF) {
        /* non-whitespace char */
        if(c != '\n' && c != ' ' && c != '\t') { 
            if(!wrd)
                wrd = 1;
            letters++;
            continue; 
        }
        /* the word is over, calculate the result */    
        if(wrd) 
            letters <= 2 ? less_2++ : (letters > 7 ? more_7++ : more_7);
        if(c == '\n') {
            /* end of the line */
            printf("> 7 letters: %d\n<= 2 letters: %d\n",   
                    more_7, less_2);
            wrd = letters = more_7 = less_2 = 0;
        } else { 
            /* whitespace or tab */
            wrd = letters = 0;
        }
    }
    return 0;
}
