#include<stdio.h>
int quick(int arr[],int s,int e){
	int pivot=arr[e];
	 int i=s-1;
	 int j;
	 for(j=s;j<e;j++){
	 	if(arr[j]<pivot){
	 		i++;
	 		int temp=arr[i];
	 		arr[i]=arr[j];
	 		arr[j]=temp;
		 }
		 
	 }
	 int t=arr[i+1];
		 arr[i+1]=arr[e];
		 arr[e]=t;
	 return i+1;
	
}
void quickSort(int arr[],int s,int e){
	if(s<e){
		int pi=quick(arr,s,e);
		
		quickSort(arr,s,pi-1);
		quickSort(arr,pi+1,e);
	}
}
int main(){
	int n,i,j;
	printf("enter the size of array=");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements=\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
    quickSort(arr,0,n-1);
    printf("the sorted array is--\n");
    for(j=0;j<n;j++){
    	printf("%d ",arr[j]);
	}
	return 0;
}
