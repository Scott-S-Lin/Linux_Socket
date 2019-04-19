#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int *array;
    int size;
    int i;
    
    scanf("%d", &size);
    	
    array = (int*)malloc(size*sizeof(int));
    
	for(i=0; i<size; i++)
		array[i] = i;

    free(array);    
    exit(0);
}

