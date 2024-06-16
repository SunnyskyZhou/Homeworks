#include <stdio.h>
#include <stdlib.h>
#include<string.h>
 
 
/**********1. 哈弗曼树的存储表示***********/
typedef struct 
{
	int weight;//结点的权值
	int parent,lchild,rchild;//结点的双亲、左右孩子下标
}HTNode,*HuffmanTree;
/* 在HT中选择两个其双亲域为0且权值最小的结点,并返回它们在HT中的序号s1和s2*/
 
void Select(HuffmanTree HT,int len,int *s1,int *s2)
{
	int i,temp=0,max1=0x3f3f3f3f,max2=0x3f3f3f3f;//先赋予最大值
	for(i=1;i<=len;i++)
	{
		if(HT[i].weight<max1&&HT[i].parent==0)
		{
			
			max1=HT[i].weight;
			*s1=i;
		}
	}
 
	temp=HT[*s1].weight;//将权值使用temp先暂时存放起来，然后先赋予最大值，防止s1被重复选择，找到第二个较小权值的结点后再恢复原来的值
	HT[*s1].weight=0x3f3f3f3f;//赋予最大值
	for(i=1;i<=len;i++)
	{
		if(HT[i].weight<max2&&HT[i].parent==0)
		{
			max2=HT[i].weight;
			*s2=i;
		}
	}
	HT[*s1].weight=temp;//恢复原来的值
}
 
/*2. 构造哈弗曼树*/
 
HTNode * CreatHuffmanTree(int n)
{
	//构造赫夫曼树HT
	int m,s1=0,s2=0,i=0; //由n个结点构建的哈夫曼树共有m=2n-1个结点，s1和s2为结点在HT中的序号
	HTNode *HT;
	if(n<=1) return 0;
	m=2*n-1; //m赋初始值
	HT=(HTNode*)malloc((m+1) * sizeof(HTNode)); //0号单元未用，所以一共需要动态分配m+1（或者2*n）个单元，HT[m]表示根结点
 
	for(int i=1;i<=m;i++) //将1~m号单元中的双亲、左孩子，右孩子的下标都初始化为0
	   {
	    	HT[i].parent=0;
			HT[i].lchild=0;
			HT[i].rchild=0;
}
	printf("请输入叶子结点的权值：\n");
	for(i=1;i<=n;++i)        	
		scanf("%d",&HT[i].weight); //输入前n个单元中叶子结点的权值
	/*――――――――初始化工作结束，下面开始创建赫夫曼树―――――――――*/
	for(i=n+1;i<=m;++i)
		{  	//通过n-1次的选择、删除、合并来创建赫夫曼树
			Select(HT,i-1,&s1,&s2); //在HT[k](1≤k≤i-1)中选择两个其双亲域为0且权值最小的结点,并返回它们在HT中的序号s1和s2
			HT[s1].parent=i;
			HT[s2].parent=i;    //得到新结点i，从森林中删除s1，s2，将s1和s2的双亲域由0改为i	
			HT[i].lchild=s1;
			HT[i].rchild=s1;
			HT[i].rchild=s2;//s1,s2分别作为i的左右孩子
			HT[i].weight=HT[s1].weight + HT[s2] .weight;//i 的权值为左右孩子权值之和
	}
	return HT;	
	free(HT);									
	}							
 
 
 
 
char * *  CreatHuffmanCode(HuffmanTree HT,int n)
{
	//从叶子到根逆向求每个字符的赫夫曼编码，存储在编码表HC中
	int i,start,c,f;
	char * *HC;
	char * cd;
	                 				//分配n个字符编码的头指针矢量
	HC=(char * *)malloc((n+1)*sizeof(char *));
	         						//分配临时存放编码的动态数组空间
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';                            		//编码结束符
	for(i=1;i<=n;++i)
	{                      					//逐个字符求赫夫曼编码
		start=n-1;                          	//start开始时指向最后，即编码结束符位置
		c=i;
		f=HT[i].parent;                		//f指向结点c的双亲结点
		while(f!=0)
		{                          		//从叶子结点开始向上回溯，直到根结点
			                         		//回溯一次start向前指一个位置
		--start;	
		if(HT[f].lchild==c)	cd[start]='0';       //如果结点c是f的左孩子，则生成代码0
		else cd[start]='1';	               //否则结点c是f的右孩子，则生成代码1
			c=f;
			f=HT[f].parent;			            		//继续向上回溯
		}                                  		//求出第i个字符的编码
		HC[i]=(char *)malloc((n-start)*sizeof(char));       // 为第i 个字符编码分配空间
		strcpy(HC[i], &cd[start]);      //将求得的编码从临时空间cd复制到HC的当前行中
	}
	free (cd);
	return HC;                            		//释放临时空间
}
 
 
 
 
 
int main()
{
  	HuffmanTree HT;
  	char **HC;
	int n,i;
	printf("请输入叶子结点的个数：\n");	
	scanf("%d",&n);
	HT=CreatHuffmanTree(n);  // 调用 CreatHuffmanTree()函数，实参为n ,构建哈夫曼树
	printf("哈夫曼树建立完毕！\n");
	printf("每个结点的权值为：");
	for(i=1;i<=2*n-1;i++)
		printf("%d ",HT[i].weight);//输出每个结点的权值 HT[i].weight
	printf("\n");
	HC=CreatHuffmanCode(HT,n);
		for(i=1;i<=n;i++)
		{
		printf("权值为：");
	    printf("%d ",HT[i].weight);
		printf("的编码为：");
		printf("%s",HC[i]);
		printf("\n");
		}
	    printf("\n");
	
	return 0;
}
