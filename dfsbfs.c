#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int n;
void bfs(int adj[][n], int visited[], int start)

{
    int queue[n], r = -1, f = -1, i, k;

    for(int k=0;k<n;k++)
    {
        visited[k] = 0;
    }

    queue[++r] = start;
    f++;
    visited[start] = 1;

    while(r>=f)
    {
        start = queue[f++];
        printf("%c->", start+65);
        

        for(int i=0;i<n;i++)
        {
            if(adj[start][i] && visited[i] == 0)
            {
                queue[++r] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int adj[][n], int visited[], int start)
{
    int stack[n];
    int top = -1, i, k;
    for(int k=0;k<n;k++)
    {
        visited[k] = 0;
    }

    stack[++top] = start;
    visited[start] = 1;

    while(top!=1)
    {
        start = stack[top--];
        printf("%c->", start + 65);

        for(int i=0;i<n;i++)
        {
            if(adj[start][i] && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
                break;
            }
        }
    }
}
int main()
{

    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    int visited[n];
    int adj[n][n], i, j;

    int option, size;

    do
    {
        printf("\n 1. Enter the values in graph\n");
        printf("2. Breadth First Search\n");
        printf("3. Depth First Search\n");
        printf("4. Exit the program\n");

        printf("Enter the choice\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1: for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    scanf("%d", &adj[i][j]);
                }
            }
            break;

            case 2: printf("BFS Traversal is: \n");
                    bfs(adj, visited, 0);
                    break;

                    case 3: printf("DFS Traversal is: \n");
                    dfs(adj, visited, 0);
                    break;

                    case 4: exit(100);
                    break;

                    default: printf("Enter the valid choice\n");
        }
    }while(option != 4);
}