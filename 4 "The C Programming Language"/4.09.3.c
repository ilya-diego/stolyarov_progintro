/* Print only 2-letter words */
#include <stdio.h>

int main()
{
    enum {des_len = 2};  /* desired length */
    int c, str_len, prnt;
    char str[des_len];
    
    str_len = prnt = 0;
    while((c = getchar()) != EOF) {
        if(c != '\n' && c != ' ' && c != '\t') {
            if(str_len < des_len)
                str[str_len] = c;
            str_len++;
            continue;
        }
        if(str_len == des_len) {
            printf("%s ", str);
            prnt = 1;
        }
        if(c == '\n' && prnt) {
            putchar('\n');
            prnt = 0;
        }
        str_len = 0;
    }
    return 0;
}
