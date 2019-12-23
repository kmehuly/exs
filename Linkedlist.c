/*Experiment No       :5
  Date of Expt        :20/9/2019
  Aim				  :To study singly linked linear lists [SLLs] and implement various operations
  					   on it “Insert, Delete, Reverse, Order, Locate, Merge, Linked Stack and Queue.
  
  Author			  :Mehul Y Khandhadiya

/*Header file inclusion */
#include<stdio.h>
#include<stdlib.h>

struct listnode{
    int data;
    struct listnode* link;
};
typedef struct listnode* list;

struct queue{
    list front;
    list rear;
};
typedef struct queue* que;
/* SINGLY LINKED LIST*/
list createNode(void);
list createList(list,int);
list insertAtBeg(list,int);
list insertAtEnd(list,int);
void displayLL(list);
int lengthLL(list);
list insertAtPos(list,int,int);
list deleteAtBeg(list);
list deleteAtEnd(list);
list deleteAtPos(list,int);
list insertOrdered(list,int);
list sortLL(list,int);
list copyLL(list);
list reverseLL(list);
list mergeorderedLL(list,list);
int searchLL(list,int);
/* STACK LINKED LIST*/
int isEmptyStk(list);
int isFullStk(list);
int topValStk(list);
/* QUEUE LINKED LIST*/
int isEmptyQue(que q);
int isFullQue(que q);
int frontValQue(que q);
int rearValQue(que q);
void insertQue(que q,int);
void deleteQue(que q);

/*main*/
int main()
{
    int choice,len,pos,mode,key,cnt,flag,select,r,ele;
    list first,top,second;
    que q;
    q=(struct queue*)malloc(sizeof(struct queue));
    do
    {
        printf("choose to start operations on linked list?\n");
        printf("1.SINGLY LINKED LIST	2.STACK LINKED LIST	3.QUEUE LINKED LIST	0.EXIT\n");
		printf("Your choice:");
        scanf("%d",&choice);
        printf("\n");
        switch(choice)
        {
            case 1:
                    first=NULL;
                    do
                    {
                        printf("choose the operation on SLL...\n");
                        printf("1.Insert node         2.Display         3.Length of LL	4.Delete at beg\n");
                        printf("5.Delete at end       6.Sort LL		    7.Copy LL		8.Rev LL\n");            
                       	printf("9.Merge ordered list  10.Delete at pos  11.search LL	12.EXIT\n");
                       	printf("your choice:");
                        scanf("%d",&select);
                        printf("\n\n");
                        switch(select)
                        {
                        case 1:
                                printf("How many nodes to insert?");
                                scanf("%d",&cnt);
                                first=createList(first,cnt); 
                                break;                  
                        case 2:   
                                displayLL(first);
                                break;
                        case 3:
                                len=lengthLL(first);
                                printf("length of list is:%d\n",len);
                                break;    
                        case 4:
                                first=deleteAtBeg(first);   
                                break;
                        case 5:
                                first=deleteAtEnd(first);
                                break;                       
                        case 6:
                                printf("select to sort linked list\n");
                                printf("1.Ascending order\n");
                                printf("2.Descending order\n");
                                printf("your choice:");
                                scanf("%d",&mode);
                                printf("\n\n");
                                if(mode==1 || mode==2)
                                {
                                    first=sortLL(first,mode);
                                }
                                else
                                {   
                                    printf("invalid choice,sort failed\n");
                                }
                                break;
                        case 7:
                                printf("copying linked list\n");
                                first=copyLL(first);
                                if(first==NULL)
                                {
                                    printf("list empty,copy failed\n");
                                }
                                else
                                {
                                    printf("list copied\n");
                                }
                                break;
                        case 8:
                                printf("reverseing linked list\n");
                                first=reverseLL(first);
                                if(first==NULL)
                                {
                                    printf("list empty,reverse failed\n");
                                }
                                else
                                {
                                    printf("list reversed\n");
                                }
                                break;
                        case 9:
                                second=NULL;
                                printf("How many Nodes?");
                                scanf("%d",&cnt);
                                second=createList(second,cnt);
                                if(first==NULL || second==NULL)
                                {
                                    printf("list empty,merge failed\n");
                                }
                                else
                                {
                                    first=mergeorderedLL(first,second);
                                    printf("list merged\n");
                                }
                                break;
                        case 10:
                                printf("Enter position?");
                                scanf("%d",&pos);
                                first=deleteAtPos(first,pos);
                                break;  
                        case 11:
                                printf("Enter key to search?");
                                scanf("%d",&key);
                                flag=searchLL(first,key);
                                    if(flag==key)
                                    {
                                        printf("Element not found\n");
                                    }
                                    else
                                    {
                                        printf("Element %d found at position:%d\n",key,flag);
                                    }                               
                                    break;                             
                        default:
                                printf("Invalid choice\n");
                                break;                        
                        case 12:
                                printf("TERMINATION ENDS...");
                                exit(0);
                        case 13:
                                printf("\n");
                                break;
                        }
                    }while(select!=13); 
                    break;
        case 2:
                top=NULL;
                printf("Performing stack linked list...\n\n"); 
                do
                {
                    printf("Choose operation on stack...\n");
                    printf("1.PUSH	    2.POP	    3.Is Empty	4.Is Full\n");
                    printf("5.Top value	6.Display	7.Exit	    8.NEW LIST\n");
                   	printf("Your choice:");
                    scanf("%d",&choice);
                    printf("\n\n");
                    switch(choice)
                    {
                        case 1:
                                printf("Enter element to insert:");
                                scanf("%d",&ele);
                                top=insertAtBeg(top,ele);
                                break;
                        case 2:
                                top=deleteAtBeg(top);
                                break;
                        case 3:
                                r=isEmptyStk(top);
                                if(r==0)
                                {
                                    printf("stack is empty\n");
                                }
                                else
                                {
                                    printf("stack is not empty\n");
                                }
                                break;
                        case 4:
                                r=isFullStk(top);
                                if(r==0)
                                {
                                    printf("stack contains element\n");
                                }
                                else
                                {
                                    printf("stack is not full\n");
                                }
                                break;
                        case 5:
                                r=topValStk(top);
                                if(r==0)
                                {
                                    printf("stack is empty\n");
                                }
                                else
                                {
                                    printf("top value:%d\n",r);
                                }
                                break;
                        case 6:
                                displayLL(top);
                                break;
                        case 7:
                                printf("TERMINATION ENDS...\n");
                                exit(0);
                        case 8:
                                printf("\n\n\n");
                                break; 
                        default:
                                printf("Invalid input\n");
                                break;
                    }
                }while(choice!=8);
                break;
        case 3:
                q->front=NULL;
                q->rear=NULL;
                printf("Performing queue linked list...\n\n");
                do
                {
                    printf("Choose operarion on queue...\n");
                    printf("1.Insert	    2.Delete	    3.Is Empty	4.Is Full\n");
                   	printf("5.Front Value	6.Rear Value	7.Display	8.EXIT	9.NEW LIST\n");
                    printf("your choice:");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1:
                                printf("Enter element to insert:");
                                scanf("%d",&ele);
                                insertQue(q,ele);
                                break;
                        case 2:
                                deleteQue(q);
                                break;
                        case 3:
                                r=isEmptyQue(q);
                                if(r==0)
                                {
                                    printf("Queue is empty\n");
                                }
                                else
                                {
                                    printf("Queue is not empty\n");
                                }
                                break;
                        case 4:
                                r=isFullQue(q);
                                if(r==0)
                                {
                                    printf("Queue contains element\n");
                                }
                                else
                                {
                                    printf("Queue is not full\n");
                                }
                                break;
                        case 5:
                                r=frontValQue(q);
                                if(r==0)
                                {
                                    printf("Queue is empty\n");
                                }
                                else
                                {
                                    printf("front value:%d\n",r);
                                }
                                break;
                        case 6:
                                r=rearValQue(q);
                                if(r==0)
                                {
                                    printf("Queue is empty\n");
                                }
                                else
                                {
                                    printf("rear value:%d\n",r);
                                }
                                break;
                        case 7:
                                displayLL(q->front);
                                break;
                        case 8:
                                printf("TERMINATION ENDS...");
                                exit(0);
                        case 9:
                                printf("\n\n\n");
                                break;
                        default:
                                printf("Invalid input\n");
                                break;
                    }
                }while(choice!=9);
                break;                                  
        }
    }while(choice!=0);
    printf("TERMINATION ENDS...");
    return(0);
}
list createNode(void)
{
    list neww;
    neww=(list)malloc(sizeof(struct listnode));
    if(neww==NULL)
    {
        return NULL;
    }
    else
    {
        return neww;
    }
}
list createList(list first,int cnt)
{
    int ele,data,select,pos;
    for(ele=0;ele<cnt;ele++)
    {
        printf("Enter key-%d:",ele+1);
        scanf("%d",&data);
        printf("select choice....\n");
        printf("1.Insert at beginning	2.Insert at end\n");
        printf("3.Insert at position	4.Insert in ordered list\n");
		scanf("%d",&select);
        switch(select)
        {
            case 1:
                    first=insertAtBeg(first,data);
                    break;
            case 2:
                    first=insertAtEnd(first,data);
                    break;
            case 3:
                    printf("enter the position:");
                    scanf("%d",&pos);
                    first=insertAtPos(first,data,pos);
                    break;
            case 4:
                    first=insertOrdered(first,data);
                    break;
            default:
                    printf("Invalid choice...\n\n");
                    break;
        }                    
    }
    return first;
}        
list insertAtBeg(list first,int data)
{
    list neww;
    neww=createNode();
    if(neww==NULL)
    {
        printf("insert failed\n\n");        
        return first;
    }
    neww->data=data;
    neww->link=NULL; 
    printf("Element inserted\n\n");   
    if(first==NULL)
    {
        return neww;
    }
    neww->link=first;
    return neww;
}
list insertAtEnd(list first,int data)
{
    list neww,temp;
    neww=createNode();
    if(neww==NULL)
    {
        printf("insert failed\n\n");
        return first;
    }
    neww->data=data;
    neww->link=NULL;
    printf("Element inserted\n\n");
    if(first==NULL)
    {
        return neww;
    }
    temp=first;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=neww;    
    return first;
}
void displayLL(list first)
{   
    printf("list contents are...\n\n");
    if(first==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while(first!=NULL)
        {
            printf("%d[%lu]-->",first->data,(unsigned long)first);
            first=first->link;
        }
        printf("NULL");
    }
    printf("\n\n");
}
int lengthLL(list first)
{
    int length=0;
    if(first==NULL)
    {
        return length;
    }
    while(first!=NULL)
    {
        length=length+1;
        first=first->link;
    }
    return length;
}
list insertAtPos(list first,int data,int pos)
{
    list neww,temp;
    int ndx=0,len;
    len=lengthLL(first);
    if(pos<1 || pos>len)
    {
        printf("invalid poition,insert failed...\n\n");
        return first;
    }
    neww=createNode();
    if(neww==NULL)
    {
        return first;
    }
    printf("Element inserted\n\n");
    neww->data=data;
    neww->link=NULL;
    if(pos==1)  
    {
        neww->link=first;
        return neww;
    }
    temp=first;
    while(ndx<pos-2)
    {
        ndx=ndx+1;
        temp=temp->link;
    }
    neww->link=temp->link;
    temp->link=neww;
    return first;
}
list deleteAtBeg(list first)
{
    list temp;
    int key;
    if(first==NULL)
    {
        printf("List empty,delete failed\n\n");
        return first;
    }
    key=first->data;
    printf("Element deleted:%d\n\n",key);
    temp=first;
    first=first->link;
    temp=first;
    return first;
}
list deleteAtEnd(list first)
{
    list temp;
    int key;
    if(first==NULL)
    {
        printf("List empty,delete failed\n\n");
        return first;
    }
    if(first->link==NULL)
    {
        key=first->data;
        return NULL;
    }
    temp=first;
    while((temp->link)->link!=NULL)
    {
        temp=temp->link;
    }
    key=(temp->link)->data;
    temp->link=NULL;
    printf("Element deleted:%d\n\n",key);
    return first;
}
list insertOrdered(list first,int data)
{
    list neww,temp;
    neww=createNode();
    if(neww==NULL)
    {
        printf("insert failed\n\n");
        return first;
    }
    printf("Elemnt inserted\n\n");
    neww->data=data;
    neww->link=NULL; 
    if(first==NULL)
    {
        return neww;
    }
    if(first->data>=neww->data)
    {
        neww->link=first;
        return neww;
    }
    temp=first;
    while(temp->link!=NULL && (temp->link)->data <= neww->data)
    {
        temp=temp->link;
    }
    neww->link=temp->link;
    temp->link=neww;
    return first;
}
list sortLL(list first,int mode)
{
    list iptr,jptr;
    int key;
    if(first==NULL || first->link==NULL)
    {
        printf("Sorting failed\n");
        return first;
    }
    iptr=first;
    for(iptr=first;iptr->link!=NULL;iptr=iptr->link)
    {
        for(jptr=iptr->link;jptr!=NULL;jptr=jptr->link)
        {
            switch(mode)
            {
                case 1:
                        if(iptr->data > jptr->data)
                        {
                            key=jptr->data;
                            jptr->data=iptr->data;
                            iptr->data=key;
                        }
                        break;
                case 2:
                        if(iptr->data < jptr->data)
                        {
                            key=iptr->data;
                            iptr->data=jptr->data;
                            jptr->data=key;
                        }
                        break;
            }
        }
    }
    return first;
}
list copyLL(list first)
{
    list neww,dupl,temp,cpy;
    if(first==NULL)
    {
        return NULL;
    }
    neww=createNode();
    neww->data=first->data;
    neww->link=NULL;
    dupl=neww;
    temp=first;
    while(temp->link!=NULL)
    {
        cpy=neww;
        temp=temp->link;
        neww=createNode();
        neww->data=temp->data;
        neww->link=NULL;
        cpy->link=neww;
    }
    neww->link=NULL;
    return dupl;
}
list reverseLL(list first)
{
    list ptr1,ptr2,rev;
    if(first==NULL)
    {
        return NULL;
    }
    rev=first;
    ptr2=(first->link)->link;
    ptr1=first->link;
    rev->link=NULL;
    ptr1->link=rev;
    while(ptr2!=NULL)
    {
        rev=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->link;
        ptr1->link=rev;
    }
    return ptr1;  
}      
list mergeorderedLL(list first,list second)
{
    list temp,third,tail,neww;
    third=temp=tail=NULL;
    while(first!=NULL && second!=NULL)
    {
        neww=createNode();
        neww->link=NULL;
        if(first->data <= second->data) 
        {
            neww->data=first->data;
            first=first->link;
        }
        else
        {
            neww->data=second->data;
            second=second->link;
        }
        if(third==NULL)
        {
            third=tail=neww;
        }
        else
        {
            tail->link=neww;
            tail=neww;
        }
        while(first!=NULL)
        {
            neww=createNode();
            neww->link=NULL;
            neww->data=first->data;
            first=first->link;
            tail->link=neww;
            tail=neww;
        }
        while(second!=NULL)
        {
            neww=createNode();
            neww->link=NULL;
            neww->data=second->data;
            second=second->link;
            tail->link=neww;
            tail=neww;
        }
    }
        return third;
}
list deleteAtPos(list first,int pos)
{
    list temp;
    int ndx=0,len,key;
    len=lengthLL(first);
    if(pos<1 || pos>len)
    {
        printf("Invalid position,delete failed\n\n");
        return first;
    }
    if(first==NULL)
    {
        printf("List empty,delete failed\n\n");
        return first;
    }
    if(pos==1)
    {
        key=first->data;
        temp=first;
        first=first->link;
        temp=first;
        printf("Element deleted:%d\n\n",key);
        return first;
    }
    temp=first;
    while(ndx<pos-2)
    {
        ndx=ndx+1;
        temp=temp->link;
    }
    key=(temp->link)->data;
    temp->link=(temp->link)->link;
    printf("Element deleted:%d\n\n",key);
    return first;
}
int searchLL(list first,int key)
{
    int ndx=1;
    while(first!=NULL)
    {
        if(first->data==key)
        {
            return ndx;
        }
        ndx=ndx+1;
        first=first->link;
    }
    return key;
}
int isEmptyStk(list top)
{
    if(top==NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int isFullStk(list top)
{
    if(top->link==NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int topValStk(list top)
{
    if(top==NULL)
    {
        return 0;
    }
    else
    {
        return top->data;
    }
}
void insertQue(que q,int ele)
{
    list neww;
    neww=createNode();
    if(neww==NULL)
    {
        printf("Insert failed\n");
    }
    else
    {
        printf("Element inserted\n");
        neww->data=ele;
        neww->link=NULL;
        if(q->front==NULL && q->rear==NULL)
        {
            q->front=neww;
            q->rear=neww;
        }
        else
        {
            q->rear->link=neww;
            q->rear=q->rear->link;
        }
    }
}
void deleteQue(que q)
{
    if(q->front==NULL)
    {
        printf("delete failed,list empty\n");
    }
    else if(q->front==q->rear)
    {
        printf("Element deleted:%d\n",q->front->data);
        q->front=NULL;
        q->rear=NULL;
    }
    else
    {
        printf("Element deleted:%d\n",q->front->data);
        q->front=q->front->link;
    }
}
int isEmptyQue(que q)
{
    if(q->front==NULL && q->rear==NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int isFullQue(que q)
{
    if(q->front!=NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int frontValQue(que q)
{
    if(q->front==NULL)
    {
        return 0;
    }
    else
    {
        return q->front->data;
    }
}
int rearValQue(que q)
{
    if(q->rear==NULL)
    {
        return 0;
    }
    else
    {
        return q->rear->data;
    }
}
/*Execution Trail
choose to start operations on linked list?
1.SINGLY LINKED LIST    2.STACK LINKED LIST     3.QUEUE LINKED LIST     0.EXIT
Your choice:1

choose the operation on SLL...
1.Insert node         2.Display         3.Length of LL  4.Delete at beg
5.Delete at end       6.Sort LL             7.Copy LL           8.Rev LL
9.Merge ordered list  10.Delete at pos  11.search LL    12.EXIT
your choice:1
How many nodes to insert?3
Enter key-1:12
select choice....
1.Insert at beginning   2.Insert at end
3.Insert at position    4.Insert in ordered list
1
Element inserted
Enter key-2:56
select choice....
1.Insert at beginning   2.Insert at end
3.Insert at position    4.Insert in ordered list
2
Element inserted
Enter key-3:87
select choice....
1.Insert at beginning   2.Insert at end
3.Insert at position    4.Insert in ordered list
1
Element inserted
choose the operation on SLL...
1.Insert node         2.Display         3.Length of LL  4.Delete at beg
5.Delete at end       6.Sort LL             7.Copy LL           8.Rev LL
9.Merge ordered list  10.Delete at pos  11.search LL    12.EXIT
your choice:2
list contents are...
87[7563968]-->12[7563904]-->56[7563936]-->NULL
choose the operation on SLL...
1.Insert node         2.Display         3.Length of LL  4.Delete at beg
5.Delete at end       6.Sort LL             7.Copy LL           8.Rev LL
9.Merge ordered list  10.Delete at pos  11.search LL    12.EXIT
your choice:1
How many nodes to insert?2
Enter key-1:34
select choice....
1.Insert at beginning   2.Insert at end
3.Insert at position    4.Insert in ordered list
3
enter the position:2
Element inserted
Enter key-2:40
select choice....
1.Insert at beginning   2.Insert at end
3.Insert at position    4.Insert in ordered list
4
Elemnt inserted
choose the operation on SLL...
1.Insert node         2.Display         3.Length of LL  4.Delete at beg
5.Delete at end       6.Sort LL             7.Copy LL           8.Rev LL
9.Merge ordered list  10.Delete at pos  11.search LL    12.EXIT
your choice:3
length of list is:5
choose the operation on SLL...
1.Insert node         2.Display         3.Length of LL  4.Delete at beg
5.Delete at end       6.Sort LL             7.Copy LL           8.Rev LL
9.Merge ordered list  10.Delete at pos  11.search LL    12.EXIT
your choice:4
Element deleted:40
choose the operation on SLL...
1.Insert node         2.Display         3.Length of LL  4.Delete at beg
5.Delete at end       6.Sort LL             7.Copy LL           8.Rev LL
9.Merge ordered list  10.Delete at pos  11.search LL    12.EXIT
your choice:5
Element deleted:56
choose the operation on SLL...
1.Insert node         2.Display         3.Length of LL  4.Delete at beg
5.Delete at end       6.Sort LL             7.Copy LL           8.Rev LL
9.Merge ordered list  10.Delete at pos  11.search LL    12.EXIT
your choice:6
select to sort linked list
1.Ascending order
2.Descending order
your choice:1
choose the operation on SLL...
1.Insert node         2.Display         3.Length of LL  4.Delete at beg
5.Delete at end       6.Sort LL             7.Copy LL           8.Rev LL
9.Merge ordered list  10.Delete at pos  11.search LL    12.EXIT
your choice:2
list contents are...
12[7563968]-->34[7564000]-->87[7563904]-->NULL
choose the operation on SLL...
1.Insert node         2.Display         3.Length of LL  4.Delete at beg
5.Delete at end       6.Sort LL             7.Copy LL           8.Rev LL
9.Merge ordered list  10.Delete at pos  11.search LL    12.EXIT
your choice:9
How many Nodes?3
Enter key-1:22
select choice....
1.Insert at beginning   2.Insert at end
3.Insert at position    4.Insert in ordered list
1
Element inserted
Enter key-2:55
select choice....
1.Insert at beginning   2.Insert at end
3.Insert at position    4.Insert in ordered list
2
Element inserted
Enter key-3:77
select choice....
1.Insert at beginning   2.Insert at end
3.Insert at position    4.Insert in ordered list
1
Element inserted
list merged
choose the operation on SLL...
1.Insert node         2.Display         3.Length of LL  4.Delete at beg
5.Delete at end       6.Sort LL             7.Copy LL           8.Rev LL
9.Merge ordered list  10.Delete at pos  11.search LL    12.EXIT
your choice:2
list contents are...
12[7564160]-->34[7564192]-->87[7564224]-->77[7564256]-->22[7564288]-->55[7564320]-->NULL
choose to start operations on linked list?
1.SINGLY LINKED LIST    2.STACK LINKED LIST     3.QUEUE LINKED LIST     0.EXIT
Your choice:2

Performing stack linked list...

Choose operation on stack...
1.PUSH      2.POP           3.Is Empty  4.Is Full
5.Top value     6.Display       7.Exit      8.NEW LIST
Your choice:1
Enter element to insert:26
Element inserted
Choose operation on stack...
1.PUSH      2.POP           3.Is Empty  4.Is Full
5.Top value     6.Display       7.Exit      8.NEW LIST
Your choice:4
stack contains element
Choose operation on stack...
1.PUSH      2.POP           3.Is Empty  4.Is Full
5.Top value     6.Display       7.Exit      8.NEW LIST
Your choice:1
Enter element to insert:56
Element inserted
Choose operation on stack...
1.PUSH      2.POP           3.Is Empty  4.Is Full
5.Top value     6.Display       7.Exit      8.NEW LIST
Your choice:6
list contents are...
56[10578592]-->26[10578560]-->NULL
Choose operation on stack...
1.PUSH      2.POP           3.Is Empty  4.Is Full
5.Top value     6.Display       7.Exit      8.NEW LIST
Your choice:3
stack is not empty
Choose operation on stack...
1.PUSH      2.POP           3.Is Empty  4.Is Full
5.Top value     6.Display       7.Exit      8.NEW LIST
Your choice:2
Element deleted:56
Choose operation on stack...
1.PUSH      2.POP           3.Is Empty  4.Is Full
5.Top value     6.Display       7.Exit      8.NEW LIST
Your choice:5
top value:26
choose to start operations on linked list?
1.SINGLY LINKED LIST    2.STACK LINKED LIST     3.QUEUE LINKED LIST     0.EXIT
Your choice:3

Performing queue linked list...

Choose operarion on queue...
1.Insert            2.Delete        3.Is Empty  4.Is Full
5.Front Value   6.Rear Value    7.Display       8.EXIT  9.NEW LIST
your choice:3
Queue is empty
Choose operarion on queue...
1.Insert            2.Delete        3.Is Empty  4.Is Full
5.Front Value   6.Rear Value    7.Display       8.EXIT  9.NEW LIST
your choice:4
Queue is not full
Choose operarion on queue...
1.Insert            2.Delete        3.Is Empty  4.Is Full
5.Front Value   6.Rear Value    7.Display       8.EXIT  9.NEW LIST
your choice:1
Enter element to insert:48
Element inserted
Choose operarion on queue...
1.Insert            2.Delete        3.Is Empty  4.Is Full
5.Front Value   6.Rear Value    7.Display       8.EXIT  9.NEW LIST
your choice:1
Enter element to insert:88
Element inserted
Choose operarion on queue...
1.Insert            2.Delete        3.Is Empty  4.Is Full
5.Front Value   6.Rear Value    7.Display       8.EXIT  9.NEW LIST
your choice:5
front value:48
Choose operarion on queue...
1.Insert            2.Delete        3.Is Empty  4.Is Full
5.Front Value   6.Rear Value    7.Display       8.EXIT  9.NEW LIST
your choice:7
list contents are...
48[11627136]-->88[11627168]-->NULL
Choose operarion on queue...
1.Insert            2.Delete        3.Is Empty  4.Is Full
5.Front Value   6.Rear Value    7.Display       8.EXIT  9.NEW LIST
your choice:6
rear value:88
Choose operarion on queue...
1.Insert            2.Delete        3.Is Empty  4.Is Full
5.Front Value   6.Rear Value    7.Display       8.EXIT  9.NEW LIST
your choice:2
Element deleted:48
Choose operarion on queue...
1.Insert            2.Delete        3.Is Empty  4.Is Full
5.Front Value   6.Rear Value    7.Display       8.EXIT  9.NEW LIST
your choice:7
list contents are...
88[11627168]-->NULL
*/


