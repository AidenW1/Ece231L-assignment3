#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: ./main <size>\n");
		return 1;
	}

	int array_size = atoi(argv[1]);
	
	if (array_size <= 0)
	{
		printf("Incorrect Size\n");
		return 1;
	}	

	return 0;
}
