/*
	Ͱ�����кܶ�����ԣ�
	1.����Ԫ�ر��붼��������
	2.����Ԫ�ز���̫�����Ҫ�������Ϊ����ô���Ǿ���Ҫ����һ��1001��С������

	ʱ�临�Ӷȣ�
	N������	��Χ��0��M-1
	ʱ�临�Ӷ�ΪO��M+N)          
*/
#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

#define MAX 100

void bucketsort(int A[], int size, int max_num)		//size��ʾ����Ĵ�С��max_num��ʾ������������
{
	int count[MAX];			//����һ��������
	memset(count, 0, sizeof(count));			//��countָ����ָ������򶼳�ʼ��Ϊ0
	for (int i = 0; i < size; i++)
	{
		++count[A[i]];			//ͳ��ԭ��������ÿ�����ĸ�����ԭ��ÿ�������ֵ��Ϊ��������±�
	}
	for (int j = 0; j <= max_num; j++)
	{
		while (count[j] > 0)
		{
			cout << j<<" ";
			count[j]--;
		}
	}
	cout << endl;
}

int main()
{
	int a[] = { 2,5,6,12,4,8,8,6,7,8,8,10,7,6,0,1 };
	bucketsort(a, sizeof(a) / sizeof(a[0]), 12);

	system("pause");
	return 0;
}