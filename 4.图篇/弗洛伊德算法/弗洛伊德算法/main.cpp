#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAX 10
#define INF 65535

typedef struct graph
{
	char vexs[MAX];
	int vexnum;		//������
	int edgnum;		//����
	int matrix[MAX][MAX];		//�ڽӾ���
}Graph;

int pathmatrix[MAX][MAX];	//��¼��Ӧ�����С·����ǰ���㣬����p(1,3) = 2 ˵������1������3����С·��Ҫ����2 
int shortPath[MAX][MAX];	//��¼��������С·��ֵ

void short_path_floyd(Graph G, int P[MAX][MAX], int D[MAX][MAX])
{
	int v, w, k;
	for (v = 0; v < G.vexnum; v++)
	{
		//��ʼ��floyd�㷨����������
		for (w = 0; w < G.vexnum; w++)
		{
			D[v][w] = G.matrix[v][w];
			P[v][w] = w;
		}
	}

	//���Ǹ��������㷨�ĺ��Ĳ���
	//kΪ�м��
	for (k = 0; k < G.vexnum; k++)
	{
		//vΪ���
		for (v = 0; v < G.vexnum; v++)
		{
			//w1Ϊ�յ�
			for (w = 0; w < G.vexnum; w++)
			{
				if (D[v][w]>(D[v][k] + D[k][w]))
				{
					D[v][w] = D[v][k] + D[k][w];	//������С·��
					P[v][w] = P[v][k];		//������С·���м䶥��
				}
			}
		}
	}

	cout << endl << "��ʼ����D����" << endl;
	for (v = 0; v < G.vexnum; v++)
	{
		for (w = 0; w < G.vexnum; w++)
		{
			cout << D[v][w];
		}
		cout << endl;
	}

	cout << endl << "��ʼ����P����" << endl;
	for (v = 0; v < G.vexnum; v++)
	{
		for (w = 0; w < G.vexnum; w++)
		{
			cout << P[v][w];
		}
		cout << endl;
	}

	v = 0;
	w = 3;
	//��0��3����С·��
	cout << endl << v << "->" << w << "����С·��Ϊ��" << D[v][w] << endl;
	k = P[v][w];
	cout << "path:" << v;	//��ӡ���
	while (k != w)
	{
		cout << "->" << k;	//��ӡ�м��
		k = P[k][w];
	}
	cout << "->" << w << endl;
}

int main()
{
	Graph G;
	int i = 0, j = 0, e = 0;
	cout << "�����붥�����ͱ��� ��" << endl;
	cin >> G.vexnum >> G.edgnum;
	cout << "�����붥�㣺" << endl;
	for (int k = 0; k < G.vexnum; k++)
	{
		cin >> G.vexs[k];
	}
	for (int i = 0; i < G.vexnum; i++)		//��ʼ��ȨֵΪ�����
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			G.matrix[i][j] = INF;
		}
	}
	cout << "������ߣ�" << endl;			//����ͼ���ڽӾ���Գ�
	for (int k = 0; k<G.edgnum; k++)
	{
		cin >> i >> j >> e;
		G.matrix[i][j] = e;
		G.matrix[j][i] = e;
	}

	short_path_floyd(G, pathmatrix, shortPath);

	return 0;
}