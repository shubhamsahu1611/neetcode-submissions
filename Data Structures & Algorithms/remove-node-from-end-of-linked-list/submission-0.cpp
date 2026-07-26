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
        int sz=0;
        ListNode* curr=head;
        while(curr!=NULL){
            sz++;
            curr=curr->next;
        }
        n=(sz-n+1);
        curr=head;
        ListNode* prev=NULL;
        for(int i=0;i<n-1;i++){
            prev=curr;
            curr=curr->next;
        }
        if(curr==head) return curr->next;
        prev->next=curr->next;
        return head;
        
    }
};
