class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr) return head;
        
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp = head;
        int count = 0;

        // Find length
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // If k is out of bounds
        if (k <= 0 || k > count) return head;
        
        // kth from end (1-indexed)
        int K_from_end = count - k;  // This gives steps to reach kth from end
        
        // Find kth node from end - we need to move (count - k) steps
        while (second != NULL && K_from_end--) {  // Changed condition
            second = second->next;
        }
        
        // Find kth node from beginning - we need to move (k-1) steps
        int k_steps = k - 1;  // Need to move k-1 steps from head
        while (first != NULL && k_steps--) {  // Changed condition
            first = first->next;
            
        }
        
        // If both nodes are same, no swap needed
        if (first == second) return head;
        
        // Swap values
        swap(first->val, second->val);
        
        return head;
    }
};