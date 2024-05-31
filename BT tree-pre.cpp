#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char data;
    struct node *Lchild, *Rchild;
}bitree;

bitree *Q[100];
bitree *root;
char ch;

bitree *CREATREE()
{
    int front, rear;
    bitree *s;
    bitree *root;
    root=NULL;
    front=1;
    rear=0;
    ch=getchar();
    while(ch!='#')
    {
        s=NULL;
        if(ch!='@')
        {
            s=(struct node*)malloc(sizeof(bitree));
            s->Lchild=NULL;
            s->Rchild=NULL;
        }
        rear++;
        Q[rear]=s;

        if(rear==1) root=s;
        else
        {
            if(s && Q[front])
                if(rear%2==0) Q[front]->Lchild=s;
            else
            Q[front]->Rchild=s;
            if(rear%2==1) front++;
        }
    ch=getchar();
    }
return root;
}


