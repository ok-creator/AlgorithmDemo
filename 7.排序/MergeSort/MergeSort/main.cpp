#include<iostream>
#include<algorithm>
#include"SortTestHelper.h"
#include"MergeSort.h"

using namespace std;

//�Ե����ϵĹ鲢����û���õ������ȡԪ�ز����������������������
template<typename T>
void mergeSortBU(T arr[], int n)
{
	for (int sz = 1; sz <= n; sz += sz)
	{
		for (int i = 0; i +sz< n; i += 2 * sz)
		{
			//��arr[i...i + sz - 1]��arr[i + sz...i + sz + sz - 1]���й鲢
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1,n-1));
		}
	}
}

int main()
{
	

	system("pause");
	return 0;
}