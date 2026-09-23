/*
Assignment 3 ECE231L
Aiden watt

Reads an array of any size from the comman line
it shifts averages it and outputs it all

AI USE:
used claude to translate between java code and C
example: Systeme.out.printf("xyz",a,b,c); and its syntax

Had to have help with malloc and what its doing that java takes care of
sames idea for the array and that im passing the pointer to the data and what that means
It feels wrong to not have variables and it just be where the data lives and thats
what im passing along but ok C you do you
*/
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(int argc, char *argv[])
{

	//taking in size argument and making sure its the right size and thing
	if (argc != 2)
	{
		printf("Usage: ./main <size>\n");
		return 1;
	}

	int array_size = atoi(argv[1]);

	//now making sure its not a negative or 0
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

	//start of the reading of the data into the array and making sure it worked
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
		arr->data[i] = i * i;
	}

	//THE PRINTER
	//section of print out all the different methods and output method
	output_array(arr);

	shift_array(arr);
	output_array(arr);

	Array *avg = average_adjacent(arr);
	output_array(avg);

	free(arr->data);
	free(arr);

	free(avg->data);
	free(avg);

	return 0;
}

//output method nuff said
//java being the most recent this feels just a lil weird to write
//and it looks wrong everytime i give it the quick glance
void output_array(Array *a)
{
	for (int i = 0;i < a->size; i++)
	{
		printf("%.2f ", a->data[i]);
	}
	printf("\n");
}

//shift array this is just math and KNOWLEDGE also takeing first
//and sticking it on the end
void shift_array(Array *a)
{
	double first = a->data[0];

	for (int i = 0;i < a->size - 1; i++)
	{
		a->data[i] = a->data[i+1];
	}
	a->data[a->size - 1] = first;
}

//weirdest one yet dealing with all this C memory and pointer thingies
Array *average_adjacent(Array *a)
{

	Array *arr = malloc(sizeof(Array));

	if(arr == NULL)
	{
		printf("Null error\n");
		return NULL;
	}

	//start of the averaging because averaging an array is half of it
	arr->size = a->size / 2;

	arr->data = malloc(arr->size * sizeof(double));
	if (arr->data == NULL)
	{
		printf("Allocation failed\n");
		free(arr);
		return NULL;
	}

	//this is just averaging math again the two data pointers added together
	//then divided by 2 and put at index j
	for (int j = 0; j < arr->size; j++)
	{
		arr->data[j] = (a->data[2 * j] + a->data[2 * j + 1]) / 2;
	}

	return arr;
}


