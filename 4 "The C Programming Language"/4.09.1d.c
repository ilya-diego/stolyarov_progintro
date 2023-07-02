/* The number of words starting with 'A' and ending with 'z' */
#include <stdio.h>

int main()
{
    int c, wrd, a_word, word_z, az_words;
    wrd = a_word = word_z = az_words = 0;
    while((c = getchar()) != EOF) {
        if(c != '\n' && c != ' ' && c != '\t') {
            if(!wrd) {
                c == 'A' ? (a_word = 1) : (a_word = 0);
                wrd = 1;
            } else {
                c == 'z' ? (word_z = 1) : (word_z = 0);
            }
            continue;
        }
        (a_word && word_z) ? az_words++ : az_words;
        if(c == '\n') {
            printf("A*z words: %d\n", az_words);
            az_words = 0;
        }
        wrd = a_word = word_z = 0;
    }   
    return 0;
}
