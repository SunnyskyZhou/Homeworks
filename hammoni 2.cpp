#include<iostream>
using namespace std;
//汉诺塔问题
int sum;//设置常变量  总共需要走的步数sum
void hanoi(int n,char x,char y,char z){
	void move(char X,int N,char Y);
	if(n==1)
	move(x,1,z);//直接从x移到z上
	else
	{
		hanoi(n-1,x,z,y);// 把上面的n-1个圆盘，从A经过C移动到B
		move(x,n,z);// 把第n个圆盘从A移动到C
		hanoi(n-1,y,x,z);// 把那n-1块个圆盘，从B经过A移动到C
	}
}
void move(char X,int N,char Y){
	cout<<N<<"从"<<X<<"->"<<Y<<endl;
	sum++;//每移动一次给sum加一
}
int main(){
	int n=0;
	char A,B,C;
	cout<<"请为n赋值：";
	cin>>n;
	hanoi(n,'A','B','C');//实参盘子数n 柱子A,B,C
	cout<<"总共需要走的步数为："<<sum<<endl;
	return 0;
}
