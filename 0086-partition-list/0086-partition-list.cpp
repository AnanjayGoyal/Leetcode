class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* curr = head;
        ListNode* AHead = NULL;  
        ListNode* Atail = NULL;  
        ListNode* BHead = NULL;  
        ListNode* Btail = NULL;  
        
        while (curr != NULL) {
            
            ListNode* nextnode = curr->next;
            curr->next = NULL;
            
            if (curr->val < x) {  // Goes to list A
                if (AHead == NULL) {
                    AHead = Atail = curr;
                } else {
                    Atail->next = curr;
                    Atail = curr;
                }
            } else {  // Goes to list B
                if (BHead == NULL) {
                    BHead = Btail = curr;
                } else {
                    Btail->next = curr;
                    Btail = curr;
                }
            }
            curr = nextnode;
        }
        
        // Merge, Connect list A's tail to list B's head
        if (Atail != NULL) {
            Atail->next = BHead;
        }
        
        return (AHead != NULL) ? AHead : BHead;
    }
};