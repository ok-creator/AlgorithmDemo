#include<algorithm>
#include<iostream>
#include"SortTestHelper.h"
#include"SelectionSort.h"
using namespace std;

template <typename T>
void insertionSort(T arr[], int n)
{
	for (int i = 1; i < n; i++)		//�����ǵ�0��Ԫ�أ�������Ϊ���ź�
	{
		//Ѱ��Ԫ��arr[i]���ʵĲ���λ��
		/*for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;
		}*/

		T e = arr[i];							//����ǰԪ�ر���
		int j;									//����Ԫ��eӦ�ò����λ��
		for (j = i; j > 0 && arr[j-1] > e; j--)	//ѭ��������j��ֵ����Ӧ�ò����λ��
			arr[j] = arr[j - 1];
		arr[j] = e;

		//for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
		//	swap(arr[j], arr[j - 1]);
	}
}

int main()
{
	int n = 10000;
	int *arr = SortTestHelper::generateNearlyOrderedArray(n, 10);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);


	delete[]arr;
	delete[]arr2;
	system("pause");
	return 0;
}