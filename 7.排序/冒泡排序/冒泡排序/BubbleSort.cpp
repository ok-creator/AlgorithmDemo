/*	
	2019-3-27
	ð������
		����һ�ֽϼ򵥵������㷨�����������
		�ɴ�Ҫ��������У�ÿ�α���ʱ��������
		��ǰ�������εıȽ������������Ĵ�С��
		���ǰ�߱Ⱥ��ߴ��򽻻����ǵ�λ�á�
		������һ�α���֮������Ԫ�ؾ�������
		��ĩβ�� ������ͬ�ķ����ٴα���ʱ���ڶ�
		���Ԫ�ؾͱ����������Ԫ��֮ǰ���ظ��˲�
		����ֱ���������ж�����Ϊֹ��
*/
#include<iostream>
using namespace std;

/*
	����˵����
		a--�����������
		n--����ĳ���
*/
void bubbleSort1(int* a, int n)
{
	int tmp, i, j;
	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			//��z[0...i]���������ݷ���ĩβ
			if (a[j] > a[j + 1])
			{
				//����a[j]��a[j+1]
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

/*
	ð������(�Ľ���)
*/
void  bubbleSort2(int* a, int n)
{
	int i, j, tmp;
	int flag;	//���

	for (i = n - 1; i > 0; i--)
	{
		flag = 0;		//��ʼ��Ϊ0
		for (j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;

				flag = 1;	//���������������Ǽ�Ϊ1
			}
		}

		if (flag == 0)
			break;			//��û������������˵������������
	}
}

int main()
{
	int i;
	int a[] = { 20,40,30,10,60,50 };
	int ilen = (sizeof(a) / sizeof(a[0]));

	cout << "before sort:";
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	//bubbleSort1(a, ilen);
	bubbleSort2(a, ilen);

	cout << "after sort:";
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}