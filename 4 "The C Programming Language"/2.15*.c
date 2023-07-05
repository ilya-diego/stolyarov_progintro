#include <stdio.h>

void print_line(int n, char c, char spc)
{
    int i;
    for(i = 0; i < n; i++)
        putchar(c);
    putchar(spc);
}

void print_mid(int h, int l, char c, char spc)
{
    int i;
    for(i = 0; i < h-l; i++)
        putchar(spc);
    putchar(c);
    for(i = 0; i < l-1; i++)
        putchar(spc);
    putchar(spc);
}

int main()
{
    int h, amount, num, l, lines_total;
    char ch = '*';
    char spc = ' ';
    char *msg = {"Height = "};
    char *msg2 = {"Amount = "};
    char *err = {"Please type an odd number >= 5\n"};
    
    while(printf("%s", msg), scanf("%d", &h), h < 5 || h % 2 == 0)
        printf("%s", err);
    printf("%s", msg2);
    scanf("%d", &amount);
    if(amount < 1)
        return 0;
    
    /* size of the full field */
    lines_total = h + amount*(h/2) - h/2;
    
    for(l = 1; l <= lines_total; l++) {
        for(num = 0; num < amount; num++) {
            /* distance to the top of the figure */
            int to_top;
            to_top = num*(h/2);
            /* print top, middle and bottom of the figure */
            if(l == to_top + 1 || l == to_top + h/2+1 ||
                l == to_top + h) {
                print_line(h, ch, spc);
            } else {
                /* print the area between top and bottom,
                 * except the middle */
                if((l > to_top + 1 && l < to_top + h/2+1) ||
                    (l > to_top + h/2+1 && l < to_top + h)) {
                    print_mid(h, l-to_top, ch, spc);
                } else {
                    /* print an empty line */
                    print_line(h, spc, spc);
                }
            }
        }
        putchar('\n');
    }
}
