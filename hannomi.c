#include<stdio.h>

int count = 0;//ȫ�ֱ�����������
void move(char Tower_1, char Tower_2)
{
	printf("�� %c �ƶ��� %c \n", Tower_1, Tower_2);
	count++;
}
void Hanoi(int n, char Tower_1, char Tower_2, char Tower_3)
{
	if (n == 1)
		//��һ���Ļ���ֱ�Ӵ�Tower_1�ƶ���Tower_3
		move(Tower_1, Tower_3);
	else
	{
		//����һ���Ļ��Ƚ���Tower_3��Tower_1�����n-1���ƶ���Tower_2
		Hanoi(n - 1, Tower_1, Tower_3, Tower_2);
		//��ɴ˹��̺�Tower_1���滹�����һ��
		move(Tower_1, Tower_3); //��Tower_1��������һ���ƶ���Tower_3
		//��Tower_2�����n-1��ͨ��Tower_1�ƶ���Tower_3
		Hanoi(n - 1, Tower_2, Tower_1, Tower_3);
	}
}
int main()
{
	printf("������Բ�̸���:\n");
	int n = 0;
	scanf("%d", &n);
	Hanoi(n, 'A', 'B', 'C');
	printf("һ��������%d��", count);
	return 0;
}
