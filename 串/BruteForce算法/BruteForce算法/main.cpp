/*
ģʽƥ��֮BF(Brute Force)�����㷨
*/
# include<iostream>
# include<string>

using namespace std;

int patternMatch_BF(string s, string t);
int main()
{
	string s;
	string t;

	cout << "����������:";
	cin >> s;
	cout << "�������Ӵ�:";
	cin >> t;

	int result = patternMatch_BF(s, t);
	if (result == -1)
		cout << endl << "ƥ��ʧ��" << endl;
	else cout << endl << "�Ӵ��������е�λ��Ϊ:" << result << endl;
	return 0;
}

int patternMatch_BF(string s, string t)//�����Ӵ�t�ڴ�s��һ�γ��ֵ�λ��(��1��ʼ)����t����s���Ӵ�
									   //����-1
{
	int i = 1, j = 1;
	while (i <= s.length() && j <= t.length())//��������ûɨ����
	{
		if (s[i - 1] == t[j - 1])	//��λ�����ַ���ȣ��ͱȽ���һ���ַ�
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;			
			//����iΪ�ϴ�ɨ��λ�õ���һλ��
			//���ֵ����������,i=i-(j-1)+1
			//
			j = 1;					//j��1��ʼ
		}

	}
	if (j > t.length())
		return (i - t.length());
	return -1;
}
























//bool BruteForce(string str1, string str2)
//{
//	int i = 0,j = 1;
//	while (true)
//	{
//		if (str1[i] == str2[0])
//		{
//			for (j = 1; j <(int)str2.length(); j++)
//			{
//				if (str1[j + i] == str2[j])
//				{
//
//				}
//				else
//					break;	
//			}
//			if (j == str2.length())
//				return true;
//		}
//		i++;
//		if (i == str1.length() - 1)
//			return false;
//
//	}
//}
//
//int main()
//{
//	string str1 = "I love FishC.com!";
//	string str2 = "FishC";
//
//	bool flag=BruteForce(str1, str2);
//	if (flag)
//		cout << "ƥ��ɹ�"<<endl;
//	else
//		cout << "ƥ��ʧ��"<<endl;
//
//	system("pause");
//	return 0;
//}
