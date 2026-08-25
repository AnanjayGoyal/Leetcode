class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // Delete matching nodes from the head
        while (head != NULL && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // Delete matching nodes after head
        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {

            if (curr->next->val == val) {

                ListNode* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
            else {
                curr = curr->next;
            }
        }
        return head;
    }
};