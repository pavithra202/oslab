#include <stdio.h>
#include <stdlib.h>

void FirstFit(int *holes, int *process, int n, int h)
{
    int j;
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < h; j++)
        {
            if (process[i] <= holes[j])
            {
                printf("\nProcess #%d is allocated to hole %d", i, j);
                holes[j] -= process[i];
                break;
            }
        }
        if (j >= h)
            printf("\nProcess #%d is waiting", i);
    }
}

void BestFit(int *holes, int *process, int n, int h)
{
    int j;
    for (int i = 0; i < n; i++)
    {
        int min_hole = 999999;
        int min_index = -1;
        for (j = 0; j < h; j++)
        {
            if (min_hole >= holes[j] && holes[j] >= process[i])
            {
                min_hole = holes[j];
                min_index = j;
            }
        }
        if (min_index != -1)
        {
            printf("\nProcess #%d is allocated to hole %d", i, min_index);
            holes[min_index] -= process[i];
        }
        else
            printf("\nProcess #%d is waiting", i);
    }
}
void WorstFit(int *holes, int *process, int n, int h)
{
    int j;
    for (int i = 0; i < n; i++)
    {
        int max_hole = -9999;
        int max_index = -1;
        for (j = 0; j < h; j++)
        {
            if (max_hole <= holes[j] && holes[j] >= process[i])
            {
                max_hole = holes[j];
                max_index = j;
            }
        }
        if (max_index != -1)
        {
            printf("\nProcess #%d is allocated to hole %d", i, max_index);
            holes[max_index] -= process[i];
        }
        else
            printf("\nProcess #%d is waiting", i);
    }
}
int main()
{
    int h;
    printf("Enter the number of holes: ");
    scanf("%d", &h);
    int *holes1 = (int *)malloc(h * sizeof(int));
    int *holes2 = (int *)malloc(h * sizeof(int));
    int *holes3 = (int *)malloc(h * sizeof(int));
    printf("\nEnter hole sizes: ");
    int s;
    for (int i = 0; i < h; i++)
    {
        scanf("%d", &s);
        holes1[i] = s;
        holes2[i] = s;
        holes3[i] = s;
    }

    int n;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    int *process = (int *)malloc(n * sizeof(int));
    printf("\nEnter hole sizes: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s);
        process[i] = s;
    }
    printf("\nHoles sizes:");
     for (int i = 0; i < h; i++)
    {
        printf(" %d",holes1[i]);
    }  
    printf("\nProcess sizes:");
     for (int i = 0; i < n; i++)
    {
        printf(" %d",process[i]);
    }  

    printf("\n\nFirst Fit");
    FirstFit(holes1, process, n, h);
    printf("\n\nBest Fit");
    BestFit(holes2, process, n, h);
    printf("\n\nWorst Fit");
    WorstFit(holes3, process, n, h);
}
