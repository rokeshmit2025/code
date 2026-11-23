#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node{
int data;
struct node*next;
};
struct node*head=NULL,*tem=NULL;
void create(){
    struct node*new_node=NULL;
    new_node=(struct node*)calloc(1,sizeof(struct node));
    if(head==NULL){
      printf("Enter the data\n");
      scanf("%d",&new_node->data);
      head=new_node;
    }
    else{
        tem=head;
        while(tem->next!=NULL) tem=tem->next;
        printf("Enter the data\n");
        scanf("%d",&new_node->data);
        tem->next=new_node;
        tem=new_node;
    }
}
void display(){
    printf("The linked list are\n");
    tem=head;
    while(tem!=NULL){
        printf("%d\t",tem->data);
        tem=tem->next;
    }
}
void reverse(){
    struct node*rev=head,*pre=NULL;
    tem=head->next;
    while(tem!=NULL){
        rev->next=pre;
        pre=rev;
        rev=tem;
        tem=tem->next;
    }
    rev->next=pre;
    head=rev;
}
int main(){
    int choice=1;
    while(choice){
        printf("1.Input data\n3.Display\n2.Reverse\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:create();
                   break;
            case 2:reverse();
                   break;
             case 3:display();
                   break;             
        }
        if(choice==0) break;
    }
}