/* Counting the number of two-character combinations "()" */
#include <stdio.h>

int main()
{
    int c, opn, cls, n;
    opn = cls = n = 0;
    while((c = getchar()) != EOF) {
        if(c == '(') {
            opn = 1;
            continue;
        }
        if(c == ')') {
            if(opn) {
                opn = 0;
                n++;
            }
            continue;
        }
        if(c == '\n') {
            printf("%d\n", n);
            opn = cls = n = 0;
            continue;
        }
        /* any other character */
        opn = 0;
    }
    return 0;
}
