//Implementation of topological sort
#include<stdio.h>
#include<stdbool.h>
#define n 6
int adj[n+1][n+1],stack[n],top=-1;
bool visited[n+1];
void adjacency_matrix();
void topological_sort(int);
int main()
{
    int i;
    printf("\ncreate adjacency matrix:\n");
    adjacency_matrix();
    for(i=1;i<=n;i++)
        visited[i]=false;
    printf("\nThe topological ordering is:\n");
    for(i=1;i<=n;i++)
        if(visited[i]==false)
            topological_sort(i);
    while(top>=0)
        printf("%d\t",stack[top--]);
    return 0;
} 
void adjacency_matrix()
{
    int s,d,i,max;
    max=n*(n-1)/2;
    for(i=1;i<=max;i++)
    {
        printf("\nEnter the start & end point (0 0 to exit):");
        scanf("%d%d",&s,&d);
        if(s==0 && d==0)
        break;
        else if(s<0 || d<0)
        {
            printf("\nInvalid edge");
            i--;
            continue;
        }
        else
        {
            adj[s][d]=1;
        }
    }
}
void topological_sort(int i)
{
    int j;
    visited[i]=true;
    for(j=1;j<=n;j++)
    {
        if(adj[i][j]==1 && visited[j]==false)
            topological_sort(j);
    }
    stack[++top]=i;
}



