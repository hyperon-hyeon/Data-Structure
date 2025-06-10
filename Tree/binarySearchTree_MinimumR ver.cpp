#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int key;
	Node* left;
	Node* right;
}Node;

Node* newNode(int x) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) {
		printf("Memory allocation is failed\n");
		exit(1);
	}
	node->key = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

Node* search(Node* node, int x) {
	if (node == NULL) {	printf("[Search failed] %d doesn't exist\n", x);}
	else if (node->key == x) {printf("[Search successed] %d is found\n",node->key);}
	else if (node->key <x) { search(node->right,x); }
	else if(node->key>x){ search(node->left,x); }
	return node;
}

Node* searchMin(Node* node) {
	if (node == NULL) { return NULL; }
	else if (node->left != NULL) { return searchMin(node->left); }
	return node;
}

Node* insert(Node* node, int x) {
	if (node == NULL) { node=newNode(x); }
	else if (node->key < x) { node->right=insert(node->right, x); }
	else if (node->key > x) { node->left=insert(node->left, x); }
	else if (node->key == x) {printf("%d already exist\n", x);}
	return node;
}

Node* deleteNode(Node* node, int x) {
	if (node == NULL) {
		printf("No key found to delete!\n");
		return NULL;
	}
	else if (node->key < x) { node->right=deleteNode(node->right, x); }
	else if (node->key > x) { node->left=deleteNode(node->left, x); }
	else {
		//leaf
		if (node->left == NULL && node->right == NULL) {
			printf("%d is deleting\n", node->key);
			free(node);
			return NULL;
		}
		//one child
		else if (node->left == NULL || node->right == NULL) {
			Node* temp=NULL;
			if (node->left == NULL) { 
				temp = node->right;
			}
			else if (node->right == NULL) {
				temp = node->left;
			}
			printf("%d is deleting\n", node->key);
			free(node);
			return temp;
		}
		//two children
		else {
			Node* temp=searchMin(node->right);
			printf("%d is deleting   ->   ", node->key);
			node->key = temp->key;
			node->right = deleteNode(node->right, temp->key); //new node(temp) R-subtree update
		}
	}
	return node;
}

void printInorder(Node* node) {
	if (node != NULL) {
		printInorder(node->left);
		printf("%d ", node->key);
		printInorder(node->right);
	}
}


int main()
{
	int keys[10] = { 100, 75, 150, 150, 50, 90, 120, 75, 490, 160 };
	int n_elements = (int)(sizeof(keys) / sizeof(keys[0]));

	Node* root = NULL;
	printf("[INSERT]\n");
	for (int i = 0; i < n_elements; i++) {
		printf("insert %d\n", keys[i]);
		root = insert(root, keys[i]);
	}

	printf("\n[INORDER TRAVERSAL]\n");
	printf("inorder traversal: ");
	printInorder(root);
	printf("\n");

	printf("\n[SEARCH]\n");
	Node* temp1 = search(root, 490);
	Node* temp2 = search(root, 80);

	printf("\n[DELETE]\n");
	root = deleteNode(root, 150);
	root = deleteNode(root, 100);
	root = deleteNode(root, 90);
	root = deleteNode(root, 90);

	printf("\n[INORDER TRAVERSAL]\n");
	printf("inorder traversal: ");
	printInorder(root);
	printf("\n");

	return 0;
}