/*
	��չ��(Splay Tree)������Ķ����������
		����������ָ�������˱����ǿö��������֮�⣬
		�����߱�һ���ص�: ��ĳ���ڵ㱻����ʱ����չ
		����ͨ����תʹ�ýڵ��Ϊ�������������ĺô�
		�ǣ��´�Ҫ���ʸýڵ�ʱ���ܹ�Ѹ�ٵķ��ʵ���
		�ڵ㡣
*/


#include<iostream>
#include"SplayTree.h"
using namespace std;

static int arr[] = { 10,50,40,30,20,60 };
#define TBL_SIZE(a) ((sizeof(a))/(sizeof(a[0])))

int main()
{
	int i, ilen;
	SplayTree<int>* tree = new SplayTree<int>();

	cout << "==������ӣ�";
	ilen = TBL_SIZE(arr);
	for (i = 0; i < ilen; i++)
	{
		cout << arr[i]<<" ";
		tree->insert(arr[i]);
	}

	cout << endl << "==ǰ�������";
	tree->preOrder();

	cout << endl << "==���������";
	tree->inOrder();

	cout << endl << "==���������";
	tree->postOrder();
	cout << endl;

	cout << "==��Сֵ��" << tree->minimum() << endl;
	cout << "==���ֵ��" << tree->maximum() << endl;
	cout << "==������ϸ��Ϣ��" << endl;
	tree->print();

	i = 30;
	cout << endl << "==��ת�ڵ�(" << i << ")Ϊ���ڵ�";
	tree->splay(i);
	cout<< "==������ϸ��Ϣ��" << endl;
	tree->print();

	tree->destroy();
	return 0;
}