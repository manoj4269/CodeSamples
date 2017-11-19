/* Binary Search Trees:
The number of comparisons to find an element is proportional to the height of the tree.
In any tree with n nodes, there'll be (n-1) edges.
Trees with worst case height of O(log n) are called as balanced search Trees.

Time Complexiety:
OPERATION    Best Case    Worst Case
FIND           n           log n
INSERT         n           log n
DELETE         n           log n
MIN            1           log n
MAX            1           log n
PRINT SORTED   n            n
UNION          n            n
INTERSECTION   n            n

AVL Trees: These are the balanced search trees which follow the following condition:
          |(Height(LEFT-SIDE) - Height(RIGHT-SIDE))| <= 1

*/

// structure of a Tree
typedef struct node_type{
  int data;
  struct node_type *left, *right;
} node;

typedef node *tree; //the variable of tree type represents a pointer which points to the tree structure

//function to find a node in a tree
tree find(tree temp, int val){    //returns the pointer of the node of val or if it isn't present, it returns the parent pointer where it can be inserted
  if (temp == NULL) return;
  else{
    if(temp->data == val) return(temp);
    else{
      if (val < temp->data){   //if the given value is lesser than that of the node, go to the left branch
        if(temp->left == NULL) return(temp); //if the value isn't there, return a pointer of the parent so that it can be inserted
        else return(find(temp->left, val));
      }
      else{
        if(temp->right == NULL) return(temp); //if the given value is greater than that of the node, go to the right branch
        else return(find(temp->right, val)); //if the value isn't there, return a pointer of the parent so that it can be inserted
      }
    }
  }
}


//function to insert a node in the tree
void insert(tree temp, int val){  //the pointer to the root and value to be inserted are passed
  tree place, newp;
  place = find(temp, val);
  if (place == NULL){ //if there is no tree at all, create a node and makee it the root of the tree
    newp = (tree)malloc(sizeof(tree));
    newp->data = val;
    newp->left = NULL;
    newp->right = NULL;
  }
  else{
    if (place->data == val) return; //if the value is equal, do nothing (if duplicates are allowed, then increment a counter)
    else{
      if(val<place->data){  //if the val is smaller than the node data, create another node to the left and store the value in it.
        place->left = (tree)malloc(sizeof(tree));
        place->left->data = val;
        place->left->left = NULL;
        place->left->right = NULL;
      }
      else{
        if(val>place->data){  //if the val is greater than the node data, create another node to the right and store the value in it.
          place->right = (tree)malloc(sizeof(tree));
          place->right->data = val;
          place->right->left = NULL;
          place->right->right = NULL;
      }
    }
  }
}
}



//to find the minimum value in a BST
int find_min(tree temp){
  if(temp == NULL) return (-1);
  else{
    if(temp->left == NULL) return(temp);
    else return(find_min(temp->left)); //recursively call the function till you reach the bottom left most element of the tree
  }
}


//to find the maximum value in a BST
int find_max(tree temp){
  if(temp == NULL) return (-1);
  else{
    if(temp->right == NULL) return(temp);
    else return(find_max(temp->right)); //recursively call the function till you reach the bottom right most element of the tree
  }
}


//to print(or to get) a tree in ascending order
void show_tree(tree temp){   //time complexiety = O(n)
  if (temp == NULL) return;
  else{
    show_tree(temp->left);  // recursively complete the left branch and then complete the right branch
    printf("%d  ", temp->data);
    show_tree(temp->right);
  }
}


//inorder travesal => used in printing the tree in sorted order
void inorder(tree temp){
  if (temp == NULL) return;
  else{
    inorder(temp->left);
    printf("%d  ",temp->data);
    inorder(temp->right);
  }
}

//pre-order traversal
void pre_order(tree temp){
  if (temp == NULL) return;
  else{
    printf("%d ", temp->data);
    pre_order(temp->left);
    pre_order(temp->right);
  }
}

//post-order => used to solve problems mentioned in the postfix notation. Eg: 453+*
void post_order(tree temp){
  if (temp == NULL) return;
  else{
    post_order(temp->left);
    post_order(temp->right);
    printf("%d ", temp->data);
  }
}
