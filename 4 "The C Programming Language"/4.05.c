#include <stdio.h>

int get_and_zero(int *n)
{
	int tmp = *n;
	*n = 0;
	return tmp;
}

int main()
{
	int n = 20;
	printf("%d %d\n", n, get_and_zero(&n));
	return 0;
}
