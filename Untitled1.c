#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

// 创建链表
void createList(int n) {
    Node *temp, *end;
    head = (Node *)malloc(sizeof(Node));
    end = head;

    for (int i = 0; i < n; i++) {
        temp = (Node *)malloc(sizeof(Node));
        printf("请输入节点%d的值: ", i + 1);
        scanf("%d", &temp->data);
        end->next = temp;
        end = temp;
    }
    end->next = NULL;
}

// 插入节点（尾插）
void insertAfter(int value) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
}

// 查找节点
Node *locate(int key) {
    Node *current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 删除节点
void deleteNode(int pos) {
    if (head == NULL) {
        printf("链表为空，无法删除节点。\n");
        return;
    }

    Node *current = head;
    Node *prev = NULL;
    int count = 1;

    while (current != NULL && count < pos) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("位置无效，无法删除节点。\n");
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// 打印链表
void printList() {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n, value, key, pos;

    printf("请输入链表节点的数量: ");
    scanf("%d", &n);
    createList(n);

    printf("原始链表: ");
    printList();

    printf("请输入要尾插的节点的值: ");
    scanf("%d", &value);
    insertAfter(value);

    printf("尾插后的链表: ");
    printList();

    printf("请输入要查找的节点的值: ");
    scanf("%d", &key);
    Node *found = locate(key);
    if (found != NULL) {
        printf("找到了节点，值为: %d\n", found->data);
    } else {
        printf("未找到节点。\n");
    }

    printf("请输入要删除的节点的位置: ");
    scanf("%d", &pos);
    deleteNode(pos);

    printf("删除节点后的链表: ");
    printList();

    return 0;
}
