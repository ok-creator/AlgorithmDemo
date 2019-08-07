#pragma once
#include<iostream>
using namespace std;

template<typename T>
void selectionSort(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//Ѱ��[i,n)���������Сֵ
		int minIndex = i;		//��ʼ����СֵΪi
		for (int j = i + 1; j < n; j++)		//�ҵ�������Сֵ������
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);	//swap������std�����ռ��У��Ǳ�׼C++11����
	}
}