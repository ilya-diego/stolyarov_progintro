/* Print the number of words and the length of the longest and shortest */
#include <stdio.h>

int main()
{
    int c, wrd, letters, words, max, min;
    wrd = letters = words = max = min = 0;
    while((c = getchar()) != EOF) {
        if(c != '\n' && c != ' ' && c != '\t') {
            if(!wrd) {
                wrd = 1;
                words++;
            }
            letters++;
            continue;
        }
        if(wrd) {
            if(min == 0 || min > letters)
                min = letters;
            if(max == 0 || max < letters)
                max = letters;
        }
        if(c == '\n') {
            printf("Words: %d, Longest: %d, Shortest: %d\n",
                    words, max, min);
            words = max = min = 0;
        } 
        wrd = letters = 0;
    }
    return 0;
}
