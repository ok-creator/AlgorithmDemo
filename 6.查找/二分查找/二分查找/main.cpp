#include<iostream>
using namespace std;
/*
	˳�����
	˳�����--�Ż�
	�۰����/��ֵ����
	쳲���������---���ڻƽ�ָ�
*/
int F[10] = { 0,1,1,2,3,5,8,13,21,34 };
//˳�����---ÿ��ѭ���������ж�
int Sequential_Search(int *a, int n, int key)
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return 0;
}

//˳�����---ÿ��ѭ����һ���ж�
int Sequential_Search(int *a, int n, int key)
{
	int i;
	a[0] = key;		//����a[0]Ϊ�ؼ���ֵ�����ǳ�֮Ϊ�ڱ�
	i = n;			//ѭ��������β����ʼ
	while (a[i] != key)
	{
		i--;
	}
	return i;		//����0��˵������ʧ��

}

//�۰����
int Binary_Search(int *a, int n, int key)
{
	int low, high, mid;
	low = 1;		//��������±�Ϊ��¼��λ
	high = n;		//��������±�Ϊ��¼ĩλ
	while (low <= high)
	{
		mid = (low + high) / 2;		//�۰�
		//mid=low+(high-low)*(key-a[low])/(a[high]-a[low]);		//��ֵ��
		if (key < a[mid])
			high = mid - 1;
		else if (key > a[mid])
			low = mid + 1;
		else
			return mid;
	}
	return 0;
}


//쳲���������
int Fibonacci_Search(int *a, int n, int key)
{
	int low, high, mid, i, k;
	low = 1;		//���λΪ��λ
	high = n;		//���λΪĩλ
	k = 0;
	while (n > F[k] - 1)	//����nλ�����е�λ��
		k++;
	for (i = n; i < F[k] - 1; i++)		//����������ֵ��ȫ
		a[i] = a[n];					// n=<i<F[k]-1����ֵȫ����Ϊa[n]

	while (low <= high)
	{
		mid = low + F[k - 1] - 1;		//F[k-1]-1=<n
		if (key < a[mid])
		{
			high = mid - 1;				//����±�������ָ��±�mid-1��
			k = k - 1;					//�������۰�
		}
		else if (key>a[mid])
		{
			low = mid + 1;
			k = k - 2;					//�������۰�
		}
		else
		{
			if (mid <= n)
				return mid;
			else						//����n����ֵ������ֵΪn����ֵ
				return n;
		}
	}
	return 0;
}




//�����۰����
int main()
{
	int a[11] = { 0,3,12,24,37,45,53,61,78,90,98 };
	int key = 0;
	cout << "����Ҫ���ҵ����֣�" << endl;
	cin >> key;
	int tmp = Binary_Search(a, 10, key);
	if (0 == tmp)
	{
		cout<<"���Ҳ������������"
	}
	else
	{
		cout << "��ѯ���ֵ�����Ϊ��" << tmp << endl;
	}
	return 0;
}