#include<iostream>
#include<string>
using namespace std;
/*
	KMP�㷨----ģʽƥ��
*/
void getNext(string t, int *next)
{
	next[0] = -1;
	int i = 0, j = -1;
	while (i < t.length())
	{
		if (j == -1 || t[i] == t[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}


int Kmp(string str1, string str2,int *next)		//KMP�㷨������
{
	int i = 0;
	int j = 0;
	while (i < (int)str1.length() && j <(int) str2.length())	//�ڽ���ǰ����ѭ��
	{
		if (-1==j || str1[i] == str2[j])	//�ж�ֵ�Ƿ����
		{
			i++;
			j++;		//��ż�1���жϺ�һλ�Ƿ����
		}
		else
			j = next[j];		//�ص�֮ǰ��jλ�������ڵ�i���бȽ�
	}
	if (j == str2.length())		//�����Ӵ�ȫ���Ƚ��꣬˵����ȫƥ��
		return (i - j);			//�����Ӵ�������������ĸ���ֵ�λ��
	else
		return -1;
}



int main()
{
	string s;
	string t;
	cout << "������������" << endl;
	cin >> s;
	cout << "�������Ӵ���" << endl;
	cin >> t;

	int *next = new int[t.length()];	//����next����

	getNext(t, next);					//��ȡnext�����Ԫ��

	int result = Kmp(s, t,next);		//����KMP�㷨
	if (-1 == result)					//���ؽ���ж�
		cout << "ƥ��ʧ�ܣ�" << endl;
	else
		cout << "�Ӵ��������е�λ��Ϊ��" << result << endl;

	system("pause");
	return 0;
}
