#include<iostream>
using namespace std;

/*
	����������ⳤ�ȵ��ַ���--�ݹ�

	ע�������ⳤ�ȣ����������ջ

*/

void print()
{
	char a;
	cin >> a;
	if (a != '#')
		print();
	if (a != '#')
		cout << a;
}

int main()
{
	print();
	system("pause");
	return 0;
}