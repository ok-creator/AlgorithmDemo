#pragma once



template <typename T>
void insertionSort(T arr[], int n)
{
	for (int i = 1; i < n; i++)		//�����ǵ�0��Ԫ�أ�������Ϊ���ź�
	{
		T e = arr[i];							//����ǰԪ�ر���
		int j;									//����Ԫ��eӦ�ò����λ��
		for (j = i; j > 0 && arr[j - 1] > e; j--)	//ѭ��������j��ֵ����Ӧ�ò����λ��
			arr[j] = arr[j - 1];
		arr[j] = e;
	}
}

template <typename T>
void insertionSort(T arr[], int l, int r)
{
	for (int i = l + 1; i <= r; i++)
	{
		T e = arr[i];
		int j;
		for (j = i; j > l&&arr[j - 1] > e; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
	return;
}