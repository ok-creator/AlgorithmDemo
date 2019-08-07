#pragma once
#ifndef TREE_H
#define TREE_H
#include"Node.h"


class Tree
{
public:
	Tree();							//���캯��
	~Tree();						//��������
	Node *SearchNode(int nodeIndex);	//�����ڵ�
	bool AddNode(int nodeIndex, int direction, Node *pNode);	//���ӽڵ�(��������/�ҡ�Ҫ���ӵĽڵ��ָ��)
	bool DeleteNode(int nodeIndex, Node *pNode);		//ɾ���ڵ�(�������ڵ�����)
	void PreprderTraversal();	//ǰ�����
	void InorderTraversal();	//�������
	void PostorderTraversal();	//�������
private:
	Node *m_pRoot;				//������ڵ�
};





#endif