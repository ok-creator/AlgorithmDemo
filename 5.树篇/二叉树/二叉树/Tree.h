#pragma once
#ifndef TREE_H
#define TREE_H


class Tree
{
public:

	Tree(int size,int *pRoot);		//������
	~Tree();			//������
	int* SearchNode(int nodeIndex);				//��������Ѱ�ҽ��
	bool AddNode(int nodeIndex, int direction, int *pNode);		//��ӽڵ�
	bool DeleteNode(int nodeIndex, int *pNode);					//ɾ���ڵ�
	void TreeTraverse();						//���ı���

private:
	int *m_pTree;
	int m_iSize;
};




















#endif