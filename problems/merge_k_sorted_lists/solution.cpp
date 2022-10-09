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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2; 
        if(list2 == nullptr) return list1;

        if(list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
    
    ListNode* mergeKListsIdx(vector<ListNode*>&lists, int a, int b) {
        if(b-a == 0) return nullptr;
        if(b-a == 1) return lists[a];
        if(b-a == 2) return mergeTwoLists(lists[a], lists[b-1]);
        // if(b-a == 3) return mergeTwoLists(lists[a], mergeTwoLists(lists[a+1], lists[a+2]));
        
        return mergeTwoLists(mergeKListsIdx(lists, a, a + (b-a)/2), mergeKListsIdx(lists, a + (b-a)/2,b));
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKListsIdx(lists, 0, lists.size());        
    }
};


// k = 2 soln
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == nullptr) return list2; 
//         if(list2 == nullptr) return list1;
        
//         if(list1->val < list2->val) {
//             list1->next = mergeTwoLists(list1->next, list2);
//             return list1;
//         }
        
//         list2->next = mergeTwoLists(list1, list2->next);
//         return list2;
//     }
// };