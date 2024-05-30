#include<stdio.h>

void print(char x, char y) {                              //用于打印盘子的移动过程

	printf("%c->%c\n", x, y);                               //显示盘子移动过程：如A->B
}
void move(int n, char start, char temp, char end) {       //n为需要移动的盘子数量，
	                                                      //start、temp、end分别对应起始杆、中转杆、目标杆
	if (n == 1) {
		print(start, end);                                //若需要移动的盘子上没有别的盘子，则直接移动
	}
	else {
		move(n - 1, start, end, temp);                    //若需要移动的盘子上有别的盘子，则先将其上面的n-1个盘子移走，
		                                                  //上面n-1个盘子需要先停留在temp杆上，所以以end杆为中转杆，
		                                                  //temp杆为目标杆，进行转移
		print(start, end);                                //此时start杆上只有一个盘子，可以直接移动到end杆上
		move(n - 1, temp, start, end);                    //最后将之前停留在temp杆上的n-1个盘子移动到end杆上,则以temp杆
		                                                  //为起始杆，start杆为中转杆，end杆为目标杆
	}

}
int main() {
	printf("请输入汉诺塔的层数：");
	int x;
	scanf("%d", &x);
	move(x,'A', 'B', 'C');                                //传入起始杆A，中转杆B，目标杆C
	return 0;
}
