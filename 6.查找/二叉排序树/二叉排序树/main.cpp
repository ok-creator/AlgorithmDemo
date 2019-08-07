#include<iostream>
#include"BSTree.h"
using namespace std;

static int arr[] = { 1,5,4,3,2,6 };
#define TBL_SIZE(a) ((sizeof(a))/(sizeof(a[0])))

int main()
{
	int i, ilen;
	BSTree<int>* tree = new BSTree<int>();

	cout << "==������ӣ�";
	ilen = TBL_SIZE(arr);
	for (i = 0; i < ilen; i++)
	{
		cout << arr[i] << " ";
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

	cout << endl << "==ɾ���ڵ�: " << arr[3];
	tree->remove(arr[3]);

	cout << endl << "==���������";
	tree->inOrder();
	cout << endl;

	tree->destroy();

	return 0;

}
