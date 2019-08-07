#include<iostream>
using namespace std;

/*
	ͼ���ڽӱ�洢------����ڽӾ���洢�˷ѿռ������

	�õ����߱�ڵ㡢�����ڵ�
*/

#define MAXVEX 100			/* ��󶥵���,Ӧ���û����� */
typedef char VertexType;	/* ��������Ӧ���û����� */
typedef int EdgeType;		/* ���ϵ�Ȩֵ����Ӧ���û����� */

typedef struct EdgeNode		/* �߱���  */
{
	int adjvex;				/* �ڽӵ���,�洢�ö����Ӧ���±� */
	EdgeType weight;		/* ���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ */
	struct EdgeNode *next;	/* ����,ָ����һ���ڽӵ� */
} EdgeNode;

typedef struct VextexNode	/* ������� */
{
	VertexType data;		/* ������,�洢������Ϣ */
	EdgeNode *firstedge;	/* �߱�ͷָ�� */
} VextexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numNodes, numEdges; /* ͼ�е�ǰ�������ͱ��� */
} GraphAdjList;


void CreateALGraph(GraphAdjList *Gp)
{
	int i, j, k;
	EdgeNode *pe;
	cout << "���붥�����ͱ���(�ո�ָ���:" << endl;
	cin >> Gp->numNodes >> Gp->numEdges;

	for (i = 0; i < Gp->numNodes; i++)
	{
		cout << "���붥����Ϣ��" << endl;
		cin >> Gp->adjList[i].data;
		Gp->adjList[i].firstedge = NULL;		/* ���߱���Ϊ�ձ� */
	}

	for (k = 0; k < Gp->numEdges; k++)			/* �����߱� */
	{
		cout << "�����(vi,vj)�Ķ������i,j���ո�ָ���:" << endl;
		cin >> i >> j;
		pe = (EdgeNode *)malloc(sizeof(EdgeNode));
		pe->adjvex = j;							/* �ڽ����Ϊj */
												//��pe�ڵ���뵽����ڵ�i�͵�һ���߱�ڵ�֮��
		pe->next = Gp->adjList[i].firstedge;
		Gp->adjList[i].firstedge = pe;			/* ����ǰ�����ָ��ָ��pe */

		pe = (EdgeNode *)malloc(sizeof(EdgeNode));
		pe->adjvex = i;
		pe->next = Gp->adjList[j].firstedge;
		Gp->adjList[j].firstedge = pe;

	}
}

int main(void)
{
	GraphAdjList GL;
	CreateALGraph(&GL);

	return 0;
}