// header file to store sorting algorithms.

// swap function to swap ints in array
void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}



// selection sort

void selction_sort(int arr[], int n)
{
    int i, j, min;

    // move through the array
    for (i = 0; i < n; i++)
    {
        min = i;
        // find the lest value element in the unsorted portion
        for (j=i+1; j< n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }  
        }
        // swap 
        swap(&arr[min], &arr[i]);
    }
}

void insertion_sort(int arr[], int n)
{
    int i,j,k;

    // traverse through arr
    for (i = 1; i < n; i++)
    {
        k = arr[i];
        // move any element greater than k one pos up the arr
        j = i - 1;
        while (j >= 0 && k < arr[j])
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;   
    }
    
}

// quicksort

int partition (int arr[], int l, int h) 
{ 
    int pivot = arr[h];    // pivot 
    int i = (l - 1);  // Index of smaller element 
  
    for (int j = l; j <= h- 1; j++) 
    { 
        // If pivot > element, increment index of element
        if (arr[j] < pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[h]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort  */
void quickSort(int arr[], int l, int h) 
{ 
    if (l < h) 
    { 
        /* pi is the index of the partition, arr[p] is now 
           at right place */
        int pi = partition(arr, l, h); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, l, pi - 1); 
        quickSort(arr, pi + 1, h); 
    } 
} 


// print the sorted array
void printArray(int arr[], int n)   
{ 
    int i; 
    for (i=0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 


int compare_ints (const void *a, const void *b)
{
    const int *da = (const int *) a;
    const int *db = (const int *) b;

    return (*da > *db - (*da < *db));
}

int reverse_ints (const void *a, const void *b)
{
    const int *da = (const int *) a;
    const int *db = (const int *) b;

    return (*da < *db - (*da > *db));
}


//takes arr and length of arr as parameters
// user selects algorithm to test.
int AlgoChoice(int ptr[], int num)
    {
        int algo;
        printf("Which algorithm would you like to test?\nEnter 1 for selection sort, 2 for Insertion sort or 3 for Quick-sort.\nPlease select: ");
        scanf("%d", &algo);
        //selection sort
        if (algo == 1)
        {
            clock_t t;
            t = clock();
            selction_sort(ptr, num);
            t = clock() - t;
            printf("Elapsed time for selection sort: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);
        }
        //insertion sort
        else if (algo == 2)
        {
            clock_t t;
            t = clock();
            insertion_sort(ptr, num);
            t = clock() - t;
            printf("Elapsed time for insertion sort: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);
        }
        // quicksort
        else if (algo == 3)
        {
            clock_t t;
            t = clock();
            quickSort(ptr, 0, num - 1);
            t = clock() - t;
            printf("Elapsed time for quick-sort: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);
        }
        // wrong input
        else
        {
            printf("invalid choice. please select 1, 2 or 3");
            return 0;
        }
}

//takes arr and length of arr as parameters
// user selects whether to sort, reverse numbers or keep them random
int Data(int arr[], int num)
{
    int c;
    printf("How would you like to test the data?\nEnter 1 for random order, 2 for sorted or 3 for reverse sorted.\nPlease select: ");
    scanf("%d", &c);
    if(c == 1)
    {
        return 0;
    }
    else if (c == 2)
    {
        qsort(arr, num, sizeof(int), compare_ints);
    }
    else if (c == 3)
    {
        qsort(arr, num, sizeof(int), reverse_ints);
    }
    else
    {
        printf("invalid choice. please select 1, 2 or 3");
        return 0;
    }
}
    