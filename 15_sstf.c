#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>

void sort(int a[100],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

}


int findMin(int req[],int noreq,int curr)
{   
    int min ,minval, minindex;
    min = 9999999;
    for(int i=0;i<noreq;i++)
    {
        if(abs(curr-req[i]) < min)
        {
            min = abs(curr-req[i]);
            minval = req[i];
            minindex = i;
        }
    }
    //printf(" [ %d - %d = %d ] ",curr,req[minindex],min);
    req[minindex] = 9999999;
    return minval;
}



void SSTF(int req[],int noreq,int curr){
    printf("SSTF scheduling :\n");
    printf("%d",curr);
    int seek_time = 0;
    for(int i=0;i<noreq;i++)
    {
        int minval = findMin(req,noreq,curr); 
        seek_time+= abs(curr-minval);
        curr = minval; 
        printf("->%d",curr);
    }
    printf("\nTotal Seek Time : %d\n",seek_time);
}


int main()
{
    int n;
    printf("Enter number of tracks in disc : ");
    scanf(" %d",&n);
    int noreq;
    printf("Tracks generated from 0 to %d \n",n-1);
    int start;
    printf("Enter the starting track : ");
    scanf(" %d",&start);
    printf("Enter the number of requests to be made : ");
    scanf(" %d",&noreq);

    int req[noreq];
    printf("Enter the order of %d requests made : ",noreq);
    for(int i=0;i<noreq;i++)
    {
        scanf(" %d",&req[i]);
    }
    sort(req,noreq);
    SSTF(req,noreq,start);
    return 0;
}