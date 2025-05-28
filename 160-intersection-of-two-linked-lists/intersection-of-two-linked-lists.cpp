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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //APPROACH 1
        // while(headB!=NULL){
        //     ListNode* temp = headA;
        //     while(temp){
        //         if(temp==headB) return headB;
        //         temp = temp->next;
        //     }
        //     headB= headB->next;
        // }   
        // return NULL;

        //APPROACH 2
        //using hashing
        // unordered_set<ListNode*> st;
        // while(headA){
        //     st.insert(headA);
        //     headA= headA->next;
        // } 
        // while(headB){
        //     if(st.find(headB)!=st.end()) return headB;
        //     headB = headB->next;
        // }
        // return NULL;



        //optimised

        ListNode* d1 = headA;
    ListNode* d2 = headB ;
    
    while(d1 != d2) {
        d1 = d1 == NULL? headB:d1->next;
        d2 = d2 == NULL? headA:d2->next;
    }
    
    return d1;
    }
};