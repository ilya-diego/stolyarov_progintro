/* Checking the balance of parentheses */
#include <stdio.h>

int main()
{
    int c, bal, opn, cls;
    bal = 1;
    opn = cls = 0;
    while((c = getchar()) != EOF) {
        if(cls > opn)
            bal = 0;
        if(c == '(') {
            opn++;
            continue;
        }
        if(c == ')') {
            cls++;
            continue;
        }
        if(c == '\n') {
            puts(bal && opn == cls ? "YES" : "NO");
            bal = 1;
            opn = cls = 0;
        }
    }
    return 0;
}
