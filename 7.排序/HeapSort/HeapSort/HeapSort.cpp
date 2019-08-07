/*
	������C++
*/

#include<iostream>
using namespace std;


/*
	(���)�ѵ����µ����㷨

	���ã��� ���µ��ڵ� �����ܵ������·�

	ע������ʵ�ֵĶ��У���N���ڵ����������ֵ�ǣ�2N+1�����Һ��ӵ�����ʱ��2N+2��
		���� ��NΪ�����±�����ֵ���������е�1������Ӧ��NΪ0

	����˵����
		a		--�����������
		start	--���µ��ڵ����ʼλ��(һ��Ϊ0����ʾ�ӵ�1����ʼ��
		end		--��ֹ��Χ(һ��Ϊ���������һ��Ԫ�ص�������

*/
void maxHeapDown(int* a, int start, int end)
{
	int c = start;			//��ǰ(current)�ڵ��λ��
	int l = 2 * c + 1;		//��(left�����ӵ�λ��
	int tmp = a[c];			//��ǰ(current)�ڵ�Ĵ�С
	for (; l <= end; c = l, l = 2 * l + 1)
	{
		//"l"�����ӣ�"l+1"���Һ���
		if (l < end && a[l] < a[l + 1])
			l++;			//���Һ�����ѡ��ϴ��ߣ���m_heap[l+1]
		if (tmp >= a[l])
			break;			//��������
		else				//����ֵ
		{
			a[c] = a[l];	//�����Һ����е����ֵ�������ڵ�
			a[l] = tmp;		
		}
	}
}

/*
	������(��С����

	�õ��Ǵ󶥶ѣ����Ѷ�Ԫ�����
	���ź���ĶѶ�Ԫ��������Ԫ�ؽ������õ���С�����˳��

	����˵����
		a--�����������
		n--����ĳ���
*/
void heapSortAsc(int* a, int n)
{
	int i, tmp;
	//�ӣ�n/2-1)---> 0��α���������֮�󣬵õ�������ʵ������һ��(���)�����
	for (i = n / 2 - 1; i >= 0; i--)
		maxHeapDown(a, i, n - 1);
	//�����һ��Ԫ�ؿ�ʼ�����н��е�����������С�����ķ�Χֱ����һ��Ԫ��
	for (i = n - 1; i > 0; i--)
	{
		//����a[0]��a[i].������a[i]��a[0...i]������
		tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		//����a[0...i-1]��ʹ��a[0...i-1]��Ȼ��һ������
		//������֤a[i-1]��a[0....i-1]�е����ֵ
		maxHeapDown(a, 0, i - 1);
	}
}

/*
	���ϴ��ֵ�����ѵ�����
	
	��maxHeapDown����ϸ΢�Ĳ��
*/
void minHeapDown(int* a, int start, int end)
{
	int c = start;
	int l = 2 * c + 1;
	int tmp = a[c];

	for (; l <= end; c = 1, l = 2 * l + 1)
	{
		if(l<end && a[l]>a[l+1])
			l++;
		if (tmp <= a[l])
			break;
		else
		{
			a[c] = a[l];
			a[l] = tmp;
		}
	}
}

//�����򣨴Ӵ�С��
void heapSortDesc(int* a, int n)
{
	int i, tmp;
	for (i = n / 2 - 1; i >= 0; i--)
		minHeapDown(a, i, n - 1);
	for (i = n - 1; i > 0; i--)
	{
		tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;

		minHeapDown(a, 0, i - 1);
	}
}

int main()
{
	int i;
	int a[] = { 20,30,90,40,70,110,60,10,100,50,80 };
	int ilen = (sizeof(a) / sizeof(a[0]));

	cout << "before sort:";
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	//heapSortAsc(a, ilen);
	heapSortDesc(a, ilen);

	cout << "after sort:";
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}