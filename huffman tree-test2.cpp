#include <stdio.h>
#include <stdlib.h>
#include<string.h>
 
 
/**********1. ���������Ĵ洢��ʾ***********/
typedef struct 
{
	int weight;//����Ȩֵ
	int parent,lchild,rchild;//����˫�ס����Һ����±�
}HTNode,*HuffmanTree;
/* ��HT��ѡ��������˫����Ϊ0��Ȩֵ��С�Ľ��,������������HT�е����s1��s2*/
 
void Select(HuffmanTree HT,int len,int *s1,int *s2)
{
	int i,temp=0,max1=0x3f3f3f3f,max2=0x3f3f3f3f;//�ȸ������ֵ
	for(i=1;i<=len;i++)
	{
		if(HT[i].weight<max1&&HT[i].parent==0)
		{
			
			max1=HT[i].weight;
			*s1=i;
		}
	}
 
	temp=HT[*s1].weight;//��Ȩֵʹ��temp����ʱ���������Ȼ���ȸ������ֵ����ֹs1���ظ�ѡ���ҵ��ڶ�����СȨֵ�Ľ����ٻָ�ԭ����ֵ
	HT[*s1].weight=0x3f3f3f3f;//�������ֵ
	for(i=1;i<=len;i++)
	{
		if(HT[i].weight<max2&&HT[i].parent==0)
		{
			max2=HT[i].weight;
			*s2=i;
		}
	}
	HT[*s1].weight=temp;//�ָ�ԭ����ֵ
}

 
 
 
 
char * *  CreatHuffmanCode(HuffmanTree HT,int n)
{
	//��Ҷ�ӵ���������ÿ���ַ��ĺշ������룬�洢�ڱ����HC��
	int i,start,c,f;
	char * *HC;
	char * cd;
	                 				//����n���ַ������ͷָ��ʸ��
	HC=(char * *)malloc((n+1)*sizeof(char *));
	         						//������ʱ��ű���Ķ�̬����ռ�
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';                            		//���������
	for(i=1;i<=n;++i)
	{                      					//����ַ���շ�������
		start=n-1;                          	//start��ʼʱָ����󣬼����������λ��
		c=i;
		f=HT[i].parent;                		//fָ����c��˫�׽��
		while(f!=0)
		{                          		//��Ҷ�ӽ�㿪ʼ���ϻ��ݣ�ֱ�������
			                         		//����һ��start��ǰָһ��λ��
		--start;	
		if(HT[f].lchild==c)	cd[start]='0';       //������c��f�����ӣ������ɴ���0
		else cd[start]='1';	               //������c��f���Һ��ӣ������ɴ���1
			c=f;
			f=HT[f].parent;			            		//�������ϻ���
		}                                  		//�����i���ַ��ı���
		HC[i]=(char *)malloc((n-start)*sizeof(char));       // Ϊ��i ���ַ��������ռ�
		strcpy(HC[i], &cd[start]);      //����õı������ʱ�ռ�cd���Ƶ�HC�ĵ�ǰ����
	}
	free (cd);
	return HC;                            		//�ͷ���ʱ�ռ�
}
 
 
 
 
 
int main()
{
  	HuffmanTree HT;
  	char **HC;
	int n,i;
	printf("������Ҷ�ӽ��ĸ�����\n");	
	scanf("%d",&n);
	HT=CreatHuffmanTree(n);  // ���� CreatHuffmanTree()������ʵ��Ϊn ,������������
	printf("��������������ϣ�\n");
	printf("ÿ������ȨֵΪ��");
	for(i=1;i<=2*n-1;i++)
		printf("%d ",HT[i].weight);//���ÿ������Ȩֵ HT[i].weight
	printf("\n");
	HC=CreatHuffmanCode(HT,n);
		for(i=1;i<=n;i++)
		{
		printf("ȨֵΪ��");
	    printf("%d ",HT[i].weight);
		printf("�ı���Ϊ��");
		printf("%s",HC[i]);
		printf("\n");
		}
	    printf("\n");
	
	return 0;
}
