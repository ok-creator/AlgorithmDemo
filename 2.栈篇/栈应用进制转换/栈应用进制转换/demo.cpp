#include<iostream>
#include<stdlib.h>
#include"MyStack.h"
using namespace std;

//*************************************************************//
/*
	ջӦ��--����ת��

	���������������ʮ����������N���ֱ����������N�Ķ����ơ��˽��ơ�ʮ�����Ƶ���

	��ʽ��N=��N div d) *d +N mod d  (div��ʾ������mod��ʾ����)
	Ŀ�ģ�ͨ��ʵ���������ջ���Ƶ�ʹ�ü���
*/
//*************************************************************//
/*
#define BITARY 2
#define OCTONARY 8
#define HSXADECIMAL 16
*/


int main(void)
{
	system("color 2E");
	char num[] = { "0123456789ABCDEF" };
	MyStack<int> *pStack = new MyStack<int>(30);
	int N = 0,flag;
	cout << "������Ҫת��������" << endl;
	cin >> N;
	cout << "������Ҫת���Ľ���(2��8��16����" << endl;
	cin >> flag;
	int mod = 0;
	while (N!=0)
	{
		mod = N % flag;
		pStack->push(mod);
		N = N / flag;
	}

	//pStack->stackTraverse(false);
	/*for (int i = pStack->stackLength() - 1; i >= 0; i--)
	{
		num[pStack[i]]
	}*/
	int elem = 0;
	while (!pStack->stackEmpty())
	{
		pStack->pop(elem);
		cout<<num[elem];
	}
	cout << endl;
	delete pStack;
	pStack = NULL;

	system("pause");
	return 0;
}