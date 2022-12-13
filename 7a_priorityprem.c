//Priority pre-emptive scheduling #include <stdio.h>
#include<stdio.h>
#include<stdlib.h>

struct process 
{
	int WT, AT, BT, TAT, PT, ID; 
}shift;
struct process a[10];
int main() 
{
	int n, temp[10], t, count = 0, short_p, i, j;
	float total_WT = 0, total_TAT = 0, Avg_WT, Avg_TAT;
	printf("Enter the no of process: "); 
	scanf("%d", &n);
	for (i = 0; i < n; i++) 
	{
		printf("\nBurst time for P%d: ", i + 1); 
		scanf("%d", &a[i].BT); 
		printf("Piriorty for P%d: ", i + 1); 
		scanf("%d", &a[i].PT);
		printf("Arrival Time for P%d: ", i + 1);
		scanf("%d", &a[i].AT);
		temp[i] = a[i].BT; 
		a[i].ID = i + 1;
	}
	a[9].PT = 10000;
	for (t = 0; count != n; t++) 
	{
		short_p = 9;
		for (i = 0; i < n; i++) 
		{
			if (a[short_p].PT > a[i].PT && a[i].AT <= t && a[i].BT > 0) 
			{
				short_p = i; 
			}
		}
		a[short_p].BT = a[short_p].BT - 1; 
		if (a[short_p].BT == 0)
		{
			count++;
			a[short_p].WT = t + 1 - a[short_p].AT - temp[short_p]; 
			a[short_p].TAT = t + 1 - a[short_p].AT;
			total_WT = total_WT + a[short_p].WT;
			total_TAT = total_TAT + a[short_p].TAT;
 		}
	}
	Avg_WT = total_WT / n; 
	Avg_TAT = total_TAT / n;
	for (i = 0; i < n - 1; i++) 
	{
		for (j = 0; j < n - 1 - i; j++) 
		{
			if (a[j].TAT > a[j + 1].TAT) 
			{
				shift = a[j]; 
				a[j] = a[j + 1]; 
				a[j + 1] = shift;
			}
		}
	}
	printf("\nGantt Chart:\n\n"); 
	for (i = 0; i < n; i++)
	{
		printf("|");
		for (j = 0; j <= a[i].WT / 2; j++)
			printf(" "); 
		printf("P%d", a[i].ID);
		for(j = a[i].WT / 2; j <= a[i].WT; j++) 
			printf(" ");
	}
	printf("|"); 
	printf("\n%d", a[0].AT); 
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= a[i].WT + 3; j++) 
			printf(" ");
		printf("%d", a[i].TAT); 
	}
	printf("\n\nAvg waiting time of the process is %f", Avg_WT); 
	printf("\nAvg turn around time of the process is %f\n", Avg_TAT);
	return 0; 
}