/*
        Experiment No           :8
        Author                  :Mehul Y Khandhadiya
        Date                    :Sept 24,2019
*/
#include<stdio.h>
#include<stdlib.h> 
struct avlNode
{
   struct avlNode *lchild;
   int data;
   int height;
   int address;
   struct avlNode *rchild;
};
typedef struct avlNode * tree;
//function prototypes
tree createAVLTree(int);
tree insertAVLNode(tree,int);
void inorderedAVL(tree);
void preorderedAVL(tree);
void postorderedAVL(tree);
int max(int,int);
int heightAVL(tree);
int bfactor(tree);
tree leftRotate(tree);
tree rightRotate(tree);
tree deleteNodeAVL(tree,int); 
tree find_MIN_Node(tree);
tree emptyAVL(tree);

int main(){
        tree root=NULL,neww;
        int knt,key,key1,choice,count,height1;
        printf("\nHow many nodes? ");
        scanf("%d",&knt);
        while(knt>0)
        {
                printf("\nData of node? ");
                scanf("%d",&key);
                root=insertAVLNode(root,key);
                knt--;
        }
        
        do{
       	printf("\n1.insert node		2.inordered avl		3.preordered avl	4.postordered avl\n");
        printf("5.height of avl		6.delete node		7.find min node		8.empty AVL\n");
		printf("9.balanceFactor		0.exit\n");
		printf("\nEnter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
                case 1:printf("Enter the data to enter:");
                       scanf("%d",&key1);
                       root=insertAVLNode(root,key1);
		       		   printf("\nThe node has been inserted\n"); 
                       break;
                case 2:printf("inordered AVL-->");
                       inorderedAVL(root);
		       		   break;		
                case 3:printf("preordered AVL-->");
                       preorderedAVL(root);
		       		   break;              
                case 4:printf("postordered AVL-->");
                       postorderedAVL(root);
		       		   break; 
                case 5:height1=heightAVL(root);
                       printf("The height of AVL is %d",height1);
		       		   break;
                case 6:printf("Enter the data to be deleted:");
                       scanf("%d",&key1);
                       root=deleteNodeAVL(root,key1);
		       		   printf("\nThe node has been deleted\n");
                       break;
                case 7:neww=find_MIN_Node(root);
                       printf("The min node is %d",neww->data);
                       break;      
                case 8:root=emptyAVL(root);
                    	printf("The tree is empty\n");
						break;
				case 9:count=bfactor(root);
					   printf("The balance factor is %d",count);
					   break;
                case 0: printf("Terminating condition entered");
                        break;
			}                      
           }while(choice!=0);
}                                                
//createTree
tree createAVLTree(int key)
{
	  tree neww;
      neww=(tree)malloc(sizeof(struct avlNode));
      neww->data=key;
      neww->height=1;
      neww->lchild=neww->rchild=NULL;
      return neww;    
}
void inorderedAVL(tree root){
    if(root!=NULL){
        inorderedAVL(root->lchild);
        printf("%4d",root->data);
        inorderedAVL(root->rchild);
    }
}   
void preorderedAVL(tree root){
    if(root!=NULL){
        printf("%4d",root->data);
        preorderedAVL(root->lchild);
        preorderedAVL(root->rchild);
    }
}  
void postorderedAVL(tree root){
    if(root!=NULL){
        postorderedAVL(root->lchild);
        postorderedAVL(root->rchild);
        printf("%4d",root->data);
    }
} 
int max(int lheight,int rheight){
	return (lheight>=rheight?lheight:rheight);
}
int heightAVL(tree root){
    if(root==NULL){
		return 0;
    }
	return (root->height);
} 
tree deleteNodeAVL(tree root,int key1){
        tree temp;
        int bal,lbal,rbal;
        if(root==NULL){
            printf("Delete failed\n");
            return root;
        }        
        if(key1<root->data)
            root->lchild=deleteNodeAVL(root->lchild,key1);
        else if(key1>root->data)
            root->rchild=deleteNodeAVL(root->rchild,key1);
        else
        {
            if(root->lchild==NULL || root->rchild==NULL)
            {
                if(root->lchild!=NULL)
                    temp=root->lchild;
                else
					temp=root->rchild;
				if(temp==NULL){
					temp=root;
					root=NULL;
				}
				else{
					root->data=temp->data;
					root->height=temp->height;
					temp=NULL;
					return temp;
					}		
                }
            else
            {
                temp=find_MIN_Node(root->rchild);
                root->data=temp->data;
                root->rchild=deleteNodeAVL((root->rchild),(temp->address));
            }
       }
		if(root==NULL)
			return root;
		root->height=max(heightAVL(root->lchild),heightAVL(root->rchild))+1;
		bal=bfactor(root);
		lbal=bfactor(root->lchild);
		rbal=bfactor(root->rchild);
		if(bal>1 && lbal>=0)
			rightRotate(root);
		if(bal>1 && lbal<0){
			root->lchild=leftRotate(root->lchild);
			return rightRotate(root);
		}
		if(bal<-1 && rbal<=0)
			leftRotate(root);
		if(bal<-1 && rbal>0){
			root->rchild=rightRotate(root->rchild);
			return leftRotate(root);
		}
	return root;	   
}       
       
tree find_MIN_Node(tree root)
{
       tree temp=root;
       while(temp->lchild!=NULL)
       		temp=temp->lchild;
       return temp;		
}

tree emptyAVL(tree root)
{
	tree temp;
        if(root!=NULL)
        {
                emptyAVL(root->lchild); //traverse to left subtree
                emptyAVL(root->rchild); //traverse to right subtree
                printf("Released node:%d ",root->data);
		temp=root;
		return NULL;
	}
return NULL;
}
int bfactor(tree root){
	if(root==NULL){
		return 0;
	}
	return (heightAVL(root->lchild)-heightAVL(root->rchild));
}	
tree leftRotate(tree X){
	tree T2,Y;
	//pivot
	Y=X->rchild;
	T2=Y->lchild;
	//rotation
	Y->lchild=X;
	X->rchild=T2;
	//update heights
	X->height=max(heightAVL(X->lchild),heightAVL(X->rchild))+1;
	Y->height=max(heightAVL(Y->lchild),heightAVL(Y->rchild))+1;
	return Y;
}
tree rightRotate(tree Y){
	tree T2,X;
	//pivot
	X=Y->lchild;
	T2=X->rchild;
	//rotation
	X->rchild=Y;
	Y->lchild=T2;
	//update heights
	Y->height=max(heightAVL(Y->lchild),heightAVL(Y->rchild))+1;
	X->height=max(heightAVL(X->lchild),heightAVL(X->rchild))+1;
	return X;
}
tree insertAVLNode(tree root,int key){
	int bal;
	if(root==NULL){
		return createAVLTree(key);
	}
	if(key<root->data)
		root->lchild=insertAVLNode(root->lchild,key);
	else if(key>root->data)
		root->rchild=insertAVLNode(root->rchild,key);
	else
		return root;
	root->height=max(heightAVL(root->lchild),heightAVL(root->rchild))+1;
	bal=bfactor(root);
	if(bal>1 && key<(root->lchild)->data)
		return rightRotate(root);
	if(bal<-1 && key>(root->rchild)->data)
		return leftRotate(root);
	if(bal>1 && key>(root->lchild)->data){
		root->lchild=leftRotate(root->lchild);
		return rightRotate(root);
	}
	if(bal<-1 && key<(root->rchild)->data){
		root->rchild=rightRotate(root->rchild);					
		return leftRotate(root);
	}
	return root;
}
/*Execution Trail
How many nodes? 5

Data of node? 13

Data of node? 23

Data of node? 43

Data of node? 56

Data of node? 87

1.insert node           2.inordered avl         3.preordered avl        4.postordered avl
5.height of avl         6.delete node           7.find min node         8.empty AVL
9.balanceFactor         0.exit

Enter the choice:2
inordered AVL-->  13  23  43  56  87
1.insert node           2.inordered avl         3.preordered avl        4.postordered avl
5.height of avl         6.delete node           7.find min node         8.empty AVL
9.balanceFactor         0.exit

Enter the choice:1
Enter the data to enter:55

The node has been inserted

1.insert node           2.inordered avl         3.preordered avl        4.postordered avl
5.height of avl         6.delete node           7.find min node         8.empty AVL
9.balanceFactor         0.exit

Enter the choice:3
preordered AVL-->  43  23  13  56  55  87
1.insert node           2.inordered avl         3.preordered avl        4.postordered avl
5.height of avl         6.delete node           7.find min node         8.empty AVL
9.balanceFactor         0.exit

Enter the choice:6
Enter the data to be deleted:13

The node has been deleted

1.insert node           2.inordered avl         3.preordered avl        4.postordered avl
5.height of avl         6.delete node           7.find min node         8.empty AVL
9.balanceFactor         0.exit

Enter the choice:4
postordered AVL-->  23  55  87  56  43
1.insert node           2.inordered avl         3.preordered avl        4.postordered avl
5.height of avl         6.delete node           7.find min node         8.empty AVL
9.balanceFactor         0.exit

Enter the choice:5
The height of AVL is 3
1.insert node           2.inordered avl         3.preordered avl        4.postordered avl
5.height of avl         6.delete node           7.find min node         8.empty AVL
9.balanceFactor         0.exit

Enter the choice:7
The min node is 23
1.insert node           2.inordered avl         3.preordered avl        4.postordered avl
5.height of avl         6.delete node           7.find min node         8.empty AVL
9.balanceFactor         0.exit

Enter the choice:9
The balance factor is -1
1.insert node           2.inordered avl         3.preordered avl        4.postordered avl
5.height of avl         6.delete node           7.find min node         8.empty AVL
9.balanceFactor         0.exit

Enter the choice:8
Released node:23 Released node:55 Released node:87 Released node:56 Released node:43 The tree is empty

1.insert node           2.inordered avl         3.preordered avl        4.postordered avl
5.height of avl         6.delete node           7.find min node         8.empty AVL
9.balanceFactor         0.exit

Enter the choice:2
inordered AVL-->
1.insert node           2.inordered avl         3.preordered avl        4.postordered avl
5.height of avl         6.delete node           7.find min node         8.empty AVL
9.balanceFactor         0.exit

Enter the choice:0
Terminating condition entered*/
		
                
                                                

                                                             
            
    
