#include<stdio.h>
#include<stdlib.h>
int n;
int partition(int arr[],int low,int high){
	int i;

	int pivot=arr[high];
	i=low-1;
	int temp;
	for(int j=low;j<=high;j++){
		if(pivot>arr[j]){
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}

	}
	temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	return (i+1);
}

void quicksort(int arr[],int low,int high){

	if(low<high){
		int pos=partition(arr,low,high);

		quicksort(arr,low,pos-1);
		quicksort(arr,pos+1,high);
	}
}


void main(){
	printf("Enter no of elements\n");
	scanf("%d",&n);
	int low,high,arr[n];
	for(int i=0;i<n;i++){
		arr[i]=rand()%100+1;
	}
	low=0;
	high=sizeof(arr)/sizeof(arr[0]);
	quicksort(arr,low,high);
	for(int i=low;i<high;i++){
		printf("%d\t",arr[i]);
	}
}
