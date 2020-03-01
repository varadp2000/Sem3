#include<stdio.h>
#include<stdlib.h>
int n;
void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void selectionsort(int arr[],int size){
	int MIN_IDX,i,j;
		MIN_IDX=i;
		for(j=i+1;j<size;j++){
			if(arr[MIN_IDX]>arr[j])
				MIN_IDX=j;
		}
	swap(&arr[MIN_IDX],&arr[j]);

	}


void main(){
	printf("Enter no of elements\n");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		arr[i]=rand();//%100+1;
	}

    printf("\nSorted Array\n");
	//sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

}
