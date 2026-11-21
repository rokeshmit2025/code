#include<stdio.h>
#define MAX 5
void selection(int [],int );
int main(){
    int arr[MAX],n;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    selection(arr,n);
    printf("The sorted array is\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
void selection(int arr[],int n){
    int posi=-1;
    for(int i=0;i<n;i++){
        posi=i;
        for(int j=i+1;j<n;j++){
            if(arr[posi]>arr[j]) {
                posi=j;
            }
        }
        if(posi!=i){
            int tem=arr[i];
            arr[i]=arr[posi];
            arr[posi]=tem;
        }
    }
}
