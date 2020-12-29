#include <stdio.h>
#include <stdlib.h>
#include<time.h>


int main(int argc, char **argv) {

    int num = atoi(argv[1]);
    int* arr;
    arr = (int*)malloc(num);
    
    // generates n numbers and adds to an array.
    srand(time(0));
    for (int i = 0; i < num; i++)
    {
        int num = rand();
        printf("%d ", num);
        arr[i] = num;
       
    }
    
    return 0;
   
}