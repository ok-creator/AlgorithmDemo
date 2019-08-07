#include"CMap.h"
#include<iostream>
#include<vector>
using namespace std;

CMap::CMap(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];
	m_pMatrix = new int[m_iCapacity*m_iCapacity];	//��һά��������ʾ�ڽӾ��󣨶�ά����
	//memset(m_pMatrix, 0, m_iCapacity*m_iCapacity*sizeof(int));	//memset���ڽӾ����ʼ��Ϊ0
	for (int i = 0; i < m_iCapacity*m_iCapacity; i++)
	{
		m_pMatrix[i] = 0;
	}
}

CMap::~CMap()
{
	delete[]m_pNodeArray;
	delete[]m_pMatrix;
}

bool CMap::addNode(Node *pNode)
{
	if (pNode == NULL)
	{
		return false;
	}
	m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;	//��������
	m_iNodeCount++;		//��������1
	return true;
}

void CMap::resetNode()
{
	for (int i = 0; i < m_iNodeCount; i++)
	{
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

bool CMap::setValueToMatrixForDirectGraph(int row, int col, int val)	//����ʵ�����ﲻ��Ҫ��дint val=1������ᱨ��
{
	if (row < 0 && row >= m_iCapacity)
	{
		return false;
	}
	if (col < 0 && col >= m_iCapacity)
	{
		return false;
	}
	m_pMatrix[row*m_iCapacity + col] = val;		//����ͼ�����ضԽ��߶Գ�
	return true;
}

bool CMap::setValueToMatrixForUndirectGraph(int row, int col, int val)
{
	if (row < 0 && row >= m_iCapacity)
	{
		return false;
	}
	if (col < 0 && col >= m_iCapacity)
	{
		return false;
	}
	m_pMatrix[row*m_iCapacity + col] = val;
	m_pMatrix[col*m_iCapacity + row] = val;
	return true;
}


bool CMap::getValueFromMatrix(int row, int col, int &val)	//��ȡ����ֵ
{
	if (row < 0 && row >= m_iCapacity)
	{
		return false;
	}
	if (col < 0 && col >= m_iCapacity)
	{
		return false;
	}
	val = m_pMatrix[row*m_iCapacity + col];
	return true;
}

void CMap::printMatrix()		//��ӡ�ڽӾ���
{
	for (int i = 0; i < m_iCapacity; i++)		//��
	{
		for (int k = 0; k < m_iCapacity; k++)	//��
		{
			cout << m_pMatrix[i*m_iCapacity + k] << " ";
		}
		cout << endl;		//ÿ�лس�
	}
}

//������ȱ���
void CMap::depthFirstTraverse(int nodeIndex)
{
	int value = 0;										//�洢����ֵ
	cout << m_pNodeArray[nodeIndex].m_cData << " ";		//���ʵ�ǰ�ڵ�
	m_pNodeArray[nodeIndex].m_bIsVisited = true;		//����ǰ�ڵ��ʶ��Ϊ�ѷ���

	for (int i = 0; i < m_iCapacity; i++)				//�����뵱ǰ�ڵ������ӵĽڵ�
	{
		getValueFromMatrix(nodeIndex, i, value);		//��ȡ����ֵ
		if (value == 1)									//�ڵ��뵱ǰ�������
		{
			if (m_pNodeArray[i].m_bIsVisited == true)	//�ڵ��Ƿ���ʹ�
			{
				continue;								//����ѭ�������¸��ڵ�
			}
			else
			{
				depthFirstTraverse(i);					//�Ե�ǰ�ҵ��Ľڵ����������ȱ���
			}
		}
		else
		{
			continue;									//�뵱ǰ�ڵ㲻����������Ѱ����һ���ڵ�
		}
	}
}

//������ȱ���
void CMap::breathFirstTraverse(int nodeIndex)
{
	cout << m_pNodeArray[nodeIndex].m_cData << " ";		//���ʵ�ǰ�ڵ�
	m_pNodeArray[nodeIndex].m_bIsVisited = true;		//����ʶ��Ϊ�ѷ���

	vector<int>curVec;									//�����������ڴ洢ÿһ��õ��Ľڵ�
	curVec.push_back(nodeIndex);						//����ǰ�ڵ���뵽������

	breathFirstTraverseImpl(curVec);					//�����������������ʵʩ����
}

void CMap::breathFirstTraverseImpl(vector<int> preVec)
{
	int value=0;										//�洢����ֵ
	vector<int>curVec;									//�����������ڴ洢ÿһ��õ��Ľڵ�
	for (int j = 0; j < (int)preVec.size(); j++)		//����ǰһ�����еĽڵ�
	{
		for (int i = 0; i < m_iCapacity;i++)			//���뵱ǰ�ڵ������Ľڵ�
		{
			getValueFromMatrix(preVec[j], i, value);	//��ȡ����ֵ
			if (value != 0)								//�뵱ǰ�ڵ�����
			{
				if (m_pNodeArray[i].m_bIsVisited == true)//�ж��Ƿ���ʹ�
				{
					continue;
				}
				else
				{
					cout << m_pNodeArray[i].m_cData << " ";//���ʽڵ������
					m_pNodeArray[i].m_bIsVisited = true;	//���ڵ���Ϊ�ѷ���
					curVec.push_back(i);					//���ڵ���ӵ������ڵ��������
				}
			}
		}
	}
	if (curVec.size() == 0)									//�ж϶�̬�������Ƿ���Ԫ��
	{
		return;												//û��Ԫ�أ�����
	}
	else
	{
		breathFirstTraverseImpl(curVec);					//��Ԫ�أ������ݹ����
	}
}