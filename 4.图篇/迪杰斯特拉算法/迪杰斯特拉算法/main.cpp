#include<iostream>
using namespace std;

#define MAX 7			//��������
#define INF 65535		//���������
//�ڽӾ���
typedef struct graph
{
	char vexs[MAX];		//���㼯��
	int vexnum;			//������
	int edgnum;			//����
	int matrix[MAX][MAX];		//�ڽӾ���
}Graph,*pGraph;

////�ߵĽṹ��
//typedef struct EdgeData
//{
//	char start;		//�ߵ����
//	char end;		//�ߵ��յ�
//	int weight;		//�ߵ�Ȩ��
//}EData;


/*
* Dijkstra���·����
* ����ͳ��ͼ(G)��"����vs"������������������·����
*
* ����˵����
*        G -- ͼ
*       vs -- ��ʼ����(start vertex)��������"����vs"��������������·����
*     prev -- ǰ���������顣����prev[i]��ֵ��"����vs"��"����i"�����·����������ȫ�������У�λ��"����i"֮ǰ���Ǹ����㡣
*     dist -- �������顣����dist[i]��"����vs"��"����i"�����·���ĳ��ȡ�
*/
void dijkstra(Graph G, int vs, int prev[], int dist[])
{
	int i, j, k;
	int min;			//�����С��
	int tmp;			//�����ʱ·������
	int flag[MAX];		//flag[i]=1 ��ʾ����vs������i�����·���ѳɹ���ȡ

	//��ʼ��
	for (i = 0; i < G.vexnum; i++)
	{
		flag[i] = 0;	//����i�����·����û�л�ȡ��
		prev[i] = 0;	//����i��ǰ���ڵ�Ϊ0
		dist[i] = G.matrix[vs][i];		//��ʼ����Ϊ��㵽�������ľ���
	}
	
	//�Զ���vs������г�ʼ��
	flag[vs] = 1;
	dist[vs] = 0;

	//����G.vexnum-1�Σ�ÿ���ҳ�һ����������·��
	for (i = 1; i < G.vexnum; i++)
	{
		//Ѱ�ҵ�ǰ��С��·����
		// ������δ��ȡ���·���Ķ����У��ҵ���vs����Ķ���(k)��
		min = INF;
		for (j = 0; j < G.vexnum; j++)
		{
			if (flag[j] == 0 && dist[j] < min)
			{
				min = dist[j];		//������·��
				k = j;				//������·���Ľڵ�
			}
		}


		//��Ƕ���kΪ�ѻ�ȡ�������·��
		//kΪû�б���ȡ���ģ����·��
		flag[k] = 1;

		// ������ǰ���·����ǰ������
		// �������Ѿ�"����k�����·��"֮�󣬸���"δ��ȡ���·���Ķ�������·����ǰ������"��
		for (j = 0; j < G.vexnum; j++)
		{
			// ��ֹ����������������INF����
			//���G.matrix[k][j]ΪINF�����ΪINF�����С��INF������min + G.matrix[k][j]
			tmp = (G.matrix[k][j] == INF ? INF : (min + G.matrix[k][j]));	
			if (flag[j] == 0 && (tmp<dist[j]))
			{
				dist[j] = tmp;		//����·������
				prev[j] = k;		//j��ǰһ�����Ϊk
			}
		}
	}

	// ��ӡdijkstra���·���Ľ��
	cout << "dijkstra(" << G.vexs[vs] << "):" << endl;
	for (i = 0; i < G.vexnum; i++)
		cout << "shortest(" << G.vexs[vs] <<","<< G.vexs[i] << ")=" << dist[i] << endl;
}

int main()
{
	Graph G;
	int i = 0, j = 0,e=0,prev[MAX],dist[MAX];
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

	dijkstra(G, 3, prev, dist);

	return 0;
}