#include<iostream>
using namespace std;

/*
	��ŵ������---�ݹ���

*/

//��n�����Ӵ� x ���� y �ƶ��� z
void move(int n,char x,char y,char z)
{
	if (1 == n)
		cout << x << "--->" << z << endl;
	else
	{
		move(n - 1, x, z, y);			//��n-1�����Ӵ�x����z�ƶ���y��
		cout << x << "--->" << z << endl;	//�ѵ�n�����Ӵ�x�ƶ���z��
		move(n - 1, y, x, z);				//��n-1����y����x�ƶ���z��
	}

}

int main()
{
	int n;
	cout << "�����뺺ŵ���Ĳ�����" << endl;
	cin >> n;
	cout << "�ƶ��Ĳ������£�" << endl;
	move(n, 'X', 'Y', 'Z');

	system("pause");
	return 0;
}