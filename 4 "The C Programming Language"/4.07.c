#include <stdio.h>

int spaces_count(const char *s)
{
    int spc = 0;
    for( ; *s; s++) {
        if(*s == ' ')
            spc++;
    }
    return spc;
}

int main()
{
    char *s = {" H e l l o , w o r l d "};
    printf("%d\n", spaces_count(s));
    return 0;
}
