#include<iostream>
using namespace std;
#include"Node.h"
#include"List.h"
#include"Person.h"
#include<string>
/*************************************************************/
//���Ա� -- ͨѶ¼
//
//��ϵ����Ϣ������ �绰


/*************************************************************/

int menu()
{
	//��ʾͨѶ¼���ܲ˵�
	cout << "���ܲ˵�" << endl;
	cout << "1.�½���ϵ��" << endl;
	cout << "2.ɾ����ϵ��" << endl;
	cout << "3.���ͨѶ¼" << endl;
	cout << "4.�˳�ͨѶ¼" << endl;

	cout << "�����룺";

	int order = 0;
	cin >> order;
	return order;
}
void createPerson(List *pList)
{
	Node node;
	cout << "������������" << endl;
	cin >> node.data.name;
	cout << "������绰��" << endl;
	cin >> node.data.phone;
	pList->ListInsertTail(&node);
}

void deletePerson(List *pList)
{
	Node node;		//��ջ�ж�����ʱ�ڵ�
	int i;			//����
	cout << "����Ҫɾ����������" << endl;
	cin >> i;
	pList->ListDelete(i, &node);	//ɾ��������ʾ�Ľڵ㣬���������
	cout << node.data.name << " �Ѿ���ɾ����";		//��ʾ��ɾ��������
}
int main(void)
{
	int userOrder = 0;
	List *pList = new List();

	while (userOrder != 4)
	{
		userOrder = menu();
		switch (userOrder)
		{
		case 1:
			cout << "�û�ָ��--->>�½���ϵ�ˣ�" << endl;
			createPerson(pList);
			break;
		case 2:
			cout << "�û�ָ��--->>ɾ����ϵ�ˣ�" << endl;
			deletePerson(pList);
			break;
		case 3:
			cout << "�û�ָ��--->���ͨѶ¼��" << endl;
			pList->ListTraverse();
			break;
		case 4:
			cout << "�û�ָ��--->�˳�ͨѶ¼��" << endl;
			break;
		default:
			break;
		}
		

	}
	delete pList;
	pList = NULL;
	system("pause");
	return 0;
}