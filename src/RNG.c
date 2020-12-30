#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Program for generating datasets//
int main()
{
    FILE *dataFile;
    dataFile = fopen("rand-int.txt", "w");

    int num;
    printf("How many numbers would you like to generate?: ");
    scanf("%d", &num);
    fprintf(dataFile, "%d ", num);
    
    // generates n numbers and writes to file.
    srand(time(0));
    for (int i = 0; i < num; i++)
    {
        int num = rand();
        fprintf(dataFile, "%d ", num);
       
    }

    fclose(dataFile);
}
