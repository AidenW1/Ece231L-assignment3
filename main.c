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

	Array *arr = malloc(sizeof(Array));

	if(arr == NULL)
	{
		printf("Null error\n");
		return 1;
	}

	arr->size = array_size;

	arr->data = malloc(array_size * sizeof(double));
	if (arr->data == NULL)
	{
		printf("Allocation failed\n");
		free(arr);
		return 1;
	}

	for (int i = 0; i < arr->size; i++)
	{
		arr->data[i] = i *1.5;
	}

	output_array(arr);
	shift_array(arr);
	output_array(arr);

	free(arr->data);
	free(arr);
	return 0;
}

void output_array(Array *a)
{
	for (int i = 0;i < a->size; i++)
	{
		printf("%.2f ", a->data[i]);
	}
	printf("\n");
}

void shift_array(Array *a)
{
	double first = a->data[0];

	for (int i = 0;i < a->size - 1; i++)
	{
		a->data[i] = a->data[i+1];
	}
	a->data[a->size - 1] = first;
}
