#pragma once
#ifndef CMAP_H
#define CMAP_H
#include"Node.h"
#include"Edge.h"
#include<vector>
using namespace std;

class CMap
{
public:
	CMap(int capacity);
	~CMap();
	bool addNode(Node *pNode);		//��ͼ����Ӷ��㣨�ڵ㣩
	void resetNode();				//���ö���
	bool setValueToMatrixForDirectGraph(int row, int col, int val = 1);		//Ϊ����ͼ�����ڽӾ���     �У��У�ֵ
	bool setValueToMatrixForUndirectGraph(int row, int col, int val = 1);	//Ϊ����ͼ�����ڽӾ���

	void printMatrix();		//��ӡ�ڽӾ���

	void primTree(int nodeIndex);				//����ķ������

private:
	bool getValueFromMatrix(int row, int col, int &val);	//�Ӿ����л�ȡȨֵ

	int getMinEdge(vector<Edge> edgeVec);
private:
	int m_iCapacity;		//ͼ��������ɵĶ�����
	int m_iNodeCount;		//����ӵĶ���ĸ���
	Node *m_pNodeArray;		//������Ŷ�������
	int *m_pMatrix;			//��������ڽӾ���

	Edge *m_pEdge;			//��������С�ߵ�ָ��
};

#endif