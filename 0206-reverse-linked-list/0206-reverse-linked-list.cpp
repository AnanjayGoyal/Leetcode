class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            // Save next node
            ListNode* temp = curr->next;

            // Reverse the link
            curr->next = prev;

            // Move pointers forward
            prev = curr;
            curr = temp;
        }
        
        return prev; // New head of reversed list
    }
};