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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0 ; i < n ; i++){
            fast = fast->next;
        }
        //agr n==length of list we gotta delete head
        if(fast==NULL)
        return head->next;
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
            //jb fast reaches null tb slow reaches delete krne wale node ke 1 position phele
        }
        ListNode* nodetodelete = slow->next;
        slow->next = slow->next->next;
        delete nodetodelete;
        return head;
    }
};