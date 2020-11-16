def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if(head is None):
            return None
        if(k==0):
            return head
        
        list_len = 0
        temp = head
        
        while(temp != None):
            temp=temp.next
            list_len = list_len+1
        
        temp = head
        for i in range(0,list_len):
            if(i+1 == list_len):
                tail = temp
                break
            temp = temp.next
            
        k = k%list_len
        
        if(k==0 or list_len == 1):
            return head

        temp = head
        tail.next = temp
        steps = list_len-k
        for i in range(0, steps):
            if(i+1 == steps):
                head = temp.next
                temp.next = None
                return head
            temp = temp.next
