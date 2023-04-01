#define ll long long 

class Solution {
public:
    // vector to store the parent node of each element
    vector<int> parent ;
    // function to find the parent of the element
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    // function to merge the sets containing a and b
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
            parent[b] = a;
    }
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        // vector to store the the number of elements in each set of k consecutive elements
        vector<ll> freq(k+1,0) ;
        // 2D vector to store the elements of each set of k consecutive elements
        vector<vector<int>> elems(k+1) ;
        int n = arr.size() ;
        // initializing the parent of each element to itself
        parent.resize(n) ;
        for(int i = 0 ; i < n ; i ++){
            parent[i] = i ; 
        }
        // merging the sets containing i and (i+k)%n
        for(int i = 0 ; i < n ; i ++){
            union_sets(i,(i+k)%n) ; 
        }
        for(int i = 0 ; i < n ; i ++){
            // incrementing the number of elements in the set containing i
            freq[find_set(i)] ++ ; 
            // adding the element arr[i] to the set containing i
            elems[find_set(i)].push_back(arr[i]) ;
        }
        // variable to store the answer
        ll ans = 0 ;
        for(int i = 0 ; i < k + 1 ; i ++){
            // if there are elements in this set
            if(freq[i]){ 
                // sorting the elements of the set in non-decreasing order
                sort(elems[i].begin(), elems[i].end()); 
                // finding the median element of the set
                ll median = elems[i][elems[i].size() / 2]; 
                // variable to store the number of operations required to make all elements equal to median
                ll operations = 0; 
                for (int j = 0; j < elems[i].size(); j++) {
                    // adding the absolute difference between each element and the median to operations
                    operations += abs(elems[i][j] - median); 
                }
                // adding operations to ans
                ans += operations ; 
            }
        }
        // we return the answer
        return ans ; 
    }
};
