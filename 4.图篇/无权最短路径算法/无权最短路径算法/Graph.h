#pragma once
#include<list>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iterator>
#include<stdio.h>
#include<errno.h>
#include<signal.h>
#include<queue>

using namespace std;

#define MAX_VERTEX_NUM 600
#define INFINITY 1000000			//���������

//=����ÿ��������Ϣ�����ݽṹ
struct GraphNode {
	bool known;			//��ǰ���������ľ����Ƿ�ȷ��
	int dist;					//��ǰ���㵽������̾���
	int path;				//��ǰ���㵽�������·����ǰһ������
};

//ͼ�ڵ���Ϣ
typedef struct Node
{
	int edge_num;		//�ߺ�
	int src;					//Դ��
	int vertex;				//����
	int weight;			//�ߵ�Ȩ��
}Node;

//�ڽӱ�ͼ
class Graph
{
private:
	int edge_num;		//ͼ�ıߵĸ���
	int vertex_num;	//ͼ�Ķ������Ŀ
	list<Node> *graph_list;		//�ڽӱ�
	vector<GraphNode> nodeArr;		//����ÿ��������Ϣ������
public:
	Graph(){}
	Graph(char* graph[], int edgenum);
	~Graph();
	void print();
	void unweightShortestPath(int src);			//�㷨1����̾���
	void unweightShortestPathAdv(int src);		//�㷨2����̾���
	void printShortestPath();			//�������src������������̾������Ϣ
private:
	vector<int> get_graph_value(char* graph[], int columns);
	void addEdge(char* graph[], int columns);
};