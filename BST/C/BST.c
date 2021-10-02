// Sample Input/Output:
/*
Inorder traversal if BST :
[1]     [3]     [4]     [5]     [7]     [8]     [9]     [11]    [12]
Min Element : 1
Max Element : 12
*/

// Include header files.
#include<stdio.h>  // for using scanf & printf
#include<stdlib.h> // for using malloc

// Structure of BST.
struct BST{
	int data;
	struct BST *left;
	struct BST *right;
};
// To refer 'struct BST' as 'BST'.
struct BST typedef BST;

// createBSTNode() fucntion to allocate memory for BST.
BST * createBSTNode(int data){	
	struct BST *node = malloc(sizeof(BST));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// insert() fucntion that will insert the data,
// at right place in a BST.
BST * insert(BST *root, int data){
	BST *head = root;
	BST *node = createBSTNode(data);
	if(root == NULL){
		return node;
	}
	BST *temp;
	while(root != NULL){
		temp = root;

		if(root->data < data){
			root = root->right;
		}
		else{
			root = root->left;
		}
	}
	if(temp->data < data){
		temp->right = node;
	}
	else{
		temp->left = node;
	}

	return head;
}

// inorder() function to print the tree,
// using Inorder traversal.
void inorder(struct BST *root){
	if(root != NULL){
		inorder(root->left);
		printf("[%d]\t", root->data);
		inorder(root->right);
	}
}

// getMin() function to get the,
// minimum element from the BST.
BST *  getMin(BST * root){
	if(root == NULL)
		return root;
	while(root->left != NULL){
		root = root->left;
	}
	return root;
}

// getMax() function to get the,
// maximum element from the BST.
BST *  getMax(BST * root){
	if(root == NULL)
		return root;
	while(root->right != NULL){
		root = root->right;
	}
	return root;
}

// main() function or the driver funciton.
int main(){
	// Creating BST,
	// and inserting data in it.
	BST *root = NULL;
	root = insert(root, 7);
	insert(root, 8);
	insert(root, 1);
	insert(root, 5);
	insert(root, 3);
	insert(root, 9);
	insert(root, 11);
	insert(root, 12);
	insert(root, 4);
	
	// Printing Inorder traversal of BST.
	printf("\nInorder traversal if BST :\n");
	inorder(root);

	// Printing minimum element fron BST.
	printf("\nMin Element : %d", getMin(root)->data);
	
	// Printing maximum element fron BST.
	printf("\nMax Element : %d", getMax(root)->data);

	return 0;
}