class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        if (head == NULL) {
            int i = 0;
            while (i < k) {
                result.push_back(NULL);
                i++;
            }
            return result;
        }
        ListNode* curr = head;
        int length = 0;
        while (curr != NULL) {
            length++;
            curr = curr->next;
        }
        int partSize = length / k;      // Minimum number of nodes each part should get
        int extraNodes = length % k;    // How many parts get 1 extra node
        curr = head;
        int partsCreated = 0;
    
        while (curr != NULL) {
            int currentPartSize = partSize + (partsCreated < extraNodes ? 1 : 0);
            ListNode* groupHead = curr;
            int count = currentPartSize - 1;

            while (count-- && curr->next != NULL) {
                curr = curr->next;
            }
            ListNode* nextGroup = curr->next;
            curr->next = NULL;
            ListNode* processedHead = groupHead;
            result.push_back(processedHead);

            curr = nextGroup;
            partsCreated++;
        }
        while (result.size() < k) {   // Fill remaining parts with NULL
            result.push_back(NULL);
        }
        return result;
    }
};