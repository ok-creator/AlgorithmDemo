#pragma once
#include<iostream>
#include<iomanip>
using namespace std;



/*
		BSTNode�Ƕ���������Ľڵ㣬����������������ļ���������Ϣ��
		(01) key -- ���ǹؼ��֣��������Զ���������Ľڵ��������ġ�
		(02) left -- ��ָ��ǰ�ڵ�����ӡ�
		(03) right -- ��ָ��ǰ�ڵ���Һ��ӡ�
		(04) parent -- ��ָ��ǰ�ڵ�ĸ���㡣
*/
template<class T>
class BSTNode
{
public:
	T key;				//�ؼ��֣���ֵ��
	BSTNode *left;		//����
	BSTNode *right;		//�Һ���
	BSTNode *parent;	//���ڵ�
	BSTNode(T value, BSTNode *p, BSTNode *l, BSTNode *r) :key(value), parent(), left(l), right(r){}
};

template<class T>
class BSTree
{
private:
	BSTNode<T> *mRoot;		//���ڵ�

public:
	BSTree();
	~BSTree();
	
	void preOrder();		//ǰ�����
	void inOrder();			//�������
	void postOrder();		//�������

	BSTNode<T>* search(T key);		//���ݹ�ʵ��)����"������"�м�ֵΪkey�Ľڵ�
	BSTNode<T>* iterativeSearch(T key);	// (�ǵݹ�ʵ��)����"������"�м�ֵΪkey�Ľڵ�

	T minimum();	// ������С��㣺������С���ļ�ֵ
	T maximum();	 // ��������㣺���������ļ�ֵ��

	BSTNode<T>* successor(BSTNode<T> *x);	 // �ҽ��(x)�ĺ�̽�㡣��������"������������ֵ���ڸý��"��"��С���"��
	BSTNode<T>* predecessor(BSTNode<T> *x);	// // �ҽ��(x)��ǰ����㡣��������"������������ֵС�ڸý��"��"�����"

	void insert(T key);		//�����(keyΪ�ڵ��ֵ)���뵽��������
	void remove(T key);		// ɾ�����(keyΪ�ڵ��ֵ)
	void destroy();			// ���ٶ�����
	void print();			// ��ӡ������
private:
	void preOrder(BSTNode<T>* tree)const;	//ǰ�����"������"
	void  inOrder(BSTNode<T>* tree)const;	// �������"������"
	void postOrder(BSTNode<T>* tree)const;	// �������"������"
	BSTNode<T>* search(BSTNode<T>* x, T key) const;	//(�ݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�
	BSTNode<T>* iterativeSearch(BSTNode<T>* x, T key) const;	// (�ǵݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�
	BSTNode<T>* minimum(BSTNode<T>* tree);		// ������С��㣺����treeΪ�����Ķ���������С���
	BSTNode<T>* maximum(BSTNode<T>* tree);		// ��������㣺����treeΪ�����Ķ������������
	void insert(BSTNode<T>* &tree, BSTNode<T>* z);		// �����(z)���뵽������(tree)��
	BSTNode<T>* remove(BSTNode<T>* &tree, BSTNode<T>* z);	// ɾ��������(tree)�еĽ��(z)�������ر�ɾ���Ľ��
	void destroy(BSTNode<T>* &tree);	// ���ٶ�����
	void print(BSTNode<T>* tree, T key, int direction);	// ��ӡ������
};

template<class T>
BSTree<T>::BSTree() :mRoot(NULL)	//���캯��
{

}

template<class T>
BSTree<T>::~BSTree()		//��������
{
	destroy();				//�������ٺ���
}

//ǰ�����������
template<class T>
void BSTree<T>::preOrder(BSTNode<T> *tree)const
{
	if (tree != NULL)					//�����㲻Ϊ��
	{
		cout << tree->key << " ";		//�������ֵ
		preOrder(tree->left);			//ǰ������������
		preOrder(tree->right);			//ǰ���������Һ���
	}
}

template<class T>
void BSTree<T>::preOrder()
{
	preOrder(mRoot);
}

//���������������ͬ�����õݹ�ķ���
template<class T>
void BSTree<T>::inOrder(BSTNode<T>* tree)const
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		cout << tree->key << " ";	//�м�������
		inOrder(tree->right);
	}
}

template<class T>
void BSTree<T>::inOrder()
{
	inOrder(mRoot);
}

//�������������
template<class T>
void BSTree<T>::postOrder(BSTNode<T>* tree)const
{
	if (tree != NULL)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->key << " ";		//���������
	}
}

template<class T>
void BSTree<T>::postOrder()
{
	postOrder(mRoot);
}

//�ݹ�ʵ�֣�����"������x"�м�ֵΪkey�Ľ��
//���ص������һ�����ҵĽ��ָ��
template<class T>
BSTNode<T>* BSTree<T>::search(BSTNode<T>* x, T key) const
{
	//xΪNULL����û�ҵ� || ��ֵ��ȱ����ҵ������ظý��
	if (x == NULL || x->key == key)
		return x;
	//��ֵС�ڽ���ֵ�����������ӣ����������Һ���
	if (key < x->key)		
		return search(x->left, key);
	else
		return search(x->right, key);
}

template<class T>
BSTNode<T>* BSTree<T>::search(T key)
{
	return search(mRoot, key);		//�Ӹ���㿪ʼ������ֵ
}

//(�ǵݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�
template<class T>
BSTNode<T>* BSTree<T>::iterativeSearch(BSTNode<T>* x, T key) const
{
	while ((x != NULL) && (x->key != key))
	{
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

template<class T>
BSTNode<T>* BSTree<T>::iterativeSearch(T key)
{
	return iterativeSearch(mRoot, key);
}

//������С��㣺����treeΪ�����Ķ���������С���
//����ߵĽ���ֵ��С��һֱ�������
template<class T>
BSTNode<T>* BSTree<T>::minimum(BSTNode<T>*tree)
{
	if (tree == NULL)		//�����ΪNULL��û�н�㣬�򷵻ؿ�
	{
		return NULL;
	}
	//���Ӳ�Ϊ��ʱ��һֱ������ֱ������Ϊ��ʱ�˳�
	while (tree->left != NULL)	
		tree = tree->left;
	return tree;
}

template<class T>
T BSTree<T>::minimum()
{
	BSTNode<T> *p = minimum(mRoot);		//pָ����Сֵ���Ǹ����
	if (p != NULL)						//�������ҷ����ڴ���ȷ
	{
		return p->key;
	}

	return (T)NULL;
}

//��������㣺����treeΪ�����Ķ������������
//���ұߵĽ���ֵ���һֱ���ұ���
template<class T>
BSTNode<T>* BSTree<T>::maximum(BSTNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}

template<class T>
T BSTree<T>::maximum()
{
	BSTNode<T> *p = maximum(mRoot);
	if (p != NULL)
		return p->key;
	return (T)NULL;
}

//�ҽ��(x)�ĺ�̽�㡣��������"������������ֵ���ڸý��"��"��С���"��
//��x��΢��һ�㣬���������Ľ��
template<class T>
BSTNode<T>* BSTree<T>::successor(BSTNode<T> *x)
{
	// ���x�����Һ��ӣ���"x�ĺ�̽��"Ϊ "�����Һ���Ϊ������������С���"
	if (x->right != NULL)
		return minimum(x->right);	
	// ���xû���Һ��ӡ���x���������ֿ��ܣ�
	// (01) x��"һ������"����"x�ĺ�̽��"Ϊ "���ĸ����"��
	// (02) x��"һ���Һ���"�������"x����͵ĸ���㣬���Ҹø����Ҫ��������"���ҵ������"��͵ĸ����"����"x�ĺ�̽��"��
	BSTNode<T>* y = x->parent;
	while ((y != NULL) && (x == y->right))
	{
		x = y;
		y = y->parent;
	}
	return y;
}

//�ҽ��(x)��ǰ����㡣��������"������������ֵС�ڸý��"��"�����"��
template<class T>
BSTNode<T>* BSTree<T>::predecessor(BSTNode<T> *x)
{
	// ���x�������ӣ���"x��ǰ�����"Ϊ "��������Ϊ���������������"��
	if (x->left != NULL)
		return maximum(x->left);
	// ���xû�����ӡ���x���������ֿ��ܣ�
	// (01) x��"һ���Һ���"����"x��ǰ�����"Ϊ "���ĸ����"��
	// (02) x��"һ������"�������"x����͵ĸ���㣬���Ҹø����Ҫ�����Һ���"���ҵ������"��͵ĸ����"����"x��ǰ�����"��
	BSTNode<T>* y = x->parent;
	while ((y != NULL) && (x == y->left))
	{
		x = y;
		y = y->parent;
	}
	return y;
}

/*
	�������뵽��������
	����˵����
		tree	�������ĸ����
		z   ����Ľ��
*/
template<class T>
void BSTree<T>::insert(BSTNode<T>* &tree, BSTNode<T>* z)
{
	BSTNode<T> *y = NULL;		//����һ���սڵ�ָ�룬�м����������
	BSTNode<T> *x = tree;		//����һ��ָ����ڵ�Ľ��ָ��
	while (x != NULL)			//��x==NULL��ʱ��x->parent=y
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if (y == NULL)			//����Ϊ��ʱ�������Ǹ�whileѭ����ִ�У�����y==NULL,ֱ�ӽ���㸳�����ڵ�
		tree = z;
	else if (z->key < y->key)
		y->left = z;		//ֵ�ȸ�С��Ϊ��ڵ�
	else
		y->right = z;		//ֵ�ȸ�С��Ϊ��ڵ�
}

template<class T>
void BSTree<T>::insert(T key)
{
	//�ü�ֵ��ʼ��һ���½�㣬Ȼ���ٲ���
	BSTNode<T>* z = NULL;
	// ����½����ʧ�ܣ��򷵻ء�
	if ((z = new BSTNode<T>(key, NULL, NULL, NULL)) == NULL)
		return;
	insert(mRoot, z);
}


/*
	ɾ�����(z)�������ر�ɾ���Ľ��
	����˵����
		tree �������ĸ����
		z ɾ���Ľ��
	������ɾ���������������:
		a)��ɾ���ڵ�zû���κ���Ů 
		b)��ɾ�ڵ�z��һ����Ů 
		c)��ɾ�ڵ�z��������Ů
*/
template<class T>
BSTNode<T>* BSTree<T>::remove(BSTNode<T>* &tree, BSTNode<T> *z)
{
	BSTNode<T> *x = NULL;
	BSTNode<T> *y = NULL;
	if ((z->left == NULL) || (z->right == NULL))	//���Һ��Ӵ���NULL
		y = z;			//ָ��yָ��Ҫɾ���Ľڵ�
	else
		y = successor(z);		
	//���Һ��Ӷ���Ϊ�գ���z�ĺ�̸���y��yΪz�������м�ֵ��С�Ľ��

	if (y->left != NULL)
		x = y->left;	
	else
		x = y->right;

	if (x != NULL)
		x->parent = y->parent;

	if (y->parent == NULL)
		tree = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;

	if (y != z)
		z->key = y->key;

	return y;
}

template<class T>
void BSTree<T>::remove(T key)
{
	BSTNode<T> *z, *node;

	if ((z = search(mRoot, key)) != NULL)
		if ((node = remove(mRoot, z)) != NULL)
			delete node;
}

//���ٶ��������ݹ�ʵ��
template<class T>
void BSTree<T>::destroy(BSTNode<T>* &tree)
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		return destroy(tree->left);
	if (tree->right != NULL)
		return destroy(tree->right);

	delete tree;		//��һ��Ҫ�ŵ������ɾ������������ɾ�������������ɾ������
	tree = NULL;		//�����ΪNULL
}

template<class T>
void BSTree<T>::destroy()
{
	destroy(mRoot);
}

/*
	��ӡ������	--	�ݹ�ʵ�֣����ж��ǲ��Ǹ��ڵ㣬Ȼ���ӡ���������ٴ�ӡ������
	key			--���ļ�ֵ
	direction	--		0,��ʾ�ýڵ��Ǹ��ڵ�;
				--		-1����ʾ�ýڵ������ĸ���������;
						1����ʾ�ýڵ������ĸ������Һ��ӡ�

*/
template<class T>
void BSTree<T>::print(BSTNode<T> *tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)
			cout << setw(2) << tree->key << "is root" << endl;
		else
			cout << setw(2) << tree->key << " is" << setw(2) << key << "'s" << setw(12) << (direction == 1 ? "right child" : "lift child") << endl;

		print(tree->left, tree->key, -1);
		print(tree->right, tree->key, 1);
	}
}

template<class T>
void BSTree<T>::print()
{
	if (mRoot != NULL)
		print(mRoot, mRoot->key, 0);
}

