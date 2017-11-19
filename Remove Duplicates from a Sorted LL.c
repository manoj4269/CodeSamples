//Remove duplicate element from sorted Linked List

//Linked List Definition
typedef struct node_type{
  int data;
  struct node_type *link;
} node;

typedef node *list;
list head;


list delete(list fst_ptr, list sec_ptr){
  list temp;
  fst_ptr->link = sec_ptr->link; //point the link of the first node to the next to next node
  temp = sec_ptr->link; //store this pointer to next to next node in a temp variable (fst->link can also be used instead)
  free(sec_ptr); //free the node that is deleted
  sec_ptr = temp; //make the sec_ptr to point to the new node
  return(sec_ptr);
}

void remove_dups(list head){
  list fst_ptr = head;
  list sec_ptr = head->link;
  if(head == NULL) return;
  else{
    while(sec_ptr != NULL){
      if(fst_ptr->data == sec_ptr->data){
        sec_ptr = delete(fst_ptr, sec_ptr);
      }
      else{
        fst_ptr = sec_ptr; //if the elements are not equal, move the fst_ptr further through the list
        sec_ptr = sec_ptr->link; //move the sec_ptr ahead as well
      }
    }
  }
}
