#include<iostream>
#include<list>
#include<queue>
using namespace std;

/*
	��ͼ���У���������Topological Sorting����һ�������޻�ͼ��DAG, Directed Acyclic Graph��
	�����ж�����������С��Ҹ����б���������������������
		(1)ÿ�����������ֻ����һ�Ρ�
		(2)������һ���Ӷ��� A ������ B ��·������ô�������ж��� A �����ڶ��� B ��ǰ�档
	�����޻�ͼ��DAG�������������򣬷�DAGͼû����������һ˵��
*/





/*********************������*******************/
class Graph
{
public:
	Graph(int V);		//���캯��
	~Graph();			//��������
	void addEdge(int v, int w);	//��ӱ�
	bool topological_sort();	//��������
private:
	int V;				//�������
	list<int> *adj;		//�ڽӱ�
	queue<int>q;		//ά��һ�����Ϊ0�Ķ���ļ���
	int *indegree;		//���飬��¼ÿ����������
};

/**********************��Ա����ʵ��********************/
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];		//�����ڴ�

	indegree = new int[V];		//���ȫ����ʼ��Ϊ0
	for (int i = 0; i < V; i++)
	{
		indegree[i] = 0;
	}
}

Graph::~Graph()
{
	delete[]adj;
	delete[]indegree;
}

void Graph::addEdge(int v, int w)		//v->w
{
	adj[v].push_back(w);				//��w���뵽�ڽӱ���
	++indegree[w];						//w����ȼ�1
}

bool Graph::topological_sort()
{
	for (int i = 0; i < V; i++)
	{
		if (indegree[i] == 0)
			q.push(i);		//���������Ϊ0�Ķ������
	}

	int count = 0;			//��������¼��ǰ�Ѿ�����Ķ�����

	while (!q.empty())		//���Ϊ0�Ķ��в�Ϊ��
	{
		int v = q.front();	//ȡ����ͷȡ��Ԫ��
		q.pop();			//����Ԫ��
		cout << v << " ";
		++count;

		list<int>::iterator beg = adj[v].begin();	//���������
		for (; beg != adj[v].end(); ++beg)			//������������ĩβ��ʱ��ÿ��ѭ������һλ
		{
			if (!(--indegree[*beg]))				//�����Ϊ0������ջ
				q.push(*beg);
		}
	}

	if (count < V)
	{
		return false;		//û�����ȫ�����㣬����ͼ���л�·
	}
	else
		return true;		//��������ɹ�
}

int main()
{
	Graph g(6);			//����ͼ
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	g.topological_sort();
	return 0;
}