/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //4 5 1 9 
        //5 
        ListNode* temp = node->next; //ye store krega ka 1
        node->val = temp->val;// 5->data = 1->data to it will be 1 ka data
        node->next = temp->next; //1->data points to 9 
        }
};