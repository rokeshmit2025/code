#include<stdio.h>
#define MAX 100
void radix_sort(int [],int,int);
int main(){
    int arr[MAX],n;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the array elemets\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int maxi=arr[0];
    for(int i=0;i<n;i++){
         if(maxi<arr[i]) maxi=arr[i];
    }
    for(int posi=1;maxi/posi>0;posi*=10) radix_sort(arr,n,posi);
    printf("The sorted array is\n");
    for(int i=0;i<n;i++) printf("%d\t",arr[i]);
}
void radix_sort(int nums[],int n,int p){
    int count[10]={0},copy[n];
    for(int i=0;i<n;i++){
        ++count[(nums[i]/p)%10];
    }
    for(int i=1;i<=9;i++){
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--){
       copy[--count[(nums[i]/p)%10]]=nums[i];
    }
    for(int i=0;i<n;i++){
        nums[i]=copy[i];
    }

}