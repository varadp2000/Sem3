#include<stdio.h>
#include<stdlib.h>
int n;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void bubblesort(int arr[], int size){
	int i,j,k;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-i-1;j++)
			if(arr[j]>arr[j+1])
				swap(&arr[j],&arr[j+1]);
	
	}

}

void main(){
	printf("Enter no of elements\n");
	scanf("%d",&n);					
	int arr[n];
	for(int i=0;i<n;i++){
		arr[i]=rand()%100+1;
	}
	bubblesort(arr,n);
	for(int i=0;i<n;i++)
		printf("%d\t",arr[i]);
}