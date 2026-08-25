/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;  // Empty or single node
        }
        
        ListNode* curr = head;
        int position = 1;  // Track position (1-indexed)
        
        // Odd positions list (1st, 3rd, 5th, ...)
        ListNode* AHead = NULL;
        ListNode* Atail = NULL;
        
        // Even positions list (2nd, 4th, 6th, ...)
        ListNode* BHead = NULL;
        ListNode* Btail = NULL;
        
        while (curr != NULL) {
            // Split: Save next before breaking
            ListNode* nextnode = curr->next;
            curr->next = NULL;
            
            // Process: Check position (not value!)
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
            position++;  // Increment position for next node
        }
        
        // Merge: Connect odd list's tail to even list's head
        if (Atail != NULL) {
            Atail->next = BHead;
        }
        
        return (AHead != NULL) ? AHead : BHead;
    }
};