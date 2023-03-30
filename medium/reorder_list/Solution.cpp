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
    void reorderList(ListNode* head) {
        // base cases, the list is empty or has only one node
        if(!head || !head->next)
            return ;
        
        // partition the list into two halves, the first half and the second half
        vector<ListNode*> seconHalf, firstHalf ;
        ListNode* it = head ;
        int i = 0 ;
        while(it){
            it = it->next ;
            i ++ ;
        }
        int j = 0 ;
        while(head){
            if(j >= (i+1)/2)
                seconHalf.push_back(head) ;
            else
                firstHalf.push_back(head) ;
            head = head->next ;
            j ++ ;
        }
        
        // reverse the second half
        reverse(seconHalf.begin(),seconHalf.end());
        
        // merge the first half and the reversed second half
        for(int j = 0 ; j < min(seconHalf.size(),firstHalf.size()) - 1 ; j ++){
            firstHalf[j]->next = seconHalf[j] ;
            seconHalf[j]->next = firstHalf[j+1] ;
        }
        
        // connect the last nodes of the first half and the reversed second half
        firstHalf[seconHalf.size()-1]->next = seconHalf[seconHalf.size()-1] ;
        
        // if the first half is longer, connect its last node to the second half's last node
        if(firstHalf.size() > seconHalf.size()){
            firstHalf[firstHalf.size()-1]->next = NULL ;
            seconHalf[seconHalf.size()-1]->next = firstHalf[firstHalf.size()-1] ;
        }
        // if the second half is longer, just end the list at its last node
        else{
            seconHalf[seconHalf.size()-1]->next = NULL ;
        }
        
        // set the reordered list as the new head
        head = firstHalf[0] ;
    }

};
