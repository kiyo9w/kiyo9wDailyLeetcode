class Solution {
public:
    // using a dummy node to handle edge cases, then swapping nodes by tweaking pointer
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head); // dummy node to simplify swapping at the head
        ListNode* cur = head;
        ListNode* prev = dummy;
        ListNode* second;
        ListNode* nextPairs;

        while(cur != NULL && cur->next != NULL){
            // while there are at least two nodes to swap
            nextPairs = cur->next->next; // save the node after the pair for the next iteration
            second = cur->next; // the second node in the current pair

            // swapping the nodes by reassigning the next pointers
            second->next = cur;
            prev->next = second;
            cur->next = nextPairs;

            // moving prev and cur to their new positions for the next swap
            prev = cur; // prev now points to the last node of the swapped pair
            cur = nextPairs; // cur moves to the next pair
        }
        return dummy->next; // return the new head of the swapped list
    }
};
