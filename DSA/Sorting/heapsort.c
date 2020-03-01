#include<stdlib.h>
#include <stdio.h>
int arr_size;
static int itre=0;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--) {
        swap(&arr[0],&arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        printf("%d\t",arr[i]);
    printf("\n");
}
int main()
{
    printf("Enter no of elements\n");
    scanf("%d",&arr_size);
    int arr[arr_size];
    for(int i=0;i<arr_size;i++){
        arr[i]=rand()%100+1;
    }
    heapSort(arr, arr_size);

    printf("Sorted array is \n");
    printArray(arr, arr_size);
}
