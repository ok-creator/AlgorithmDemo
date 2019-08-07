#include"Node.h"
#include<iostream>
using namespace std;
Node::Node()
{
	index = 0;
	data = 0;
	pLChild = NULL;
	pRChild = NULL;
	pParent = NULL;
}
Node *Node::SearchNode(int nodeIndex)	//�����ڵ㣬ʹ���˵ݹ��㷨
{
	//1.�Ƚϵ�ǰ��������
	if (this->index == nodeIndex)		//����˽ڵ����������Ҫ��ѯ���������򷵻�
	{
		return this;
	}
	//2.������ʱ�Ľڵ�
	Node *temp = NULL;		//����һ�����������ڴ洢�ӽڵ��ҵ��Ľ��
	//3.�Ƚϵ�ǰ������ӵ�����
	if (this->pLChild != NULL)			//������Ӵ���
	{
		if (this->pLChild->index == nodeIndex)	//�ж���ڵ�������Ƿ���Ҫ��ѯ������һ��
		{
			return this->pLChild;
		}
		else
		{
			temp= this->pLChild->SearchNode(nodeIndex);		//�����һ�£�����������Ϊ�������в���
			if (temp != NULL)
			{
				return temp;			//���ҽ�����ڣ��򷵻�
			}
		}
	}
	//3.�Ƚϵ�ǰ����Һ��ӵ�����
	if (this->pRChild != NULL)
	{
		if (this->pRChild->index == nodeIndex)
		{
			return this->pRChild;
		}
		else
		{
			temp=this->pRChild->SearchNode(nodeIndex);
			return temp;
		}
	}
	return NULL;
}

void Node::DeleteNode()
{
	if (this->pLChild != NULL)
	{
		this->pLChild->DeleteNode();	//ɾ����ǰ��������
	}
	if (this->pRChild != NULL)
	{
		this->pRChild->DeleteNode();	//ɾ����ǰ�����Һ���
	}
	
	if (this->pParent != NULL)			//��ǰ�����ڸ��ڵ�
	{
		if (this->pParent->pLChild == this)		//�жϵ�ǰ����Ǹ�ָ�������
		{
			this->pParent->pLChild = NULL;		//����ָ���������ΪNULl
		}
		if (this->pParent->pRChild == this)		//�жϵ�ǰ����Ǹ�ָ�������
		{
			this->pParent->pRChild = NULL;
		}
	}
	delete this;								//ɾ����ǰ�������

}

void Node::PreprderTraversal()		//ǰ�����
{
	cout << this->index<<"--------"<<this->data << endl;		//���ʸ��ڵ�
	if (this->pLChild != NULL)									//������ڵ�
	{
		this->pLChild->PreprderTraversal();
	}
	if (this->pRChild != NULL)									//�����ҽڵ�
	{
		this->pRChild->PreprderTraversal();
	}
}

void Node::InorderTraversal()
{
	if (this->pLChild != NULL)									//������ڵ�
	{
		this->pLChild->InorderTraversal();
	}
	cout << this ->index << "--------" << this->data << endl;	//���ʸ��ڵ�
	if (this->pRChild != NULL)									//�����ҽڵ�
	{
		this->pRChild->InorderTraversal();
	}
}

void Node::PostorderTraversal()
{
	if (this->pLChild != NULL)
	{
		this->pLChild->PostorderTraversal();		
	}
	if (this->pRChild != NULL)
	{
		this->pRChild->PostorderTraversal();
	}
	cout << this->index << "--------" << this->data << endl;
}