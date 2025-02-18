#include <stdlib.h>
#include <stdio.h>
struct BSTNode
{
	int data;
	struct BSTNode* left;
	struct BSTNode* right;
}; 
typedef struct BSTNode BSTNode;
BSTNode* Insert(BSTNode* root,int data);
BSTNode* getnewnode(int data);
int search(BSTNode* root,int data);
int findmin(BSTNode* root);
int max(int a,int b);
int findheight(BSTNode* root);

int main()
{
	BSTNode* root=(BSTNode*)malloc(sizeof(BSTNode));
	root=NULL;
	root=Insert(root,5);
	root=Insert(root,8);
	root=Insert(root,10);
	root=Insert(root,15);
	root=Insert(root,19);
	root=Insert(root,21);
	printf("%d",search(root,21));
}


BSTNode* getnewnode(int data)
{
	BSTNode* newnode=(BSTNode*)malloc(sizeof(BSTNode));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
BSTNode* Insert(BSTNode* root,int data)
{
	if(root==NULL) root=getnewnode(data);
	else if(data<root->data) root->left=Insert(root->left,data);
	else if(data>root->data) root->right=Insert(root->right,data);
	return root;
}
int search(BSTNode* root,int data)
{
	if(root==NULL) return -1;
	if(root->data==data) return 1;
	else if(data>root->data) return search(root->right,data);
	else if(data<root->data) return search(root->left,data);
}
int findmin(BSTNode* root)
{
	if(root==NULL) return -1;
	else if(root->left==NULL) return root->data;
	return findmin(root->left);
}
int max(int a,int b)
{
	if(a>=b)return a;
	else return b;
}
int findheight(BSTNode* root)
{
	if(root==NULL) return -1;
	return max(findheight(root->left),findheight(root->right))+1;
}
