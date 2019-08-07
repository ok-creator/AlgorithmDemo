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

	m_pEdge = new Edge[m_iCapacity - 1];		//��С�������ıߵĸ���Ϊ��ĸ�����һ
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

//����ķ������
void CMap::primTree(int nodeIndex)
{
	int value = 0;				//����ȡ��
	int edgeCount=0;			//��С����������ѡ��ı���
	vector<int> nodeVec;		//��ļ���
	vector<Edge> edgeVec;		//�ߵļ��ϣ��ߵ�����û������

	cout << m_pNodeArray[nodeIndex].m_cData << endl;	//�����ǰ��������

	nodeVec.push_back(nodeIndex);						//����ǰ������㼯��
	m_pNodeArray[nodeIndex].m_bIsVisited = true;		//����ǰ�����Ϊ�ѷ���

	//��ȡ���еĴ�ѡ��
	while (edgeCount < m_iCapacity - 1)					//�������ڵ�����1������ѭ��
	{
		int temp = nodeVec.back();						//ȡ��β�����

		for (int i = 0; i < m_iCapacity; i++)
		{
			getValueFromMatrix(temp, i, value);			//�õ�����Ȩֵ
			if (value != 0)								//���Ȩֵ��Ϊ0
			{
				if (m_pNodeArray[i].m_bIsVisited)		//�жϽ�� i �Ƿ��ѷ��ʹ�
				{
					continue;							//����ѭ��������һ�����
				}
				else
				{
					Edge edge(temp, i, value);			//�����
					edgeVec.push_back(edge);			//������ӵ���ѡ����
				}
			}
		}
		
		//�ӿ�ѡ�߼������ҳ���С��
		int edgeIndex=getMinEdge(edgeVec);				//�ҳ���̱ߵ�����
		edgeVec[edgeIndex].m_bSelected = true;			//������Ϊ��ѡ��

		cout << edgeVec[edgeIndex].m_iNodeIndexA << "----" << edgeVec[edgeIndex].m_iNodeIndexB << " ";		//������ͱ�
		cout << edgeVec[edgeIndex].m_iWeightValue << endl;

		m_pEdge[edgeCount] = edgeVec[edgeIndex];		//���ߴ�����С�������ı߼�����
		edgeCount++;									//��С�������ı߼����бߵ���Ŀ��1

		int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;	//��ȡ��С���е���һ���ڵ������

		nodeVec.push_back(nextNodeIndex);						//������������뵽�㼯����
		m_pNodeArray[nextNodeIndex].m_bIsVisited = true;		//������Ϊ�ѷ���
		cout << m_pNodeArray[nextNodeIndex].m_cData << endl;
	}
}

int CMap::getMinEdge(vector<Edge> edgeVec)
{
	int minWeight = 0;			//������СȨֵ
	int edgeIndex = 0;			//����ߵ�����
	int i = 0;					//�����������

	//�ҵ���һ��δ��ѡ��ı�
	for (; i < edgeVec.size(); i++)
	{
		if (!edgeVec[i].m_bSelected)
		{
			minWeight = edgeVec[i].m_iWeightValue;		//��ȡȨֵ
			edgeIndex = i;								//��ȡ�ߵ�����
			break;										//�ҵ�֮����������forѭ��
		}
	}

	
	if (minWeight == 0)
	{
		return -1;
	}

	//�ҵ���С�ߵ�����
	for (; i < edgeVec.size(); i++)
	{
		if (edgeVec[i].m_bSelected)
		{
			continue;
		}
		else
		{
			if (minWeight > edgeVec[i].m_iWeightValue)
			{
				minWeight = edgeVec[i].m_iWeightValue;
				edgeIndex = i;
			}
		}
	}

	return edgeIndex;	//������С�ߵ�����
}