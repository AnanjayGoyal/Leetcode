// Slow and Fast Pointers, initialise fast pointer with a gap of n, when the fast pointer will reach the end of the list, the slow pointer will be at nth node from the end of the list.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        // Moving fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            if (fast == NULL)
                return head;
            fast = fast->next;
        }
        
        // Remove head
        if (fast == NULL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        
        // Move both pointers until fast reaches the end
        while (fast != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        // Remove the node
        prev->next = slow->next;
        delete slow;
        return head;
    }
};