#include <stdio.h>

int	spaces_count(const char *s)
{
	int spc = 0;
	for( ; *s; s++) {
		if(*s == ' ')
			spc++;
	}
	return spc;
}

int main(int argc, char **argv)
{
	if(argc > 1)
		printf("%d\n", spaces_count(argv[1]));
	return 0;
}
