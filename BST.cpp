/*
Experiment No           :7
Aim                     :To study binary search tree (BST) and implement various operations on a BST. 
Date                    :Sept 24,2019
Problem Statement       :Consider a binary search tree node – treeNode, representing a self-referential structure.
						 Write a menu driven program to – (1) insert a node into BST, (2) delete a node from BST, 
						(3) print traversals (inorder, preorder, postorder) for a BST, (4) find height of BST, 
						(5) count and print all leaf nodes, parent nodes. Your program must also allow for 
						creating a pre-allocated list before the start of BST ADT. You must not use global variables. 
*/
#include<stdio.h>
#include<stdlib.h> 
struct Tree
{
   struct Tree *lchild;
   int data;
   struct Tree *rchild;
};
typedef struct Tree * tree;
//function prototypes
tree createTree(void);
tree insertBSTNode(tree,int);
void inorderedBST(tree);
void preorderedBST(tree);
void postorderedBST(tree);
int max(int,int);
int heightBST(tree);
tree deleteNodeBST(tree,int); 
tree find_MIN_Node(tree);
int internalNodes(tree);
int parentsBT(tree); 
int allNodes(tree);
int leavesBT(tree);
tree emptyBT(tree);

int main(){
        tree root=NULL,neww;
        int knt,key,key1,choice,count,height;
        printf("\nHow many nodes? ");
        scanf("%d",&knt);
        while(knt>0)
        {
                printf("\nData of node? ");
                scanf("%d",&key);
                root=insertBSTNode(root,key);
                knt--;
        }
        
        do{
       	printf("\n1.insert node		2.inordered bst		3.preordered bst	4.postordered bst\n");
        printf("5.height of bst		6.delete node		7.find min node		8.internal nodes\n");
        printf("9.parents BT		10.count of nodes	11.leaves of BT		12.empty BT\n");
	printf("0.exit\n");
	printf("\nEnter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
                case 1:printf("Enter the data to enter:");
                       scanf("%d",&key1);
                       root=insertBSTNode(root,key1);
		       printf("\nThe node has been inserted\n"); 
                       break;
                case 2:printf("inordered BST-->");
                       inorderedBST(root);
		       break;		
                case 3:printf("preordered BST-->");
                       preorderedBST(root);
		       break;              
                case 4:printf("postordered BST-->");
                       postorderedBST(root);
		       break; 
                case 5:height=heightBST(root);
                       printf("The height of BST is %d",height);
		       break;
                case 6:printf("Enter the data to be deleted:");
                       scanf("%d",&key1);
                       root=deleteNodeBST(root,key1);
		       printf("\nThe node has been deleted\n");
                       break;
                case 7:neww=find_MIN_Node(root);
                       printf("The min node is %d",neww->data);
                       break;      
                case 8:count=internalNodes(root);
                       printf("The no. of internal nodes are %d",count);
                       break;
                case 9:count=parentsBT(root);
                       printf("The no. of parent nodes are %d",count);
                       break; 
                case 10:count=allNodes(root);
                        printf("The total no. of nodes are %d",count);
                        break;
                case 11:count=leavesBT(root);
                        printf("The total no. of leaves are %d",count);
                        break;
                case 12:root=emptyBT(root);
                        printf("The tree is empty\n");
			break;
                case 0: printf("\nTerminating condition entered");
                        break;
		
             }                      
           }while(choice!=0);
}                                                
//createTree
tree createTree(void)
{
      tree neww;
      neww=(tree)malloc(sizeof(struct Tree));
      return neww;    
}
//insertBST
tree insertBSTNode(tree root,int key1){
    if(root==NULL)
    {
        root=createTree();
        if(root==NULL){
            printf(" Insert failed\n");
        }
        root->data=key1;
        root->lchild=NULL;
        root->rchild=NULL;
    }
    else if(key1<root->data)
        root->lchild=insertBSTNode(root->lchild,key1);
    else if(key1>root->data)
        root->rchild=insertBSTNode(root->rchild,key1);    
    else
        printf("Duplicate key,not inserted");
    return root;
}
void inorderedBST(tree root){
    if(root!=NULL){
        inorderedBST(root->lchild);
        printf("%4d",root->data);
        inorderedBST(root->rchild);
    }
}   
void preorderedBST(tree root){
    if(root!=NULL){
        printf("%4d",root->data);
        preorderedBST(root->lchild);
        preorderedBST(root->rchild);
    }
}  
void postorderedBST(tree root){
    if(root!=NULL){
        postorderedBST(root->lchild);
        postorderedBST(root->rchild);
        printf("%4d",root->data);
    }
} 
int max(int lheight,int rheight){
    return (lheight>=rheight?lheight:rheight);
    }
int heightBST(tree root){
    if(root==NULL||(root->lchild==NULL && root->rchild==NULL))
        return 0;
    return max(heightBST(root->lchild),heightBST(root->rchild))+1;
} 
tree deleteNodeBST(tree root,int key1){
        tree temp;
        if(root==NULL){
                printf("Delete failed\n");
                return root;
        }        
        if(key1<root->data)
                root->lchild=deleteNodeBST(root->lchild,key1);
        else if(key1>root->data)
                root->rchild=deleteNodeBST(root->rchild,key1);
        else
        {
                if(root->lchild!=NULL && root->rchild!=NULL)
                {
                        temp=find_MIN_Node(root->rchild);
                        root->data=temp->data;
                        root->rchild=deleteNodeBST(root->rchild,root->data);
                }
                else
                {
                        temp=root;
                        if(root->lchild==NULL)
                                root=root->rchild;
                        else if(root->rchild==NULL)
                                root=root->lchild;
                        temp=root;
			return temp;
                }
       }
       return root;
}       
       
tree find_MIN_Node(tree root)
{
        if(root==NULL)
                return root;
        if(root->lchild==NULL)
                return root;
        return find_MIN_Node(root->lchild);
}
int internalNodes(tree root)
{
        if(root==NULL)
                return 0;
        return 1+internalNodes(root->lchild)+internalNodes(root->rchild);
}
int parentsBT(tree root)
{
        if(root==NULL||(root->lchild==NULL && root->rchild==NULL))
                return 0;
        printf("%d  ",root->data);
        return parentsBT(root->lchild)+parentsBT(root->rchild)+1;
}
int allNodes(tree root)
{
        int count=1;
        if(root==NULL)
                return 0;
        printf("%d  ",root->data);
        count=count+allNodes(root->lchild)+allNodes(root->rchild);
        return count;
}
int leavesBT(tree root)
{
        if(root==NULL)
                return 0;
        if(root->lchild==NULL && root->rchild==NULL){
                printf("%d  ",root->data);
                return 1;
        }
        return leavesBT(root->lchild)+leavesBT(root->rchild);                                
}
tree emptyBT(tree root)
{
	tree temp;
        if(root!=NULL)
        {
                emptyBT(root->lchild); //traverse to left subtree
                emptyBT(root->rchild); //traverse to right subtree
                printf("Released node:%d ",root->data);
		temp=root;
		return NULL;
	}
return root;
}
//Execution Trail
/*                
How many nodes? 7

Data of node? 14

Data of node? 75

Data of node? 89

Data of node? 25

Data of node? 43

Data of node? 56

Data of node? 42

1.insert node           2.inordered bst         3.preordered bst        4.postordered bst
5.height of bst         6.delete node           7.find min node         8.internal nodes
9.parents BT            10.count of nodes       11.leaves of BT         12.empty BT
0.exit

Enter the choice:2
inordered BST-->  14  25  42  43  56  75  89
1.insert node           2.inordered bst         3.preordered bst        4.postordered bst
5.height of bst         6.delete node           7.find min node         8.internal nodes
9.parents BT            10.count of nodes       11.leaves of BT         12.empty BT
0.exit

Enter the choice:3
preordered BST-->  14  75  25  43  42  56  89
1.insert node           2.inordered bst         3.preordered bst        4.postordered bst
5.height of bst         6.delete node           7.find min node         8.internal nodes
9.parents BT            10.count of nodes       11.leaves of BT         12.empty BT
0.exit

Enter the choice:4
postordered BST-->  42  56  43  25  89  75  14
1.insert node           2.inordered bst         3.preordered bst        4.postordered bst
5.height of bst         6.delete node           7.find min node         8.internal nodes
9.parents BT            10.count of nodes       11.leaves of BT         12.empty BT
0.exit

Enter the choice:5
The height of BST is 4
1.insert node           2.inordered bst         3.preordered bst        4.postordered bst
5.height of bst         6.delete node           7.find min node         8.internal nodes
9.parents BT            10.count of nodes       11.leaves of BT         12.empty BT
0.exit

Enter the choice:1
Enter the data to enter:71

The node has been inserted

1.insert node           2.inordered bst         3.preordered bst        4.postordered bst
5.height of bst         6.delete node           7.find min node         8.internal nodes
9.parents BT            10.count of nodes       11.leaves of BT         12.empty BT
0.exit

Enter the choice:7
The min node is 14
1.insert node           2.inordered bst         3.preordered bst        4.postordered bst
5.height of bst         6.delete node           7.find min node         8.internal nodes
9.parents BT            10.count of nodes       11.leaves of BT         12.empty BT
0.exit

Enter the choice:10
14  75  25  43  42  56  71  89  The total no. of nodes are 8
1.insert node           2.inordered bst         3.preordered bst        4.postordered bst
5.height of bst         6.delete node           7.find min node         8.internal nodes
9.parents BT            10.count of nodes       11.leaves of BT         12.empty BT
0.exit

Enter the choice:6
Enter the data to be deleted:43

The node has been deleted

1.insert node           2.inordered bst         3.preordered bst        4.postordered bst
5.height of bst         6.delete node           7.find min node         8.internal nodes
9.parents BT            10.count of nodes       11.leaves of BT         12.empty BT
0.exit

Enter the choice:2
inordered BST-->  14  25  42  56  71  75  89
1.insert node           2.inordered bst         3.preordered bst        4.postordered bst
5.height of bst         6.delete node           7.find min node         8.internal nodes
9.parents BT            10.count of nodes       11.leaves of BT         12.empty BT
0.exit

Enter the choice:11
42  71  89  The total no. of leaves are 3
1.insert node           2.inordered bst         3.preordered bst        4.postordered bst
5.height of bst         6.delete node           7.find min node         8.internal nodes
9.parents BT            10.count of nodes       11.leaves of BT         12.empty BT
0.exit

Enter the choice:12
Released node:42 Released node:71 Released node:56 Released node:25 Released node:89 Released node:75 Released node:14 The tree is empty

1.insert node           2.inordered bst         3.preordered bst        4.postordered bst
5.height of bst         6.delete node           7.find min node         8.internal nodes
9.parents BT            10.count of nodes       11.leaves of BT         12.empty BT
0.exit

Enter the choice:
*/                                              

                                                             
            
    

