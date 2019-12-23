/*Experiment No 	: 06
Date                : 14/10/2019
Aim                 : To study doubly linked linear lists [DLLs] and implement various operations on it.
/* Headers */
#include<stdio.h>
#include<stdlib.h>
struct node_dll
{
 int data;
 struct node_dll *rpoint;
 struct node_dll *lpoint;
};
typedef struct node_dll list;
/* Function Prototypes */
list* create_node();
list* insertatbeg(list* start,int data);
list* insertatend(list* start,int data);
list* insertatpos(list* start,int data,int pos);
list* deleteatbeg(list* start);
list* deleteatend(list* start);
list* deleteatpos(list* start,int pos);
list* deleteByVal(list* start,int key);
void traverse(list* temp);
void display(list* temp);
list* Search(list* start,int element);
int length(list* temp);
list* reverse(list *first);
list* copyList(list *first);
int main()
{
    int choice,llchoice,no_nodes,fno_nodes,sno_nodes,i,key,key1,pos,ele,l;
    list *START=NULL,*newnode;
    printf("\nA Doubly Linked Linear Lists ADT\n");
do{
    printf("\nPerform operations on Doubly Linked Linear list ?\nEnter 1 for YES or press 0 to EXIT : ");
    scanf("%d",&choice);
    if(choice!=1)
{
printf("\n=====Terminating=====\n");
    exit(1);
}    
do{
    printf("\nChoose an ADT operation\n");
    printf("\n1.Create a list\n2.Length of List\n3.Insert At Beginning\n4.Insert At End\n5.Insert At random Position \n6.Delete from Front\n7.Delete from Rear\n8.Delete BY Value\n9.Search the list\n10.Display\n11.Reverse\n12.Copy\n0.Exit");  
    printf("\nEnter your operation code : ");
    scanf("%d",&llchoice);
	switch(llchoice)
      {
        case 0:
          printf("\n=====Terminating the Operation=====\n");
        break;
		case 1:
          printf("\n====Create a List====\n");
          printf("How many nodes to you want to create ?\n");
          scanf("%d",&no_nodes);
          i=0;
          while(i<no_nodes)
          {
            printf("Enter data : ");
            scanf("%d",&key);
            START=insertatbeg(START, key);
            i++;
          }
        break;
		case 2:
          printf("\n====Length of List====\n");
          printf("Length of list : %d\n",length(START));
        break;
       	case 3:
          printf("\n====Insert At Beginning====\n");
          printf("\nEnter data to be inserted : ");
          scanf("%d",&key);
          START=insertatbeg(START, key);
          display(START);
        break;
       	case 4:
            printf("\n====Insert At End====\n");
            printf("\nEnter data to be inserted : ");
            scanf("%d",&key);
            START=insertatend(START, key);
            display(START);
        break;
       	case 5:
            printf("\n====Insert At random Position====\n");
            printf("\nEnter data to be inserted : ");
            scanf("%d",&key);
			printf("\nEnter position : ");
            scanf("%d",&pos);
            l=length(START);
            if(pos==0)
                START=insertatbeg(START,key);
            else if(pos==l)
                START=insertatend(START,key);
            else
               START=insertatpos(START,key, pos);
			display(START);
        break;
		case 6:
            printf("\n====Delete from Front====\n");
            START = deleteatbeg(START);
            display(START);
        break;
		case 7:
            printf("\n====Delete from End====\n");
            START=deleteatend(START);
            display(START);
        break;
		case 8:
            printf("\n====Delete by Value====\n");
            printf("\nEnter value of the key to be deleted\n");
            scanf("%d",&key1);
            START=deleteByVal(START,key1);
            display(START);
        break;
		case 9:
            printf("\n====Search the list====\n");
            printf("\nEnter key to be searched: ");
            scanf("%d",&ele);
            START = Search(START,ele);
        break;
		case 10:
            printf("\n====Display List====\n");
            traverse(START);
        break;
     	case 11:
            printf("\n====Reverse List====\n");
            printf("\nOriginal List\n");
            display(START);
            START=reverse(START);
            printf("\nReversed List\n");
            display(START);
        break;
		case 12:
            printf("\n====Copy List====\n");
            printf("\nOriginal List\n");
            display(START);
            START=copyList(START);
            printf("\nDuplicate List\n");
            display(START);            
		default:
          printf("\nxxxxxx Incorrect input xxxxxx");
		}
    }while(llchoice!=0);
}while(choice!=0);
return 0;
}
list* create_node()
{
list* p;
p = (list*)malloc(sizeof(list));
if (p==NULL)
    {
    printf("\nNode not created.");
    return NULL;
    }
else
    {
    return p;
    }
}
list* insertatbeg(list* start,int data)
{
  list* newnode;
  newnode = create_node();
    if(newnode == NULL)
        return(start);

    newnode->data = data;
    if(start==NULL)
    {
      newnode->rpoint=NULL;
      newnode->lpoint=NULL;
      start=newnode;
    }
    else
    {
      newnode->lpoint=NULL;
      newnode->rpoint=start;
      start->lpoint=newnode;
      start=newnode;
    }
 return start;
}
list* insertatend(list* start,int data)
{
  list* newnode;
  list* temp;
  newnode = create_node();
    if(newnode == NULL)
        return(start);

    newnode->data = data;
    newnode->rpoint=NULL;

    if(start==NULL)
    {
    newnode->lpoint=NULL;
    start=newnode;
    }
    else
    {
    temp=start;
    while(temp->rpoint!=NULL)
    {
      temp=temp->rpoint;
    }
    temp->rpoint=newnode;
    newnode->lpoint=temp;
    }
  return(start);
}
list* insertatpos(list* start,int data,int pos)
{
 list* newnode;
list* temp;
 int k=0;
 newnode = create_node();
   if(newnode == NULL)
       return(start);

  newnode->data = data;
  if(start==NULL)
   {
    newnode->rpoint=NULL;
    newnode->lpoint=NULL;
    start=newnode;
   }
  else
  {
   temp=start;
   while((k<pos-1)&&(temp!=NULL))
   {
     temp=temp->rpoint;
     k=k+1;
   }
   if(temp!=NULL && k==pos-1)
   {

     newnode->rpoint=temp->rpoint;
     newnode->lpoint=temp;
     temp->rpoint->lpoint=newnode;
     temp->rpoint=newnode;
   }
  }
return start;
}
list* deleteatbeg(list* start)
{
 list* temp;
 int key;
 if(start==NULL)
 {
  printf("\nDeletion not possible\n");
  return(start);
 }
else
 {
  temp=start;
  key=temp->data;
  start=temp->rpoint;
  start->lpoint=NULL;
  free(temp);
  printf("\nDeleted key is %d \n",key);
 }
return start;
}
list* deleteatend(list* start)
{
 list* temp;
 int key;
 if(start==NULL)
 {
  printf("\nDeletion not possible\n");
  return(start);
 }
  temp=start;
  while(temp->rpoint!=NULL)
  {
   temp=temp->rpoint;
  }
  if(temp->lpoint!=NULL)
  {
    temp->lpoint->rpoint=NULL;
  }
  else
  {
    start=NULL;
  }
  key=temp->data;
  free(temp);
  printf("\nThe deleted key is %d\n",key);
 return start;
}
list* deleteByVal(list* start,int key)
{
  list* temp;
  if(start==NULL)
  {
    printf("Empty list!!\n");
    return start;
  }
  if(start->rpoint==NULL && start->data==key)
  {
    key=start->data;
    free(start);
    return NULL;
  }
  temp=start;
  while(temp->rpoint!=NULL && temp->data!=key)
  {
   temp=temp->rpoint;
   if(temp->data==key)
   {
     if(temp->rpoint==NULL)
     {
       temp->lpoint->rpoint=NULL;
       temp->lpoint=NULL;
     }
     else
     {
       temp->lpoint->rpoint=temp->rpoint;
       temp->lpoint=temp->lpoint;
     }
    key=temp->data;
    free(temp);
   }
  }
  if(temp->data!=key)
   {
     printf("\nKey not found : Deletion Failed\n");
   }
  return start;
}
void traverse(list* temp)
{
  while((temp->rpoint) != NULL)
  {
    printf("[%lu] %d [%lu] -> ",/*(unsigned long)*/temp->lpoint,temp->data,/*(unsigned long)*/temp->rpoint);
    temp=temp->rpoint;
  }

    printf("[%lu] %d [%lu]",/*(unsigned long)*/temp->lpoint,temp->data,/*(unsigned long)*/temp->rpoint);
}
void display(list* temp)
{
  while((temp->rpoint) != NULL)
  {
    printf("%d -> ",temp->data);
    temp=temp->rpoint;
  }

    printf("%d ",temp->data);
}
list* Search(list* start,int element)
{
  list* temp;
  int pos=0;
  temp=start;
  while ((temp != NULL) && (temp->data != element))
  {
    temp = temp->rpoint;
    pos=pos+1;
  }
  if (temp==NULL)
      printf("\nThe key is not present in the list \n");
  else
      printf("\nValue found at index : %d",pos);
  return start;
}
int length(list* temp)
{
  int c=0;
  while(temp != NULL)
    {
      c++;
      temp=temp->rpoint;
    }
  return c;
}

list* copyList(list *first)
{
  list* neww;
  list* temp;
  list* dupl;
  list* cpy;
  neww=create_node();
  if(first==NULL)  
  {
    printf("\nList is empty!\nCopy operation can't be performed\n");
    return NULL;
  }
  neww->data=first->data;
  neww->rpoint=NULL;
  dupl=neww;
  temp=first;
  while(temp->rpoint != NULL)
  {
    cpy=neww;
    temp=temp->rpoint;
    neww=create_node();
    neww->data=temp->data;
    neww->rpoint=NULL;
    cpy->rpoint=neww;
  }
  neww->rpoint=NULL;
  return dupl;
}
list* reverse(list *first)
{
  list *prev=NULL, *current=first, *rpoint=NULL;
  while(current!=NULL)
  {
    rpoint = current->rpoint;
    current->rpoint = prev; 
    prev = current; 
    current = rpoint;
  }
  first = prev;
  return first;
}

/*Execution Trail
A Doubly Linked Linear Lists ADT

Perform operations on Doubly Linked Linear list ?
Enter 1 for YES or press 0 to EXIT : 1

Choose an ADT operation

1.Create a list
2.Length of List
3.Insert At Beginning
4.Insert At End
5.Insert At random Position
6.Delete from Front
7.Delete from Rear
8.Delete BY Value
9.Search the list
10.Display
11.Reverse
12.Copy
0.Exit
Enter your operation code : 1

====Create a List====
How many nodes to you want to create ?
4
Enter data : 12
Enter data : 25
Enter data : 45
Enter data : 85

Choose an ADT operation

1.Create a list
2.Length of List
3.Insert At Beginning
4.Insert At End
5.Insert At random Position
6.Delete from Front
7.Delete from Rear
8.Delete BY Value
9.Search the list
10.Display
11.Reverse
12.Copy
0.Exit
Enter your operation code : 2

====Length of List====
Length of list : 4

Choose an ADT operation

1.Create a list
2.Length of List
3.Insert At Beginning
4.Insert At End
5.Insert At random Position
6.Delete from Front
7.Delete from Rear
8.Delete BY Value
9.Search the list
10.Display
11.Reverse
12.Copy
0.Exit
Enter your operation code : 3

====Insert At Beginning====

Enter data to be inserted : 55
55 -> 85 -> 45 -> 25 -> 12
Choose an ADT operation

1.Create a list
2.Length of List
3.Insert At Beginning
4.Insert At End
5.Insert At random Position
6.Delete from Front
7.Delete from Rear
8.Delete BY Value
9.Search the list
10.Display
11.Reverse
12.Copy
0.Exit
Enter your operation code : 8

====Delete by Value====

Enter value of the key to be deleted
2

Key not found : Deletion Failed
55 -> 85 -> 45 -> 25 -> 12
Choose an ADT operation

1.Create a list
2.Length of List
3.Insert At Beginning
4.Insert At End
5.Insert At random Position
6.Delete from Front
7.Delete from Rear
8.Delete BY Value
9.Search the list
10.Display
11.Reverse
12.Copy
0.Exit
Enter your operation code : 11

====Reverse List====

Original List
55 -> 85 -> 45 -> 25 -> 12
Reversed List
12 -> 25 -> 45 -> 85 -> 55
Choose an ADT operation

1.Create a list
2.Length of List
3.Insert At Beginning
4.Insert At End
5.Insert At random Position
6.Delete from Front
7.Delete from Rear
8.Delete BY Value
9.Search the list
10.Display
11.Reverse
12.Copy
0.Exit
Enter your operation code : 10

====Display List====
[12085920] 12 [12085920] -> [12085952] 25 [12085952] -> [12085984] 45 [12085984] -> [12086016] 85 [12086016] -> [0] 55 [0]
Choose an ADT operation

1.Create a list
2.Length of List
3.Insert At Beginning
4.Insert At End
5.Insert At random Position
6.Delete from Front
7.Delete from Rear
8.Delete BY Value
9.Search the list
10.Display
11.Reverse
12.Copy
0.Exit
Enter your operation code : 6

====Delete from Front====

Deleted key is 12
25 -> 45 -> 85 -> 55
Choose an ADT operation

1.Create a list
2.Length of List
3.Insert At Beginning
4.Insert At End
5.Insert At random Position
6.Delete from Front
7.Delete from Rear
8.Delete BY Value
9.Search the list
10.Display
11.Reverse
12.Copy
0.Exit
Enter your operation code : 10

====Display List====
[0] 25 [12085952] -> [12085984] 45 [12085984] -> [12086016] 85 [12086016] -> [0] 55 [0]
Choose an ADT operation

1.Create a list
2.Length of List
3.Insert At Beginning
4.Insert At End
5.Insert At random Position
6.Delete from Front
7.Delete from Rear
8.Delete BY Value
9.Search the list
10.Display
11.Reverse
12.Copy
0.Exit
Enter your operation code : 0

=====Terminating the Operation=====*/
