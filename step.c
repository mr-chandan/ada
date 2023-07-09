#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len;
    printf("Enter the number of nodes: ");
    scanf("%d", &len);

    int adj[len][len];
    int parent[len], weight[len], visited[len];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    for (int j = 0; j < len; j++)
    {
        parent[j] = -1;
        weight[j] = 999;
        visited[j] = 0;
    }

    weight[0] = 0;

    for (int i = 0; i < len; i++)
    {
        int min = 999;
        int minIndex = -1;

        for (int z = 0; z < len; z++)
        {
            if (visited[z] == 0 && weight[z] < min)
            {
                min = weight[z];
                minIndex = z;
            }
        }

        visited[minIndex] = 1;

        for (int j = 0; j < len; j++)
        {
            if (adj[minIndex][j] != 0 && visited[j] == 0 && adj[minIndex][j] < weight[j])
            {
                parent[j] = minIndex;
                weight[j] = adj[minIndex][j];
            }
        }
    }

    printf("Minimum Spanning Tree:\n");
    printf("Edge \tWeight\n");
    for (int i = 1; i < len; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, adj[parent[i]][i]);
    }

    return 0;
}
