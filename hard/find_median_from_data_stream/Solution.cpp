#include <bits/extc++.h> // pbds
using namespace __gnu_pbds;
typedef tree< 
                pair<int,int>,          // Pair of integers (value, index)
                null_type,              // No mapped value
                less<pair<int,int>>,   // Comparator: sort based on the first integer
                rb_tree_tag,            // Red-black tree
                tree_order_statistics_node_update  // Supports order statistics
            > ordered_set_pair; 
                        
class MedianFinder {
public:
    ordered_set_pair tree; // Define a tree of pairs to store values and indices
    int i = 0; // Index counter

    MedianFinder() {
        // Constructor not doing anything
        // int md = 0; // Unused variable
        // int check = 0; // Unused variable
    }
    
    void addNum(int num) {
        // Insert the number into the tree along with its index
        // The index is incremented to maintain uniqueness
        this->tree.insert({num, i++});
    }
    
    double findMedian() {
        // Get the size of the tree
        int n = this->tree.size();

        // If the size is odd, return the middle element
        if (n % 2)
            return tree.find_by_order(n / 2)->first;
        // If the size is even, return the average of the two middle elements
        else
            return 0.5 * ((tree.find_by_order(n / 2)->first) + tree.find_by_order(n / 2 - 1)->first);
    }
};
