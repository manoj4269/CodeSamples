/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* compare(struct ListNode*a, struct ListNode*b){
    while(a && b){
        if(a == b) return a;
        else{
            a = a->next;
            b = b->next;
        }
    }
    return NULL;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    if (headA == NULL || headB == NULL) return NULL;
    struct ListNode *s1 = headA, *s2 = headB;
    int diff, l1 = 0, l2 = 0;
    while(s1->next!=NULL){
        l1++;
        s1 = s1->next;
    }
    //s1->next = headB;
    while(s2->next!=NULL){
        l2++;
        s2 = s2->next;
    }
    //s2->next = headA;
    if(l1 == l2) return (compare(headA, headB));
    else{
        if(l1>l2){
         diff = l1-l2;
         while(diff!=0){
             headA = headA->next;
             diff--;
          }
        return(compare(headA, headB));
        }
        else{
            diff = l2-l1;
            while(diff!=0){
                headB = headB->next;
                diff--;
            }
            return (compare(headA, headB));
        }
    }
    return NULL;
}
