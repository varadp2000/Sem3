//Adjecency Matrix for graph with directed edges
//Traversing Done in only one edge hence graph[v][u]=0;

#include<stdio.h>
void main(){
	int n;
	printf("Enter Vertices in Graph\n");
	scanf("%d",&n);
	int graph[n][n];
	for(int i=0;i<=n;i++){
		for(int j=0;j<n;j++)
			graph[i][j]=0;	
	}
	int e,v,u;
	printf("Enter Edges in graph\n");
	scanf("%d",&e);
	for(int i=1;i<=e;i++){
		printf("Edge No %d from\n",i);
		scanf("%d",&u);
		printf("%d to \n",u);
		scanf("%d",&v);
		graph[u-1][v-1]=1;
	}
	printf("Adjecency Matrix is\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d\t",graph[i][j]);
		printf("\n");

		}
	}
