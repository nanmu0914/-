#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
//--------���Ա�Ķ�̬����˳��洢�ṹ-----
#define LIST_INIT_SIZE 100//�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT	10//���Ա�Ĵ洢�ռ�ķ�����
#define TRUE 1
#define FLASE 0
#define OK	1
#define ERROR 0
#define LIFEASIBLE -1
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;
/*
		����Ĵ洢����
*/
typedef struct {
	ElemType	*elem;	//�洢�ռ�Ļ�ַ
	int		length;	//�洢�ĳ���
	int		listsize;	//��ǰ�Ĵ洢��������
}SqList;
//����һ���յ����Ա�

/*
Status Initlist_Sq(SqList L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));//����洢�ռ�
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
*/
Status InitList_Sq(SqList* L)
{
	(*L).elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!(*L).elem)
		exit(OVERFLOW);
	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
	return OK;
}
//����һ�����Ա�
/*
void CreateList_Sq(SqList L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));//����洢�ռ�
	if (!L.elem) exit(OVERFLOW);

}

*/
Status CreateList_Sq(SqList L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));//����洢�ռ�
	if (L.elem) exit(OVERFLOW);
	//printf("������˳���ĳ���:\n");
	//scanf_s("%d", &L.length);
	L.listsize = LIST_INIT_SIZE;
	int i;
	printf("���������Ա��Ԫ��:\n");
	for (i = 0;i < L.length;i++) {
		scanf_s("%d",&L.elem[i]);
	}
	for (int i = 0;i < L.length;i++) {
		printf("%d ", L.elem[i]);
	}
	return OK;
}

//���Ա�Ĳ���
/*
Status LinstInsert_Sq(SqList L,int i,ElemType e) {
	//1  �ж�i��ֵ�Ƿ�Ϸ�
	//n-i+1
	if (i<1 || i>L.length+1) return ERROR;
	//�洢�ռ��Ƿ�����
	if (L.length >= L.listsize) {
		ElemType *newbase;
		newbase = (ElemType *)realloc(L.elem,
			(L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;//��ǰ�ķ�����������
	}
	int *q, *p;
	q = &(L.elem[i - 1]);
	for (p = &(L.elem[L.length - 1]);q <= p;--p) {
		*(p + 1) = *p;
		}
	*q = e;
	++L.length;
	return OK;
	}
*/
Status ListInsert_Sq(SqList* L, int i, ElemType e)
{
	if (i<1 || i>(*L).length + 1)
		return ERROR;  //iֵ���Ϸ�
	if ((*L).length >= (*L).listsize) {  //��ǰ�洢�ռ����������ӷ���
		ElemType* newbase;
		newbase = (ElemType*)realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
			exit(OVERFLOW);
		(*L).elem = newbase;  //�»�ַ
		(*L).listsize += LISTINCREMENT;  //���Ӵ洢����
	}//if
	ElemType* q, * p;
	q = &((*L).elem[i - 1]); //qΪ����λ��
	for (p = &((*L).elem[(*L).length - 1]); p >= q; --p)
		*(p + 1) = *p;  //����λ�ü�֮���Ԫ������
	*q = e;  //����e
	++(*L).length;  //����1
	return OK;
}
//���Ա��ɾ��
Status ListDelete_Sq(SqList L, int i, ElemType e) {
	if ((i<1 || i>L.length))return ERROR;//i��ֵ�Ƿ�Ϸ�}
	int *p, *q;
	p = &(L.elem[i - 1]);
	e = *p;
	q = L.elem + L.length - 1;//��
	for (++p;p <= q;++p) {
		*(p - 1) = *q;
	}
	--L.length;
		return OK;
}

int LocateElem_Sq(SqList L, ElemType e,Status(* compare)(ElemType ,ElemType)) {
	//compare�ȽϺ���
	//��˳�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
	int i = 1;
	ElemType *p;
	p = L.elem;
	while (i <= L.length && !(* compare)(*p++, e))++i;//compare ���=Ϊ1 ����Ϊ0
	if (i <= L.length) return i;
	else return 0;
}
//˳���ĺϲ�
//ȥ���ظ���  �������������ݱ��Ǵ���ֵ����ֵ��
void MergeList_Sq(SqList LA,SqList LB,SqList *LC) {
	//LA LB��֪  �ϲ���ΪLC��
	ElemType* pa, * pb, * pc, *pa_last, *pb_last;
	int out;
	//int pa_last, pb_last;
	pa = LA.elem;
	pb = LB.elem;
	(*LC).listsize = (*LC).length = LA.length + LB.length;
	pc = (ElemType*)malloc((*LC).listsize * sizeof(ElemType));
	(*LC).elem = pc;
	if (!(*LC).elem)exit(OVERFLOW);//�洢����ʧ��
	pa_last = LA.elem + LA.length - 1;//LA���һ��Ԫ��
	pb_last = LB.elem + LB.length - 1;//LB���һ��Ԫ��
	/*
	if (LA.length >= LB.length) {
		while (pa <= pa_last) {
			*pc++ = *pa++;
		}
		pa = LA.elem;
		while (pa <= pa_last && pb <= pb_last) {
			if (*pa == *pb)continue;
			else {
				*pc++ = *pb++;
			}
		}
	}
	else {
		while (pb <= pb_last) {
			*pc++ = *pb++;
		}
		pb = LB.elem;
		while (pa <= pa_last && pb <= pb_last) {
			if (*pa == *pb)
			{
				*pa++;
				continue;
			}
			else {
				*pc++ = *pa++;
			}
		}
	}
	*/
	if (LA.length >= LB.length) {
		while (pa <= pa_last) {
			*pc++ = *pa++;
		}
		pa = LA.elem;
		for(;pb<= pb_last;pb++){
			for (out = 0, pa = LA.elem;pa <= pa_last;pa++) {
				if (*pb == *pa) { out = 1;break; };
			}
			if (out == 1)continue;
			else {*pc++ = *pb++;}
		}
	}
	else {
     		while (pb <= pb_last) {
			*pc++ = *pb++;
		}
		for (;pa <= pa_last;pa++) {
			for (out = 0, pb = LB.elem;pb <= pb_last;pb++) {
				if (*pa == *pb) { out = 1;break; }
			}
			if (out == 1)continue;
			else *pc++ = *pa;
		}
	}
	/*
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb) *pc++ = *pa++;
		else *pc++ = *pb++;
	}
	*/
	//while (pa <= pa_last)*pc++ = *pa++;
	//while (pb <= pb_last) *pc++ = *pb++;
}

//����
void Print_Sq(SqList L) {
	for (int i = 0;i < L.length;i++) {
		printf("%d ",L.elem[i]);
	}
	printf("\n");
}

void displayTable(SqList L) {
	int i;
	for (i = 0; i < L.length; i++) {
 		printf("%d ", L.elem[i]);
	}
	printf("\n");
}

