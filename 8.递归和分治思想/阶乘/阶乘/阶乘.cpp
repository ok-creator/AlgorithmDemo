#include<iostream>
using namespace std;

/*
	����n�Ľ׳�n��-----���õݹ�


*/

int factorial(int n)
{
	if (0 == n)
		return 1;
	else
		return n*factorial(n - 1);
}

int main()
{
	cout << "5!=" << factorial(5) << endl;

	system("pause");
	return 0;
}