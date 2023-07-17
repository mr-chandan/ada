#include <stdio.h>
#include <conio.h>

int minimumof(int weight[], int selected[], int n)
{
    int min = 999;
    int i = 0;
    int minindex;
    for (i = 0; i < n; i++)
    {
        if (selected[i] != 1 && weight[i] < min)
        {
            min = weight[i];
            minindex = i;
        }
    }
    return minindex;
}

void main()
{
    int parent[10], graph[15][15], weight[10], selected[10], n, i, j, min, z;
    int totalWeight = 0;

    printf("enter the nop of nodes");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (j = 0; j < n; j++)
    {
        weight[j] = 999;
        selected[j] = 0;
        parent[j] = -1;
    }

    weight[0] = 0;

    for (j = 0; j < n; j++)
    {
        min = minimumof(weight, selected, n);

        selected[min] = 1;
        for (z = 0; z < n; z++)
        {
            if (graph[min][z] != 0 && selected[z] == 0 && graph[min][z] < weight[z])
            {
                weight[z] = graph[min][z];
                parent[z] = min;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }

    printf("Total Weight of the Minimum Spanning Tree: %d\n", totalWeight);
}