#pragma once

#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node();
	Node *SearchNode(int nodeIndex);		//�����ڵ�
	void DeleteNode();						//ɾ���ڵ�
	void PreprderTraversal();				//ǰ�����
	void InorderTraversal();				//�������
	void PostorderTraversal();				//�������
public:
	int index;		//����
	int data;		//�洢������
	Node *pLChild;	//���ӵ�ָ��
	Node *pRChild;	//�Һ��ӵ�ָ��
	Node *pParent;	//���ڵ��ָ��
};


#endif