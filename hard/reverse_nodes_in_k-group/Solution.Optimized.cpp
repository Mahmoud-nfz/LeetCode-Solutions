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

    // Helper function to reverse a group of k nodes in the linked list
    ListNode* reverseK(ListNode* head, int k, int currStep, ListNode* prev, ListNode* firstInSeq) {
        // If head is NULL, or currStep reaches k-1, or it's time to reverse the group
        if (!head) {
            if (currStep < k - 1)
                return NULL;
            return NULL;
        }

        // If currStep is 0, it's time to start reversing the group
        if (currStep == 0) {
            ListNode* ans = reverseK(head->next, k, currStep + 1, head, head);
            if (!ans)
                return head;
            ListNode* nextSeq = reverseK(head->next, k, 0, NULL, NULL);
            head->next = nextSeq;
            return ans;
        }

        // If currStep is less than k-1, continue reversing the group
        if (currStep < k - 1) {
            ListNode* ans = reverseK(head->next, k, currStep + 1, head, firstInSeq);
            if (!ans)
                return NULL;
            head->next = prev;
            return ans;
        }

        // If currStep is k-1, it's time to connect the reversed group to the previous part
        if (currStep == k - 1) {
            firstInSeq->next = head->next;
            head->next = prev;
            return head;
        }

        return NULL;
    }

    // Main function to reverse nodes in groups of k
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseK(head, k, 0, NULL, NULL);
    }
};
