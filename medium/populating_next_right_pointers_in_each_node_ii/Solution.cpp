/*
    We first perform a level order traversal of the tree.
    Then we point each node to its next right sibling in the same level
    see : https://github.com/Mahmoud-nfz/LeetCode-Solutions/blob/main/medium/binary_tree_level_order_traversal/binary_tree_level_order_traversal.md
    for the description of the level order traversal
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<Node*> curr , next ;
        if(root)
            curr.push_back(root) ;
        while(!curr.empty()){
            vector<Node*> temp ;
            for(auto elem : curr){
                if(elem->left)
                    next.push_back(elem->left) ;
                if(elem->right)
                    next.push_back(elem->right) ;
                temp.push_back(elem) ;
            }
            for(int i = 0 ; i < temp.size() - 1 ; i ++){
                temp[i]->next = temp[i+1] ;
            }
            temp[temp.size() - 1]->next = NULL ;
            curr = next ;
            next = vector<Node*>() ;
        }
        return root ;
    }
};