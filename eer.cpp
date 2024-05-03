#define maxsize 1024
#include <stdio.h>
#include <stdlib.h>

int data[maxsize];
int n = 0; // 当前顺序表大小

// 插入操作
void insert(int pos, int value) {
    if (pos < 1 || pos > n + 1 || n == maxsize) {
        printf("Insert position is invalid or list is full.\n");
        return;
    }
    for (int i = n; i >= pos; i--) {
        data[i] = data[i - 1];
    }
    data[pos - 1] = value;
    n++;
}

// 删除操作
void delete1(int pos) {
    if (pos < 1 || pos > n) {
        printf("Delete position is invalid.\n");
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) {
        data[i] = data[i + 1];
    }
    n--;
}

// 查找操作
int find(int value) {
    for (int i = 0; i < n; i++) {
        if (data[i] == value) {
            return i + 1; // 返回位置从1开始计数
        }
    }
    return -1; // 如果没有找到，返回-1
}

int main() {
    // 示例使用
    insert(1, 10);
    insert(2, 20);
    insert(3, 30);
    printf("List: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    int pos = find(20);
    if (pos != -1) {
        printf("Value 20 found at position: %d\n", pos);
    } else {
        printf("Value 20 not found.\n");
    }

    delete1(2);
    printf("List after deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
