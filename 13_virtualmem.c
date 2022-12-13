#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int convert2Decimal(char val[100],int pbit)
{
    int t =0;
    
    for(int i=pbit-1;i>=0;i--)
    {
        t += ((int)val[i] - 48)*(int)pow(2,pbit-1-i);
    }
    return t;
}
void convert2Binary(int n,int fbit,int a[100])
{
    int count = 0;
    for(int i=0;count<=fbit;i++)
    {
        a[i] = n%2;
        n/=2;
        count+=1;
    } 

}

void setPageTable(int page[100],int page_len,int val[4][2])
{
    printf("-----PAGE TABLE-----");
    for(int i=0;i<page_len;i++)
    {
        page[i] = -1;
        int rows = sizeof((int)val[0][0]);
        for(int j=0;j<rows;j++)
        {
            if(val[j][0] == i)
                page[i] = val[j][1];
        }
    printf("\nPage %d has frame %d",i,page[i]);    
    }
}

int main()
{

    int page_len,frame_len,page_size;
    //input values:
    int val[4][2] = {{0,2},{4,15},{6,5},{7,9}};
    int page[100];
    printf("Enter the length of page and length of frame in bytes : ");//say 3 4
    scanf(" %d %d",&page_len,&frame_len);
    int pbit = (int)log2(page_len);
    int fbit = (int)log2(frame_len);
    int d;
    setPageTable(page,page_len,val);
    printf("\nEnter page/frame size in bytes(d)");
    scanf(" %d",&page_size);
    d = (int)log2(page_size);
    char la[100],pa[100];
    printf("\nEnter logical address value : ");
    scanf(" %s",la);

    int t =convert2Decimal(la,pbit);//intermediate state
    
    int t1 = page[t];
    if(t1 == -1)
    {
        printf("NO VALID MAPPING FOUND");
        return 0;
    }
    printf("\nPAGE %d : FRAME %d\n",t,t1);
    int a[100];
    convert2Binary(t1,fbit,a);
    printf("PHYSICAL ADDRESS : ");
    for(int i=fbit-1;i>=0;i--)
        printf("%d",a[i]);
    for(int i=pbit;i<d;i++)
        printf("%c",la[i]);
    printf("\n");
    return 0;
}