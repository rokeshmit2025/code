#include<stdio.h>
#define MAX 100
int arr[MAX][MAX],n,indeg[MAX],front=-1,rear=-1,queue[MAX],topo[MAX];
int indegree(int);
int enqueue(int);
int dequeue();
int main(){
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the adjacency list\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    } 
     for(int i=0;i<n;i++){
        indeg[i]=indegree(i);
        if(indeg[i]==0) enqueue(i);
     }
     int j=0;
     while(front!=-1 && front<=rear){
        int val=dequeue();
        topo[j]=val;
        j++;
        for(int i=0;i<n;i++){
            if(arr[val][i]!=0){
                arr[val][i]=0;
                indeg[i]--;
                if(indeg[i]==0) enqueue(i);
            }
        }
     }
     printf("the topological sort is\n");
     for(int i=0;i<j;i++){
        printf("%d\t",topo[i]);
     }
}
int indegree(int tar){
     int sum=0;
     for(int i=0;i<n;i++){
        sum+=arr[i][tar];
     }
     return sum;
}
int enqueue(int val){
    if(front==-1 && rear==-1){
        front=0,rear=0;
        queue[rear]=val;
    }
    else if(rear==MAX-1) printf("Over flow\n");
    else{
        rear++;
        queue[rear]=val;
    }
}
int dequeue(){
    if(front==-1 || front>rear) printf("Under flow\n");
    else {
        int val=queue[front];
        front++;
        return val;
    }
}
