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
    // simple approach, might not work with bigger k but still got accepted so *shrugs*
    // I basically saw that this can just be solved with merge sort with little tweak
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr; // no lists to merge, return null

        // iterate through all lists and keep merging them into lists[0]
        for(size_t i = 1; i < lists.size(); ++i){
            lists[0] = SortedMerge(lists[0], lists[i]); // merge lists[0] with lists[i]
        }
        return lists[0]; // the merged list is now in lists[0]
    }

    // helper function to merge two sorted lists, (just merge sort with linked list)
    ListNode* SortedMerge(ListNode* a, ListNode* b)
    {
        ListNode* result = NULL;

        // base cases: if one list is empty, return the other
        if (a == NULL)
            return b;
        else if (b == NULL)
            return a;

        // pick either a or b, and recur
        if (a->val <= b->val) {
            result = a; // choose a
            result->next = SortedMerge(a->next, b); // link the rest
        }
        else {
            result = b; // choose b
            result->next = SortedMerge(a, b->next); // link the rest
        }
        return result;
    }
};
