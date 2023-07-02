#include <stdio.h>

int spaces_count_rec(const char *s)
{
    int spc = 0;
    if(!*s) {
        return 0;
    }
    else {
        if(*s == ' ')
            spc++;
        return(spaces_count_rec(s+1) + spc);
    }
}

int main()
{
    char *s = {" H e l l o , w o r l d "};
    printf("%d\n", spaces_count_rec(s));
    return 0;
}
