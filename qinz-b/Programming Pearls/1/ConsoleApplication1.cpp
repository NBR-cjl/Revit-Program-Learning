// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Windows.h>
#include <algorithm>
#include <set>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define  N 10000000
int a[1 + N / BITSPERWORD];//a[x] ��һ��32λ�ֽ�
int b[N];

using namespace std;
void sets(int i)//��a[x]ĳһλ��ֵ1
{
	//i >> SHIFT ��i ���� SHIFT λ����i/32����(1<<(i & MASK)) �뵱�� 000010 �� 111111 ���룬Ȼ��1���� 2λ��
	a[i >> SHIFT] |= (1 << (i & MASK));
}

void clr(int i)//��a[x]ĳһλ����
{
	a[i >> SHIFT] &= ~(1 << (i & MASK));
}

int test(int i)//�ж�a[x], ĳ���ֽ��Ƿ�Ϊ1
{
	return a[i >> SHIFT] & (1 << (i & MASK));
}

int intcomp(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}

void test1()
{
	for (int i = 0; i < N; i++)
		b[i] = i;
	qsort(b, N, sizeof(int), intcomp);
}

void test2(int nCount)
{
	set<int> s;
	for (int i = 0; i < nCount; i++)
	{
		s.insert(i);
	}
}
void test3(int nCount)//λ��
{
	int i;
	for (i = 0; i < nCount; i++)
		clr(i);
	//while (scanf("%d", &i) != EOF)
	for (i = 0; i < nCount; i++)
	{
		sets(i);
		//int j = i >> SHIFT;
		/*int j = i & MASK;*/
		//printf("%d  ", j);
	}

	for (i = 0; i < nCount; i++)
		if (test(i))
		{
			//printf("%d  ", i);
		}
}
int main()
{
	DWORD t1, t2;
	t1 = GetTickCount();
	test1();
	t2 = GetTickCount();
	printf("Use Time:%f\n", (t2 - t1)*1.0 / 1000);//7

	t1 = GetTickCount();
	test3(N);
	t2 = GetTickCount();
	printf("Use Time:%f\n", (t2 - t1)*1.0 / 1000);//7

	t1 = GetTickCount();
	test2(1000000);
	t2 = GetTickCount();
	printf("Use Time:%f\n", (t2 - t1)*1.0 / 1000);//0.733000
    return 0;
}

