#pragma once
#ifndef MYSTACK_H
#define MYSTACK_H
//Դ�ļ���ʵ���ļ�����һ�𣬷�ֹ������

template<typename T>
class MyStack
{
public:
	MyStack(int szie);		//�����ڴ��ʼ��ջ�ռ䣬�趨ջ������ջ��
	~MyStack();				//����ջ�ռ��ڴ�
	bool stackEmpty();		//�ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ���true,�ǿշ���FALSE
	bool stackFull();		//�ж�ջ�Ƿ�Ϊ����Ϊ������true,��������FALSE
	void clearStack();		//���ջ
	int stackLength();		//����Ԫ�صĸ���
	void push(T elem);	//Ԫ����ջ��ջ������
	void pop(T &elem);	//Ԫ�س�ջ��ջ���½�
	void stackTraverse(bool isFromButtom);	//����ջ������Ԫ��

private:
	T *m_pBuffer;		//ջ�ռ�ָ��,����Ҫ�����ݵ�����һ��
	int m_iSize;			//ջ����
	int m_iTop;				//ջ����ջ��Ԫ�ظ���
};

template<typename T>
MyStack<T>::MyStack(int size)
{
	m_iSize = size;
	m_pBuffer = new T[size];
	m_iTop = 0;
}

template<typename T>
MyStack<T>::~MyStack()
{
	delete[]m_pBuffer;
}

template<typename T>
bool MyStack<T>::stackEmpty()
{
	if (m_iTop == 0)	//if(0==m_iTop)	д�ɺ�һ����ʽ��д����=ϵͳ�ᱨ��ǰ��Ĳ���
		return true;
	else
		return false;
}

template<typename T>
bool MyStack<T>::stackFull()
{
	if (m_iTop >= m_iSize)
		return true;
	return false;
}

template<typename T>
void MyStack<T>::clearStack()
{
	m_iTop = 0;
}

template<typename T>
int MyStack<T>::stackLength()
{
	return m_iTop;
}

template<typename T>
void MyStack<T>::push(T elem)
{
	if (stackFull())
	{
		cout << "ջ�������޷�ѹջ" << endl;
		return;
	}
	m_pBuffer[m_iTop++] = elem;
}

template<typename T>
void MyStack<T>::pop(T &elem)
{
	if (stackEmpty())
	{
		cout << "ջΪ�գ��޷�����Ԫ��" << endl;
		return;
	}
	elem = m_pBuffer[--m_iTop];
}

template<typename T>
void MyStack<T>::stackTraverse(bool isFromButtom)
{
	if (isFromButtom)
	{
		for (int i = 0; i < m_iTop; i++)
		{
			cout << m_pBuffer[i];
			//m_pBuffer[i].printCoordinate();
		}
	}
	else
	{
		for (int i = m_iTop - 1; i >= 0; i--)
		{
			cout << m_pBuffer[i];
			//m_pBuffer[i].printCoordinate();
		}
	}

}
#endif