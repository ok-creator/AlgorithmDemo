#include"List.h"
#include<iostream>
using namespace std;

List::List()
{
	m_pList = new Node;		//����ͷ���
	m_pList->data = 0;		//ͷ���������ֵΪ0��û������		
	m_pList->next = NULL;	//ͷ���ָ���򸳳�ֵΪNULL
	m_iLength = 0;			//ͷ��㲻����������֮��
}

List::~List()				//ɾ�����н��
{
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

void List::ClearList()		//����ͷ���
{

	Node *currentNode = m_pList->next;
	while (currentNode != NULL)			//��Ѷ��ǰ�ķ���
	{
		Node *temp = currentNode->next;	//�ҵ��¼�
		delete currentNode;				//ɾ���ϼ�
		currentNode = temp;				//��ǰ���¼ұ���ϼ�
	}
	m_pList->next = NULL;
}

bool List::ListEmpty()		//C����û��bool���ͣ���д��BOOL����Ϊ�ĺ궨��
{
	if (m_iLength == 0)
	{
		return true;
	}
	else
		return false;
	//return m_iLength==0? true:false
}

int List::ListLength()
{
	return m_iLength;
}

bool List::ListInsertHead(Node *pNode)
{
	Node *temp = m_pList->next;

	//���������ڴ棬�����ջ�������ڴ棬����������֮���ڴ潫�ᱻ����
	Node *newNode = new Node;		
	if (newNode == NULL)		//�����ڴ�ʧ�ܣ����ش���
	{
		return false;
	}
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = temp;
	m_iLength++;
	return true;
}
bool List::ListInsertTail(Node *pNode)
{
	Node *currentNode = m_pList;

	//1.��ȡβָ��
	while (currentNode->next != NULL)		
	{
		currentNode = currentNode->next;
	}
	//2.�����½��
	Node *newNode = new Node;
	if (newNode == NULL)		//���������ڴ�ʧ�ܣ����ش���
	{
		return false;
	}
	//3.��������
	newNode->data = pNode->data;
	//4.ʹ�½����β���
	newNode->next = NULL;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}


bool List::ListInsert(int i, Node *pNode)
{
	if (i<0 || i>m_iLength)
	{
		return false;
	}
	Node*currentNode = m_pList;
	for (int k = 0; k < i; k++)
	{
		currentNode = currentNode->next;
	}
	Node *newNode = new Node;
	if (newNode == NULL)		//���������ڴ�ʧ�ܣ����ش���
	{
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}

bool List::ListDelete(int i, Node *pNode)
{
	if (i < 0 || i >= m_iLength)	//���i����m_iLength����ôɾ��β������һ����㣬���ǲ����ܵ�
	{
		return false;
	}
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	currentNodeBefore->next = currentNode->next;
	pNode->data = currentNode->data;
	delete currentNode;
	currentNode = NULL;
	m_iLength--;
	return true;
}

bool List::GetElem(int i, Node *pNode)
{
	if (i < 0 || i >= m_iLength)	//���i����m_iLength����ôɾ��β������һ����㣬���ǲ����ܵ�
	{
		return false;
	}
	Node *currentNode = m_pList;
	for (int k = 0; k <= i; k++)
	{
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	return true;
}
int List::LocateElem(Node *pNode)
{
	int count=0;
	Node *currentNode = m_pList;
	while (currentNode->next!=NULL)
	{
		currentNode = currentNode->next;
		if (currentNode->data == pNode->data)
		{
			return count;
		}
		count++;
	}
	return -1;
}

bool List::PriorElem(Node *pCurrentNode, Node *pPreNode)
{
	Node *currentNode = m_pList;
	Node *tempNode = NULL;
	while (currentNode->next != NULL)
	{
		tempNode = currentNode;				//������ǰ����ǰһ�����
		currentNode = currentNode->next;	//ʹ��ǰ���ָ����һ�����
		if (currentNode->data == pCurrentNode->data)
		{
			if (tempNode == m_pList)		//��ǰ�����ͷ�������һ����㣬ͷ��㲻�ܷ���������
			{
				return false;
			}
			pPreNode->data = tempNode->data;
			return true;
		}
	}
	return false;
}

bool List::NextElem(Node *pCurrentNode, Node *pNextNode)
{
	Node *currentNode = m_pList;

	while (currentNode->next != NULL)
	{			
		currentNode = currentNode->next;	//ʹ��ǰ���ָ����һ�����
		if (currentNode->data == pCurrentNode->data)
		{
			if (currentNode->next==NULL)		//��ǰ���������㣬û�к��
			{
				return false;
			}
			pNextNode->data = currentNode->next->data;
			return true;
		}
	}
	return false;
}

void List::ListTraverse()
{
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		currentNode->printNode();
	}
}