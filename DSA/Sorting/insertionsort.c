#include <stdio.h>
#include<stdlib.h>
void insertionsort(int arr[],int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=arr[i];
		j=i-1;
		while(arr[j]>temp && j>=0){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}

void main(){
	int n;
	printf("Enter Size of Array");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		arr[i]=rand()%100+1;
	insertionsort(arr,n);
	for(int i=0;i<n;i++)
		printf("%d\t",arr[i]);
}