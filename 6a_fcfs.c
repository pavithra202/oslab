#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data; //Process id
    int at;
    int bt;
    int exit;
    int wait;
    int tat;
    struct node *next;
}Node;

void print(Node *head){
    Node *temp=head;
    printf("PROCESS NAME  BURST TIME  ARRIVAL TIME   WAITING TIME    EXIT TIME   TURN AROUND TIME\n");
    while(temp!=NULL){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",temp->data,temp->bt,temp->at,temp->wait,temp->exit,temp->tat);
        printf("\n");
        temp=temp->next;
    }
}

void addlast(Node **head,int pros,int at,int bt){
    Node *newnode= malloc(sizeof(Node));
    newnode->data=pros;
    newnode->at=at;
    newnode->bt=bt;
    newnode->next=NULL;
    
    if(*head==NULL){
        *head=newnode;
    }

    else{
        Node *last=*head;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=newnode;
    }
}

void sort(Node **head){
    Node *point=*head;

    while(point!=NULL){
        Node *curr=point->next;
        while(curr!=NULL){
            if(point->at>curr->at){
                int curdata=point->data;
                point->data=curr->data;
                curr->data=curdata;

                int curat=point->at;
                point->at=curr->at;
                curr->at=curat;

                int curbt=point->bt;
                point->bt=curr->bt;
                curr->bt=curbt;
            }
            curr=curr->next;
        }
        point=point->next;
    }
}

void gantt(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        printf("|\tP%d\t ",curr->data);
        curr=curr->next;
    }
    printf("|\n");
    curr=head;
    printf("%d\t\t",0);
    while(curr!=NULL){
        printf("%d\t\t",curr->exit);
        curr=curr->next;
    }
    printf("\n\n");
}

float wait_t(Node **head){
    float avg_wt=0;
    int count=0;
    Node *curr=*head;
    curr->wait=0;
    while(curr!=NULL){
        curr->wait=curr->tat-curr->bt;
        avg_wt=avg_wt+curr->wait;
        count+=1;
        curr=curr->next;
    }
    return avg_wt/count;
}

void exit_t(Node **head){
    Node *prev=*head;
    Node *curr=prev->next;
    prev->exit=prev->at+prev->bt;

    while(curr !=NULL){
        if(curr->at<=prev->exit)
            curr->exit=prev->exit+curr->bt;
        else
            curr->exit=curr->at+curr->bt;
        curr=curr->next;
        prev=prev->next;
    }
}

float tat(Node **head){
    Node *curr=*head;
    float avg_tat=0;
    int count=0;
    while(curr!=NULL){
        curr->tat=curr->exit-curr->at;
        avg_tat+=curr->tat;
        curr=curr->next;
        count++;
    }
    return avg_tat/count;
}

int main()
{
    Node *head=NULL;
    printf("\n FCFS Scheduling....\n");
    int n;
    printf("Enter no of process : ");
    scanf("%d",&n);
    float avg_wait=0,avg_tat=0;
    for(int i =0;i<n;i++){
        int temp_at,temp_bt;
        printf("P%d: ",i+1);
        printf("\nEnter Arrival time : ");
        scanf("%d",&temp_at);
        printf("\nEnter Burst time : ");
        scanf("%d",&temp_bt);
        addlast(&head,i+1,temp_at,temp_bt);
    }

    // FCFS Scheduling starts from here;

    sort(&head);
    exit_t(&head);
    avg_tat=tat(&head);
    avg_wait=wait_t(&head);
    print(head);

    printf("\nGantt Chart: \n\n");
    gantt(head);

     printf("\nAverage Waiting Time:\t%f\n", avg_wait);

     printf("\nAverage Turn Around Time:%f\n", avg_tat);

     return 0;
}
