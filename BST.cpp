#include<iostream>

#define NIL NULL

using namespace std;

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
	NODE *node = root;
	while(node != NULL)
	{
		if(node->lchild == NULL)
		{
			cout<<node->key<<endl;
			if(node->rchild != NULL)
				node = node->rchild;

			while(node != NULL && (node->rchild) == NULL)
			{
				node = node->parent;
				if (node != NULL)
				{
					cout<<node->key<<endl;
				}
			}
		}else
			node = node->lchild;
	}
}

int main(int argc, char const *argv[])
{
	NODE *root = NULL;
	build(root,5);
	build(root,4);
	build(root,1);
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

		while(tmp != NULL)
		{
			p = tmp;
			if (tmp->key > key)
			{
				tmp = tmp->lchild;
				if (tmp == NULL)
				{
					NODE *next = new NODE;
					next->key = key;
					next->lchild = NIL;
					next->rchild = NIL;
					next->parent = p;
					p->lchild = next;
				}
			}else
			{
				tmp = tmp->rchild;
				if (tmp == NULL)
				{
					NODE *next = new NODE;
					next->key = key;
					next->lchild = NIL;
					next->rchild = NIL;
					next->parent = p;
					p->rchild = next;
				}
			}
		}
	}
}












