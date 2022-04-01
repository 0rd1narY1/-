#include "BST.h"

/*
Args:
* root: The root pointer of the BST
   arr: The pointer to a integer array
   len: The length of the data, which needs to be stored in BST

Description:
* Create an BST with arr whose length is len
*/
void CreateBST(BST_P *root, int *arr, int len)
{
	int i;
	for ( i = 0; i < len; i++)
	{
		InsertBSTNode(root, arr[i]);
	}
}



/*
Args:
* root: The root pointer of the BST

Description:
* Destroy root BST, free all the memory of root BST
*/
void DestoryBST(BST_P *root)
{
	if (*root == NULL)
		return;
	else
	{
		DestoryBST(&(*root)->lchild);
		DestoryBST(&(*root)->rchild);
	}
	free(*root);
	*root = NULL;
}


/*
Args:
* root: The root pointer of the BST
  data: The data you want to insert into BST

Description:
* Insert data into the root BST,return true.
* ATTENTION: If data already exist in BST, DO NOTIHNG and return false.
*/
bool InsertBSTNode(BST_P *root, DataType data)
{
	if ((*root) == NULL)
	{
		BST_T* p = malloc(sizeof(BST_T));
		p->data = data;
		p->lchild = p->rchild = NULL;
		*root= p;
		return true;
	}
	if (SearchBST(root, data) != NULL)
		return false;
	if (data < (*root)->data)
	{
		InsertBSTNode(&(*root)->lchild, data);
	}
	else
	{
		InsertBSTNode(&(*root)->rchild, data);
	}
}


/*
Args:
* root: The root pointer of the BST
  data: The data you want to delete from BST

Description:
* Delete data from the root BST, and free the memory
* ATTENTION: If data doesn't exist in BST, DO NOTIHNG and return false.
*/
bool DeleteBSTNode(BST_P *root, DataType data)
{
	if (!*root)
	{
		return false;
	}
	else
	{
		if ((*root)->data == data)
			return Delete(root);
		else if (data < (*root)->data)
			return DeleteBSTNode(&(*root)->lchild, data);
		else
			return DeleteBSTNode(&(*root)->rchild, data);
	}
}
bool Delete(BST_P *p)
{
	BST_P q;
	if (!(*p)->lchild)
	{
		q = *p; 
		*p = (*p)->rchild; 
		free(q);
	}
	else if (!(*p)->rchild)
	{
		q = *p;
		*p = (*p)->lchild; free(q);
	}
	else
	{
		BST_P s;
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
		s = NULL;
	}
	return true;
}

/*
Args:
* root: The root pointer of the BST
  data: The data you want to search

Description:
* Search data within the root BST, and return its BST pointer
* ATTENTION: If data doesn't exist in BST, return NULL.
*/
BST_P SearchBST(BST_P *root, DataType data)
{
	if (*root==NULL)
		return NULL;
	else if (data < (*root)->data)
		return SearchBST(&(*root)->lchild, data);
	else if (data > (*root)->data)
		return SearchBST(&(*root)->rchild, data);
	else
		return *root;
}



/*
Args:
* root: The root pointer of the BST

Description:
* visualize the MidOrderTraverse of root BST
*/
void MidOrderTraverse(BST_P root)
{
	if (root!=NULL)
	{
		MidOrderTraverse(root->lchild);
		printf("%d, ", root->data);
		MidOrderTraverse(root->rchild); 
	}
}

