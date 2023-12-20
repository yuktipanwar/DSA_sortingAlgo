#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// SELECTION SORT
void selectionSort(int *A, int n)
{

    printf("Running selection sort...\n");

    int indexOfMin, temp;
    for (int i = 0; i < (n - 1); i++)
    { // loop for passes
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            { // set the index of min value in the unsorted part as 'indexOf

                indexOfMin = j;
                
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}


int main()
{

    int A[] = {3, 5, 2, 13, 2};
    int n = 5;

    // DRY RUN
    //  Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //   00  01  02  03  04
    //  |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13

    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);

    return 0;
}
