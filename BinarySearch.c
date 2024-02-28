#include <stdio.h>
#include <stdlib.h>
#include <memory.h> 

//preorder, inorder, postorder, maxdepth

typedef struct treeNode{
	int key;
	struct treeNode *left;
	struct treeNode *right;
}treeNode;

treeNode *insert(treeNode *p, int x)
{
	treeNode *newNode;
	if(p = NULL){
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		
		return newNode;
	}
	else if(x < p->key) p->left = insert(p->left, x);
	else if(x > p->key) p->right = insert(p->right, x);
	
	return p;
}

void preorder(treeNode *root) //전위 순회 
{
	if(root){
		printf("%d", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(treeNode *root)//중위 순회 
{
	if(root){
		inorder(root->left);
		printf("%d", root->key);
		inorder(root->right);
	}
}

void postorder(treeNode *root)//후위 순회 
{
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("%d", root->key);
	}
}
int main(){
	
	treeNode *root = NULL;
	int key;
	
	root = insert(root, 8);
	insert(root, 4);
	insert(root, 12);
	insert(root, 1);
	insert(root, 6);
	insert(root, 15);
	insert(root, 5);
	insert(root, 7);
	
	preorder(root);
}
