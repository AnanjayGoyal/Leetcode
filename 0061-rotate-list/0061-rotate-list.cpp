// 2 Pointers Approach 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        
        ListNode* curr = head;
        int length = 0;
        while (curr != NULL) {
            length++;
            curr = curr->next;
        }
        
        // Optimise k 
        k = k % length;
        if (k == 0) {
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Move fast pointer k steps ahead
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches the last node
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Step 4: Rotate the list
        ListNode* newHead = slow->next;  // New head after rotation
        slow->next = NULL;                // Break the list
        fast->next = head;                // Connect last node to original head
        
        return newHead;
    }
};