// At node 5, we can only delete its forward nodes like node 1 ... but we cannot delete node 5 or node 4 directly from node 5, so the trick is copy node 1 into node 5 and delete the node 1.

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the value of the next node into the current node
        node->val = node->next->val;
        
        // Store the next node
        ListNode* temp = node->next;
        
        // Bypass the next node
        node->next = node->next->next;
        
        // Delete the next node (optional but good practice)
        delete temp;
    }
};