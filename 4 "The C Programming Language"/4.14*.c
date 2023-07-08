/* remove all spaces from the string */
#include <stdio.h>

void delete_chars(char *s, char c)
{
    char *src;
    char *dst;
    src = dst = s;
    while(1) {
        if(*src != c) {
            *dst = *src;
            if(*dst == '\0')
                return;
            dst++;
        }
        src++;
    }
}

int main()
{   
    char s[] = {"    H  e    ll o,  w  or     l  d   !         "};
    printf("%s\n", s);
    delete_chars(s, ' ');
    printf("%s\n", s);
    return 0;
}
