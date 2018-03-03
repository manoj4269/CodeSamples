struct ListNode* mergesort(struct ListNode *l, struct ListNode* r){
    struct ListNode head;
    struct ListNode *p = &head;
    while(l && r){
        if(l->val <= r->val){
            p->next = l;
            l = l->next;
        }
        
        else{
            p->next = r;
            r = r->next;
        }
        p = p->next;
    }
    p->next = (l == NULL ? r : l);
    return head.next;
}

struct ListNode* sortList(struct ListNode* head) {
    
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *s1 = head, *s2 = head->next;
    while(s2 && s2->next){
        s1 = s1->next;
        s2 = s2->next->next;
    }
    s2 = s1->next;
    s1->next = NULL;
    return mergesort(sortList(head), sortList(s2));
}
