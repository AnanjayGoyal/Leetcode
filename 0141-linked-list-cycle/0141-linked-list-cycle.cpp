// This is not a Circular LL Problem. This is floyds loop detection.

class Solution {
public:
    bool hasCycle(ListNode* head) {

        if (head == nullptr)
            return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};