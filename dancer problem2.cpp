#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // 假设最大人数为100

// 队列结构体
typedef struct {
    int data[MAX_SIZE];
    int front; // 队头
    int rear;  // 队尾
} Queue;

// 初始化队列
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}
// 判断队列是否为空
int isEmpty(Queue *q) {
    return q->front == (q->rear + 1) % MAX_SIZE;
}

// ...（其他代码保持不变）

// 判断队列是否已满
int isFull(Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// 入队
int enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return 0; // 返回0表示入队失败
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    return 1; // 返回1表示入队成功
}

// 出队
int dequeue(Queue *q, int *value) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return 0; // 返回0表示出队失败
    }
    *value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return 1; // 返回1表示出队成功
}

// 模拟舞伴配对
void dancePartnerPairing(Queue *men, Queue *women) {
    int man, woman;
    while (dequeue(men, &man) && dequeue(women, &woman)) {
        printf("Man %d and Woman %d are dancing.\n", man, woman);
    }

    // 处理剩余的人（如果有）
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

    // 假设男士和女士的排队顺序如下
    // 你可以根据实际情况改变这些数字或增加更多的人，但要确保不超过MAX_SIZE
    for (int i = 1; i <= 5 && !isFull(&men); i++) {
        enqueue(&men, i);
    }
    for (int i = 1; i <= 7 && !isFull(&women); i++) {
        enqueue(&women, i);
    }

    // 开始配对
    dancePartnerPairing(&men, &women);

    return 0;
}
