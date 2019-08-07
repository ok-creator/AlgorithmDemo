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
	delete[]m_pEdge;
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

int CMap::getMinEdge(vector<Edge> edgeVec)
{
	int minWeight = 0;			//������СȨֵ
	int edgeIndex = 0;			//����ߵ�����
	int i = 0;					//�����������

	//�ҵ���һ��δ��ѡ��ı�
	for (; i < (int)edgeVec.size(); i++)
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
	for (; i < (int)edgeVec.size(); i++)
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

//��³˹�����㷨������
void CMap::kruskalTree()
{
	int value = 0;			//���Ȩֵ
	int edgeCount = 0;		//����������бߵĸ���

	//�����Žڵ㼯�ϵ�����
	vector<vector<int>> nodeSets;		//�൱��һ����ά����

	//��һ��ȡ�����б�
	vector<Edge> edgeVec;	

	for (int i = 0; i < m_iCapacity; i++)		//�Գƾ���ȡ���������Ϸ��ı�
	{
		for (int k = i + 1; k < m_iCapacity; k++)
		{
			getValueFromMatrix(i, k, value);
			if (value != 0)
			{
				Edge edge(i, k, value);
				edgeVec.push_back(edge);
			}
		}
	}

	//�ڶ����������б���ȡ�������С�������ı�
	//1.�ҵ��㷨��������
	while (edgeCount < m_iCapacity - 1)
	{

		//2.�ӱ߼������ҵ���С��
		int minEdgeIndex=getMinEdge(edgeVec);		//�����С��
		edgeVec[minEdgeIndex].m_bSelected = true;	//����С����Ϊ��ѡ

		//3.�ҳ���С�����ӵĵ�
		int nodeAIndex = edgeVec[minEdgeIndex].m_iNodeIndexA;		//��ȡ��С�ߵ���������
		int nodeBIndex = edgeVec[minEdgeIndex].m_iNodeIndexB;		//��ȡ��С�ߵ���������

		bool nodeAIsInSet = false;				//��A�Ƿ��ڵ㼯���еı�־
		bool nodeBIsInSet = false;				//��B�Ƿ��ڵ㼯���еı�־

		int nodeAInSetLabel = -1;				//��A���ڵļ��ϵ�����
		int nodeBInSetLabel = -1;				//��B���ڵļ��ϵ�����

		//4.�ҳ������ڵĵ㼯��
		for (int i = 0; i < (int)nodeSets.size(); i++)
		{
			nodeAIsInSet=isInSet(nodeSets[i], nodeAIndex);	//�жϵ�A�Ƿ��ڵ㼯����
			if (nodeAIsInSet)	
			{
				nodeAInSetLabel = i;						//��ȡA���ڵĵ㼯�ϵ�����
			}
		}

		for (int i = 0; i < (int)nodeSets.size(); i++)
		{
			nodeBIsInSet = isInSet(nodeSets[i], nodeBIndex);//�жϵ�B�Ƿ��ڵ㼯����
			if (nodeBIsInSet)
			{
				nodeBInSetLabel = i;						//��ȡB���ڵĵ㼯�ϵ�����
			}
		}

		//5.���ݵ����ڼ��ϵĲ�ͬ������ͬ�Ĵ���
		if (nodeAInSetLabel == -1 && nodeBInSetLabel == -1)	//A��B�����ڵ㼯����
		{
			vector<int> vec;
			vec.push_back(nodeAIndex);						//��A��B�����ڵ��㼯����
			vec.push_back(nodeBIndex);
			nodeSets.push_back(vec);						//�㼯�ϴ浽��������
		}
		else if (nodeAInSetLabel == -1 && nodeBInSetLabel != -1)	//ֻ��A���ڵ㼯����
		{
			nodeSets[nodeBInSetLabel].push_back(nodeAIndex);		//��A�浽B���ڵĵ㼯����
		}
		else if (nodeAInSetLabel != -1 && nodeBInSetLabel == -1)	//ֻ��B���ڵ㼯����
		{
			nodeSets[nodeAInSetLabel].push_back(nodeBIndex);		//��B�浽A���ڵĵ㼯����
		}
		else if (nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel != nodeBInSetLabel)		//���A��B���ڵ㼯���У��Ҳ���ͬһ���㼯��
		{
			mergeNodeSet(nodeSets[nodeAInSetLabel], nodeSets[nodeBInSetLabel]);			//��B���ڵĵ㼯�Ϻϲ���A���ڵĵ㼯����
			for (int k = nodeBInSetLabel; k < (int)nodeSets.size() - 1; k++)			//ɾ��B���ڵĵ㼯��
			{
				nodeSets[k] = nodeSets[k + 1];
			}
		}
		else if (nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel == nodeBInSetLabel)   //���A��B���ڵ㼯���У���ͬһ���㼯����
		{
			continue;			//���ɻ�·������ѭ��
		}

		m_pEdge[edgeCount] = edgeVec[minEdgeIndex];			//����С����ӵ���������
		edgeCount++;										//�������еı�����1

		cout << edgeVec[minEdgeIndex].m_iNodeIndexA << "--" << edgeVec[minEdgeIndex].m_iNodeIndexB << " ";		//����ߺ�Ȩֵ
		cout << edgeVec[minEdgeIndex].m_iWeightValue << endl;
	}
}

bool CMap::isInSet(vector<int>nodeSet, int target)		//�жϵ��Ƿ��ڵ㼯����
{
	for (int i = 0; i <(int)nodeSet.size(); i++)
	{
		if (nodeSet[i] == target)
		{
			return true;
		}
	}
	return false;
}

void CMap::mergeNodeSet(vector<int> &nodeSetA, vector<int> &nodeSetB)	//�ϲ��㼯��
{
	for (int i = 0; i <(int)nodeSetB.size(); i++)
	{
		nodeSetA.push_back(nodeSetB[i]);
	}
}