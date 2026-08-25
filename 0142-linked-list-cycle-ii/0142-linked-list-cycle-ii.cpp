class Solution {
public:
    ListNode* floydDetectLoop(ListNode* head) {
        if (head == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return slow;  // Intersection point found
            }
        }
        return NULL;  // No cycle
    }
    
    // Find the start of the cycle
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL) return NULL;
        
        ListNode* intersection = floydDetectLoop(head);
        
        if (intersection == NULL) {
            return NULL;  // No cycle
        }
        
        ListNode* start = head;
        
        while (start != intersection) {
            start = start->next;
            intersection = intersection->next;
        }
        return start;  // Start of the cycle
    }
};