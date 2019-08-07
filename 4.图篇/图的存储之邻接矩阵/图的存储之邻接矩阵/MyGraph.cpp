#include"MyGraph.h"
#include<iostream>
using namespace std;

#define INFINITY 65535		// ��65535�����������

MyGraph::MyGraph(int n,int e,bool f)
{
	numVertexes = n;
	numEdges = e;
	flag = f;
	for (int i = 0; i < this->numVertexes; i++)
	{
		for (int j = 0; j < this->numVertexes; j++)
		{
			this->arc[i][j] = INFINITY;			// �ڽӾ����ʼ��
		}
	}
}

void MyGraph::CreateGraph()
{
	int i,j, w;
	cout << "���������붥�㣺" << endl;
	for (int k = 0; k < this->numVertexes; i++)
	{
		cin >> vexs[k];
	}
	cout << "�������(Vi,Vj)�ϵ��±�i,�±�j�Ͷ�Ӧ��Ȩw: " << endl;
	for (int k = 0; k < this->numEdges; k++)
	{
		cin >> i >> j >> w;
		if (!flag)
		{
			this->arc[i][j] = w;
			this->arc[j][i] = w;
		}
		else
		{
			this->arc[i][j] = w;
		}
	}
}