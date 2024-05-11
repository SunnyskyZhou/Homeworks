#include<stdio.h>
#include<stdlib.h>
typedef struct node
{ int data;
  struct node *next;
}linklist;
linklist *head,*s,*p,*r;
int h,key,i;
int x;
int pos;

linklist *CREATLISTR1()
{
	linklist *head,*s,*r;
	head=(struct node *)malloc(sizeof(linklist));
	r=head;
    scanf("%d",&h);
	while(h!=-1)
	{
		s=(struct node *)malloc(sizeof(linklist));
		s->data=h;
        r->next=s;
        r=s;
       scanf("%d",&h);
	}
	if(r!=NULL)r->next=NULL;
	return head;
}

linklist *GET()
{  int j;
   linklist *p;
   p=head;j=0;
   while((p->next!=NULL)&&(j<i))
   {p=p->next;
    j++;
   }
if(i==j)return p;
else return NULL;
}
linklist *LOCATE()
{linklist *p;
   p=head->next;
   while(p!=NULL)
   if(p->data!=key)
      p=p->next;
   else break;
return p;
}


void INSERTAFTER()
{linklist *s;
 s=(struct node *)malloc(sizeof(linklist));
 s->data=x;
 s->next=p->next;
 p->next=s;
}

void DELETE()
{
    linklist *q;
    int j = 1;
    p = head;

    // 寻找要删除的节点的前一个节点
    while (p->next != NULL && j < pos) {
        p = p->next;
        j++;
    }

    // 如果位置有效，则删除节点
    if (p->next != NULL && j == pos) {
        q = p->next;
        p->next = q->next;
        free(q);
        printf("位置 %d 的节点已成功删除\n", pos);
    } else {
        printf("无效的位置，删除失败\n");
    }
}

int main()
{ printf("请输入链表的数据\n");
  head=CREATLISTR1();
  p=head->next;
while(p!=NULL)
{
	printf("%10d",p->data);
     p=p->next;
}
 printf("\n");


 printf("请输入查找位置i\n");
scanf("%d",&i);
p=GET();
if(p!=NULL)	printf("%6d\n",p->data);
else  printf("没找到\n");
printf("请输入插入的数\n");
scanf("%d",&x);
INSERTAFTER();
p=head->next;
while(p!=NULL)
{
	printf("%10d",p->data);
     p=p->next;
}
 printf("\n");

printf("请输入查找的数\n");
scanf("%d",&key);
p=LOCATE();
if(p!=NULL)	printf("%10d\n",p->data);
   else  printf("没找到\n");

printf("请输入插入的数\n");
scanf("%d",&x);
INSERTAFTER();
p=head->next;
while(p!=NULL)
{
	printf("%5d",p->data);
     p=p->next;
}
 printf("\n");

  printf("请输入要删除节点的位置：\n");
    scanf("%d", &pos);
    DELETE();

    // 打印删除后的链表
    p = head->next;
    while (p != NULL) {
        printf("%10d", p->data);
        p = p->next;
    }
    printf("\n");

}
