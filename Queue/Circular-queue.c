#include<stdio.h>

#include<stdlib.h>

#include<stdbool.h>

#define QUEUE_SIZE 5

void InsertRear(char [],int*,int*,char);

char DeleteFront(char[],int*,int*);

void Display(char [],int,int);

bool QueueFull(int,int);

bool QueueEmpty(int,int);

int main()

{

 char myQueue[QUEUE_SIZE];

 int iFront=-1,iRear=-1;

 int iChoice;

 char cElem;

 

 for(;;)

 {

 printf("\n Queue Operations \n");

 printf("=====================");

 printf("\n1.Qinsert \n2.Qdelete \n3.Qdisplay \n4.Exit \n"); {

 printf("\n Enter an element : ");

 scanf("%c",&cElem);

 InsertRear(myQueue,&iFront,&iRear,cElem);

 }

 else

 {

 printf("\n Queue is Full \n");

 }

 break;

 case 2: if(!QueueEmpty(iFront,iRear))

 {

 cElem = DeleteFront(myQueue,&iFront,&iRear);

 printf("\n Deleted element is %c \n", cElem);

 }

 else

 {

 printf("\n Queue is Empty \n");

 }

 break;

 case 3: if(!QueueEmpty(iFront,iRear))

 {

 printf("\n Contents of the Queue is: \n");

 Display(myQueue,iFront,iRear);

 }

 else

 {

 printf("\n Queue is Empty \n");

 }

 break;

 case 4: exit(0);

 default: printf("\n Invalid choice \n");

 break;

 }

 }

 return 0;

} bool QueueFull(int f,int r)

{

 if((r+1)%QUEUE_SIZE==f)

 return true;

 else

 return false;

}

bool QueueEmpty(int f,int r)

{

 if(f==-1)

 return true;

 else

 return false;

}

void InsertRear(char queue[],int *f,int *r,char cVal)

{

 if(*r==-1)

 {

 *f=*f+1;

 *r=*r+1;

 }

 else

 *r=(*r+1)%QUEUE_SIZE;

 

 queue[*r]=cVal;

}

char DeleteFront(char queue[],int *f,int *r)

{

 char cElem;

 cElem=queue[*f];

 

 if(*f==*r)

 {

 *f=-1;

 *r=-1;

 }

 else

 {

 *f=(*f+1)%QUEUE_SIZE; }

 return cElem;

}

void Display(char queue[],int f,int r)

{

 int i;

 if(f<=r)

 {

 for(i=f;i<=r;i++)

 {

 printf("%c \t",queue[i]);

 }

 printf("\n"); 

 }

 else

 {

 for(i=f;i<=QUEUE_SIZE-1;i++)

 {

 printf("%c \t",queue[i]);

 }

 for(i=0;i<=r;i++)

 {

 printf("%c \t",queue[i]);

 }

 printf("\n"); 

 }

}
