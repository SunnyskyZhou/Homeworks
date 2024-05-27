#include<stdio.h>

int count = 0;//全局变量做计数器
void move(char Tower_1, char Tower_2)
{
	printf("将 %c 移动到 %c \n", Tower_1, Tower_2);
	count++;
}
void Hanoi(int n, char Tower_1, char Tower_2, char Tower_3)
{
	if (n == 1)
		//是一个的话就直接从Tower_1移动到Tower_3
		move(Tower_1, Tower_3);
	else
	{
		//不是一个的话先借助Tower_3将Tower_1上面的n-1个移动到Tower_2
		Hanoi(n - 1, Tower_1, Tower_3, Tower_2);
		//完成此过程后Tower_1上面还有最后一个
		move(Tower_1, Tower_3); //将Tower_1上面的最后一个移动到Tower_3
		//将Tower_2上面的n-1个通过Tower_1移动到Tower_3
		Hanoi(n - 1, Tower_2, Tower_1, Tower_3);
	}
}
int main()
{
	printf("请输入圆盘个数:\n");
	int n = 0;
	scanf("%d", &n);
	Hanoi(n, 'A', 'B', 'C');
	printf("一共进行了%d次", count);
	return 0;
}
