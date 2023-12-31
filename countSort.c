#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maximum(int A[], int n){
    int max=INT_MIN;
    for(int i = 0; i<n; i++){
        if(max<A[i]){
            max = A[i];
        }
    }
    return max;
}

//COUNT SORT
void countSort(int * A, int n){
    int i,j;
    // Find the maximum element in array
    int max=maximum(A, n);

    //create the count array
    int* count = (int *) malloc((max+1)*sizeof(int));

    //Initialize thr count array elements to 0. 
    for( i = 0; i<max+1; i++){
        count[i]=0;
    }

    //Increment the corresponding index in the count array
    for( i = 0; i<n; i++){
        count[A[i]]=count[A[i]] + 1;
    }
    i=0;      //counter for count array
    j=0;      //counter for given array

    while(i<=max){
        if(count[i]>0){
            A[j]=i;
            count[i]=count[i]-1;
            j++;
        }else{
            i++;
        }
    }

}
int main()
{

    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;

    printArray(A, n);
    countSort(A, 7);
    printArray(A, n);

    return 0;
}