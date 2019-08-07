#pragma once

#include<iostream>
#include<iomanip>
#include<ctime>
#include<cassert>
#include<algorithm>
#include<string>
using namespace std;

namespace SortTestHelper
{
	//������n��Ԫ�ص�������飬ÿ��Ԫ�ص������ΧΪ[rangeL��rangeR]
	int* generateRandomArray(int n,int rangeL,int rangeR)
	{
		assert(rangeL <= rangeR);

		int *arr = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++)		//��������������ɷ�Χ
		{
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}

	//����һ��������������� 
	int *generateNearlyOrderedArray(int n, int swapTimes)
	{
		int *arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			arr[i];
		}
		srand(time(NULL));
		for (int i = 0; i < swapTimes; i++)
		{
			int posx = rand() % n;
			int posy = rand() % n;
			swap(arr[posx], arr[posy]);
		}

		return arr;
	}

	template<typename T>
	void printArray(T arr[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	template<typename T>
	bool isSorted(T arr[], int n)
	{
		for (int i = 0; i < n - 1; i++)
			if (arr[i]>arr[i + 1])
				return false;

		return true;
	}

	template<typename T>
	void testSort(const string &sortName,void(*sort)(T[], int),T arr[],int n)	//����ָ��
	{
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		cout << sortName << " : " << setiosflags(ios::fixed) << setprecision(5) << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
		
		assert(isSorted(arr, n));
		return;
	}

	int* copyIntArray(int a[], int n)
	{
		int* arr = new int[n];
		copy(a, a + n, arr);
		return arr;
	}
}