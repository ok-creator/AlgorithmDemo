/*
	AVL����ʵ���ļ�
	�����������ת��ò���ͼƬ�������������
*/
#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

template<class T>
class AVLTreeNode		//AVL���ڵ�
{
public:
	T key;				//�ؼ��֣���ֵ��
	int height;			//�߶�
	AVLTreeNode *left;	//����
	AVLTreeNode *right;	//�Һ���
	AVLTreeNode(T value, AVLTreeNode *l,AVLTreeNode *r):
		key(value),height(0),left(l),right(r){}
};

//AVL��
template<class T>
class AVLTree
{
private:
	AVLTreeNode<T> *mRoot;		//���ڵ�
public:
	AVLTree();
	~AVLTree();
	int height();				//��ȡ���ĸ߶�
	int max(int a, int b);		//��ȡ�������е����ֵ

	void preOrder();
	void inOrder();
	void postOrder();

	AVLTreeNode<T>* search(T key);
	AVLTreeNode<T>* iterativeSearch(T key);

	T minimum();
	T maximum();

	void insert(T key);
	void remove(T key);

	void destroy();
	void print();
private:
	int height(AVLTreeNode<T>* tree);		//��ȡ���ĸ߶�

	void preOrder(AVLTreeNode<T> *tree)const;
	void inOrder(AVLTreeNode<T> *tree)const;
	void postOrder(AVLTreeNode<T> *tree)const;

	AVLTreeNode<T>* search(AVLTreeNode<T>* x, T key)const;
	AVLTreeNode<T>* iterativeSearch(AVLTreeNode<T>* x, T key)const;

	AVLTreeNode<T>* minimum(AVLTreeNode<T>* tree);
	AVLTreeNode<T>* maximum(AVLTreeNode<T>* tree);

	//LL: �����Ӧ�����������ת��
	AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T> *k2);

	//RR:���Ҷ�Ӧ��������ҵ���ת��
	AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T> *k1);

	//LR�����Ҷ�Ӧ���������˫��ת��
	AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T> *k3);

	//RL:�����Ӧ���������˫��ת��
	AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* k1);
	//���ڵ���뵽AVL����
	AVLTreeNode<T>* insert(AVLTreeNode<T>* &tree, T key);
	//ɾ��AVL���еĽ�㣬�����ر�ɾ���Ľ��
	AVLTreeNode<T>* remove(AVLTreeNode<T>* &tree, AVLTreeNode<T> *z);
	//����AVL��
	void destroy(AVLTreeNode<T>* &tree);
	//��ӡAVL��
	void print(AVLTreeNode<T> *tree, T key, int drirection);
};

//���캯��
template <class T>
AVLTree<T>::AVLTree() :mRoot(NULL)
{
}

//��������
template <class T>
AVLTree<T>::~AVLTree()
{
     destroy(mRoot);
}

//��ȡ���ĸ߶�
template<class T>
int AVLTree<T>::height(AVLTreeNode<T> *tree)
{
	if (tree != NULL)		//����Ϊ��
		return tree->height;//ֱ�ӷ������ĸ߶Ȳ���

	return 0;				//����ն������߶ȷ���0
}

template<class T>
int AVLTree<T>::height()
{
	return height(mRoot);
}

//�Ƚ�����ֵ�Ĵ�С
template<class T>
int AVLTree<T>::max(int a, int b)
{
	return a > b ? a : b;
}

//ǰ�����AVL��
template <class T>
void AVLTree<T>::preOrder(AVLTreeNode<T>* tree) const
{
	if (tree != NULL)
	{
		cout << tree->key << " ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

template <class T>
void AVLTree<T>::preOrder()
{
   preOrder(mRoot);
}

//�������AVL��
template <class T>
void AVLTree<T>::inOrder(AVLTreeNode<T>* tree) const
{
     if (tree != NULL)
     {
         inOrder(tree->left);
         cout << tree->key << " ";
         inOrder(tree->right);
     }
}

template <class T>
void AVLTree<T>::inOrder()
{
     inOrder(mRoot);
}

//�������AVL��
template <class T>
void AVLTree<T>::postOrder(AVLTreeNode<T>* tree) const
{
     if (tree != NULL)
     {
         postOrder(tree->left);
         postOrder(tree->right);
         cout << tree->key << " ";
     }
}

template <class T>
void AVLTree<T>::postOrder()
{
     postOrder(mRoot);
}

//���ݹ�ʵ�֣�����AVL���м�ֵΪkey�Ľڵ�
template <class T>
AVLTreeNode<T>* AVLTree<T>::search(AVLTreeNode<T>* x, T key) const
{
     if (x == NULL || x->key == key)
         return x;

     if (key < x->key)
         return search(x->left, key);
     else
         return search(x->right, key);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::search(T key)
{
     return search(mRoot, key);
}

/*
  * (�ǵݹ�ʵ��)����"AVL��x"�м�ֵΪkey�Ľڵ�
*/
template <class T>
AVLTreeNode<T>* AVLTree<T>::iterativeSearch(AVLTreeNode<T>* x, T key) const
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

template <class T>
AVLTreeNode<T>* AVLTree<T>::iterativeSearch(T key)
{
     return iterativeSearch(mRoot, key);
}

//������С�ڵ㣺����treeΪ���ڵ��AVL������С���
template <class T>
AVLTreeNode<T>* AVLTree<T>::minimum(AVLTreeNode<T>* tree)
{
     if (tree == NULL)
         return NULL;

     while (tree->left != NULL)
         tree = tree->left;
     return tree;
}

template <class T>
T AVLTree<T>::minimum()
{
     AVLTreeNode<T> *p = minimum(mRoot);
     if (p != NULL)
         return p->key;

     return (T)NULL;
}

//��������㣺����treeΪ���ڵ��AVL���������
template <class T>
AVLTreeNode<T>* AVLTree<T>::maximum(AVLTreeNode<T>* tree)
{
     if (tree == NULL)
         return NULL;

     while (tree->right != NULL)
         tree = tree->right;
     return tree;
}

template <class T>
T AVLTree<T>::maximum()
{
	AVLTreeNode<T> *p = maximum(mRoot);
	if (p != NULL)
		return p->key;

	return (T)NULL;
}

/*	LL :�����Ӧ�����������ת��
	����ֵ����ת��ĸ��ڵ�
		LL��ת��Χ��"ʧȥƽ���AVL���ڵ�"���еģ�Ҳ���ǽڵ�k2����������
		��LL����������������������ץ��"���ӣ���k1"ʹ��ҡ����k1��ɸ�
		�ڵ㣬k2���k1����������"k1��������"���"k2��������
*/
template<class T>
AVLTreeNode<T>* AVLTree<T>::leftLeftRotation(AVLTreeNode<T>* k2)
{
	AVLTreeNode<T> *k1;		//������ʱ�ڵ�
	k1 = k2->left;			//��k2�����ӱ�����k1��
	k2->left = k1->right;	//��k1���Һ��ӱ��k2������
	k1->right = k2;			//��k2���k1���Һ���

	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;

	return k1;				//���ص���֮��ĸ��ڵ�
}

//RR�����Ҷ�Ӧ��������ҵ���ת��
//����ֵ����ת��ĸ��ڵ�
template<class T>
AVLTreeNode<T>* AVLTree<T>::rightRightRotation(AVLTreeNode<T>* k1)
{
	AVLTreeNode<T>* k2;
	k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;

	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(height(k2->right), k1->height)+1;

	return k2;
}

//LR�����Ҷ�Ӧ�����(��˫��ת)
//����ֵ����ת��ĸ��ڵ�
template<class T>
AVLTreeNode<T>* AVLTree<T>::leftRightRotation(AVLTreeNode<T>* k3)
{
	//�ȶ�k3�����ӽ���������ת��������Ȼ��k3������
	k3->left = rightRightRotation(k3->left);	
	//�ٶ�k3����������ת��������
	return leftLeftRotation(k3);
}

//RL�������Ӧ���������˫��ת��
//����ֵ����ת��ĸ��ڵ�
template<class T>
AVLTreeNode<T>* AVLTree<T>::rightLeftRotation(AVLTreeNode<T> *k1)
{
	k1->right = leftLeftRotation(k1->right);

	return rightRightRotation(k1);
}

/*
	���ڵ���뵽AVL���У������ظ��ڵ�
	����˵����
		tree AVL���ĸ��ڵ�
		key	 ����Ľڵ�ļ�ֵ
	����ֵ��
		���ڵ�
*/
template<class T>
AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* &tree, T key)
{
	if (tree == NULL)
	{
		//������ڵ�Ϊ�գ����½��ڵ㣬�ù��캯����ʼ��
		tree = new AVLTreeNode<T>(key, NULL, NULL);
		if (tree == NULL)
		{
			cout << "ERROR:create avltree node failed!" << endl;
			return NULL;
		}
	}
	else if (key < tree->key)
	{
		//С�ڵ�ǰ��㣬������ڵ��Ͻ��в���
		tree->left = insert(tree->left, key);
		//�������֮���ж��Ƿ�����ƽ��
		if (height(tree->left) - height(tree->right) == 2)
		{
			//�жϲ����λ�ã���������ӵ���˲��룬�����LL
			//���������ӵ��Ҷ˲��룬����LR
			if (key < tree->left->key)
				tree = leftLeftRotation(tree);
			else
				tree = leftRightRotation(tree);
		}
	}
	else if (key>tree->key)
	{
		tree->right = insert(tree->right, key);
		if (height(tree->right) - height(tree->left) == 2)
		{
			if (key > tree->right->key)
				tree = rightRightRotation(tree);
			else
				tree = rightLeftRotation(tree);
		}
	}
	else		//�ڵ�ֵ�뵱ǰ����ֵ��ͬ������ʧ��
	{
		cout << "���ʧ�ܣ������������ͬ�Ľڵ㣡" << endl;
	}
	tree->height = max(height(tree->left), height(tree->right)) + 1;
	return tree;
}

template<class T>
void AVLTree<T>::insert(T key)
{
	insert(mRoot, key);		//�ڸ��ڵ�����ֵ
}

/*
	ɾ���ڵ㣨z),���ظ��ڵ�
	����˵����
		tree	AVL���ĸ��ڵ�
		z		��ɾ���Ľڵ�
	����ֵ��
		���ڵ�
*/
template<class T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* &tree, AVLTreeNode<T> *z)
{
	//��Ϊ�� ���� û��Ҫɾ���Ľڵ㣬ֱ�ӷ���NULL
	if (tree == NULL || z == NULL)
		return NULL;
	if (z->key < tree->key)		//��ɾ���Ľڵ���tree����������
	{
		tree->left = remove(tree->left, z);
		//ɾ���ڵ����AVL��ʧȥƽ��
		if (height(tree->right) - height(tree->left) == 2)
		{
			//������ʱ�ڵ�Ϊ�����ҽڵ�
			AVLTreeNode<T> *r = tree->right;
			if (height(r->left)>height(r->right))
				tree = rightLeftRotation(tree);
			else
				tree = rightRightRotation(tree);
		}
	}
	else if(z->key>tree->key)	//��ɾ���Ľڵ���tree����������
	{
		tree->right = remove(tree->right, z);
		if (height(tree->left) - height(tree->right) == 2)
		{
			AVLTreeNode<T>* l = tree->left;
			if (height(l->right) > height(l->left))
				tree = leftRightRotation(tree);
			else
				tree = leftLeftRotation(tree);
		}
	}
	else		//tree�Ƕ�ӦҪɾ���Ľڵ�
	{
		//����������Ӷ��ǿ�
		if ((tree->left != NULL) && (tree->right != NULL))
		{
			//���tree������������������
			//��(01���ҳ�tree���������е������
			//��02������������ֵ����tree
			//��03��ɾ���������
			//������������tree�������������ڵ���tree������
			//�������ַ�ʽ�ĺô��ǣ�ɾ��tree�е��������е����ڵ��AVL����Ȼ��ƽ���
			if (height(tree->left) > height(tree->right))
			{
				AVLTreeNode<T> *max = maximum(tree->left);
				tree->key = max->key;
				tree->left = remove(tree->left, max);
			}
			else
			{
				// ���tree��������������������(��������ȣ�������������������1)
				// ��(01)�ҳ�tree���������е���С�ڵ�
				//   (02)������С�ڵ��ֵ��ֵ��tree��
				//   (03)ɾ������С�ڵ㡣
				// ����������"tree������������С�ڵ�"��"tree"������
				// �������ַ�ʽ�ĺô��ǣ�ɾ��"tree������������С�ڵ�"֮��AVL����Ȼ��ƽ��ġ�
				AVLTreeNode<T>* min = maximum(tree->right);
				tree->key = min->key;
				tree->right = remove(tree->right, min);
			}
		}
		else	//������ƽ�������������Һ��Ӳ��Ϊ1������һ���߶�Ϊ0����һ���߶ȱ�ȻΪ1
		{
			AVLTreeNode<T>* tmp = tree;
			tree = (tree->left != NULL) ? tree->left : tree->right;
			delete tmp;
		}
	}
	return tree;
}

template<class T>
void AVLTree<T>::remove(T key)
{
	AVLTreeNode<T>* z;

	if ((z = search(mRoot, key)) != NULL)
		mRoot = remove(mRoot, z);
}

/*
	* ����AVL��
*/
template <class T>
void AVLTree<T>::destroy(AVLTreeNode<T>* &tree)
{
    if (tree == NULL)
        return;

    if (tree->left != NULL)
        destroy(tree->left);
    if (tree->right != NULL)
        destroy(tree->right);

	delete tree;
 }

//����AVL��
template <class T>
void AVLTree<T>::destroy()
{
	 destroy(mRoot);
}

/*
	* ��ӡ"���������"
	*
	* key        -- �ڵ�ļ�ֵ
	* direction  --  0����ʾ�ýڵ��Ǹ��ڵ�;
	*               -1����ʾ�ýڵ������ĸ���������;
	*                1����ʾ�ýڵ������ĸ������Һ��ӡ�
*/
template <class T>
void AVLTree<T>::print(AVLTreeNode<T>* tree, T key, int direction)
{
	if (tree != NULL)		//�жϵ�ǰ����Ƿ�Ϊ��
	{
		if (direction == 0)    // tree�Ǹ��ڵ�
			cout << setw(2) << tree->key << " is root" << endl;
		else                // tree�Ƿ�֧�ڵ�
			cout << setw(2) << tree->key << " is " << setw(2) << key << "'s " << setw(12) << (direction == 1 ? "right child" : "left child") << endl;
		
		print(tree->left, tree->key, -1);
		print(tree->right, tree->key, 1);
	}
}

template <class T>
void AVLTree<T>::print()
{
	if (mRoot != NULL)
		print(mRoot, mRoot->key, 0);
}