#include<stdio.h>
#include<stdbool.h>
#define MAX 9999
#define INF 9999

#define V 5
struct source{
int G[V][V];
}arr[V];
int total=0;
int bb[V];
void mst(){
    int no_edge;
  bool selected[V];
  for(int i=0;i<V;i++)
    selected[i]=false;
    no_edge = 0;
  selected[0] = true;
  int x;
  int y;
  printf("Edge : Weight\n");
  for(int k=0;k<V;k++){
  while (no_edge < V - 1) {
   int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && arr[k].G[i][j]) {
            if (min > arr[k].G[i][j]) {
              min = arr[k].G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, arr[k].G[x][y]);
    total+=arr[k].G[x][y];
    selected[y] = true;
    no_edge++;
  }}
}
int minimumDist(int dist[], bool Tset[]) 
{
 int min=INF,index;
              
 for(int i=0;i<6;i++) 
 {
  if(Tset[i]==false && dist[i]<=min)      
  {
   min=dist[i];
   index=i;
  }
 }
 return index;
}

void dijikstra(int graph[V][V],int src)
{
 int dist[V];                        
 bool Tset[V];
 for(int i = 0; i<V; i++)
 {
  dist[i] = INF;
  Tset[i] = false; 
 }
	
 dist[src] = 0;           
	
 for(int i = 0; i<V; i++)                           
 {
  int m=minimumDist(dist,Tset); 
  Tset[m]=true;
  for(int i = 0; i<V; i++)                  
  {
   
   if(!Tset[i] && graph[m][i] && dist[m]!=INF && dist[m]+graph[m][i]<dist[i])
    dist[i]=dist[m]+graph[m][i];
  }
 }
 for(int i = 0; i<V; i++)                      
 { if(i==0)
           bb[i]=dist[i];
  printf("%d\n",bb[i]+dist[i]);
 }
}


int main(){
    int i,j,k;
    for(k=0;k<V;k++){
    printf("\nEnter the adjacency matrix::\n");
 for(i=0;i < V;i++)
  for(j=0;j < V;j++)
   scanf("%d", &arr[k].G[i][j]);}
   for(int y=0;y<V;y++){
   printf("For %d\n",y);
   mst(arr);}
   printf("Total cost %d\n",total*10000);
   for(int h=0;h<V;h++)
   dijikstra(arr[h].G,0);
   return 0;
}