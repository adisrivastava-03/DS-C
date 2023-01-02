#include<stdio.h>
#include<stdbool.h>
#define n 7
int adj[n+1][n+1];
void bfs(int);
void dfs(int);
void ad_mat();
bool visited[n+1];

void main()
{
	int start;
	printf("\nEnter the Adjacency Matrx :-\n");
	ad_mat();
	printf("Enter the Start for BFS :- ");
	scanf("%d",&start);
	printf("\nBFS traversal for Graph:-\n");
	bfs(start);
	printf("\nEnter the Start for DFS :- ");
	scanf("%d",&start);
	printf("\nDFS traversal for Graph:-\n");
	for(int i=1;i<=n;i++)
		visited[i]=false;
	dfs(start);
	printf("\n");
}

void ad_mat()
{
	int max,i,source,dest;
	max=n*(n-1)/2;
	for(i=1;i<=max;i++)
	{
		printf("Enter the Start and Ending point of Vertex (0 0 to exit);-");
		scanf("%d%d",&source,&dest);
		if(source==0 && dest==0)
			break;
		if(source<0 || dest<0)
		{
			printf("\nInvalid edge \nRe-enter the edge");
			i--;
		}
		adj[source][dest]=1;
	}
}

void bfs(int start)
{
	int queue[n];
	int front=0,rear=0,u;
	queue[rear]=start;
	
	for(int j=1;j<=n;j++)
		visited[j]=false;
	
	while(front<=rear)
	{
		u=queue[front++];
		visited[u]=true;
		printf("%d\t",u);
		for(int i=1;i<=n;i++)
		{
			if(adj[u][i]==1 && visited[i]==false)
			{
				visited[i]=true;
				queue[++rear]=i;
				
			}
		}
	}
}

void dfs(int start)
{
	visited[start]=true;
	printf("%d\t",start);
	for(int i=1;i<=n;i++)
	{
		if(adj[start][i]==1 && visited[i]==false)
			dfs(i);
	}
}
	
	
