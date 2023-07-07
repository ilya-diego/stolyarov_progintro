/* remove all spaces from the string */
#include <stdio.h>

void delete_spaces(char *str)
{
    enum {spc = ' '};
    int i;
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == spc) {
            int j = i;
            int k = 1;
            while(str[j+k] == spc)
                k++;
            while(1) {
                str[j] = str[j+k];
                if(str[j] == '\0')
                    break;
                j += 1;
            }
        }
    }
}

int main()
{   
    char str[] = {"    H  e    ll o,  w  or     l  d!    "};
    printf("%s\n", str);
    delete_spaces(str);
    printf("%s\n", str);
    return 0;
}
