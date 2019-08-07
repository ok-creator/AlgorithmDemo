#pragma once

/*
	C++ ����ʵ�ֺ����
*/

#include<iostream>
#include<iomanip>
using namespace std;

enum RBTColor{RED,BLACK};	//����ö�٣�����������ɫ

template<class T>
class RBTNode				//��ڽڵ�
{
public:
	RBTColor color;			//��ɫ
	T key;					//�ؼ���(��ֵ)
	RBTNode *left;			//����
	RBTNode *right;			//�Һ���
	RBTNode *parent;		//���ڵ�

	//���캯����ʼ��
	RBTNode(T value,RBTColor c,RBTNode *p,RBTNode *l,RBTNode *r):
		key(value),color(c),parent( ),left(l),right(r){}
};

template<class T>
class RBTree				//�������
{
private:
	RBTNode<T> *mRoot;
public:
	RBTree();
	~RBTree();

	RBTNode<T>* search(T key);		//���ݹ�ʵ�֣����Һ�����м�ֵΪkey�Ľڵ�
	RBTNode<T>* iterativeSearch(T key);	//���ǵݹ�ʵ�֣����Һ�����м�ֵΪkey�Ľڵ�

	T minimum();	//������С�ڵ㣺������С�ڵ�ļ�ֵ
	T maximum();	//�������ڵ㣺������С�ڵ�ļ�ֵ

	RBTNode<T>* successor(RBTNode<T> *x);		//�ҽڵ�(x)�ĺ�̽ڵ㡣��������"�����������ֵ���ڸý��"��"��С���"
	RBTNode<T>* predecessor(RBTNode<T> *x);		//�ҽڵ�(x)��ǰ���ڵ㡣��������"�����������ֵС�ڸý��"��"�����"��

	void insert(T key);	//�����(keyΪ����ֵ�����뵽�������
	void remove(T key);	//ɾ�����(keyΪ����ֵ��

	void destroy();		//���ٺ����

	void print();		//��ӡ�����

public:
	RBTNode<T>* search(RBTNode<T>* x, T key)const;
	RBTNode<T>* iterativeSearch(RBTNode<T> *x, T key)const;
	RBTNode<T>* minimum(RBTNode<T>* tree);
	RBTNode<T>* maximum(RBTNode<T>* tree);

	void leftRotate(RBTNode<T>* &root, RBTNode<T> *x);		//����
	void rightRotate(RBTNode<T>* &root, RBTNode<T> *y);		//����

	void insert(RBTNode<T>* &root, RBTNode<T>* node);	//���뺯��
	void insertFixUp(RBTNode<T>* &root, RBTNode<T>* node);	//������������

	void remove(RBTNode<T>* &root, RBTNode<T>* node);	//ɾ������
	void removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent);	//ɾ����������

	void destroy(RBTNode<T>* &tree);	//���ٺ����
	void print(RBTNode<T>* tree, T key, int direction);		//��ӡ�����

#define rb_parent(r)	((r)->parent)		//�õ����ĸ����
#define rb_color(r)	((r)->color)			//�õ�������ɫ
#define rb_is_red(r)	((r)->color==RED)	//�жϽ���Ƿ�Ϊ��ɫ
#define rb_is_black(r)	((r)->color==BLACK)	//�жϽ���Ƿ�Ϊ��ɫ
#define rb_set_black(r)	do {(r)->color=BLACK;} while(0)	//�����ɫ���óɺ�ɫ
#define rb_set_red(r)	do {(r)->color=RED;} while(0)	//�����ɫ���óɺ�ɫ
#define rb_set_parent(r,p)	do {(r)->parent=(p);} while(0)	//���ø����
#define rb_set_color(r,c)	do {(r)->color=(c);} while(0)	//���ý����ɫΪ��ǰ��ɫ
};

template<class T>
RBTree<T>::RBTree() :mRoot(NULL)
{
	mRoot = NULL;
}

template<class T>
RBTree<T>::~RBTree()
{
	destroy();
}

/*
	���ݹ�ʵ�֣�������ֵΪkey�Ľ��
	x:	������ʼ�Ľ��
	T:	�����ļ�ֵ
	����ֵ��ָ�����ָ��
*/
template<class T>
RBTNode<T>* RBTree<T>::search(RBTNode<T>* x, T key)const
{
	/*
		1.���ڵ�Ϊ�գ�ֱ�ӷ���
		2.����ֵ���ڵ�ǰ���ļ�ֵ��ֱ�ӷ���
	*/
	if (x == NULL || x->key == key)
		return x;

	if (key < x->key)
	{
		return search(x->left, key);	//����ֵС�ڵ�ǰ���ļ�ֵ��������������
	}
	else
		return search(x->right, key);	//����ֵ���ڵ�ǰ���ļ�ֵ��������������
}

template<class T>
RBTNode<T>* RBTree<T>::search(T key)
{
	search(mRoot, key);		//�Ӹ��ڵ㿪ʼ������ֵΪkey�Ľ��
}

/*
	(�ǵݹ�ʵ��)������ֵΪkey�Ľ��
	x:	������ʼ�Ľ��
	T:	�����ļ�ֵ
	����ֵ��ָ�����ָ��
*/
template<class T>
RBTNode<T>* RBTree<T>::iterativeSearch(RBTNode<T>* x, T key)const
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
RBTNode<T>* RBTree<T>::iterativeSearch(T key)
{
	iterativeSearch(mRoot, key);
}

/*
	������С�ڵ㣨�ں����������ߣ�������Ƕ���������������ʱ���ڲ��Ѿ�����������
	tree: ��ʼ���ҵĽ��
	����ֵ��ָ�����ָ��
*/
template<class T>
RBTNode<T>* RBTree<T>::minimum(RBTNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

/*
	���Һ�����е���Сֵ
	����ֵ����С����Ӧ�ļ�ֵ
*/
template<class T>
T RBTree<T>::minimum()
{
	RBTNode<T> *p = minimum(mRoot);	//�õ���С���
	if (p != NULL)
		return p->key;

	return (T)NULL;
}

/*
	�������ֵ��Ӧ�Ľ�㣨���������Ҷˣ�
	tree����ʼ�����Ľ��
	����ֵ��ָ�����ָ��
*/
template<class T>
RBTNode<T>* RBTree<T>::maximum(RBTNode<T>* tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->right != NULL)
		tree = tree->right;

	return tree;
}

/*
	���Һ�����е����ֵ
	����ֵ�����е����ֵ
*/
template<class T>
T RBTree<T>::maximum()
{
	RBTNode<T> *p = maximum(mRoot);	//�õ����Ľ��
	if (p != NULL)
		return p->key;

	return (T)NULL;
}

/*
	���ҽ��ĺ��
	x��Ҫ���ҵĽ��
	����ֵ�����ָ��
*/
template<class T>
RBTNode<T>* RBTree<T>::successor(RBTNode<T> *x)
{
	//�����������Ϊ�գ������������е���С���
	if (x->right != NULL)
		return minimum(x->right);
	//������Ϊ�յ����
	//1.x��һ�����ӣ���x�ĺ�̽��Ϊ���ĸ����
	//2.x��һ���Һ��ӣ���x�Ǹ÷�֧����㣬���Ҹþֲ���֧�ĸ��ڵ㣬����x�ڷ�֧�����
	/*
	               O --->Ҫ��Ľ��
				 /
				O
			  /   \
			 O     O --->��������x���
	*/
	RBTNode<T> *y = x->parent;
	while ((y != NULL) && (x == y->right))	//Ϊ���㣬������ѭ��
	{
		x = y;
		y = y->parent;
	}

	return y;
}

/*
	���ҽ���ǰ��
	x��Ҫ���ҵĽ��
	����ֵ�����ָ��
*/
template<class T>
RBTNode<T>* RBTree<T>::predecessor(RBTNode<T> *x)
{
	//��������Ϊ�գ������������������
	if (x->left != NULL)
		return maximum(x->left);
	//��������Ϊ��
	//1.x��һ���Һ��ӣ���x��ǰ���ڵ�Ϊ���ĸ��ڵ�
	//2.x��һ�����ӣ���x�Ǹ÷�֧����Сֵ�����Ҹþֲ���֧�ĸ���㣬x�ڽڵ����������
	RBTNode<T>* y = x->parent;
	while ((y != NULL) && (x == y->left))
	{
		x = y;
		y = y->parent;
	}
	return y;
}

/*
	�Խ��x��������ת
	root :	�����
	x��		����ת�Ľ��
	����ʾ��ͼ(�Խڵ�x��������)��
	      px                              px
	     /                               /
	    x                               y
	   /  \      --(����)-->           / \                #
	  lx   y                          x  ry
	     /   \                       /  \
	    ly   ry                     lx  ly	 
*/
template<class T>
void RBTree<T>::leftRotate(RBTNode<T>* &root, RBTNode<T> *x)
{
	//����x���Һ���Ϊy
	RBTNode<T> *y = x->right;
	//��y��������Ϊx���Һ���
	//���y�����ӷǿգ���x��Ϊy�����ӵĸ���
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;
	//��x�ĸ�����Ϊy�ĸ���
	y->parent = x->parent;

	if (x->parent == NULL)	//���x�ĸ����ǿսڵ㣬��y��Ϊ���ڵ㣨ֻ�и��ڵ�ĸ��ײ�Ϊ�գ�
	{
		root = y;
	}
	else
	{
		if (x->parent->left == x)	//x�ڵ������ӣ���y�ڵ���ת��Ϊ����
			x->parent->left = y;
		else
			x->parent->right = y;	//x�ڵ����Һ��ӣ���y�ڵ���ת��Ϊ�Һ���
	}
	//��x��Ϊy������
	y->left = x;
	//��x�ĸ��ڵ���Ϊy
	x->parent = y;
}


/*
	�Ժ�����Ľڵ�(y)��������ת
	����ʾ��ͼ(�Խڵ�y��������)��
            py                               py
           /                                /
          y                                x
         /  \      --(����)-->            /  \                     #
        x   ry                           lx   y
       / \                                   / \                   #
      lx  rx                                rx  ry
 */
template<class T>
void RBTree<T>::rightRotate(RBTNode<T>* &root, RBTNode<T>* y)
{
	RBTNode<T> *x = y->left;

	y->left = x->right;
	if (x->right != NULL)
		x->right->parent = y;

	x->parent = y->parent;

	if (y->parent == NULL)
	{
		root = x;
	}
	else
	{
		if (y == y->parent->right)
			y->parent->right = x;
		else
			y->parent->left = x;
	}

	x->right = y;
	y->parent = x;
}

/*
	�����������������
	
	���������в���ڵ�֮��(ʧȥƽ��)���ٵ��øú�����
	Ŀ���ǽ������������һ�ź������
	
	����˵����
		root ������ĸ�
	    node ����Ľ��        // ��Ӧ���㷨���ۡ��е�z
*/
template<class T>
void RBTree<T>::insertFixUp(RBTNode<T>* &root, RBTNode<T>* node)
{
	RBTNode<T> *parent, *gparent;	//���常�׽ڵ���游�ڵ�

	//�����׽ڵ���ڣ��Ҹ��׽ڵ����ɫ�Ǻ�ɫ
	while ((parent = rb_parent(node)) && rb_is_red(parent))
	{
		//�õ��游�ڵ�
		gparent = rb_parent(parent);
		//�����ڵ����游�ڵ������
		if (parent == gparent->left)
		{
			RBTNode<T> *uncle = gparent->right;
			//Case 1: ����ڵ��Ǻ�ɫ
			if (uncle && rb_is_red(uncle))
			{
				rb_set_black(uncle);
				rb_set_black(parent);
				rb_set_red(gparent);
				node = gparent;
				continue;	//����ѭ��while
			}
			//Case 2:�����Ǻ�ɫ���ҵ�ǰ������Һ���
			if (parent->right == node)
			{
				RBTNode<T> *tmp;
				leftRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}
			//case3 �������Ǻ�ɫ���ҵ�ǰ���������
			rb_set_black(parent);
			rb_set_red(gparent);
			rightRotate(root, gparent);
		}
		else	//�����ڵ����游�ڵ���Һ���
		{
			RBTNode<T> *uncle = gparent->left;
			//Case 1:����ڵ��Ǻ�ɫ
			if (uncle && rb_is_red(uncle))
			{
				rb_set_black(uncle);
				rb_set_black(parent);
				rb_set_red(gparent);
				node = gparent;
				continue;
			}
			//Case 2�������Ǻ�ɫ���ҵ�ǰ���������
			if (parent->left == node)
			{
				RBTNode<T> *tmp;
				rightRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}
			//Case 3�� �����Ǻ�ɫ���ҵ�ǰ������Һ���
			rb_set_black(parent);
			rb_set_red(gparent);
			leftRotate(root, gparent);
		}
	}
	//�����ڵ����óɺ�ɫ
	rb_set_black(root);
}

/*
	���ڵ���뵽�������
	����˵����
		root	������ĸ��ڵ�
		node	����Ľ��
*/
template<class T>
void RBTree<T>::insert(RBTNode<T>* &root, RBTNode<T>* node)
{
	RBTNode<T> *y = NULL;
	RBTNode<T> *x = root;
	//1.�����������һ�Ŷ�������������ڵ���ӵ������������
	while (x != NULL)
	{
		y = x;		//���Ҫ������ĸ��ڵ�
		if (node->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	node->parent = y;
	if (y != NULL)
	{
		if (node->key < y->key)
			y->left = node;
		else
			y->right = node;
	}
	else
		root = node;
	//2.���ý����ɫΪ��ɫ
	node->color = RED;
	//3.������������Ϊһ�Ŷ��������
	insertFixUp(root, node);
}

/*
	�����(keyΪ�ڵ��ֵ)���뵽�������
	
	����˵����
	    tree ������ĸ����
		key ������ļ�ֵ
*/
template<class T>
void RBTree<T>::insert(T key)
{
	RBTNode<T> *z = NULL;
	//����½��ڵ�ʧ�ܣ��򷵻�
	if ((z = new RBTNode<T>(key, BLACK, NULL, NULL, NULL)) == NULL)
		return;

	insert(mRoot, z);
}

/*
	�����ɾ����������

	�ڴӺ������ɾ������ڵ��(�����ʧȥƽ��)���ٵ��øú�����
	Ŀ���ǽ������������һ�Ŷ�����

	����˵����
		root	������ĸ�
		node	�������Ľڵ�
*/
template<class T>
void RBTree<T>::removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent)
{
	RBTNode<T> *other;
	//node��Ϊ���ڵ㣬��nodeΪ�ջ���nodeΪ��ɫ
	while ((!node || rb_is_black(node)) && node != root)
	{
		//node������
		if (parent->left == node)
		{
			//�ҵ�node���ֵ�
			other = parent->right;
			if (rb_is_red(other))
			{
				//Case 1��x���ֵ�w�Ǻ�ɫ��
				rb_set_black(other);
				rb_set_red(parent);
				leftRotate(root, parent);
				other = parent->right;
			}

			if ((!other->left || rb_is_black(other->left)) &&
				(!other->right || rb_is_black(other->right)))
			{
				//Case 2:x���ֵ�w�Ǻ�ɫ����w����������Ҳ���Ǻ�ɫ��
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				//Case 3��x���ֵ�w�Ǻ�ɫ�ģ�����w�������Ǻ�ɫ���Һ���Ϊ��ɫ
				if ((!other->left || rb_is_black(other->right)))
				{
					rb_set_black(other->left);
					rb_set_red(other);
					rightRotate(root, other);
					other = parent->right;
				}
				//Case 4��x���ֵ�w�Ǻ�ɫ�ģ�����w���Һ����Ǻ�ɫ�ģ�������������ɫ
				rb_set_color(other, rb_color(parent));
				rb_set_black(parent);
				rb_set_black(other->right);
				leftRotate(root, parent);
				node = root;
				break;
			}
		}
		else
		{
			other = parent->left;
			if (rb_is_red(other))
			{
				//Case 1��x���ֵ��Ǻ�ɫ��
				rb_set_black(other);
				rb_set_red(parent);
				rightRotate(root, parent);
				other = parent->left;
			}
			if ((!other->left || rb_is_black(other->left)) &&
				(!other->right || rb_is_black(other->right)))
			{
				//Case 2: x���ֵ�w�Ǻ�ɫ����w����������Ҳ���Ǻ�ɫ�� 
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (!other->left || rb_is_black(other->left))
				{
					// Case 3: x���ֵ�w�Ǻ�ɫ�ģ�����w�������Ǻ�ɫ���Һ���Ϊ��ɫ
					rb_set_black(other->right);
					rb_set_red(other);
					leftRotate(root, other);
					other = parent->left;
				}
				// Case 4: x���ֵ�w�Ǻ�ɫ�ģ�����w���Һ����Ǻ�ɫ�ģ�����������ɫ��
				rb_set_color(other,rb_color(parent));
				rb_set_black(parent);
				rb_set_black(other->left);
				rightRotate(root, parent);
				node = root;
				break;
			}
		}
	}
	if (node)
		rb_set_black(node);
}

/*	
	ɾ���ڵ�(node),�����ر�ɾ���Ľڵ�

	����˵����
		root ������ĸ��ڵ�
		node ɾ���Ľڵ�
*/
template<class T>
void RBTree<T>::remove(RBTNode<T>* &root, RBTNode<T> *node)
{
	RBTNode<T> *child=NULL, *parent=NULL;
	RBTColor color=BLACK;
	//��ɾ���ڵ�����Һ��Ӷ���Ϊ��
	if ((node->left != NULL) && (node->right != NULL))
	{
		//��ɾ���ڵ�ĺ�̽ڵ㣬��Ϊȡ���ڵ�
		//������ȡ����ɾ���ڵ��λ�ã�Ȼ���ڽ���ɾ���ڵ�ȥ��
		RBTNode<T> *replace = node;
		//��ȡ��̽ڵ�
		replace = replace->right;
		while (replace->left != NULL)
			replace = replace->left;
		// "node�ڵ�"���Ǹ��ڵ�(ֻ�и��ڵ㲻���ڸ��ڵ�)
		if (rb_parent(node))
		{
			if (rb_parent(node)->left == node)
				rb_parent(node)->left = replace;
			else
				rb_parent(node)->right = replace;
		}
		else
			// "node�ڵ�"�Ǹ��ڵ㣬���¸��ڵ㡣
			root = replace;
		// child��"ȡ���ڵ�"���Һ��ӣ�Ҳ����Ҫ"�����Ľڵ�"��
		// "ȡ���ڵ�"�϶����������ӣ���Ϊ����һ����̽ڵ㡣
		child = replace->left;
		parent = rb_parent(replace);
		// ����"ȡ���ڵ�"����ɫ
		color = rb_color(replace);
		// "��ɾ���ڵ�"��"���ĺ�̽ڵ�ĸ��ڵ�"
		if (parent == node)
		{
			parent = replace;
		}
		else
		{
			// child��Ϊ��
			if (child)
				rb_set_parent(child, parent);
			parent->left = child;

			replace->right = node->right;
			rb_set_parent(node->right, replace);
		}

		replace->parent = node->parent;
		replace->color = node->color;
		replace->left = node->left;
		node->left->parent = replace;

		if (color == BLACK)
			removeFixUp(root, child, parent);

		delete node;
		return;
	}

	if (node->left != NULL)
		child = node->left;
	else
		child = node->right;

	parent = node->parent;
	// ����"ȡ���ڵ�"����ɫ
	color = node->color;

	if (child)
		child->parent = parent;
	// "node�ڵ�"���Ǹ��ڵ�
	if (parent)
	{
		if (parent->left == node)
		{
			parent->left = child;
		}
		else
			parent->right = child;
	}
	else
		root = child;

	if (color == BLACK)
		removeFixUp(root, child, parent);

	delete node;
}

/*
	ɾ��������м�ֵΪkey�Ľڵ�

	����˵����
		tree ������ĸ����
*/
template<class T>
void RBTree<T>::remove(T key)
{
	RBTNode<T> *node=NULL;
	// ����key��Ӧ�Ľڵ�(node)���ҵ��Ļ���ɾ���ýڵ�
	if ((node == search(mRoot, key)) != NULL)
		remove(mRoot, node);
}

template<class T>
void RBTree<T>::destroy(RBTNode<T>* &tree)
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		return destroy(tree->left);
	if (tree->right != NULL)
		return destroy(tree->right);

	delete tree;
	tree = NULL;
}

template<class T>
void RBTree<T>::destroy()
{
	destroy(mRoot);
}

/*
	��ӡ"���������"
	
	key        -- �ڵ�ļ�ֵ
	direction  --  0����ʾ�ýڵ��Ǹ��ڵ�;
	              -1����ʾ�ýڵ������ĸ���������;
	               1����ʾ�ýڵ������ĸ������Һ��ӡ�
*/
template<class T>
void RBTree<T>::print(RBTNode<T>* tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)
			cout << setw(2) << tree->key << "(B) is root" << endl;
		else
			cout << setw(2) << tree->key << (rb_is_red(tree) ? "(R)" : "(B)") << " is " << setw(2) << key << "'s" << setw(12) << (direction == 1 ? "right child" : "left child") << endl;
		print(tree->left, tree->key, -1);
		print(tree->right, tree->key, 1);
	}
}

template<class T>
void RBTree<T>::print()
{
	if (mRoot != NULL)
		print(mRoot, mRoot->key, 0);
}

