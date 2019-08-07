#include<iostream>
#include<cstdio>
#include<string>
using namespace std;



/*
	��������---��Ȩ·��������̵���


*/

#define N 10		//�������ַ��ĸ�����������Ҷ�ӽڵ��������
#define M (2*N-1)	//�����ܵĽ����Ŀ

class HTNode		//���н��Ľṹ
{
public:
	unsigned int weight;
	unsigned int parent, lchild, rchild;
};

class HTCode		//���������Ľṹ
{
public:
	char data;		//��������ַ�
	int weight;		//�ַ���Ȩֵ
	char code[N];	//�ַ��ı���
};

void Init(HTCode hc[], int *n)
{
	//��ʼ��������������ַ��ĸ���n���Ӽ�������n���ַ���n��Ȩֵ
	cout << "���������n��";
	cin >> *n;

	cout << "������n���ַ���";
	for (int i = 1; i <= *n; i++)
	{
		cin >> hc[i].data;
	}

	cout << "������n��Ȩֵ��";
	for (int i = 1; i <= *n; i++)
	{
		cin >> hc[i].weight;
	}
}

void Select(HTNode ht[], int k, int *s1, int *s2)
{
	//ht[1...k]��ѡ��parentΪ0������weight��С��������㣬�������ָ�����s1��s2ָʾ
	int i;
	for (i = 1; i <= k&&ht[i].parent != 0; i++)
	{
		; ;
	}
	*s1 = i;		//������һ��ѭ��ʱ�ҵ���һ�� ht[i].parent=0
	for (i = 1; i <= k; i++)
	{
		if (ht[i].parent == 0 && ht[i].weight < ht[*s1].weight)
			*s1 = i;			//ht[*s1].weight��Ȩֵ��С
	}
	for (i = 1; i <= k; i++)
	{
		if (ht[i].parent == 0 && i != *s1)
			break;
	}
	*s2 = i;		//������һ��ѭ��ʱ�ҵ���һ�� ht[i].parent=0
	for (i = 1; i <= k; i++)
	{
		if (ht[i].parent == 0 && i != *s1&&ht[i].weight < ht[*s2].weight)
			*s2 = i;		//ht[*s2].weight��Ȩֵ��С
	}
}

void HuffmanCoding(HTNode ht[],HTCode hc[],int n)
{
	//����Huffman��ht�������n���ַ��ı���
	char cd[N];
	int i, m, c, f, s1, s2, start;
	m = 2 * n - 1;					//�ܵĽ����Ŀ
	for (i = 1; i <= m; i++)		//�������н��
	{
		if (i <= n)
			ht[i].weight = hc[i].weight;	//��Ҷ�ӽڵ㶼���и�ֵ
		else
			ht[i].weight = 0;				//��Ҷ�ӽڵ��ʼ����¾���ֵΪ0
		ht[i].parent = ht[i].lchild = ht[i].rchild = 0;		//�����������ֵΪ0
	}
	for (i = n + 1; i <= m; i++)			//�Է�Ҷ�ӽڵ���в���
	{
		Select(ht, i - 1, &s1, &s2);		//ѡȡ��С�������ڵ�ı��,�����һ���ڵ�
		ht[s1].parent = i;					
		ht[s2].parent = i;
		ht[i].lchild = s1;
		ht[i].rchild = s2;
		ht[i].weight = ht[s1].weight + ht[s2].weight;
	}

	cd[n - 1] = '\0';

	for (i = 1; i <= n; i++)		//����Ҷ�ӽڵ�
	{
		start = n - 1;
		for (c = i, f = ht[i].parent; f; c = f, f = ht[f].parent)		//��ȡÿ��Ҷ�ӽڵ�ı���
		{
			if (ht[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
			strcpy(hc[i].code, &cd[start]);		//�����뿽�����ṹ���еı�����
		}
	}
}

int main()
{
	int n;
	HTNode ht[M + 1];
	HTCode hc[N + 1];
	Init(hc, &n);
	HuffmanCoding(ht, hc, n);
	for (int i = 1; i <= n; i++)
	{
		cout << hc[i].data << "-----" << hc[i].code << endl;
	}
	return 0;
}