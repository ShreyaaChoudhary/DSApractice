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
    ListNode* reverselinkedlist(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newhead = reverselinkedlist(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        bool flag = true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newhead2 = reverselinkedlist(slow); //2 1 => 1 2 head will be 1;
        ListNode* newhead1 = head;
        ListNode* second = newhead2;
        while(second!=NULL){
            if(newhead1->val!=second->val){
                flag = false;
                break;
            }
            newhead1 = newhead1->next;
            second = second->next;

        }
        return flag;
    }
};