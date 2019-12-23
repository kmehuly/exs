/*
EXPERIMENT NUMBER : 09
DATE : 09/10/2019
AIM : To study a graph data structure and demonstrate different traversals on it - Depth First Search and Breadth First Search.
*/
#include<stdio.h>
#include<stdlib.h>
#define MX 7
#define SIZE 50
void addEdge(int g[][MX],int src, int dest);
void initAdjacencyMatrix(int g[][MX]);
void showAdjacencyMatrix(int g[][MX]);
void setUpDFSBFS();
void dfsAdjMatrix(int g[][MX],int visitedDFS[],int src);
void bfsAdjMatrix(int g[][MX],int visitedBFS[],int src,int q[MX]);
void cmdisplay(int visited[MX],int src);
//initQueue()int isqEmpty(int f, int r);
int isqFull(int r,int lenq);
int isqEmpty(int f, int r);
void displayq(int*q,int f,int r);
int main()
{
    int choice,choice1;
    int g[MX][MX];
 int visitedDFS[MX];
    int path[MX];
 int visitedBFS[MX];
 int i,j,edge,ed1,ed2,src;
    int knt=0;
 //variable for Queue
 int qcheck,front=-1,rear=-1,lenq,q[MX];
	printf("\n==== Graph Data Structure ====\n");
    printf("\nPerform graph traversals ?\nEnter 1 for YES or Enter 0 to EXIT : ");
    scanf("%d",&choice);    
  if(choice!=1)
  {
    printf("\n=====Terminating=====\n");
    return 0;
  }
  else
  {
    initAdjacencyMatrix(g);		//INITIALIZE ADJACENCY MATRIX
 //SETTING UP EDGES
 for(i=0;i<MX;i++)
 {
printf("\nAdd Edge [%d] : ",i);
scanf("%d %d",&ed1,&ed2);
addEdge(g,ed1,ed2);
addEdge(g,ed2,ed1);
 }
    printf("\nDisplaying Graph......\n");
 showAdjacencyMatrix(g);
    printf("\n");
  do{
 for(i=0;i<MX;i++)			//SETTING UP VISITED TO 0
 {
visitedDFS[i]=0;
 }
    for(i=0;i<MX;i++)
 {
path[i]='X';
 }
 for(i=0;i<MX;i++)
 {
visitedBFS[i]=0;
 }
      printf("\nTraversal on: \n1.Depth First Search\n2.Breadth First Search\n");
      printf("\nEnter your operation code : ");
      scanf("%d",&choice1);
		switch(choice1)
        {
          case 0:
                printf("\n=====Thank You=====\n");
          break;
		  case 1:
                printf("\n====Depth First Search====\n");
                printf("\nEnter Source for DFS : ");
                scanf("%d",&src);
                dfsAdjMatrix(g,visitedDFS,src);
   
          break;
		  case 2:
                printf("\n====Breadth First Search====\n");
                printf("\nEnter Source for BFS : ");
                scanf("%d",&src);
                bfsAdjMatrix(g,visitedBFS,src,q);
		  break;
       	  default:
                printf("\nxxxxxx Incorrect Input xxxxxx");
        }
  }while(choice1!=0);

    }    
	return 0;
}
//INITIALIZE ADJANCEY MATRIX TO 0
void initAdjacencyMatrix(int g[][MX])
{
  int i,j;
    for(i = 0; i < MX; i++)
        for(j = 0; j < MX; j++)
            g[i][j] = 0;
}
//ADD EDGE
void addEdge(int g[][MX],int src, int dest)
{
    g[src][dest] = 1;
}

void showAdjacencyMatrix(int g[][MX])
{
  int i, j;
     printf("\nu|v | \t0\t1\t2\t3\t4\t5\t6\n");
     printf("     __ __ __ __ __ __ __ __ __ __  __ __ __ __ __ __\n");
     printf("\n0   | ");
     for(i=0;i<MX;i++)
     {
         printf("\t");
         for(j=0;j<MX;j++)
         {
             printf("%d\t", g[i][j]);
         }
         if(i+1<MX)
           printf("\n%d   | ",i+1);
     }
}
void dfsAdjMatrix(int g[][MX],int visitedDFS[],int src)
{
   
    int vknt=0;
    visitedDFS[src]=1;
    cmdisplay(visitedDFS,src);
    printf("\n\t\t\t------------ %d VISITED ------------- \n",src);
    while(vknt < MX)
    {
      if(g[src][vknt]==1 && visitedDFS[vknt]==0)
      {
       
        dfsAdjMatrix(g,visitedDFS,vknt);
       
      }
     
      vknt++;
    }
 
}
void bfsAdjMatrix(int g[][MX],int visitedBFS[],int src,int q[MX])
{
  int front=-1,rear=-1,vknt,l;
  visitedBFS[src]=1;
  rear=rear+1;
  front=front+1;
  q[rear]=src;
  //displayq(q,front,rear);
  while(front<=rear)
  {
    src=q[front];
    front++;
    vknt=0;
    while(vknt<MX)
    {
      if(g[src][vknt]==1 && visitedBFS[vknt]==0)
      {
          visitedBFS[vknt]=1;
          rear=rear+1;
          q[rear]=vknt;
      }
      vknt++;
    }
    if(isqEmpty(front,rear))
    {
      displayq(q,front,rear);
      printf("\n--------------------------------------------------\n");
    }
 }
}
void cmdisplay(int visited[MX],int src)
{
  int i;
  printf("\n\n\n\t============ SRC : %d ============\n",src);
  printf("\n---------------------------------------------------------------------------------");
  printf("\n    DS    \t| 0 |\t| 1 |\t| 2 |\t| 3 |\t| 4 |\t| 5 |\t| 6 |\n");
  printf("\n----------------------------------------------------------------");
  printf("\n VISITED ");
  for(i=0;i<MX;i++)
  {
    printf("\t| %d |",visited[i]);
  }
  printf("\n---------------------------------------");
}
void displayq(int queue[MX],int front,int rear)
{
  int i;
  for(i=0;i<=rear;i++)
  {
    if(queue[i]!=-99)
      printf("| %d |",queue[i]);
    else
      printf("| X |");
  }
}
int isqFull(int rear,int lenq)
{
  if(rear==lenq-1)
    return(0);
  else
    return(1);
}
int isqEmpty(int front, int rear)
{
  if((front==-1 && rear==-1)||(front>rear))
    return(0);
  else
    return(1);
}
/*Execution Trail
==== Graph Data Structure ====

Perform graph traversals ?
Enter 1 for YES or Enter 0 to EXIT : 1

Add Edge [0] : 1 2

Add Edge [1] : 1 3

Add Edge [2] :  1 4

Add Edge [3] : 2 3

Add Edge [4] : 3 5

Add Edge [5] : 4 6

Add Edge [6] : 4 5

Displaying Graph......

u|v |   0       1       2       3       4       5       6
     __ __ __ __ __ __ __ __ __ __  __ __ __ __ __ __

0   |   0       0       0       0       0       0       0
1   |   0       0       1       1       1       0       0
2   |   0       1       0       1       0       0       0
3   |   0       1       1       0       0       1       0
4   |   0       1       0       0       0       1       1
5   |   0       0       0       1       1       0       0
6   |   0       0       0       0       1       0       0

Traversal on:
1.Depth First Search
2.Breadth First Search

Enter your operation code : 1

====Depth First Search====

Enter Source for DFS : 1



        ============ SRC : 1 ============

---------------------------------------------------------------------------------
    DS          | 0 |   | 1 |   | 2 |   | 3 |   | 4 |   | 5 |   | 6 |

----------------------------------------------------------------
 VISITED        | 0 |   | 1 |   | 0 |   | 0 |   | 0 |   | 0 |   | 0 |
---------------------------------------
                        ------------ 1 VISITED -------------



        ============ SRC : 2 ============

---------------------------------------------------------------------------------
    DS          | 0 |   | 1 |   | 2 |   | 3 |   | 4 |   | 5 |   | 6 |

----------------------------------------------------------------
 VISITED        | 0 |   | 1 |   | 1 |   | 0 |   | 0 |   | 0 |   | 0 |
---------------------------------------
                        ------------ 2 VISITED -------------



        ============ SRC : 3 ============

---------------------------------------------------------------------------------
    DS          | 0 |   | 1 |   | 2 |   | 3 |   | 4 |   | 5 |   | 6 |

----------------------------------------------------------------
 VISITED        | 0 |   | 1 |   | 1 |   | 1 |   | 0 |   | 0 |   | 0 |
---------------------------------------
                        ------------ 3 VISITED -------------



        ============ SRC : 5 ============

---------------------------------------------------------------------------------
    DS          | 0 |   | 1 |   | 2 |   | 3 |   | 4 |   | 5 |   | 6 |

----------------------------------------------------------------
 VISITED        | 0 |   | 1 |   | 1 |   | 1 |   | 0 |   | 1 |   | 0 |
---------------------------------------
                        ------------ 5 VISITED -------------



        ============ SRC : 4 ============

---------------------------------------------------------------------------------
    DS          | 0 |   | 1 |   | 2 |   | 3 |   | 4 |   | 5 |   | 6 |

----------------------------------------------------------------
 VISITED        | 0 |   | 1 |   | 1 |   | 1 |   | 1 |   | 1 |   | 0 |
---------------------------------------
                        ------------ 4 VISITED -------------



        ============ SRC : 6 ============

---------------------------------------------------------------------------------
    DS          | 0 |   | 1 |   | 2 |   | 3 |   | 4 |   | 5 |   | 6 |

----------------------------------------------------------------
 VISITED        | 0 |   | 1 |   | 1 |   | 1 |   | 1 |   | 1 |   | 1 |
---------------------------------------
                        ------------ 6 VISITED -------------

Traversal on:
1.Depth First Search
2.Breadth First Search

Enter your operation code : 2

====Breadth First Search====

Enter Source for BFS : 2
| 2 || 1 || 3 |
--------------------------------------------------
| 2 || 1 || 3 || 4 |
--------------------------------------------------
| 2 || 1 || 3 || 4 || 5 |
--------------------------------------------------
| 2 || 1 || 3 || 4 || 5 || 6 |
--------------------------------------------------
| 2 || 1 || 3 || 4 || 5 || 6 |
--------------------------------------------------

Traversal on:
1.Depth First Search
2.Breadth First Search

Enter your operation code : 3

xxxxxx Incorrect Input xxxxxx*/

