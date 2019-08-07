#include<stdio.h>
#include<iostream>
#include<malloc.h>

using namespace std;

typedef struct node
{
	float coef;		//����ʽϵ��
	int expn;			//����ʽָ��
	node *next;		//ָ����һ���ڵ��ָ��
}Lnode,*Dxs;		//����ڵ��ָ�����ָ��


//��������
Dxs create();
Dxs add_dxs(Dxs firsta, Dxs firstb);
void printDxs(Dxs h);
//void deleteNode(Dxs h, Dxs p);


int main()
{
	Dxs ha, hb, hc;			//�����һ������ʽha���ڶ�������ʽhb���ṹ����ʽhc
	cout << "�����������һ������ʽ��ϵ����ָ��\n" << endl;
	ha = create();
	cout << "����������ڶ�������ʽ��ϵ����ָ��\n" << endl;
	hb = create();
	cout << "����ĵ�һ������ʽ�ǣ�" << endl;
	printDxs(ha->next);
	cout << "����ĵڶ�������ʽ�ǣ�" << endl;
	printDxs(hb->next);
	hc = add_dxs(ha, hb);
	cout << "��������ʽ�ĺ�Ϊ��" << endl;
	printDxs(hc->next);

	system("pause");
	return 0;
}

//������������������0 0������
Dxs create()
{
	float coef;				//����ϵ������
	int expn;					//����ָ������
	Dxs first, qa, s;			//��������ָ�룬firstΪͷ���ָ�룬qaΪ��ǰ���ָ�룬sΪ�½��ڵ�ָ��
	first = (Dxs)malloc(sizeof(Lnode));			//Ϊͷ�������ڴ�
	first->coef = -1;										//ͷ���ϵ����Ϊ-1
	first->expn = -1;										//ͷ���ָ����Ϊ-1
	first->next = NULL;									
	qa = first;													//��ͷ���ָ�봫��qa
	while (1)
	{
		cin >> coef;											//����ϵ��
		cin >> expn;										//����ָ��
		if (coef == 0 && expn == 0)				//ϵ����ָ��ͬʱΪ0����ʾ�������
		{
			break;
		}
		s = (Dxs)malloc(sizeof(Lnode));			//Ϊ�½������ڴ�
		s->coef = coef;									//Ϊ�½���ϵ����ֵ
		s->expn = expn;									//Ϊ�½���ָ����ֵ
		s->next = NULL;							
		qa->next = s;										//ʹͷ����nextָ��ָ���½��
		qa = s;													//���½�㴫��qa
	}
	return first;												//����ͷ���
}

//�������
Dxs add_dxs(Dxs firsta, Dxs firstb)
{
	//����5���ڵ�ָ��
	// first:	Ϊ�������ʽ��ͷ����ָ��
	// ha:	Ϊ��һ������ʽ��ǰ����ָ��
	// hb:	Ϊ�ڶ�������ʽ��ǰ����ָ��
	// hc:	Ϊ����������ʽ��ǰ����ָ��
	// s:		Ϊ�½�����ָ��
	Dxs firstc, ha, hb, pc, s;							
	int a, b;														//���ϵ����ָ��			
	float sum;													//�����ӵĺ�
	firstc = (Dxs)malloc(sizeof(Lnode));			//Ϊ��һ���ڵ�����ڴ�
	firstc->coef = -1;										//��һ�����ĳ�ֵ��Ϊ-1
	firstc->expn = -1;
	firstc->next = NULL;
	pc = firstc;												//��ͷ���ָ�봫��pc

	ha = firsta->next;									//��ȡ��һ������ʽ��ͷ���֮��Ľ��
	hb = firstb->next;									//��ȡ�ڶ�������ʽ��ͷ���֮��Ľ��
	while (ha != NULL && hb != NULL)		//����ڵ��ָ�붼��Ϊ��
	{
		a = ha->expn;										//��ȡ��ǰ����ָ��
		b = hb->expn;
		if (a < b)												//���ָ��С��
		{	
			//��a���뵽c�У��ƶ�a��c��ָ��
			pc->next = ha;
			pc = pc->next;
			ha = ha->next;
		}
		else if (a > b)									//���ָ������
		{
			//��b���뵽C�У��ƶ�b��c��ָ��
			pc->next = hb;
			pc = pc->next;
			hb = hb->next;
		}
		else													//���ָ�����
		{
			sum = ha->coef + hb->coef;		//ϵ�����
			if (sum != 0.0)								//����Ͳ�Ϊ0
			{
				//���ͼ���a�У��ٽ�a����c�У��ƶ�C��ָ��
				ha->coef = sum;
				pc->next = ha;
				pc = pc->next;
			}
			else
			{
				//����ɾ��A��ϵ��֮��Ϊ0���Ǹ��ڵ�
				s = firsta;
				while (s != ha)
				{
					s = s->next;
				}
				s->next = ha->next;
			}
			//ab�Ѿ�������ɣ�ͬʱ����һλ
			ha = ha->next;
			hb = hb->next;
		}
	}
	//��ʣ�ಿ�ּ��뵽c����
	if (ha != NULL)
	{
		pc->next = ha;
	}
	if (hb != NULL)
	{
		pc->next = hb;
	}
	return firstc;				//���ؽ������ʽ��ͷ���
}

//������ʾ����
void printDxs(Dxs h)
{
	while (h != NULL)
	{	
		if (h->next == NULL || h->next->coef<0)
		{
			cout << h->coef << "X^" << h->expn;
		}
		else
		{
			cout << h->coef << "X^" << h->expn << "+";
		}
		h = h->next;
	}
	cout << endl;
}

