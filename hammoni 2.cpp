#include<iostream>
using namespace std;
//��ŵ������
int sum;//���ó�����  �ܹ���Ҫ�ߵĲ���sum
void hanoi(int n,char x,char y,char z){
	void move(char X,int N,char Y);
	if(n==1)
	move(x,1,z);//ֱ�Ӵ�x�Ƶ�z��
	else
	{
		hanoi(n-1,x,z,y);// �������n-1��Բ�̣���A����C�ƶ���B
		move(x,n,z);// �ѵ�n��Բ�̴�A�ƶ���C
		hanoi(n-1,y,x,z);// ����n-1���Բ�̣���B����A�ƶ���C
	}
}
void move(char X,int N,char Y){
	cout<<N<<"��"<<X<<"->"<<Y<<endl;
	sum++;//ÿ�ƶ�һ�θ�sum��һ
}
int main(){
	int n=0;
	char A,B,C;
	cout<<"��Ϊn��ֵ��";
	cin>>n;
	hanoi(n,'A','B','C');//ʵ��������n ����A,B,C
	cout<<"�ܹ���Ҫ�ߵĲ���Ϊ��"<<sum<<endl;
	return 0;
}
