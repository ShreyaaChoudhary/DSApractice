class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(); // dummy node
        ListNode* curr = dummy;           // pointer to build new list
        ListNode* temp = head;

        while (temp != NULL) {
            // Skip all duplicates
            if (temp->next && temp->val == temp->next->val) {
                int dupVal = temp->val;
                while (temp && temp->val == dupVal) {
                    temp = temp->next;
                }
            } else {
                curr->next = temp;
                curr = curr->next;
                temp = temp->next;
                curr->next = nullptr; // important to break any old next links
            }
        }

        return dummy->next;
    }
};
