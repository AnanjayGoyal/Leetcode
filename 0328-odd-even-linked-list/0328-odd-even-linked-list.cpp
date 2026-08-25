class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head; 
        }
        ListNode* curr = head;
        int position = 1;  // Track position 

        ListNode* AHead = NULL;
        ListNode* Atail = NULL;
        ListNode* BHead = NULL;
        ListNode* Btail = NULL;
        
        // Split
        while (curr != NULL) {
            ListNode* nextnode = curr->next;
            curr->next = NULL;
            // Process
            if (position % 2 != 0) {  // Odd position → List A
                if (AHead == NULL) {
                    AHead = Atail = curr;
                } else {
                    Atail->next = curr;
                    Atail = curr;
                }
            } else {  // Even position → List B
                if (BHead == NULL) {
                    BHead = Btail = curr;
                } else {
                    Btail->next = curr;
                    Btail = curr;
                }
            }
            curr = nextnode;
            position++;  
        }
        
        // Merge, Connect odd list's tail to even list's head
        if (Atail != NULL) {
            Atail->next = BHead;
        }
        return (AHead != NULL) ? AHead : BHead;
    }
};