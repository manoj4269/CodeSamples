//Finding the middle of a linked list in C

/* LOGIC
By the time fast_ptr reaches the end of the list, slow ptr will reach the middle of the list.
Hence, we return the slow pointer.
*/

//Linked List Definition
typedef struct node_type{
  int data;
  struct node_type *link;
} node;

typedef node *list;
list head;

list middle(list head){
  list fast_ptr = head;
  list slow_ptr = head;
  if (head == NULL) return;
  while (fast_ptr != NULL && fast_ptr->link != NULL) {
    fast_ptr = fast_ptr->link->link;
    slow_ptr = slow_ptr->link;
  }

  return(slow_ptr);
}
