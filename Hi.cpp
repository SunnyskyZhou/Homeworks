#define maxsize 1024
#include <stdio.h>
#include <stdlib.h>

int data[maxsize];
int last = -1; // ��ʼ��Ϊ-1����ʾ˳���Ϊ��
int i,j;
int n,x;

// ���뺯��
void insert() {
    int pos, value; //pos��������֣�valueΪ����ֵ
    printf("������Ҫ�����λ�ú�Ҫ����������ÿո��������\n");
    scanf("%d %d", &pos, &value);
    if (last >= maxsize - 1) {
        printf("˳����������޷�������Ԫ�ء�\n");
        return;
    }
    if (pos < 1 || pos > last + 1) {
        printf("����λ����Ч��\n");
        return;
    }
    for (int j = last; j >= pos - 1; j--) {
        data[j + 1] = data[j];
    }
    data[pos - 1] = value; // ��Ҫ��������ŵ���ȷ��λ��
    last++; // ����last��ֵ
}

// ɾ������
void delete1(int index) {  //index��������
    if (index < 0 || index > last) {
        printf("��Ч���������޷�ɾ��Ԫ�ء�\n");
        return;
    }
    for (int i = index; i < last; i++) {
        data[i] = data[i + 1]; // ����������ȷ�ؽ�����Ԫ����ǰ�ƶ�
    }
    last--;
}

// ���Һ���
int search(int n) {  //nΪ���ҵ���ֵ
    for (int i = 0; i <= last; i++) {
        if (data[i] == n) {
            return i; // ����Ԫ�ص�����
        }
    }
    return -1; // ���δ�ҵ�Ԫ�أ�����-1
}

int main() {
    int n, i, x;
    printf("��������2������µ�˳���\n");
    printf("���������\n");
    scanf("%d", &n);
    printf("�������\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    last = n - 1; // �����˸�ֵ��λ�ã������������ݺ����last

    // �ڲ���֮ǰ�������û�����Ҫ�����λ�ú�ֵ
    insert();

    // ���������˳���
    printf("�����˳�������\n");
    for (i = 0; i <= last; i++) {
        printf("%6d", data[i]);
    }
    printf("\n");

    // ���Һ�ɾ������
    printf("������Ҫɾ�������ֵ�λ��\n");
    scanf("%d", &i);
    delete1(i - 1); // λ�ü�1����Ϊ�û������λ���Ǵ�1��ʼ�ģ������������Ǵ�0��ʼ��

    // ���ɾ�����˳���
    printf("���˳���\n");
    for (i = 0; i <= last; i++) {
        printf("%6d", data[i]);
    }
    printf("\n");

    printf("������Ҫ���ҵ�����\n");
    scanf("%d", &x);
    int index = search(x);
    if (index != -1) {
        printf("�ҵ�����%d��λ��Ϊ%d\n", x, index + 1); // λ��+1����Ϊ�û�ͨ��������1��ʼ����
    } else {
        printf("δ�ҵ�����%d\n", x);
    }

    return 0;
}
