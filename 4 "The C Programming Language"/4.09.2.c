/* Print words in parentheses */
/* Variable 'emp' is optional here, it's used for a better appearance */
#include <stdio.h>

int main()
{
    int c, wrd, emp;
    wrd = 0;
    emp = 1; /* line with no words */
    while((c = getchar()) != EOF) {
        if(c != ' ' && c != '\t' && c != '\n') {
            emp = 0;
            if(!wrd) {
                printf("(%c", c);
                wrd = 1;
            } else {
                putchar(c);
            }
            continue;
        }
        /* whitespace, '\t' or '\n' */
        if(wrd) {
            putchar(')');
            wrd = 0;
        }
        if(c == '\n' && !emp) {
            /* put '\n' only if the line contains words */
            putchar('\n');
            emp = 1;
        }
    }
    return 0;
}
