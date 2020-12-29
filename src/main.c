#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "main.h"


int main(int argc, char **argv) {

    

    int *ptr, num = atoi(argv[1]);
    
    ptr = (int*)malloc(num * sizeof(int));
    
    // generates n numbers and adds to an array.
    srand(time(0));
    for (int i = 0; i < num; i++)
    {
        int num = rand();
        ptr[i] = num;
       
    }
    
   
    qsort(ptr, num, sizeof(int), compare_ints);
   
    
    clock_t t;
    t = clock();
    //selction_sort(ptr, num);//
    //insertion_sort(ptr, num);//
    t = clock() - t;

    printf("Elapsed time: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);
    return 0;
}
