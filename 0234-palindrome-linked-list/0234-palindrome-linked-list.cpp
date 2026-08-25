class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while (curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    ListNode* middle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        // Important: This finds the FIRST middle for even length
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
  
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;  
        
        ListNode* first = head;
        ListNode* mid = middle(head);      // Now mid is first middle for even length
        ListNode* second = reverse(mid->next);
        
        while (second != NULL) {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};