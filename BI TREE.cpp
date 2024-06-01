#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{char data;
 struct node *lchild,*rchild;
}bitree;
bitree  *Q[100];
bitree *root;
char ch;
bitree *t;
bitree *CREATREE()
{
int front,rear;
bitree  *s;
bitree *root;
root=NULL;
front=1;
rear=0;
ch=getchar();
while(ch!='#')
{ s=NULL;
  if(ch!='@')
{
	s=( struct node*)malloc(sizeof(bitree));
	s->data=ch;
	s->lchild=NULL;
	s->rchild=NULL;
}
rear++;
Q[rear]=s;
if(rear==1) root=s;

else
{
if( s && Q[front])
if(rear%2==0) Q[front]->lchild=s;
else
Q[front]->rchild=s;
if(rear%2==1)  front++;
}
ch=getchar();
}
return root;
}


/*
INORDER(t)
bitree *t;
{
	if(t)
	{
		INORDER(t->lchild);
		printf("\t%c\n",t->data);
        INORDER(t->rchild);
	}
}
*/

PREORDER(bitree *t)
{

	if(t)
	{
		printf("\t%c\n",t->data);
		PREORDER(t->lchild);
		PREORDER(t->rchild);
		}
	}


/*
POSTORDER(t)
		bitree *t
	{
		if(t)
		{
POSTORDER(t->lchild);
POSTORDER(t->rchild);
printf("\t%c\n",t->data);
		}
	}

*/



int main()
{
root=CREATREE();
PREORDER(root);

}
