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
        // find the lowest value element in the unsorted portion
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