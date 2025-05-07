#include<stdio.h>
void findMinMax(int arr[],int l,int h,int *min,int *max){
	int minLeft,minRight,maxLeft,maxRight;
	if(l==h){
		*min=arr[l];
		*max=arr[l];
		return;
	}
	if(h==l+1){
		if(arr[l]<arr[h]){
		*min=arr[l];
		*max=arr[h];	
		}else{
			*min=arr[h];
	     	*max=arr[l];
		}
		return;
	}
	
	int mid=l+(h-l)/2;
	findMinMax(arr,l,mid,&minLeft,&maxLeft);
	findMinMax(arr,mid+1,h,&minRight,&maxRight);
	
	*min=(minLeft<minRight)? minLeft:minRight;
	*max=(maxLeft>maxRight)? maxLeft: maxRight;
}
int main(){
	int n,i;
	printf("enter the size of array=");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements=\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int min,max;
	findMinMax(arr,0,n-1,&min,&max);
	printf("the minimum element is =%d",min);
	printf("\nthe maximum element is =%d",max);
	return 0;
}

