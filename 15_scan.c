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

int search(int req[],int noreq,int start)
{
    for(int i=0;i<noreq;i++)
    {
        if(start == req[i])
            return i;
    }
}

void SCAN(int req[],int noreq,int start,int limit)
{
    //finding start in array
    int startIndex = search(req,noreq,start);
    int minIndex = abs(start - req[startIndex-1]) > abs(start - req[startIndex+1])?startIndex+1:startIndex-1;
    int seekTime = 0;
    printf("SCAN SCHEDULING :\n");
    printf("%d",start);
    if(minIndex > startIndex)
    {
        for(int i=minIndex;i<noreq;i++)
        {
            printf("->%d",req[i]);
        }
        printf("->%d",limit-1);
        for(int i=startIndex-1;i>=0;i--)
        {
            printf("->%d",req[i]);
        }
        seekTime = limit - 1 - req[0];
    }
    else
    {
        for(int i=startIndex-1;i>=0;i--)
        {
            printf("->%d",req[i]);
        }
        printf("->%d",0);
        int i;
        for(i=startIndex+1;i<noreq;i++)
        {
            printf("->%d",req[i]);
        }
        seekTime = req[i-1] + start;
    } 
    printf("\nSEEK TIME : %d",seekTime);
    
    
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
    int req[noreq+1];
    printf("Enter the order of %d requests made : ",noreq);
    for(int i=0;i<noreq;i++)
    {
        scanf(" %d",&req[i]);
    }
    noreq+=1;
    req[noreq-1] = start;
    sort(req,noreq);
    SCAN(req,noreq,start,n);
    return 0;
}