#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int *A, int n)
{

    int temp;
    for (int i = 0; i < (n - 1); i++)
    { // loop for number of passes

        for (int j = 0; j < (n - 1 - i); j++)
        { // loop for comparions

            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

// n     -1       -i      passes
// 6      -1        0      pass 1
// 5      -2       -1      pass 2
// 4      -3       -2      pass 3....


//MAKING BUBBLE SORT ADAPTIVE
void bubbleSortAdaptive(int *A, int n)
{

    int temp;
    int isSorted = 0; // for making bubble sort adaptive
    for (int i = 0; i < (n - 1); i++)
    { // loop for number of passes

        printf("Working on pass number %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < (n - 1 - i); j++)
        { // loop for comparions

            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}



int main()
{

    int A[] = {12, 54, 65, 7, 23, 9};
    int B[] = {1, 2, 3, 4, 5, 6};
    int n = 6;

    printArray(A, n); // Printing Array before sorting
    bubbleSortAdaptive(A, n); // Function to sort the array
    printArray(A, n); // Printing Array after sorting

    printf("\n");

    printArray(B, n); // Printing Array before sorting
    bubbleSortAdaptive(B, n); // Function to sort the array
    printArray(B, n); // Printing Array after sorting

    return 0;
}