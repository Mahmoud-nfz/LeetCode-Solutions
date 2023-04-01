# Problem : Make K-Subarray Sums Equal

### Difficulty : **Medium**

https://leetcode.com/contest/biweekly-contest-101/problems/make-k-subarray-sums-equal/

---

### Tags : **arrays, dsu**

### Relevant Tutorials :



---

# Statement


<p>You are given a <strong>0-indexed</strong> integer array <code>arr</code> and an integer <code>k</code>. The array <code>arr</code> is circular. In other words, the first element of the array is the next element of the last element, and the last element of the array is the previous element of the first element.</p>

<p>You can do the following operation any number of times:</p>

<ul>
	<li>Pick any element from <code>arr</code> and increase or decrease it by <code>1</code>.</li>
</ul>

<p>Return <em>the minimum number of operations such that the sum of each <strong>subarray</strong> of length </em><code>k</code><em> is equal</em>.</p>

<p>A <strong>subarray</strong> is a contiguous part of the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,4,1,3], k = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong> we can do one operation on index 1 to make its value equal to 3.
The array after the operation is [1,3,1,3]
- Subarray starts at index 0 is [1, 3], and its sum is 4 
- Subarray starts at index 1 is [3, 1], and its sum is 4 
- Subarray starts at index 2 is [1, 3], and its sum is 4 
- Subarray starts at index 3 is [3, 1], and its sum is 4 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [2,5,5,7], k = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong> we can do three operations on index 0 to make its value equal to 5 and two operations on index 3 to make its value equal to 5.
The array after the operations is [5,5,5,5]
- Subarray starts at index 0 is [5, 5, 5], and its sum is 15
- Subarray starts at index 1 is [5, 5, 5], and its sum is 15
- Subarray starts at index 2 is [5, 5, 5], and its sum is 15
- Subarray starts at index 3 is [5, 5, 5], and its sum is 15 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
</ul>


---

# Solution 

Solutions Author : https://github.com/Mahmoud-nfz

## C++ Solution

<ul>
<li>

<details>
    <summary>Explained Solution</summary>

```cpp
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

```
</details>
</li>

<li>
<details>
    <summary>Raw Solution</summary>

```cpp
#define ll long long 
class Solution {
public:
    vector<int> parent ;
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
            parent[b] = a;
    }
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        vector<ll> freq(k+1,0) ;
        vector<vector<int>> elems(k+1) ;
        int n = arr.size() ;
        parent.resize(n) ;
        for(int i = 0 ; i < n ; i ++){
            parent[i] = i ; 
        }
        for(int i = 0 ; i < n ; i ++){
            union_sets(i,(i+k)%n) ; 
        }
        for(int i = 0 ; i < n ; i ++){
            freq[find_set(i)] ++ ; 
            elems[find_set(i)].push_back(arr[i]) ;
        }
        ll ans = 0 ;
        for(int i = 0 ; i < k + 1 ; i ++){
            if(freq[i]){ 
                sort(elems[i].begin(), elems[i].end()); 
                ll median = elems[i][elems[i].size() / 2]; 
                ll operations = 0; 
                for (int j = 0; j < elems[i].size(); j++) {
                    operations += abs(elems[i][j] - median); 
                }
                ans += operations ; 
            }
        }
        return ans ; 
    }
};
```
</details>
</li>
</ul>
