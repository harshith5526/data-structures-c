#include<stdio.h>

#include<stdlib.h>

struct node

{

 char usn[25], name[25],programme[25];

 int sem;

 long int phone;

 struct node *link;

};

typedef struct node * NODE;

NODE start = NULL;

int count=0;

NODE create()

{

 NODE snode;

 snode = (NODE)malloc(sizeof(struct node));

 if(snode == NULL)

 {

 printf("\n Memory is not available");

 exit(1);

 }

 printf("\n Enter the usn,Name,Programme, sem,PhoneNo of the student:");

 scanf("%s %s %s %d %ld",snode->usn, snode->name, snode->programme, &snode->sem, &snode->phone); }

 temp->link = start;

 return temp;

}

NODE deletefront()

{

 NODE temp;

 if(start == NULL)

 {

 printf("\n Linked list is empty");

 return NULL;

 }

 if(start->link == NULL)

 {

 printf("\n The Student node with usn:%s is deleted ",start->usn);

 count--;

 free(start);

 return NULL;

 }

 temp = start;

 start = start->link;

 printf("\n The Student node with usn:%s is deleted",temp->usn);

 count--;

 free(temp);

 return start;

}

NODE insertend()

{

 NODE cur,temp;

 temp = create();

 if(start == NULL)

 {

 return temp;

 }

 cur = start;

 while(cur->link !=NULL)

 {

 cur = cur->link;

 }

 cur->link = temp;

 return start;

}

NODE deleteend()

{

 NODE cur,prev;

 if(start == NULL)

 {

 printf("\n Linked List is empty");

 return NULL;

 }

 if(start->link == NULL)

 {

 printf("\n The student node with the usn:%s is deleted",start->usn); free(start);

 count--;

 return NULL;

 }

 prev = NULL;

 cur = start;

 while(cur->link!=NULL)

 {

 prev = cur;

 cur = cur->link;

 }

 printf("\n The student node with the usn:%s is deleted",cur->usn);

 free(cur);

 prev->link = NULL;

 count--;

 return start;

 }

void display()

{

 NODE cur;

 int num=1;

 if(start == NULL)

 {

 printf("\n No Contents to display in SLL \n");

 return;

 }

 printf("\n The contents of SLL: \n");

 cur = start;

 while(cur!=NULL)

 {

 printf("\n ||%d|| USN:%s| Name:%s| Programme:%s| Sem:%d| Ph:%ld|",num,cur->usn, cur->name, 

cur->programme, cur->sem,cur->phone);

 cur = cur->link;

 num++;

 }

 printf("\n No of student nodes is %d \n",count);

}

void stackdemo()

{

 int ch;

 while(1)

 {

 printf("\n~~~Stack Demo using SLL~~~\n");

 printf("\n1:Push operation \n2: Pop operation \n3: Display \n4:Exit \n");

 printf("\n Enter your choice for stack demo : ");

 scanf("%d",&ch);

 switch(ch)

 {

 case 1: start = insertfront();

 break;

 case 2: start = deletefront();

 break; case 3: display();

 break;

 default : return;

 }

 }

 return;

}

int main()

{

 int ch,i,n;

 while(1)

 {

 printf("\n~~~Menu~~~");

 printf("\n Enter your choice for SLL operation \n");

 printf("\n 1:Create SLL of Student Nodes");

 printf("\n 2:DisplayStatus");

 printf("\n 3:InsertAtEnd");

 printf("\n 4:DeleteAtEnd");

 printf("\n 5:Stack Demo using SLL(Insertion and Deletion at Front)");

 printf("\n 6:Exit \n");

 printf("\n Enter your choice:");

 scanf("%d",&ch);

 switch(ch)

 {

 case 1 : printf("\n Enter the no of students: ");

 scanf("%d",&n);

 for(i=1;i<=n;i++)

 start = insertfront();

 break;

 case 2: display();

 break;

 case 3: start = insertend();

 break;

 case 4: start = deleteend();

 break;

 case 5: stackdemo();

 break;

 case 6: exit(0);

 default: printf("\n Please enter the valid choice ");

 }

 }

}
