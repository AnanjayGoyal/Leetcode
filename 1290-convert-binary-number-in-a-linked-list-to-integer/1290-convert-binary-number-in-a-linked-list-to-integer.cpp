class Solution {
public:
    int getDecimalValue(ListNode* head) {

        if(head == NULL) {
            return 0;
        }
        
        ListNode* curr = head;
        int result = 0;
        
        while(curr != NULL) {
            result = result * 2 + curr->val;
            curr = curr->next;
        }
        
        return result;
    }
};