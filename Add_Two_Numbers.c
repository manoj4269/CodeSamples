/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum, carry=0, fdata, sdata;
    struct ListNode*temp, *head, *l;
    temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->next=NULL;
    head = temp;
    
    while(l1!=NULL || l2!=NULL){
        if(l1!=NULL)
            fdata = l1->val;
        else
            fdata = 0;
        if(l2!=NULL)
            sdata = l2->val;
        else
            sdata = 0;
        
        sum = fdata+sdata+carry;
        carry=0;
        if(sum>=10){
            carry=1;
            sum=sum%10;
        }
        temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next->val=sum;
        temp->next->next=NULL;
        temp = temp->next;
        if (l1!=NULL)
            l1=l1->next;
        if (l2!=NULL)
            l2=l2->next;
    }
    
    if(l1==NULL && l2==NULL && carry==1){
        temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next->val=1;
        temp->next->next=NULL;
    }
    return head->next;
}
