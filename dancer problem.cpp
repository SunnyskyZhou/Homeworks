#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 1000    //�����пɴﵽ����󳤶�
#define OK  1
#define ERROR  0
#define OVERFLOW -2

typedef int  Status;

typedef struct{
	char name [20]; //����
	char sex; //�Ա�'F'��ʾŮ�ԣ�'M'��ʾ����
}Person;

typedef struct{
	Person *base; //����������Ԫ������ΪPerson
	int front; //ͷָ��
	int rear;  //βָ��
}SqQueue;

Status InitQueue (SqQueue *Q);  //����һ���ն���Q
Status EnQueue(SqQueue *Q, Person e);  //����Ԫ��eΪQ���µĶ�βԪ��
Status DeQueue(SqQueue *Q, Person *e);  //ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
Person GetHead(SqQueue Q);  //����Q�Ķ�ͷԪ�أ����Ķ�ͷָ��
Status QueueEmpty(SqQueue Q);  //�ж϶����Ƿ�Ϊ�գ�������򷵻�1
void DancePartner(Person dancer[],int num);  //�����������ƥ���㷨

int main()
{
	Person dancer[MAXSIZE];int i,num;
	printf("������������������");
	scanf("%d",&num);
	printf("��������������˵��������Ա�'F'��ʾŮ�ԣ�'M'��ʾ���ԣ���\n");
	for(i=0;i<num;i++)
	{
		printf("�������%d�������˵��������Ա��ÿո��������",i+1);
		scanf("%s %c",&dancer[i].name,&dancer[i].sex);
	}
	DancePartner(dancer,num);  //��ӡ������б���Բ����
	return 0;
}

Status InitQueue (SqQueue *Q)
{//����һ���ն���Q
	Q->base=(Person *)malloc(MAXSIZE*sizeof(Person));  //Ϊ���з���һ���������ΪMAXSIZE������ռ�
	if(!Q->base) exit(OVERFLOW);  //�洢����ʧ��
	Q->front=Q->rear=0;  //ͷָ���βָ����Ϊ�㡢����Ϊ��
	return OK;
}

Status EnQueue(SqQueue *Q, Person e)
{//����Ԫ��eΪQ���µĶ�βԪ��
	if ((Q->rear+1)%MAXSIZE==Q->front)  //βָ����ѭ�������ϼ�1�����ͷָ�룬������������
	return ERROR;
	Q->base[Q->rear]=e;  //��Ԫ�ز����β
	Q->rear=(Q->rear+1)%MAXSIZE;  //��βָ���1
	return OK;
}

Status DeQueue(SqQueue *Q, Person *e)
{//ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
	if(Q->front==Q->rear) return ERROR;  //��ʾ�ӿ�
	*e=Q->base[Q->front];  //�����ͷ��Ԫ��e
	Q->front=(Q->front+1)%MAXSIZE;  //��ͷָ���1
	return OK;
}

Person GetHead(SqQueue Q)
{
    //����Q�Ķ�ͷԪ�أ����޸Ķ�ͷָ��
	if(Q.front!=Q.rear) //���зǿ�
	return Q.base[Q.front]; //���ض�ͷԪ�ص�ֵ����ͷָ�벻��
}

Status QueueEmpty(SqQueue Q)
{//�ж϶����Ƿ�Ϊ��
	if(Q.front==Q.rear) return OK;//���пգ�����1
	else return ERROR;//���в��գ�����0
}

void DancePartner(Person dancer[],int num)
{//�ṹ����dancer�д���������Ů��num�������������
	SqQueue Mdancers,Fdancers;
	Person p;
	int i;
	InitQueue(&Mdancers); //�ж��г�ʼ��
	InitQueue(&Fdancers); //Ů���г�ʼ��
	for(i=0;i<num;i++) //���ν������߸������Ա����
	{
		p=dancer[i];
		if (p.sex=='F') EnQueue(&Fdancers,p); //����Ů��
		else EnQueue(&Mdancers,p); //�����ж�
	}
	printf("The dancing partners are:\n");
	while(!QueueEmpty(Fdancers)&&!QueueEmpty(Mdancers))
	{//���������Ů��������
		DeQueue(&Fdancers,&p); //Ů����
		printf("%s ",p.name);; //�������Ů������
		DeQueue(&Mdancers,&p); //�г���
		printf("%s\n",p.name); //�������������
	}
	if (!QueueEmpty(Fdancers)) //���Ů���зǿգ����Ů��ͷ������
	{
		p=GetHead(Fdancers); //ȡŮ��ͷ
		printf("The first woman to get a partner is: %s\n", p.name);
	}
	else if (!QueueEmpty (Mdancers)) //����ж��зǿգ�����ж�ͷ������
	{
		p=GetHead(Mdancers); //ȡ�ж�ͷ
		printf("The first man to get a partner is: %s\n", p.name);
	}
}
