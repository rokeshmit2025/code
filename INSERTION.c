#include<stdio.h>
#define MAX 5
void insertion(int [],int);
int main() {
   int n,arr[MAX];
   printf("enter the size of array\n");
   scanf("%d",&n);
   for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
   }
   insertion(arr,n);
   printf("The sorted array i s\n");
   for(int i=0;i<n;i++) printf("%d\t",arr[i]);
}
void insertion(int arr[],int n){
    int tem,j;
    for(int i=1;i<n;i++){
        tem=arr[i];
        for( j=i-1;j>=0;j--){
            if(tem<arr[j]) arr[j+1]=arr[j];
            else break;
        }
        arr[j+1]=tem;
    }
}