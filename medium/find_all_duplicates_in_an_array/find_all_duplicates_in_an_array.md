# Problem : Find All Duplicates in an Array

### Difficulty : **Medium**

https://leetcode.com/problems/find-all-duplicates-in-an-array/

---

### Tags : **data structures, frequency array**

### Relevant Tutorials :



---

# Statement



---

# Solution 

Solutions Author : https://github.com/Mahmoud-nfz

## C++ Solution

<ul>
<li>

<details>
    <summary>Explained Solution</summary>

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // Initialize a vector 'freq' with size n+1 where n is the size of the input array.
        // This vector will be used to keep track the number of appearances of each element in the input array.
        vector<int> freq(nums.size()+1) ;
        // Initialize a vector 'res' to store the result.
        vector<int> res ;
        
        // Traverse the input array 'nums' and update the frequency of each element in the 'freq' vector.
        for(auto c : nums){
            freq[c] ++ ;
        }
        
        // Traverse the 'freq' vector and add all elements whose frequency is greater than 1 to the 'res' vector.
        for(int i =1 ; i < freq.size() ; i ++){
            if(freq[i] > 1){
                res.push_back(i) ;
            }
        }
        
        // Return the 'res' vector containing all elements that appear twice in the input array.
        return res ;
    }
};

```
</details>
</li>

<li>
<details>
    <summary>Raw Solution</summary>

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> freq(nums.size()+1) ;
        vector<int> res ;
        for(auto c : nums){
            freq[c] ++ ;
        }
        for(int i =1 ; i < freq.size() ; i ++){
            if(freq[i] > 1){
                res.push_back(i) ;
            }
        }
        return res ;
    }
};
```
</details>
</li>
</ul>
