#include<stdio.h>
#define MAX 100
#define VAL 999999
int d[MAX],parent[MAX],visit[MAX],adj[MAX][MAX],n,ans[MAX][MAX],k=0;
void prims(int);
int main(){
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    int source;
    printf("Enter the source \n");
    scanf("%d",&source);
    prims(source);
    printf("The value is \n");
    for(int i=0;i<k;i++){
        printf("%d\t\t%d",ans[0][i],ans[1][i]);
        printf("\n");
    }
}
void prims(int source){
    int min,u;
   for(int i=0;i<n;i++){
    parent[i]=source;
    d[i]=adj[source][i];
    visit[i]=0;
   }
   visit[source]=1;
   for(int i=0;i<n-1;i++){
     min=VAL;
     u=-1;
     for(int j=0;j<n;j++){
        if(visit[j]==0 && d[j]<min){
            min=d[j];
            u=j;
        }
    }
        visit[u]=1;
        ans[0][k]=parent[u];
        ans[1][k]=u;
        k++;
        for(int v=0;v<n;v++){
            if(visit[v]==0 && adj[u][v]!=0 && adj[u][v]<d[v]){
                    d[v]=adj[u][v];
                    parent[v]=u;
                
            }
        }
     
   }
}
