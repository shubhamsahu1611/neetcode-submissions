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
    void reorderList(ListNode* head) {
        ListNode* curr=head;
        ListNode* tail=head;
        map<ListNode*, ListNode*> parent;
        int len=0;
        while(tail->next!=NULL){
            parent[tail->next]=tail;
            len++;
            tail=tail->next;
        }
        int count=(len+1)/2;
        while(count--){
            ListNode* temp=curr->next;
            ListNode* pt=parent[tail];
            curr->next=tail;
            tail->next=temp;
            curr=temp;
            tail=pt;
        }
        curr->next=NULL;
    }
};
