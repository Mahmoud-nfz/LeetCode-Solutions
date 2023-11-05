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

    // Helper function to reverse a group of k nodes in an array
    ListNode* reverseKfromArray(vector<ListNode*>& nodes, int k) {
        int i = 0, n = nodes.size();

        // Reverse the nodes in groups of k until there are k nodes left to reverse
        while (i < n - (n % k)) {
            reverse(nodes.begin() + i, nodes.begin() + i + k);
            i += k;
        }

        // Update the next pointers to link the reversed nodes together
        for (int i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->next = nodes[i + 1];
        }
        nodes[nodes.size() - 1]->next = NULL;

        return nodes[0]; // Return the new head of the reversed group
    }

    // Main function to reverse nodes in groups of k
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> nodes;

        // Convert the linked list into a vector of nodes
        while (head && head->next) {
            nodes.push_back(head);
            head = head->next;
        }
        nodes.push_back(head);

        // Call the helper function to reverse nodes in groups of k
        return reverseKfromArray(nodes, k);
    }
};
