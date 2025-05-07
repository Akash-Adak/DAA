#include<stdio.h>
void merge(int arr[],int s,int m,int e){
	int i,j,k;
	int n1=m-s+1;
	int n2=e-m;
	int l[n1],r[n2];
	for(i=0;i<n1;i++){
		l[i]=arr[s+i];
	}
	for(j=0;j<n2;j++){
		r[j]=arr[m+1+j];
	}
	i=0,j=0,k=s;
	 while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            arr[k] =l[i];
            i++;
        } else {
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = l[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = r[j];
        j++;
        k++;
    }
	
}
 void mergeSort(int arr[],int s,int e){
 	if(s<e){
 		int mid=s+(e-s)/2;
 		mergeSort(arr,s,mid);
 		mergeSort(arr,mid+1,e);
 		merge(arr,s,mid,e);
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
    mergeSort(arr,0,n-1);
    printf("the sorted array is--\n");
    for(j=0;j<n;j++){
    	printf("%d ",arr[j]);
	}
	return 0;
}

