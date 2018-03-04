/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head) {
    
    struct ListNode *prev = NULL, *curr = head, *nxt=NULL;
    if (head == NULL) return NULL;
    else if(head->next == NULL) return head;
    while(curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
    
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL) return NULL;
    if (head->next == NULL && n==1) return NULL;
    int len = 0, diff, i;
    struct ListNode *s1, *s2, *s3;
    s1 = reverse(head);
    s2 = s1;
    if(n==1){
            s3 = s1;
            s1 = s1->next;
            return (reverse(s1));
        }
    for(i=1;i<n;i++){
        
        if(i+1 == n && s1->next == NULL){
            return (reverse(s2));
        }
        else if(i+1 == n){
            s3 = s1->next;
            s1->next = s1->next->next;
            free(s3);
            return (reverse(s2));
        }
        s1 = s1->next;
    }
    return (NULL);
}
