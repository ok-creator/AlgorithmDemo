#include"Tree.h"
#include<iostream>


Tree::Tree()
{
	m_pRoot = new Node();	//��ʼ�����ڵ�
}

Tree::~Tree()
{
	//DeleteNode(0, NULL);		//ɾ�����еĽڵ�
	m_pRoot->DeleteNode();		//��ɾ�������Ը��ڵ�Ϊ���ڵ�����нڵ�
}
Node *Tree::SearchNode(int nodeIndex)
{
	 return m_pRoot->SearchNode(nodeIndex);		//���ýڵ�ĳ�Ա��������������
}

bool Tree::AddNode(int nodeIndex, int direction, Node *pNode)
{
	//1.�������ڵ�
	Node *temp = SearchNode(nodeIndex);		//���ҵ�Ҫ��Ӹ��ڵ�
	if (temp == NULL)						//û���ҵ��ڵ�
	{
		return false;			//���ش���
	}
	//2.�����½ڵ�
	Node *node = new Node();	//����һ���½��
	if (node == NULL)			//�����ڴ�ʧ��
	{
		return false;
	}
	//3.���ݽڵ����ݺ�����
	node->index = pNode->index;	//��������
	node->data = pNode->data;	//��������
	node->pParent = temp;		//���ݸ�ָ��
	//4.ȷ��ָ���ָ��
	if (direction == 0)			//directionΪ0�������������
	{
		temp->pLChild = node;	
	}
	if (direction == 1)			//directionΪ1����������Һ���
	{
		temp->pRChild = node;
	}
	return true;				//��ӽڵ�ɹ�
}

bool Tree::DeleteNode(int nodeIndex, Node *pNode)
{
	//1.����Ҫɾ���Ľڵ�
	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL)
	{
		return false;
	}
	//2.�жϴ���Ķ����Ƿ���Ч�������Ƿ����ݴ��ݳ�ȥ
	if (pNode != NULL)		//����ڵ㲻ΪNULL�������ݴ����ڵ�
	{
		pNode->data = temp->data;
	}
	//3.ɾ���ڵ�
	temp->DeleteNode();
	return true;
}

void Tree::PreprderTraversal()
{
	m_pRoot->PreprderTraversal();
}

void Tree::InorderTraversal()
{
	m_pRoot->InorderTraversal();
}

void Tree::PostorderTraversal()
{
	m_pRoot->PostorderTraversal();
}