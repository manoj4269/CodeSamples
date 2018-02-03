//function to create a bst from a sorted array
//This function assumes that there are no duplicates


#include "stdio.h"
#include "stdlib.h"

typedef struct treenode{
  int data;
  struct treenode *left;
  struct treenode *right;
}tree;

int main(void) {
  printf("Hello World\n");
  
  tree* createBST(int arr, int start, int end){
    if(start < end) return NULL;
    int mid = (start+end)/2;
    tree *root;
    
    root = (tree*)malloc(sizeof(tree));
    root->data = arr[mid];
    root->left = createBST(arr, start, mid-1);
    root->right = createBST(arr, mid+1, end);
    return root;
  }
  
  tree* createtree(int arr){
    int len = sizeof(arr)/sizeof(arr[0]);
    createBST(arr, 0, len);
  }

  
  return 0;
}
