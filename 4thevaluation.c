#include <stdio.h>
#include <stdlib.h>

typedef struct KRUSH
{
    int r, p, x;

} krush;

int *arr = NULL;

void swap(krush *kru1, krush *kru2)
{
    krush *d;
    d = (krush *)malloc(sizeof(krush));
    if (d == NULL)
    {
        printf("Heap is full!");
        exit(0);
    }
    *d = *kru1;
    *kru1 = *kru2;
    *kru2 = *d;
    free(d);
}

void bubbleSort(krush *kru, int edge)
{
    krush *d;
    d = (krush *)malloc(sizeof(krush));
    for (int i = 0; i < edge - 1; i++)
    {
        for (int j = 0; j < edge - i - 1; j++)
        {
            if (kru[j].x > kru[j + 1].x)
            {
                swap((kru + j), (kru + j + 1));
            }
        }
    }
}

void unionfind(int a, int b, int vert)
{
    int o = arr[a];
    int q = arr[b];
    for (int i = 0; i < vert; i++)
    {
        if (arr[i] == o)
        {
            arr[i] = q;
        }
    }
}

int find(int a, int b, int vert)
{
    if (arr[a] == arr[b])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

krush *input(int vert, int edge)
{
    int s, t;
    int r, p;
    int x;

    krush *kru = (krush *)malloc(sizeof(krush) * edge);
    arr = (int *)malloc(sizeof(int) * vert);

    if (kru == NULL)
    {
        printf("full!");
        exit(0);
    }
    if (arr == NULL)
    {
        printf("full!");
        exit(0);
    }

    for (int i = 0; i < vert; i++)

    {
        arr[i] = i;
    }

    for (int i = 0; i < edge; i++)
    {

        printf("enter the first edge ", i);
        scanf("%d", &s);
        printf("enter the second edge", i);
        scanf("%d", &t);

        if (r > p)
        {
            kru[i].r = p;
            kru[i].p = r;
        }
        else
        {
            kru[i].r = r;
            kru[i].p = p;
        }
        printf("Enter the weight", i);
        scanf("%d", &kru[i].x);
        printf("\n\n");
    }
    return kru;
}

int krushalgo(krush *kru, int vert, int edge)
{
    int weight = 0;
    int count = 0;
    printf("Minimum spanning Tree: \n");
    for (int i = 0; i < edge; i++)
    {
        if (count == vert - 1)
            break;
        if (!find(kru[i].r, kru[i].p, vert))
        {
            printf("%d %d -> %d\n", kru[i].r, kru[i].p, kru[i].x);
            unionfind(kru[i].r, kru[i].p, vert);
            weight += kru[i].x;
            count++;
        }
    }
    return weight;
}

int main()
{

    int vert, edge, weight;
    krush *kru;
    printf("Minimum spanning tree \n");
    printf("Enter the number of vertices: ");
    scanf("%d", &vert);
    printf("Enter the number of edges: ");
    scanf("%d", &edge);
    kru = input(vert, edge);
    bubbleSort(kru, edge);
    weight = krushalgo(kru, vert, edge);
    printf("\nThe total cost is: %d", weight);

    return 0;
}