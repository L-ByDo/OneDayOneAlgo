#include <stdio.h>
#include<conio.h>
#define INF 999
#define MAX 10
void printMatrix(int matrix[MAX][MAX],int);

// Implementing floyd warshall algorithm
void floydWarshall(int graph[][MAX],int nv)
 {
  int matrix[MAX][MAX], i, j, k;

  for (i = 1; i <=nv; i++)
    for (j = 1; j <= nv; j++)
      matrix[i][j] = graph[i][j];

  // Adding vertices individually
  for (k = 1; k <= nv; k++) 
  {
    for (i = 1; i <= nv; i++) 
    {
      for (j = 1; j <= nv; j++) 
      {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  for ( i = 1; i <= nv; i++)
   {
    for ( j = 1; j <= nv; j++) 
    {
      if (matrix[i][j] ==999)
        printf("999");
      else
        printf("%d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() 
{
    int nv,i,j,graph[MAX][MAX];
printf("\nEnter the number of nodes:");
 	scanf("%d",&nv);
 	printf("\nEnter the adjacency matrix:\n");
	for(i=1;i<=nv;i++)
	for(j=1;j<=nv;j++)
 	{
        scanf("%d",&graph[i][j]);
 		if(graph[i][j]==0 && i!=j)
         {
             	graph[i][j]=999;
         } 
	}
  floydWarshall(graph,nv);
}