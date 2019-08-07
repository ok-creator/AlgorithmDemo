#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <sys/timeb.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include "Graph.h"

#define MAX_LINE_LEN 4000

int read_file(char ** const buff, const unsigned int spec, const char * const filename);
void release_buff(char ** const buff, const int valid_item_num);

int main(int argc, char *argv[])
{
	char *topo[5000];
	int edge_num;
//	char *demand;
//	int demand_num;

	char *topo_file = "E:\\All code\\���ݽṹ\\4.ͼƪ\\��Ȩ���·���㷨\\��Ȩ���·���㷨\\11.txt";
	edge_num = read_file(topo, 5000, topo_file);
	if (edge_num == 0)
	{
		printf("Please input valid topo file.\n");
		return -1;
	}

	int src;
	cout << "���������·������㣺";
	cin >> src;

	Graph G(topo, edge_num);
	G.print();

	cout << "�㷨1: " << endl;
	G.unweightShortestPath(src);
	G.printShortestPath();

	cout << "�㷨2��" << endl;
	G.unweightShortestPathAdv(src);
	G.printShortestPath();


	release_buff(topo, edge_num);

	system("pause");
	return 0;
}

/****************************************************************
*   �������ƣ�read_file
*   ��������: ��ȡ�ļ��е�ͼ��������Ϣ
*   �����б�: buff�ǽ��ļ���ȡ��ͼ��Ϣ���浽buffָ��Ķ�ά������
*             spec���ļ���ͼ�������ıߵĸ���
*             filename��Ҫ�򿪵�ͼ�ļ�
*   ���ؽ������
*****************************************************************/
int read_file(char ** const buff, const unsigned int spec, const char * const filename)
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Fail to open file %s, %s.\n", filename, strerror(errno));
		return 0;
	}
	printf("Open file %s OK.\n", filename);

	char line[MAX_LINE_LEN + 2];
	unsigned int cnt = 0;
	while ((cnt < spec) && !feof(fp))
	{
		line[0] = 0;
		fgets(line, MAX_LINE_LEN + 2, fp);
		if (line[0] == 0)   continue;
		buff[cnt] = (char *)malloc(MAX_LINE_LEN + 2);
		strncpy(buff[cnt], line, MAX_LINE_LEN + 2 - 1);
		buff[cnt][4001] = 0;
		cnt++;
	}
	fclose(fp);
	printf("There are %d lines in file %s.\n", cnt, filename);

	return cnt;
}

/****************************************************************
*   �������ƣ�release_buff
*   ��������: �ͷŸղŶ�ȡ���ļ��е�ͼ��������Ϣ
*   �����б�: buff��ָ���ļ���ȡ��ͼ��Ϣ
*             valid_item_num��ָͼ�бߵĸ���
*   ���ؽ����void
*****************************************************************/
void release_buff(char ** const buff, const int valid_item_num)
{
	for (int i = 0; i < valid_item_num; i++)
		free(buff[i]);
}