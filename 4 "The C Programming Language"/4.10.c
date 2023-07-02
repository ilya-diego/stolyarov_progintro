#include <stdio.h>

int main(int argc, char **argv)
{
	int n;
	for(n = 1; n < argc; n++) {
		if(argv[n][0] != '-')
			printf("%s\n", argv[n]);
	}
	return 0;
}
