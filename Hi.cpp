#define maxsize 1024
#include <stdio.h>
#include <stdlib.h>

int data[maxsize];
int last = -1; // 初始化为-1，表示顺序表为空
int i,j;
int n,x;

// 插入函数
void insert() {
    int pos, value; //pos是溢出数字，value为返回值
    printf("请输入要插入的位置和要插入的数（用空格隔开）：\n");
    scanf("%d %d", &pos, &value);
    if (last >= maxsize - 1) {
        printf("顺序表已满，无法插入新元素。\n");
        return;
    }
    if (pos < 1 || pos > last + 1) {
        printf("插入位置无效！\n");
        return;
    }
    for (int j = last; j >= pos - 1; j--) {
        data[j + 1] = data[j];
    }
    data[pos - 1] = value; // 将要插入的数放到正确的位置
    last++; // 更新last的值
}

// 删除函数
void delete1(int index) {  //index是索引数
    if (index < 0 || index > last) {
        printf("无效的索引，无法删除元素。\n");
        return;
    }
    for (int i = index; i < last; i++) {
        data[i] = data[i + 1]; // 修正错误，正确地将后续元素向前移动
    }
    last--;
}

// 查找函数
int search(int n) {  //n为查找的数值
    for (int i = 0; i <= last; i++) {
        if (data[i] == n) {
            return i; // 返回元素的索引
        }
    }
    return -1; // 如果未找到元素，返回-1
}

int main() {
    int n, i, x;
    printf("这是网工2班周润德的顺序表\n");
    printf("请输入个数\n");
    scanf("%d", &n);
    printf("请输入表\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    last = n - 1; // 修正了赋值的位置，在输入完数据后更新last

    // 在插入之前，先让用户输入要插入的位置和值
    insert();

    // 输出插入后的顺序表
    printf("输出的顺序表如下\n");
    for (i = 0; i <= last; i++) {
        printf("%6d", data[i]);
    }
    printf("\n");

    // 查找和删除操作
    printf("请输入要删除的数字的位置\n");
    scanf("%d", &i);
    delete1(i - 1); // 位置减1是因为用户输入的位置是从1开始的，而数组索引是从0开始的

    // 输出删除后的顺序表
    printf("输出顺序表\n");
    for (i = 0; i <= last; i++) {
        printf("%6d", data[i]);
    }
    printf("\n");

    printf("请输入要查找的数字\n");
    scanf("%d", &x);
    int index = search(x);
    if (index != -1) {
        printf("找到数字%d，位置为%d\n", x, index + 1); // 位置+1是因为用户通常期望从1开始计数
    } else {
        printf("未找到数字%d\n", x);
    }

    return 0;
}
