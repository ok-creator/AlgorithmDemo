#include<iostream>
using namespace std;

/*
	�˻ʺ�����----�ݹ���

*/

int count1 = 0;		//count1��ʾ�ܵĿ����Ե�������Ϊ�����ͻ��ĩβ���˸�1

bool notDanger(int row, int  j, int(*chess)[8])			//����������� �� ��ָ�� ���ж��Ƿ���Σ��
{	
	//i��k����������
	//flag����ʾ�ڲ�ͬ�������Ƿ��ͻ�ı�־
	int i,k,flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0,flag5 = 0;

	//�ж��з���
	for (i = 0; i < 8; i++)
	{
		if (*(*(chess + i) + j) != 0)		//�ӵ�һ�е����һ�У�����ɨ��
		{
			flag1 = 1;
			break;
		}
	}

	//�ж����Ϸ�
	for (i = row, k = j; i >= 0 && k >=0; i--, k--)
	{
		if (*(*(chess + i) + k) != 0)		//����������ͬ����1����ʾб45�ȷ���
		{
			flag2 = 1;
			break;
		}
	}

	//�ж����·�
	for (i = row, k = j; i <8 && k <8; i++, k++)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag3 = 1;
			break;
		}
	}

	//�ж����Ϸ�
	for (i = row, k = j; i>=0&& k <8; i--, k++)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag4 = 1;
			break;
		}
	}

	//�ж����·�
	for (i = row, k = j; i<8 && k >=0; i++, k--)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag5 = 1;
			break;
		}
	}
	if (flag1 || flag2 || flag3 || flag4 || flag5)
	{
		return false;
	}
	{	
		return true;		//��5����־��Ϊ1����ʾû��Σ��ʱ���ŷ���
	}
}

void EightQueen(int row,int n,int (*chess)[8])			//�������壬�������У��У���ָ��
{
	//����row����ʾ��ʼ��
	//����n����ʾ����
	//����chess��ʾָ������ÿһ�е�ָ��
	int chess2[8][8],i,j;	//����һ����ʱ������
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8;j++)
		{
			chess2[i][j] = chess[i][j];	//��ʱ���̴洢��ǰ��������
		}
	}

	if (8 == row)						//�ݹ��������
	{
		cout << "��" << (count1 + 1 )<< "��" << endl;
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				cout<<*(*(chess2+i)+j)<<" ";	//�����ֽ��
			}
			cout << endl;
		}
		cout << endl;
		count1++;
	}
	else										//�ݹ�û�н���
	{
		//�ж����λ���Ƿ���Σ�գ����û��Σ�գ���������
		for (j = 0; j < n; j++)
		{
			if (notDanger(row,j,chess))			//�жϵ�ǰλ���Ƿ�Σ��
			{
				for (i = 0; i < 8; i++)
				{
					*(*(chess2 + row) + i) = 0;		//���������Ԫ�ض���Ϊ0
				}
				*(*(chess2 + row) + j)=1;
				EightQueen(row + 1, n, chess2);		//��������һ��Ѱ�Һ���λ��
			}
		}
	}
}


int main()
{
	int chess[8][8];				//��������

	for (int i = 0; i < 8; i++)		//��ʼ�����̣�0��ʾû�з��κζ���
	{
		for (int j = 0; j < 8; j++)
		{
			chess[i][j] = 0;
		}
	}
	EightQueen(0,8,chess);			//���ú������ӵ�һ�п�ʼ

	cout << "�ܹ���" << count1 << "�ֽ��������" << endl << endl;

	system("pause");
	return 0;
}