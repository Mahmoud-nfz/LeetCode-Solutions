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
    int k, len; // 'k' for rotation count and 'len' for the list length
    ListNode* newHead; // Pointer to the new head of the list after rotation

    // Recursive function to traverse the list and adjust links
    int solve(ListNode* curr, ListNode* first, int currLen){
        // Base case: end of the list
        if(!curr){
            k = k % currLen; // Normalize k to prevent unnecessary rotations
            len = currLen; // Record the total length of the list
            return 0; // Return 0 to start indexation for adjusting links
        }

        // Recur for the next node
        int idx = solve(curr->next, first, currLen + 1);

        // Link the last node to the first node (making the list circular temporarily)
        if(!idx)
            curr->next = first;
        
        // Identify the new head just after the rotated tail
        if(idx == k-1)
            newHead = curr;
        
        // Disconnect the new tail from the rotated part
        if(idx == k)
            curr->next = NULL;

        // Return the incremented index
        return idx + 1;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        // Edge cases: no rotation needed or empty list
        if(!k || !head)
            return head;

        this->k = k; // Set the global rotation count

        // Start the recursive process
        solve(head, head, 0);

        // If k is a multiple of the list length or the list has only one element
        if((k % (this->len)) == 0 || this->len == 1){
            return head; // No change in head needed
        }
        // Return the new head of the list
        return newHead;
    }
};
