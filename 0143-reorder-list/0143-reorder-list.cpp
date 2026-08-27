// Find the middle of the linked list (using slow/fast pointers), Reverse the second half of the list, Merge the two halves alternately.
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* next = nullptr;
        
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Merge the two halves
        ListNode* first = head;
        ListNode* second = prev; // Head of reversed second half
        
        while (second->next != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};