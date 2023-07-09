#include <conio.h>
#include <stdio.h>
int minimumof(int key[], int selected[], int size)
{
    int min = 999, minindex;
    for (int j = 0; j < size; j++)
    {

        if (selected[j] == 0 && key[j] < min)
        {
            min = key[j];
            minindex = j;
        }
    }
    return minindex;
}
void main()
{
    int size;

    printf("enter the number of nodes");
    scanf("%d", &size);

    int graph[size][size], parent[size], key[size], selected[size];
    printf("enter cost matrix");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("Enter the cost from vertex %d to vertex %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    for (int j = 0; j < size; j++)
    {
        parent[j] = -1;
        key[j] = 999;
        selected[j] = 0;
    }

    key[0] = 0;

    for (int i = 0; i < size; i++)
    {
        int min = minimumof(key, selected, size);

        selected[min] = 1;

        for (int z = 0; z < size; z++)
        {

            if (graph[min][z] != 0 && selected[z] != 1 && graph[min][z] < key[z])
            {
                key[z] = graph[min][z];
                parent[z] = min;
            }
        }
    }

    printf("Minimum Spanning Tree:\n");
    printf("Edge \tWeight\n");
    for (int i = 1; i < size; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}