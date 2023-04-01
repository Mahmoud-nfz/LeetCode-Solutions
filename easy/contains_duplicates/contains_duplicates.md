# Problem : Contains Duplicate

### Difficulty : **Easy**

https://leetcode.com/problems/contains-duplicate/

---

### Tags : **Hash Map, Data Structures**

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
    bool containsDuplicate(vector<int>& nums) {
        // create an unordered set to store the unique elements
        // the use of an unordered set guarantees that the insertion, deletion, and search of elements has an average time complexity of O(1)
        unordered_set<int> s;
        
        // iterate through the array and insert each element into the set
        // if an element is already in the set, then it's a duplicate and we can return true immediately
        for(int x : nums) {
            if(s.find(x) != s.end()) // O(1) on average
                return true;
            s.insert(x); // O(1) on average
        }
        
        // if no duplicates were found, then return false
        return false;
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
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int x : nums) {
            if(s.find(x) != s.end()) 
                return true;
            s.insert(x); 
        }
        return false;
    }
};
```
</details>
</li>
</ul>
