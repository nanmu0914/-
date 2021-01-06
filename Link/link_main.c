/*
#include <stdio.h>
#include <stdlib.h>
#define Size 5
typedef struct Table {
    int* head;
    int length;
    int size;
}table;
table initTable() {
    table t;
    t.head = (int*)malloc(Size * sizeof(int));
    if (!t.head)
    {
        printf("��ʼ��ʧ��");
        exit(0);
    }
    t.length = 0;
    t.size = Size;
    return t;
}
table addTable(table t, int elem, int add)
{
    int i;
    if (add > t.length + 1 || add < 1) {
        printf("����λ��������");
        return t;
    }
    if (t.length >= t.size) {
        t.head = (int*)realloc(t.head, (t.size + 1) * sizeof(int));
        if (!t.head) {
            printf("�洢����ʧ��");
        }
        t.size += 1;
    }
    for (i = t.length - 1; i >= add - 1; i--) {
        t.head[i + 1] = t.head[i];
    }
    t.head[add - 1] = elem;
    t.length++;
    return t;
}
table delTable(table t, int add) {
    int i;
    if (add > t.length || add < 1) {
        printf("��ɾ��Ԫ�ص�λ������");
        exit(0);
    }
    for (i = add; i < t.length; i++) {
        t.head[i - 1] = t.head[i];
    }
    t.length--;
    return t;
}
int selectTable(table t, int elem) {
    int i;
    for (i = 0; i < t.length; i++) {
        if (t.head[i] == elem) {
            return i + 1;
        }
    }
    return -1;
}
table amendTable(table t, int elem, int newElem) {
    int add = selectTable(t, elem);
    t.head[add - 1] = newElem;
    return t;
}
void displayTable(table t) {
    int i;
    for (i = 0; i < t.length; i++) {
        printf("%d ", t.head[i]);
    }
    printf("\n");
}
int main() {
    int i, add;
    table t1 = initTable();
    for (i = 1; i <= Size; i++) {
        t1.head[i - 1] = i;
        t1.length++;
    }
    printf("ԭ˳���\n");
    displayTable(t1);

    printf("ɾ��Ԫ��1:\n");
    t1 = delTable(t1, 1);
    displayTable(t1);

    printf("�ڵ�2��λ�ò���Ԫ��5:\n");
    t1 = addTable(t1, 5, 2);
    displayTable(t1);

    printf("����Ԫ��3��λ��:\n");
    add = selectTable(t1, 3);
    printf("%d\n", add);

    printf("��Ԫ��3��Ϊ6:\n");
    t1 = amendTable(t1, 3, 6);
    displayTable(t1);
    return 0;
}
*/


#include "List_head.h"
void main() {
	SqList LA,LB,LC;
   // LA.length = 5;
    InitList_Sq(&LA);
    InitList_Sq(&LB);
    InitList_Sq(&LC);
   int count,number;
   printf("������LA��4����:\n");
   for (count = 1;count <= 4;count++) {
       scanf_s("%d",&number);
       ListInsert_Sq(&LA, count, number);
   }
   displayTable(LA);
   printf("������LB��7����:\n");
   for (count = 1;count <= 7;count++) {\
        scanf_s("%d",&number);
   ListInsert_Sq(&LB, count, number);
   }
    //CreateList_Sq(&LA);
   displayTable(LB);
   MergeList_Sq(LA,LB,&LC);
   displayTable(LC);
	//Print_Sq(LA);
}


