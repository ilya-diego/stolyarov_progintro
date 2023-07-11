#include <stdio.h>

int str_len(const char *s) {
    const char *p;
    for(p = s; *p; p++)
        {}
    return (p - s);
}

void longest_arg(char **argv)
{
    int i, max_len, longest, tmp;
    for(i = 1, max_len = 0, longest = 0; argv[i]; i++) {
        tmp = str_len(argv[i]);
        if(tmp > max_len) {
            max_len = tmp;
            longest = i;
        }
    }
    printf("a) Longest argument: %s (%d)\n", argv[longest], max_len);
}

void no_repeated_letters(char **argv)
{
    int i;
    int no_match = 1;
    printf("b) Arguments with no repeating letters:\n");
    for(i = 1; argv[i]; i++) {
        int j;
        for(j = 0; argv[i][j]; j++) {
            int test;
            for(test = j+1; argv[i][test]; test++) {
                if(argv[i][j] == argv[i][test])
                    /* matching characters are found , no need to 
                     * check the string further => exit from two cycles */
                    goto found_repeat;
            }
        }
        printf("   %s\n", argv[i]);
        no_match = 0;
        found_repeat:
            continue;
    }
    if(no_match)
        printf("   (None)\n");
}

void at_and_points(char **argv)
{
    int i;
    int no_match = 1;
    printf("c) Arguments contains one '@' and at least one '.':\n");
    for(i = 1; argv[i]; i++) {
        int j, at, point;
        for(j = 0, at = 0; argv[i][j]; j++) {
            if(argv[i][j] == '@')
                at++;
        }
        for(j = 0, point = 0; argv[i][j]; j++) {
            if(argv[i][j] == '.') {
                point = 1;
                break;
            }
        }
        if(at == 1 && point) {
            printf("   %s\n", argv[i]);
            no_match = 0;
        }
    }
    if(no_match)
        printf("   (None)\n");
}

void only_digits(char **argv)
{
    int i;
    int no_match = 1;
    printf("d) Arguments contains only digits:\n");
    for(i = 1; argv[i]; i++) {
        int j, ok;
        ok = 1;
        for(j = 0; argv[i][j]; j++) {
            if(argv[i][j] < '0' || argv[i][j] > '9') {
                ok = 0;
                break;
            }
        }
        if(ok) {
            printf("   %s\n", argv[i]);
            no_match = 0;
        }
    }
    if(no_match)
        printf("   (None)\n");
}

void single_char(char **argv)
{
    int i;
    int no_match = 1;
    printf("e) Arguments consisting of identical characters:\n");
    for(i = 1; argv[i]; i++) {
        int ok = 1;
        int j;
        for(j = 1; argv[i][j]; j++) {
            if(argv[i][0] != argv[i][j]) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            printf("   %s\n", argv[i]);
            no_match = 0;
        }
    }
    if(no_match)
        printf("   (None)\n");
}

void latin_letter(char **argv)
{
    int i;
    int no_match = 1;
    printf("f) Arguments contains at least one latin letter:\n");
    for(i = 1; argv[i]; i++) {
        int j;
        int got_letter = 0;
        for(j = 0; argv[i][j]; j++) {
            if((argv[i][j] >= 'A' && argv[i][j] <= 'Z') || 
               (argv[i][j] >= 'a' && argv[i][j] <= 'z')) {
                got_letter = 1;
                break;
            }
        }
        if(got_letter) {
            printf("   %s\n", argv[i]);
            no_match = 0;
        }
    }
    if(no_match)
        printf("   (None)\n");
}

void common_char(char **argv)
{
    int i;
    int no_match = 1;
    printf("g) Arguments that have at least 1 common character ");
    printf("with 1st argument (%s):\n", argv[1]);
    for(i = 2; argv[i]; i++) {
        int j;
        for(j = 0; argv[i][j]; j++) {
            int k;
            for(k = 0; argv[1][k]; k++) {
                if(argv[1][k] == argv[i][j]) {
                    /* matching characters are found , no need to 
                     * check the string further => exit from two cycles */
                    goto found_match;
                }
            }
        }
        continue;
        found_match:
            printf("   %s\n", argv[i]);
            no_match = 0;
    }
    if(no_match)
        printf("   (None)\n");
}

int main(int argc, char **argv)
{
    if(argc < 2)
        return 0;
    longest_arg(argv);
    no_repeated_letters(argv);
    at_and_points(argv);
    only_digits(argv);
    single_char(argv);
    latin_letter(argv);
    common_char(argv);
    return 0;
}
