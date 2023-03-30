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
    ListNode* reverseList(ListNode* head) {
        // If the linked list is empty or has only one node, return it as is
        if(!head || !head->next)
            return head ;
        
        // Initialize elem pointer as head's next node, set head's next to NULL
        ListNode* elem = head->next ;
        head->next = NULL ;
        
        // Iterate over the remaining nodes and reverse their pointers
        while(elem){
            ListNode* newHead = elem->next ;
            elem->next = head ;
            head = elem ;
            elem = newHead ;
            if(!elem)
                return head ; // Return the reversed head of the linked list
        }
        
        return NULL ; // Should never get here
    }
};
