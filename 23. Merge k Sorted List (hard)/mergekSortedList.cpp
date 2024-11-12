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
        if (lists.empty()) return nullptr;
        for(size_t i = 1; i < lists.size(); ++i){
            lists[0] = SortedMerge(lists[0], lists[i]);
        }
        return lists[0];
    }
    ListNode* SortedMerge(ListNode* a, ListNode* b)
    {
        ListNode* result = NULL;

        /* Base cases */
        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);

        /* Pick either a or b, and recur */
        if (a->val <= b->val) {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else {
            result = b;
            result->next = SortedMerge(a, b->next);
        }
        return (result);
    }
};