#pragma once
#define MAXVEX 100



class  MyGraph
{
	MyGraph(int v,int e,bool f);
	void CreateGraph();
private:
	char vexs[MAXVEX];			//�����
	int arc[MAXVEX][MAXVEX];	//�ڽӾ���
	int numVertexes, numEdges;	//ͼ�е�ǰ�Ķ������ͱ���
	bool flag;					//��־���ж�ͼ�Ƿ�������ͼ,false����������ͼ
};