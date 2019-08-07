#pragma once
#ifndef CMAP_H
#define CMAP_H
#include"Node.h"
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

	void depthFirstTraverse(int nodeIndex);		//������ȱ���
	void breathFirstTraverse(int nodeIndex);	//������ȱ���

private:
	bool getValueFromMatrix(int row, int col, int &val);	//�Ӿ����л�ȡȨֵ
	void breathFirstTraverseImpl(vector<int> preVec);		//������ȱ���ʵ�ֺ���
private:
	int m_iCapacity;		//ͼ��������ɵĶ�����
	int m_iNodeCount;		//����ӵĶ���ĸ���
	Node *m_pNodeArray;		//������Ŷ�������
	int *m_pMatrix;			//��������ڽӾ���
};

#endif