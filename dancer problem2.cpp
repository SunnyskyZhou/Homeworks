#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // �����������Ϊ100

// ���нṹ��
typedef struct {
    int data[MAX_SIZE];
    int front; // ��ͷ
    int rear;  // ��β
} Queue;

// ��ʼ������
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}
// �ж϶����Ƿ�Ϊ��
int isEmpty(Queue *q) {
    return q->front == (q->rear + 1) % MAX_SIZE;
}

// ...���������뱣�ֲ��䣩

// �ж϶����Ƿ�����
int isFull(Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// ���
int enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return 0; // ����0��ʾ���ʧ��
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    return 1; // ����1��ʾ��ӳɹ�
}

// ����
int dequeue(Queue *q, int *value) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return 0; // ����0��ʾ����ʧ��
    }
    *value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return 1; // ����1��ʾ���ӳɹ�
}

// ģ��������
void dancePartnerPairing(Queue *men, Queue *women) {
    int man, woman;
    while (dequeue(men, &man) && dequeue(women, &woman)) {
        printf("Man %d and Woman %d are dancing.\n", man, woman);
    }

    // ����ʣ����ˣ�����У�
    while (!isEmpty(men)) {
        dequeue(men, &man);
        printf("Man %d is waiting for the next dance.\n", man);
    }

    while (!isEmpty(women)) {
        dequeue(women, &woman);
        printf("Woman %d is waiting for the next dance.\n", woman);
    }
}

int main() {
    Queue men, women;
    initQueue(&men);
    initQueue(&women);

    // ������ʿ��Ůʿ���Ŷ�˳������
    // ����Ը���ʵ������ı���Щ���ֻ����Ӹ�����ˣ���Ҫȷ��������MAX_SIZE
    for (int i = 1; i <= 5 && !isFull(&men); i++) {
        enqueue(&men, i);
    }
    for (int i = 1; i <= 7 && !isFull(&women); i++) {
        enqueue(&women, i);
    }

    // ��ʼ���
    dancePartnerPairing(&men, &women);

    return 0;
}
