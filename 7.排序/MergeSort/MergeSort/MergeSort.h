#pragma once
#include<iostream>
#include<algorithm>
#include"insertionSort.h"


using namespace std;

//��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
template<typename T>
void __merge(T arr[], int l, int mid, int r)
{
	T *aux = new T[r - l + 1];
	for (int i = l; i <= r; i++)
	{
		aux[i - l] = arr[i];
	}
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
	{
		if (i > mid)		//�ж������ĺϷ���
		{
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r)
		{
			arr[k] = aux[i - l];
			i++;
		}

		else if (aux[i - l] < aux[j - l])
		{
			arr[k] = aux[i - l];
			i++;
		}
		else
		{
			arr[k] = aux[j - l];
			j++;
		}
	}
	delete[]aux;
}

//�ݹ�ʹ�ù鲢���򣬶�arr[l...r]�ķ�Χ��������
template<typename T>
void __mergeSort(T arr[], int l, int r)
{
	//if (l >= r)
	//	return;
	if (r - l <= 15)			//�Ż���2.�����ݽ���ʱ���������򣬲��ò������򣬼���ʱ��
	{
		insertionsort(arr, l, r);
		return;
	}


	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);

	//mid֮ǰ�Ѿ�����mid+1֮
	//��Ҳ������ģ����mid����ֵ
	//С��mid+1����ֵ������������
	if (arr[mid]>arr[mid + 1])	//�Ż���1.�����н������������£����𵽺ܴ������
		__merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n)
{
	__mergeSort(arr, 0, n - 1);
}

/*

	int main()
	{
	int n = 10000;
	cout << "Test for Random Array,size= " << n << ",random range [0," << n << "]" << endl;
	int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

	delete[]arr1;
	delete[]arr2;

	int swapTimes = 1000;
	cout << "Test for Random Nearly Ordered Array,size= " << n << ",random range [0," << n << "]" << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

	delete[]arr1;
	delete[]arr2;


	cout << endl;

	system("pause");
	return 0;	
	}

*/
