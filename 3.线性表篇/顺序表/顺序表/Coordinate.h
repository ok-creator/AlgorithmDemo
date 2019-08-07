#pragma once
#ifndef COORDINATE_H
#define COORDINATE_H
#include<ostream>
using namespace std;


class Coordinate
{
	
public:
	friend ostream &operator<<(ostream &out, Coordinate &coor);		//������������
	Coordinate(int x=0, int y=0);	//�ڹ���ʱҪ���г�ʼ����������ֵ���ᱨ��
	void printCoordinate();
	bool operator==(Coordinate &coor);
private:
	int m_iX;
	int m_iY;
};

#endif