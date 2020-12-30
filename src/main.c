#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "main.h"


int main() {


    FILE *dataFile;
    dataFile = fopen("rand-int.txt", "r");

    
    int i, *ptr, num;
    //first number in file equals the amount of numbers in file.
    fscanf(dataFile, "%d", &num);

    ptr = (int*) malloc(num * sizeof(int));
    
    // read file contents to array
    if (dataFile == NULL)
    {
        printf("Error Reading File\n");
        exit (0);
    }

    for (i = 0; i < num; i++)
    {
        fscanf(dataFile, "%d ", &ptr[i]);
    }


    AlgoChoice(ptr, num);
    }
