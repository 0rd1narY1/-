#pragma once
#ifndef __BST_H__
#define __BST_H__

typedef int bool;
#define true 1;
#define false 0;
#include<stdio.h>
#include<stdlib.h>


typedef int DataType;
typedef struct BST_Node
{
	DataType data;
	struct BST_Node *lchild, *rchild;
}BST_T, *BST_P;

void CreateBST(BST_P *root, int *arr, int len);
void DestoryBST(BST_P *root);
bool InsertBSTNode(BST_P *root, DataType data);
bool DeleteBSTNode(BST_P *root, DataType data);
BST_P SearchBST(BST_P *root, DataType data);

void MidOrderTraverse(BST_P root);

#endif // __BINARY_SORT_TREE__
