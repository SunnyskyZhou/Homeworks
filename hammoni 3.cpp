#include<stdio.h>

void print(char x, char y) {                              //���ڴ�ӡ���ӵ��ƶ�����

	printf("%c->%c\n", x, y);                               //��ʾ�����ƶ����̣���A->B
}
void move(int n, char start, char temp, char end) {       //nΪ��Ҫ�ƶ�������������
	                                                      //start��temp��end�ֱ��Ӧ��ʼ�ˡ���ת�ˡ�Ŀ���
	if (n == 1) {
		print(start, end);                                //����Ҫ�ƶ���������û�б�����ӣ���ֱ���ƶ�
	}
	else {
		move(n - 1, start, end, temp);                    //����Ҫ�ƶ����������б�����ӣ����Ƚ��������n-1���������ߣ�
		                                                  //����n-1��������Ҫ��ͣ����temp���ϣ�������end��Ϊ��ת�ˣ�
		                                                  //temp��ΪĿ��ˣ�����ת��
		print(start, end);                                //��ʱstart����ֻ��һ�����ӣ�����ֱ���ƶ���end����
		move(n - 1, temp, start, end);                    //���֮ǰͣ����temp���ϵ�n-1�������ƶ���end����,����temp��
		                                                  //Ϊ��ʼ�ˣ�start��Ϊ��ת�ˣ�end��ΪĿ���
	}

}
int main() {
	printf("�����뺺ŵ���Ĳ�����");
	int x;
	scanf("%d", &x);
	move(x,'A', 'B', 'C');                                //������ʼ��A����ת��B��Ŀ���C
	return 0;
}
