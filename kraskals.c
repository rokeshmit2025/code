#include<stdio.h>
#define MAX 100
#define VAL 99999
int adj[MAX][MAX],n,parent[MAX];
int find(int);
void kraskals();
int main(){
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the array input\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    kraskals();
}
void kraskals(){
    int u,v,edge=0,weight=0,mini,i,j;
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
     while(edge<n-1){
        u=-1,v=-1,mini=VAL;
        for( i=0;i<n;i++){
            for( j=i+1;j<n;j++){
                 int a=adj[i][j];
                 int b=adj[j][i];
                 if(a==0 && b==0 ) continue;
                 else if(a==0) weight=b;
                 else if(b==0) weight=a;
                 else weight=(a<b)?a:b;
                if(mini>weight){
                    mini=weight;
                u=i;
                v=j;
                }
            }
        }
                int root1=find(u);
                int root2=find(v);
                if(root1!=root2){
                    parent[root1]=root2;
                    printf("%d-%d",u,v);
                    printf("\n");
                      edge++;
                }
                adj[u][v]=VAL;
                adj[v][u]=VAL;
     }
              
        }
 int find(int vertex){
            while(vertex!=parent[vertex]) vertex=parent[vertex];
            return vertex;
        }