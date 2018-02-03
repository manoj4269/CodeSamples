//function to check whether the bst is balanced or not

#include "stdio.h"

typedef struct treenode{
  int data;
  struct treenode *left;
  struct treenode *right;
}tree;


int main(void) {
  printf("Hello World\n");
  
  int checkheight(tree* root){
    if (root==NULL)
      return 0;
    
    int leftheight = checkheight(root.left);
    if (leftheight == -1) return -1;
    
    int rightheight = checkheight(root.right);
    if (rightheight ==-1) return -1;
    
    int heightdiff = leftheight - rightheight;
    if (abs(heightdiff) > 1) return -1;
    else {
      if (leftheight>rightheight) return leftheight+1;
      else return rightheight+1;
      
    }
  }
  
  bool isBalanced(tree *root){
    if(checkheight(root) == -1) return false;
    else return true;
  }
  
  return 0;
}
