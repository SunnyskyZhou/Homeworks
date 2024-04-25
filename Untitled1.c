#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

// ��������
void createList(int n) {
    Node *temp, *end;
    head = (Node *)malloc(sizeof(Node));
    end = head;

    for (int i = 0; i < n; i++) {
        temp = (Node *)malloc(sizeof(Node));
        printf("������ڵ�%d��ֵ: ", i + 1);
        scanf("%d", &temp->data);
        end->next = temp;
        end = temp;
    }
    end->next = NULL;
}

// ����ڵ㣨β�壩
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

// ���ҽڵ�
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

// ɾ���ڵ�
void deleteNode(int pos) {
    if (head == NULL) {
        printf("����Ϊ�գ��޷�ɾ���ڵ㡣\n");
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
        printf("λ����Ч���޷�ɾ���ڵ㡣\n");
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// ��ӡ����
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

    printf("����������ڵ������: ");
    scanf("%d", &n);
    createList(n);

    printf("ԭʼ����: ");
    printList();

    printf("������Ҫβ��Ľڵ��ֵ: ");
    scanf("%d", &value);
    insertAfter(value);

    printf("β��������: ");
    printList();

    printf("������Ҫ���ҵĽڵ��ֵ: ");
    scanf("%d", &key);
    Node *found = locate(key);
    if (found != NULL) {
        printf("�ҵ��˽ڵ㣬ֵΪ: %d\n", found->data);
    } else {
        printf("δ�ҵ��ڵ㡣\n");
    }

    printf("������Ҫɾ���Ľڵ��λ��: ");
    scanf("%d", &pos);
    deleteNode(pos);

    printf("ɾ���ڵ�������: ");
    printList();

    return 0;
}
