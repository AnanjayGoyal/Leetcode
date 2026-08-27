class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Handle base cases
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        
        // Determine the head of the merged list
        ListNode* head = nullptr;
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        ListNode* current = head;
        // Merge the rest
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        // Attach remaining nodes
        if (list1 != nullptr) {
            current->next = list1;
        }
        if (list2 != nullptr) {
            current->next = list2;
        }
        return head;
    }
};