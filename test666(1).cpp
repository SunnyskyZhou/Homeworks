#include<stdio.h>
#include<stdlib.h>
typedef struct node
{ int data;
  struct node *next;
}linklist;
linklist *head,*s,*p,*r;
int h,h1,key,i;

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

linklist *CREATLISTR2() //ͷ��
{
	linklist *head1,*s1,*r1;
	head=(struct node *)malloc(sizeof(linklist));
	r1=head;
    scanf("%d",&h1);
	while(h1!=-1)
	{
		s1=(struct node *)malloc(sizeof(linklist));
		s1->data=h1;
        s1->next=head->next;
        //ȱ���м�ڵ�ָ��a1
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

int  main()
{
  printf("���������2023103020122�ĵ�����\n");
  printf("��������������֣������ԡ�-1��Ϊ��β\n");
  head=CREATLISTR2();
  p=head->next;
while(p!=NULL)
{
	printf("%10d",p->data);
     p=p->next;
}
 printf("\n");
 printf("���������λ��i\n");
scanf("%d",&i);
p=GET();
if(p!=NULL)	 printf("%6d\n",p->data);
else  printf("û�ҵ�\n");

printf("��������ҵ���\n");
scanf("%d",&key);
p=LOCATE();

if(p!=NULL)	printf("%10d\n",p->data);
   else  printf("û�ҵ�\n");

}
