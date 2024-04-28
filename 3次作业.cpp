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

void INSERTBEFORE() {
    linklist *s;
    s = (struct node *)malloc(sizeof(linklist));
    s->data = x;
    s->next = p;
    if(p == head) { // 如果p是头节点，则需要特殊处理
        head = s;
    } else {
        // 否则找到p的前一个节点，并修改其next指针指向新节点
        linklist *q = head;
        while(q->next != p) {
            q = q->next;
        }
        q->next = s;
    }
}

void DELETE()
{
    linklist *q;
    int j = 1;
    p = head;

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
{
    printf("这是周润德2023103020122的链表\n");
    printf("请输入链表的数据，并以“-1”作为结束符\n");
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

printf("请输入后面需要插入的数\n");
scanf("%d",&x);
INSERTAFTER();
p=head->next;
while(p!=NULL)
{
	printf("%10d",p->data);
     p=p->next;
}
 printf("\n");


printf("请输入需要查找的数\n");
scanf("%d",&key);
p=LOCATE();
if(p!=NULL)	printf("%10d\n",p->data);
   else  printf("没找到\n");

printf("请输入需要尾插的数\n");
scanf("%d",&x);
INSERTAFTER();
p=head->next;
while(p!=NULL)
{
	printf("%5d",p->data);
     p=p->next;
}
 printf("\n");

printf("请输入要头插的数\n");
scanf("%d",&x);
p = LOCATE(); // 首先找到要插入位置的前一个节点
if(p != NULL) {
    INSERTBEFORE(); // 如果找到了，就插入
} else {
    printf("找不到插入位置，插入失败\n");
}
p = head->next;
while(p != NULL) {
    printf("%10d",p->data);
    p = p->next;
}
printf("\n");
 printf("\n");

  printf("请输入要删除节点的位置：\n");
    scanf("%d", &pos);

    DELETE();
    p = head->next;
    while (p != NULL) {
        printf("%10d", p->data);
        p = p->next;
    }
    printf("\n");

}
