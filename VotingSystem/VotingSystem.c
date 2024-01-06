
//we have to make a program in which users can vote through the letter.
//And to acheive this we have to make a linked list and in that linked list every node consist of a char type of data and an int type of data.
//Initially the list is empty. Nodes are added to the list every time a respondent states their favorite letter.
//whenever any user wants to vote to his favorite letter then the node's integer will get incremented with 1.
//and if the list is empty then the integer part of node will be intialized from 1.
//Votes can be case insensitive

// Like
// Sam voted to 'a'  that node will be constructed and that in that node the values are 'a' and 1
// Ashok voted to 'a' then the node value 'a' and 2.

#include<stdio.h>
#include<stdlib.h>

typedef struct __abc
{
char sign;
int numOfVotes;
struct __abc *next;
}Node;

Node *start;



void add(char val)
{
Node *t;
if(val>97 || val<122) val-=32;

if(val<65 || val>90) {
printf("Invalid Input\n");
return;
}

t=(Node *)malloc(sizeof(Node));
t->sign=val;
t->next=NULL;
t->numOfVotes=1;
if(start==NULL)
{
t->numOfVotes=1;
start=t;
}
else
{
int found=0;
Node *prev,*iter;
prev=start;
for(iter=start;iter!=NULL;iter=iter->next)
{
if(iter->sign==val)
{
iter->numOfVotes++;
return;
}
else if(iter->sign>val)
{
break;
}
else{
prev=iter;
continue;
}
}

if(iter==start)
{
t->next=start;
start=t;
return;
}
else if(iter==NULL)prev->next=t;
else{
t->next=prev->next;
prev->next=t;
}

}
}


void printList()
{
for(Node*t=start;t!=NULL;t=t->next) printf("Letter : %c, Voter turnout : %d, Address : %u\n",t->sign,t->numOfVotes,t);
}


int main()
{
int choice;
char vote;
while(1)
{
printf("1. Vote\n2.Exit\n");
printf("Enter your choice : ");

scanf("%d",&choice);
fflush(stdin);

if(choice==1)
{
printf("Enter the vote character : ");
scanf("%c",&vote);
add(vote);
printList();
}
else if(choice==2) break;
else 
{
printf("Invalid Input!\n");
continue;
}

}


return 0;
}
