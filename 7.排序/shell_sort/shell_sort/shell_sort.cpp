/*
	ϣ������C++
*/
#include<iostream>
using namespace std;

/*
	ϣ������

	����˵����
		a--�����������
		n--����ĳ���
*/
void shellSort1(int* a, int n)
{
	int i, j, gap;
	// gapΪ������ÿ�μ�Ϊԭ����һ��
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		//��gap(0...gap-1)�飬��ÿһ�鶼ִ��ֱ�Ӳ�������
		for (i = 0; i < gap; i++)
		{
			for (j = i + gap; j < n; j += gap)
			{
				//���a[j]<a[j-gap]����Ѱ��a[j]λ�ã�������������ݵ�λ�ö�����
				if (a[j] < a[j - gap])
				{
					int tmp = a[j];		//������ǰֵa[j]��ֵ
					int k = j - gap;	//�����ǰ��һ��ֵ������

					//����ǰֵ��ǰ���ÿһ��ֵ���Ƚϣ�ѭ����ֹa[k]<=tmp
					while (k >= 0 && a[k]>tmp)		
					{
						a[k + gap] = a[k];			//��ֵ����ƶ�
						k -= gap;					//����ǰ��һ��ֵ
					}
					a[k + gap] = tmp;		//K�ĺ���һ��λ�ü�Ϊtmp����ȷλ��
				}
			}
		}
	}
}


/*
	��ϣ�������еĵ������������

	����˵����
		a--�����������
		n--�����ܵĳ���
		i--�����ʼλ��
		gap--��Ĳ���

*/
void groupSort(int* a, int n, int i, int gap)
{
	int j;
	for (j = i + gap; j < n; j += gap)
	{
		if (a[j] < a[j - gap])
		{
			int tmp = a[j];
			int k = j - gap;
			while (k >= 0 && a[k]>tmp)
			{
				a[k + gap] = a[k];
				k -= gap;
			}
			a[k + gap]=tmp;
		}
	}
}

/*
	ϣ������
		����˵����
		a--�����������
		n--����ĳ���
*/
void shellSort2(int* a, int n)
{
	int i, gap;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = 0; i < gap; i++)
			groupSort(a, n, i, gap);
	}
}

int  main()
{
	int i;
	int a[] = { 80,30,60,40,20,10,50,70 };
	int ilen = (sizeof(a) / sizeof(a[0]));

	cout << "before sort:";
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	//shellSort1(a, ilen);
	shellSort2(a, ilen);

	cout << "after sort:";
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}