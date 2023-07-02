#include <stdio.h>

int put_sum(int *a, int *b, int *c)
{
    int sum = *a + *b + *c;
    *a = *b = *c = sum;
    return sum;
}

int main()
{
    int a, b, c, s;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d %d %d\n", a, b, c);
    s = put_sum(&a, &b, &c);
    printf("%d %d %d %d\n", a, b, c, s);
    return 0;
}
