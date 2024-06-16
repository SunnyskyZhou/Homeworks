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
 
/*2. �����������*/
 
HTNode * CreatHuffmanTree(int n)
{
	//����շ�����HT
	int m,s1=0,s2=0,i=0; //��n����㹹���Ĺ�����������m=2n-1����㣬s1��s2Ϊ�����HT�е����
	HTNode *HT;
	if(n<=1) return 0;
	m=2*n-1; //m����ʼֵ
	HT=(HTNode*)malloc((m+1) * sizeof(HTNode)); //0�ŵ�Ԫδ�ã�����һ����Ҫ��̬����m+1������2*n������Ԫ��HT[m]��ʾ�����
 
	for(int i=1;i<=m;i++) //��1~m�ŵ�Ԫ�е�˫�ס����ӣ��Һ��ӵ��±궼��ʼ��Ϊ0
	   {
	    	HT[i].parent=0;
			HT[i].lchild=0;
			HT[i].rchild=0;
}
	printf("������Ҷ�ӽ���Ȩֵ��\n");
	for(i=1;i<=n;++i)        	
		scanf("%d",&HT[i].weight); //����ǰn����Ԫ��Ҷ�ӽ���Ȩֵ
	/*�D�D�D�D�D�D�D�D��ʼ���������������濪ʼ�����շ������D�D�D�D�D�D�D�D�D*/
	for(i=n+1;i<=m;++i)
		{  	//ͨ��n-1�ε�ѡ��ɾ�����ϲ��������շ�����
			Select(HT,i-1,&s1,&s2); //��HT[k](1��k��i-1)��ѡ��������˫����Ϊ0��Ȩֵ��С�Ľ��,������������HT�е����s1��s2
			HT[s1].parent=i;
			HT[s2].parent=i;    //�õ��½��i����ɭ����ɾ��s1��s2����s1��s2��˫������0��Ϊi	
			HT[i].lchild=s1;
			HT[i].rchild=s1;
			HT[i].rchild=s2;//s1,s2�ֱ���Ϊi�����Һ���
			HT[i].weight=HT[s1].weight + HT[s2] .weight;//i ��ȨֵΪ���Һ���Ȩֵ֮��
	}
	return HT;	
	free(HT);									
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
