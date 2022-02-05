#include<stdio.h>
#include<stdlib.h>
#define INFINITY 9999
     
 void floydeval(int a[20][20],int v)
 {int i,k,j,x[20][20];
    for( int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            x[i][j]= a[i][j];
        }
    }
    for(int k=0; k<v; k++)
    {
        for( int i=0; i<v; i++)
        {
            for(int j=0; j<v; j++)
            {
                if( x[k][i]+x[j][k] < x[i][j])
                {
                   x[i][j]=x[k][i] + x[j][k];
                }
            }
        }
    }
    printf("**********************\n");
    printf("FINAL MATRIX IS\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j <v ; j++)
        {
           printf("%d ", x[i][j]);
        }
        printf("\n");
        
    }
    
     
 }
int main(){
          
int i,v,j,a[20][20],x;
printf("**********************\n");
printf("ENTER THE NUMBER OF VERTICES\n");
scanf("%d",&v);
printf("**********************\n");
printf("ENTER THE WEIGHTED GRAPH MATRIX\n");
for(int i=0; i<v; i++)
{
    for (int j = 0; j < v; j++)
{
     printf("%d->%d\t",i+1,j+1);
     scanf("%d",&a[i][j]);
}

   
}
floydeval(a,v);
return 0;
}



   
