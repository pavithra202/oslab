#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct proc{
    int data; //Process id
    int at;
    int bt;
    int exit;
    int wait;
    int tat;
    bool completed;
}Proc;



int main(){
printf("\nShort Job First:\n\n");
int n;
printf("Enter number of process: ");
scanf("%d",&n);
Proc p[n];

for(int i =0;i<n;i++){
    int temp_at,temp_bt;
    printf("P%d: ",i+1);
    printf("\nEnter Arrival time : ");
    scanf("%d",&temp_at);
    printf("\nEnter Burst time : ");
    scanf("%d",&temp_bt);
    p[i].data=i+1;
    p[i].at=temp_at;
    p[i].bt=temp_bt;
    p[i].completed=false;
    }


//SJF operation
int current=0;
bool Finish=false;
while(Finish!=true){
    int min_index=-1;
    int minm=99999;
    bool check=false;
    for(int i=0;i<n;i++){
        if(p[i].at<=current && p[i].completed==false){
            if(minm>p[i].bt){
                minm=p[i].bt;
                min_index=i;
                check=true;
            }
        }
    }
    if(check==false){
        current++;
    }
    else{
        if((min_index!=-1) && (p[min_index].completed==false)){
                current=current+p[min_index].bt;
                p[min_index].exit=current;
                p[min_index].completed=true;
        Finish=true;
        for(int i=0;i<n;i++){
            if(p[i].completed==false){
                Finish=false;
                break;
                }   
            }
        }
    }
}
//sort exit
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(p[i].exit>p[j].exit){
            Proc temp=p[i];
            p[i]=p[j];
            p[j]=temp;
        }
    }
}

// tat
float avg_tat=0;
for(int i=0;i<n;i++){
    p[i].tat=p[i].exit-p[i].at;
    avg_tat+=p[i].tat;
}
avg_tat/=n;

//wait

float avg_wt=0;
for(int i=0;i<n;i++){
    p[i].wait=p[i].tat-p[i].bt;
    avg_wt+=p[i].wait;
}
avg_wt/=n;

//Print

printf("PROCESS NAME  BURST TIME  ARRIVAL TIME   WAITING TIME    EXIT TIME   TURN AROUND TIME\n");
for(int i=0;i<n;i++){
        printf("%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d",p[i].data,p[i].bt,p[i].at,p[i].wait,p[i].exit,p[i].tat);
        printf("\n");
}
//Gantt chart
printf("\n\n");
for(int i=0;i<n;i++)
    printf("|\tP%d\t",p[i].data);
printf("|\n");

printf("%d\t\t",0);
for(int i=0;i<n;i++)
    printf("%d\t\t",p[i].exit);
printf("\n\n");


//Misc

printf("\nAverage Waiting Time:\t%f\n", avg_wt);

printf("\nAverage Turn Around Time:%f\n", avg_tat);

}
