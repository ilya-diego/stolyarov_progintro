/* Print the length of the longest word, the longest sequence of whitepaces */
#include <stdio.h>

int main()
{
    int c, letters, spaces, max_wrd, max_spc;
    letters = spaces = max_wrd = max_spc = 0;
    while((c = getchar()) != EOF) {
        if(c != '\n' && c != ' ' && c != '\t') {
            letters++;
            if(max_wrd < letters)
                max_wrd = letters;
            spaces = 0;
            continue;
        }
        if(c == ' ' || c == '\t') {
            spaces++;
            if(max_spc < spaces)
                max_spc = spaces;
            letters = 0;
            continue;
        }
        if(c == '\n') {
            printf("Longest word: %d, Longest sequence of spaces: %d\n",
                    max_wrd, max_spc);
            letters = spaces = max_wrd = max_spc = 0;
        }
    }
    return 0;
}
