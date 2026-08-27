class Solution {
public:
    int pairSum(ListNode* head) {
        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half
        ListNode* prev = NULL;
        ListNode* curr = slow;
        
        while(curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        // Step 3: Pair first half with reversed second half
        ListNode* first = head;
        ListNode* second = prev; // This is the head of reversed second half
        int maxSum = 0;
        
        while(second != NULL) {
            int twinSum = first->val + second->val;
            maxSum = max(maxSum, twinSum);
            first = first->next;
            second = second->next;
        }
        
        return maxSum;
    }
};   