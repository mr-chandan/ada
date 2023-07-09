#include <conio.h>
#include <stdio.h>

void main()
{
    int size;

    printf("enter the number of nodes");
    scanf("%d", &size);

    int graph[size][size], parent[size], weight[size], selected[size];
    printf("enter cost matrix");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("Enter the cost from vertex %d to vertex %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
}