#include "BST.h"
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>//add this header file to detect memory leaks
#include <assert.h>

int main(int argc, char *argv[])
{
	int arr[] = { 18,10,25,16,20,8,42,9,15,32, 78, 39 };
	BST_P root = NULL;
	BST_P result = NULL;
	bool flag=0;
	
	CreateBST(&root, arr, 3);
	DestoryBST(&root);
	if (!_CrtDumpMemoryLeaks())
	{
		printf("60!\n\n");
	}
	

	CreateBST(&root, arr, 12);
	printf("Correct answer: 8, 9, 10, 15, 16, 18, 20, 25, 32, 39, 42, 78,\n");
	printf("Your answer:    ");
	MidOrderTraverse(root);
	printf("\n");

	
	result = SearchBST(&root, 54);
	assert(result == NULL);
	result = SearchBST(&root, 42);
	assert(result->data == 42);
	assert(result->lchild->data = 32);
	assert(result->rchild->data == 78);
	printf("70!\n\n");


	
	flag = InsertBSTNode(&root, 8);
	assert(!flag);
	flag = InsertBSTNode(&root, 19);
	assert(flag);
	flag = InsertBSTNode(&root, 23);
	assert(flag);
	printf("Correct answer: 8, 9, 10, 15, 16, 18, 19, 20, 23, 25, 32, 39, 42, 78,\n");
	printf("Your answer:    ");
	MidOrderTraverse(root);
	printf("\n");
	result = SearchBST(&root, 20);
	assert(result->data == 20);
	assert(result->lchild->data == 19);
	assert(result->rchild->data == 23);
	printf("80!\n\n");

	
	flag = DeleteBSTNode(&root, 99);
	assert(!flag);
	flag = DeleteBSTNode(&root, 19);
	assert(flag);
	flag = DeleteBSTNode(&root, 16);
	assert(flag);
	flag = DeleteBSTNode(&root, 8);
	assert(flag);
	flag = DeleteBSTNode(&root, 25);
	assert(flag);
	printf("Correct answer: 9, 10, 15, 18, 20, 23, 32, 39, 42, 78,\n");
	printf("Your answer:    ");	
	MidOrderTraverse(root);
	printf("\n90!\n\n");
	

	DestoryBST(&root);
	if (!_CrtDumpMemoryLeaks())
	{
		printf("100!\n");
	}
	return 0;
}



