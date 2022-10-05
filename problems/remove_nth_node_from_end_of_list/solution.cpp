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
        if(head->next == nullptr) return nullptr;
        ListNode *i=head;
        short sz = 1;
        
        while(i->next != nullptr) {
            i = i->next; sz++; 
        }
        if(sz-n == 0) return head->next;
        
        i = head;
        for(int x=0;x<sz-n-1;x++) i = i->next;
        i->next = i->next->next;
        
        return head;
    }
};