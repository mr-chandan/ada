#include <conio.h>
#include <stdio.h>

void main()
{
    int objects;
    printf("enter the no of objects");
    scanf("%d", &objects);

    int weight[objects], price[objects], capacity, totalprofit, checki;
    float ratio[objects], complete[objects];

    printf("enter the capacity");
    scanf("%d", &capacity);

    printf("enter the no of price");
    for (int i = 0; i < objects; i++)
        scanf("%d", &price[i]);

    printf("enter the no of weight");
    for (int i = 0; i < objects; i++)
        scanf("%d", &weight[i]);

    for (int i = 0; i < objects; i++)
    {
        ratio[i] = (float)price[i] / weight[i];
        complete[i] = 0.0;
    }
    for (int i = 0; i < objects; i++)
    {
        for (int j = 0; j < objects - i - 1; j++)
        {
            if (ratio[j] > ratio[j + 1])
            {
                float temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                int tempo = price[j];
                price[j] = price[j + 1];
                price[j + 1] = tempo;

                int tempm = weight[j];
                weight[j] = ratio[j + 1];
                weight[j + 1] = tempm;
            }
        }
    }

    for (checki = 0; checki < objects; checki++)
    {
        if (weight[checki] > capacity)
        {
            break;
        }
        else
        {
            complete[checki] = 1.0;
            totalprofit += price[checki];
            capacity -= weight[checki];
        }
    }

    if (checki < objects)
    {
        complete[checki] = (float)capacity / weight[checki];
    }
    totalprofit += complete[checki] * price[checki];

    for (int i = 0; i < objects; i++) {
        printf("Item %d: %.2f\n", i + 1, complete[i]);
    }
}