#include<iostream>
#include"stdlib.h"
#include"MyStack.h"
#include"Coordinate.h"
using namespace std;

//*********************************************************************************/
/*
	ջ ��ģ��
	Ҫ��
		����ͨջ�������ģ��ջ��ʹ����������κ���������
	Ŀ�ģ��������ջ���ƣ�����������������ջ�е�Ӧ��
*/
//*********************************************************************************/

int main(void)
{
	/*
		MyStack<Coordinate> *pStack = new MyStack<Coordinate>(5);
		pStack->push(Coordinate(1,2));		//��
		pStack->push(Coordinate(3,4));
	*/
	MyStack<char> *pStack = new MyStack<char>(5);
	pStack->push('h');		//��
	pStack->push('l');

	pStack->stackTraverse(true);

	pStack->stackTraverse(false);


	cout << pStack->stackLength() << endl;

	if (pStack->stackEmpty())
		cout << "ջΪ��" << endl;

	if (pStack->stackFull())
		cout << "ջΪ��"<<endl;

	delete pStack;
	pStack = NULL;

	system("pause");
	return 0;
}