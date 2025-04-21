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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
        return nullptr;
        while(lists.size()>1){
            vector<ListNode*> res;
            for(int i = 0 ; i<lists.size(); i=i+2){
                ListNode* l1 = lists[i];
                ListNode* l2 = ((i+1)<lists.size())?lists[i+1]:NULL;
                ListNode* temp = mergetwo(l1,l2);
                res.push_back(temp);
            }
            lists = res;
        }
        return lists[0];
    }
    ListNode* mergetwo(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode* curr=&dummy;
        while(l1&&l2){
            if(l1->val>l2->val){
                curr->next = l2;
                l2 = l2->next;
            }
            else{
                curr->next = l1;
                l1 = l1->next;
            }
            curr=curr->next;
        }
        if(l1)
        curr->next = l1;
        if(l2)
        curr->next = l2;
        return dummy.next;
    }
};