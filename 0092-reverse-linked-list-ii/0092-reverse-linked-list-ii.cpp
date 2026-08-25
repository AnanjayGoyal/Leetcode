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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || head->next == NULL || left == right) {
            return head;
        }
        ListNode* AHead = NULL; // Nodes before 'left'
        ListNode* Atail = NULL;
        ListNode* BHead = NULL; // Nodes from 'left' to 'right' (to be reversed)
        ListNode* Btail = NULL;
        ListNode* CHead = NULL; // Nodes after 'right'
        ListNode* Ctail = NULL;
        ListNode* curr = head;
        int position = 1;
        while (curr != NULL) {
            ListNode* nextnode = curr->next;
            curr->next = NULL;
            if (position < left) {
                if (AHead == NULL) {
                    AHead = Atail = curr;
                } else {
                    Atail->next = curr;
                    Atail = curr;
                }
            } else if (position >= left && position <= right) {
                // Goes to list B (middle part to reverse)
                if (BHead == NULL) {
                    BHead = Btail = curr;
                } else {
                    Btail->next = curr;
                    Btail = curr;
                }
            } else {
                // Goes to list C (after right)
                if (CHead == NULL) {
                    CHead = Ctail = curr;
                } else {
                    Ctail->next = curr;
                    Ctail = curr;
                }
            }

            curr = nextnode;
            position++;
        }
        // Process, Reverse list B
        ListNode* reversedB = reverse(BHead);
        // Merge, Connect A -> reversedB -> C
        if (Atail != NULL) {
            Atail->next = reversedB;
        } else {
            AHead = reversedB;
        }
        ListNode* temp = reversedB;
        while (temp != NULL && temp->next != NULL) {
            temp = temp->next;
        }
        if (temp != NULL) {
            temp->next = CHead;
        } else {
            if (Atail != NULL) {
                Atail->next = CHead;
            }
        }
        return (AHead != NULL) ? AHead : (BHead != NULL ? reversedB : CHead);
    }
};