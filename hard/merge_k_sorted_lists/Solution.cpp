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
        // Create a set to store pairs of (value, ListNode) for the heads of each linked list
        set<pair<int, ListNode*>> heads;

        // Insert the heads of non-empty linked lists into the set
        for (ListNode* head : lists) {
            if (head) {
                heads.insert({head->val, head});
            }
        }

        ListNode* ans = NULL;
        ListNode* curr;

        // Check if the set is not empty
        if (!heads.empty()) {
            auto firstPair = *heads.begin();
            ans = firstPair.second;
            curr = ans;
            heads.erase(heads.begin());

            // If there is a next node in the same linked list, insert it back into the set
            if (firstPair.second->next) {
                heads.insert({firstPair.second->next->val, firstPair.second->next});
            }
        }

        // Merge the linked lists in ascending order
        while (!heads.empty()) {
            auto nextPair = *heads.begin();
            curr->next = nextPair.second;
            curr = curr->next;
            heads.erase(heads.begin());

            // If there is a next node in the same linked list, insert it back into the set
            if (nextPair.second->next) {
                heads.insert({nextPair.second->next->val, nextPair.second->next});
            }
        }

        return ans; // Return the merged sorted linked list
    }
};
