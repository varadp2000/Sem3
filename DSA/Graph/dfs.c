//DFS traversal of graph using adjecency matrix

#include<stdio.h>
int stack[10];
int top=-1;

void push(int ele){
    stack[++top]=ele;
}
int pop(){
    return (stack[top--]);
}

void dfs(int graph[10][10],int n){
    int visited[n];
    for(int i=0;i<n;i++)
        visited[i]=0;
    int i=0;
    visited[i]=1;
    printf("%d\t",i);
    push(i);
    while(top!=-1){
        i=stack[top];
        pop();
        for(int j=0;j<n;j++){
            if(graph[i][j]==1&&visited[j]==0){
                visited[j]=1;
                push(j);
                printf("%d\t",j);
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
    dfs(graph,n);
    }
