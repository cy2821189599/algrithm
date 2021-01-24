#include<iostream>

#define NIL NULL

using namespace std;

/*************************************/
/*

二叉搜索树的构建和二叉搜索树的中序遍历

*/
/*************************************/


typedef struct NODE
{
	int key;
	NODE *parent;
	NODE *lchild;
	NODE *rchild;
}node;

/* 不考虑树的旋转(树的高度不会调整) */
void build(NODE* &root, int key);

/*中序遍历（inorder tree walk）*/
void itw(NODE *root)
{
	if(root != NULL)
	{
		itw(root->lchild);
		cout<<root->key<<endl;
		itw(root->rchild);
	}
	
}

int main(int argc, char const *argv[])
{
	NODE *root = NULL;
	build(root,5);
	build(root,4);
	build(root,1);
	build(root,10);
	build(root,9);
	build(root,11);
	build(root,8);
	itw(root);
	return 0;
}

void build(NODE* &node, int key)
{

	if (node == NULL)
	{
		node = (NODE*) malloc(sizeof(NODE));
		node->key = key;
		node->parent = NIL;
		node->lchild = NIL;
		node->rchild = NIL;
	}else
	{
		NODE *tmp = node;
		NODE *p = NULL;
		NODE *next = new NODE;
		next->lchild = NIL;
		next->rchild = NIL;

		while(tmp != NULL)
		{
			p = tmp;

			if (tmp->key > key)
			{
				tmp = tmp->lchild;
				if (tmp == NULL)
				{
					next->key = key;
					next->parent = p;
					p->lchild = next;
				}
			}else
			{
				tmp = tmp->rchild;
				if (tmp == NULL)
				{
					next->key = key;
					next->parent = p;
					p->rchild = next;
				}
			}
		}
	}
}












