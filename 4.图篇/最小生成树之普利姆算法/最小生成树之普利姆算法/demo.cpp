#include<iostream>
#include"CMap.h"
#include"Edge.h"
/*

	��С������֮����ķ�㷨��

	����˼�룺
		����ķ��Prim���㷨˼������n��������ɵ���ͨ�������У�
		����ѡ�����еĶ��㣬�����ж���ֳ��������ϣ�һ������
		�ڼ�����Ķ��㼯�ϣ���ʼʱ��ѡһ����������Ķ�������
		������Ķ��㼯�ϡ���Σ�ѡ��ߣ�Ҳ����ÿ��ѡ��һ����
		���ڼ����һ���˵��ڼ�������ɵıߣ���������������
		��ɱ�Ҫ�ǵ�ǰ��С��Ȩֵ��ÿ�����������һ������.��Ӧ
		��Ҳ�͹���һ����С�������ıߡ����Ѽ���������ж��㶼
		���뵽�˼����Ҳ�͹�����һ����С��������

	ͼ��

			A
		 /  |  \
		B - F - E
		 \ /  \	/
		  C - D

	��ţ�

	A B C D E F 
	0 1 2 3 4 5

	������Ȩֵ��

	A-B  6		A-E  5		A-F  1
	B-C  3		B-F  2
	C-F  8		C-D  7
	D-F  4      D-E  2
	E-F  9

	��Ĺ�ϵ˵����

	CMap	�õ�Node��
			�õ�Edge��
	Node���Edge��û�м̳й�ϵ��ͨ��������������ϵ

*/

int main()
{
	CMap *pMap = new CMap(6);

	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');
	Node *pNodeF = new Node('F');

	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);

	pMap->setValueToMatrixForUndirectGraph(0, 1, 6);
	pMap->setValueToMatrixForUndirectGraph(0, 4, 5);
	pMap->setValueToMatrixForUndirectGraph(0, 5, 1);
	pMap->setValueToMatrixForUndirectGraph(1, 2, 3);
	pMap->setValueToMatrixForUndirectGraph(1, 5, 2);
	pMap->setValueToMatrixForUndirectGraph(2, 5, 8);
	pMap->setValueToMatrixForUndirectGraph(2, 3, 7);
	pMap->setValueToMatrixForUndirectGraph(3, 5, 4);
	pMap->setValueToMatrixForUndirectGraph(3, 4, 2);
	pMap->setValueToMatrixForUndirectGraph(4, 5, 9);

	pMap->primTree(0);

	system("pause");
	return 0;
}