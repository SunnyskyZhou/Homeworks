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
    if(p == head) { // ���p��ͷ�ڵ㣬����Ҫ���⴦��
        head = s;
    } else {
        // �����ҵ�p��ǰһ���ڵ㣬���޸���nextָ��ָ���½ڵ�
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

    // ���λ����Ч����ɾ���ڵ�
    if (p->next != NULL && j == pos) {
        q = p->next;
        p->next = q->next;
        free(q);
        printf("λ�� %d �Ľڵ��ѳɹ�ɾ��\n", pos);
    } else {
        printf("��Ч��λ�ã�ɾ��ʧ��\n");
    }
}

int main()
{
    printf("���������2023103020122������\n");
    printf("��������������ݣ����ԡ�-1����Ϊ������\n");
  head=CREATLISTR1();
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
if(p!=NULL)	printf("%6d\n",p->data);
else  printf("û�ҵ�\n");

printf("�����������Ҫ�������\n");
scanf("%d",&x);
INSERTAFTER();
p=head->next;
while(p!=NULL)
{
	printf("%10d",p->data);
     p=p->next;
}
 printf("\n");


printf("��������Ҫ���ҵ���\n");
scanf("%d",&key);
p=LOCATE();
if(p!=NULL)	printf("%10d\n",p->data);
   else  printf("û�ҵ�\n");

printf("��������Ҫβ�����\n");
scanf("%d",&x);
INSERTAFTER();
p=head->next;
while(p!=NULL)
{
	printf("%5d",p->data);
     p=p->next;
}
 printf("\n");

printf("������Ҫͷ�����\n");
scanf("%d",&x);
p = LOCATE(); // �����ҵ�Ҫ����λ�õ�ǰһ���ڵ�
if(p != NULL) {
    INSERTBEFORE(); // ����ҵ��ˣ��Ͳ���
} else {
    printf("�Ҳ�������λ�ã�����ʧ��\n");
}
p = head->next;
while(p != NULL) {
    printf("%10d",p->data);
    p = p->next;
}
printf("\n");
 printf("\n");

  printf("������Ҫɾ���ڵ��λ�ã�\n");
    scanf("%d", &pos);

    DELETE();
    p = head->next;
    while (p != NULL) {
        printf("%10d", p->data);
        p = p->next;
    }
    printf("\n");

}
