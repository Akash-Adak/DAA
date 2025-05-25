#include<stdio.h>
void merge(int arr[],int s,int mid,int e){
    int i,j,k;
    int n1=mid-s+1;
    int n2=e-mid;
    int left[n1],right[n2];
    for(i=0;i<n1;i++){
        left[i]=arr[s+i];
    } 
    for(j=0;j<n2;j++){
        right[j]=arr[mid+1+j];
    }
    i=0;
    j=0;
    k=s;
    while(i<n1 && j<n2){
        if(left[i]<= right[j]){
            arr[k]=left[i];
            i++;
            }
            else{
                arr[k]=right[j];
                j++;
                }
                k++;

    }
    while(i<n1 ){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2 ){
        arr[k]=right[j];
        j++;
        k++;
        }
    
}
void mergesort(int arr[],int s,int e){
    int mid=(s+e)/2;
    if(s<e){
        mergesort(arr,s,mid);
        mergesort(arr,mid+1,e);
        merge(arr,s,mid,e);
    }
}
int main(){
    printf("emter no of elements:");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("enter elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printf("sorted are  :");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}