//BFS traversal of graph using adjecency matrix

#include<stdio.h>
int queue[10];
int f=-1 ,r=-1;
void enq(int ele)
{
 if(f==r && r==-1)
 {f=r=0;
   queue[r]=ele;
  }
  else if(r==4)
printf("queue is full\n");
  else
  {r++;
    queue[r]=ele;
  }
}
int dq()
{
  int a;
   if(f==r && r==-1)
  { printf("q is empty\n" );
}
else if(f==r)
{
  a=queue[f];
  f=-1;
  r=-1;
  return (a);
}
else
{
  a=queue[f];
  f++;
  return(a);
}

  }


void bfs(int graph[10][10],int n){
    int visited[n];
    for(int i=0;i<n;i++)
        visited[i]=0;
    int i=0;
    visited[i]=0;
    enq(i);
    while(f!=-1&&r!=-1){
        i=dq();
        printf("%d\t",i);
        for(int j=0;j<n;j++){
            if(graph[i][j]==1&&visited[j]==0){
                visited[j]=1;
                enq(j);
            }
        }

    }
}
void main(){
    int n;
    printf("Enter Vertices in Graph\n");
    scanf("%d",&n);
    int graph[n][n];
    for(int i=0;i<=n;i++){
        for(int j=0;j<n;j++)
            graph[i][j]=0;  
    }
    printf("Enter Adjecency Matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
        printf("\n");
    }
    printf("Adjecency Matrix is\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d\t",graph[i][j]);
        printf("\n");
        }
    printf("\n");
    bfs(graph,n);
    }
