# Problem : Reorganize String

### Difficulty : **Medium**

https://leetcode.com/problems/reorganize-string/

---

### Tags : **strings, greedy, data structures**

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
    string reorganizeString(string t) {
        // Initialize an array to store the count of each character in the string
        int a[28] = {0};
        for(char c : t){
            a[c-'a'] ++ ;
        }
        // Use a set to store the characters and their counts
        // The set is sorted in decreasing order based on the count of each character
        // This makes it easier to choose the most frequent character that hasn't been used recently
        set<pair<int,char>> s ;
        for(int i = 0 ; i < 28 ; i ++){
            if(a[i])
                s.insert({a[i],'a'+i}) ;
        }
        // Initialize a string to store the rearranged string
        string ans ;
        // Initialize a variable to keep track of the previously used character
        char prev = '.' ;
        // Repeat as long as there are characters
        while(!s.empty()){
            // Choose the most frequent character that hasn't been used recently
            auto x = s.rbegin() ;
            if(x->second == prev){
                x ++ ;
            }
            // If there are no available characters to choose from, then it is impossible
            if(x == s.rend())
                return "" ;
            auto p = *x ;
            // Add the chosen character to the rearranged string
            ans += p.second ;
            // Update the set by removing the chosen character and decreasing its count
            s.erase(*x) ;
            if(p.first > 1)
                s.insert({p.first-1,p.second}) ;
            // Update the previously used character
            prev = p.second ;
        }
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
class Solution {
public:
    string reorganizeString(string t) {
        int a[28] = {0};
        for(char c : t){
            a[c-'a'] ++ ;
        }
        set<pair<int,char>> s ;
        for(int i = 0 ; i < 28 ; i ++){
            if(a[i])
                s.insert({a[i],'a'+i}) ;
        }
        string ans ;
        char prev = '.' ;
        while(!s.empty()){
            auto x = s.rbegin() ;
            if(x->second == prev){
                x ++ ;
            }
            if(x == s.rend())
                return "" ;
            auto p = *x ;
            ans += p.second ;
            s.erase(*x) ;
            if(p.first > 1)
                s.insert({p.first-1,p.second}) ;
            prev = p.second ;
        }
        return ans ;
    }
};
```
</details>
</li>
</ul>
