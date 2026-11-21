#include<stdio.h>
#define MAX 500
void count_sort(int [],int);
int main(){
    int n,arr[MAX];
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the array element\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    count_sort(arr,n);
    printf("jhc\n");
    printf("The sorted array is\n");
    for(int i=0;i<n;i++) printf("%d\t",arr[i]);
}
void count_sort(int nums[],int n){
    int maxi=nums[0];
    for(int i=0;i<n;i++) if(nums[i]>maxi) maxi=nums[i];
    int count[maxi+1],copy[n];
    for(int i=0;i<=maxi;i++) count[i]=0;
    for(int i=0;i<n;i++){
        ++count[nums[i]];
    }
    for(int i=1;i<=maxi;i++) count[i]=count[i]+count[i-1];
    for(int i=n-1;i>=0;i--){
        copy[--count[nums[i]]]=nums[i];
    }
    for(int i=0;i<n;i++){
        nums[i]=copy[i];
    }
}
