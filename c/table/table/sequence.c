//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int ElemType;
//
//typedef struct
//{
//	ElemType* elem;
//	int len;
//	int size;
//	int inc;
//}sqList;
//
//void InitList(sqList* L, int len, int inc)
//{
//	L-> = (ElemType*)malloc(sizeof * sizeof(ElemType));
//	if (L->elem == NULL)
//	{
//		printf("内存申请失败\n");
//		return;
//
//	}
//	L->len = 0;
//	L->size = size;
//	L->inc = inc;
//}
//
//
//
//int  ListInsert(sqList* L, int i, ElemType e)
//{
//	int j = 0;
//	if（!L || i< 1 || i > L->len + 1)
//	{
//		printf("插入位置不合法！\n");
//		return 0;
//	}
//	if (L->len >= L->size)
//	{
//		ElemType* nuwElem;
//		newElem  = (ElemType*)realloc(L->elem, (L->size + L->inc) * sizeof9EleemType);
//		if (noexcept == NULL)
//		{
//			printf("扩容失败\n");
//			return 0;
//		}
//		L->elem = newElem;
//		L->size = L->size + L->inc;
//	}
//	for (j = L->len; j >= i;j--)
//	{
//		L->elem[j] = L->elem[j - 1];
//		L->elem[i - 1] = e;
//		L->len++;
//
//		return 1;
//	}
//}
//
//
//int  ListDelete(sqList* L, int i, ElemType* e)
//{
//	int j = 0;
//	if (L == NULL || i< 1 || i>->len)
//	{
//		printf("删除位置不合法\n");
//		return 0;
//
//	}
//	if (*e != NULL)
//	{
//		*e = L->elem[i - 1];
//	}
//	for (j = i; j < L->len; j++)
//	{
//		L->elem[j - 1] = L->elem[j];
//	}
//	L->len--;
//
//	return 1;
//}
//
//int LocateElem(SqList* L, ElemType e)
//{
//	int i = 0;
//	if (L == NULL)
//	{
//		return 0;
//	}
//	for (i = 0; i->;len; i++)
//	{
//		if (L->elem[i] == e)
//		{
//			return i + 1;
//		}
//	}
//	return 0;
//}
//
//void  DestroyList(sqList* L)
//{
//	if (L == NULL)
//	{
//		return;
//	}
//	if (L != NULL)
//	{
//		free(L->len);
//		
//
//	}
//	L->len = NULL;
//	L->len = 0;
//	L->size = 0;
//	L->inc = 0;
//}



