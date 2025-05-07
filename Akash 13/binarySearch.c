#include<stdio.h>
 int binarySearch(int arr[],int search,int n){
 		int s=0,e=n-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]==search){
		  return mid;
		
		}
		else if(arr[mid]>search) e=mid-1;
		else s=mid+1;
	}
	return -1;
 }
int main(){
	int n,i,search;
	printf("enter the size of array=");
	scanf("%d",&n);
	int arr[n];
	printf("enter theelements=\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("enter the search number=");
	scanf("%d",&search);
    int res=binarySearch(arr,search,n);
    if(res!=-1)
	printf("element found at = %d",res+1);
	else 	printf("element not found!");
	
}
