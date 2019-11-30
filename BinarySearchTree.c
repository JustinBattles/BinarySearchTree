#include<stdio.h>
#include<stdlib.h>

struct nodeStruct {
  int data;
  struct nodeStruct *left;
  struct nodeStruct *right;
};

typedef struct nodeStruct node;

node *root = 0;

int max(node *curr) {
	while (curr->right)
		curr = curr->right;
	return curr->data;
}

int min(node *curr) {
  while (curr->left)
    curr = curr->left;
  return curr->data;
}

void inOrder(node *curr) {
	if (curr == 0) return;
	inOrder(curr->left);
	printf("%d\n", curr->data);
	inOrder(curr->right);
}

//address, value
//find the location in the tree to attach the new node containing x.
void place(node *curr, int x) {
  node *prev;
  //make a node, and put x in that node
  node *nn = malloc(sizeof(node));
  nn->data = x;
  nn->left = nn->right = 0;
  //searching for the location where we will attatch our new node
  while (curr) {//non-zero is true; also ptr to a node
    prev = curr; //keep track of the old curr
    if(x > curr->data) {
      curr = curr->right;
      
    } else {
      curr = curr->left;
    }
  }
  //loop done. prev points to the tree node where we will attach the new node.
  //prev will be the parent of the new node.
  if (x > prev->data)
	  prev->right = nn;
  else
	  prev->left = nn;
}

int main() {
  int x;
  while (scanf("%d", &x) == 1) {
    //Build the tree
    if (root == 0) {
      //get the node
      root = malloc(sizeof(node));
      //fill the 3 fields
      root->data = x;
      root->left = 0;
      root->right = 0;
    } 
    else place(root, x);
    
  }
  printf("Build is complete\n");
  inOrder(root);
  printf("Max: %d\n", max(root));
  printf("Min: %d\n", min(root));
}