# Problem : Fruit Into Baskets

### Difficulty : **Medium**

https://leetcode.com/problems/fruit-into-baskets/

---

### Tags : **arrays**

### Relevant Tutorials :



---

# Statement

<p>You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array <code>fruits</code> where <code>fruits[i]</code> is the <strong>type</strong> of fruit the <code>i<sup>th</sup></code> tree produces.</p>

<p>You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:</p>

<ul>
	<li>You only have <strong>two</strong> baskets, and each basket can only hold a <strong>single type</strong> of fruit. There is no limit on the amount of fruit each basket can hold.</li>
	<li>Starting from any tree of your choice, you must pick <strong>exactly one fruit</strong> from <strong>every</strong> tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.</li>
	<li>Once you reach a tree with fruit that cannot fit in your baskets, you must stop.</li>
</ul>

<p>Given the integer array <code>fruits</code>, return <em>the <strong>maximum</strong> number of fruits you can pick</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> fruits = [<u>1,2,1</u>]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can pick from all 3 trees.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> fruits = [0,<u>1,2,2</u>]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> fruits = [1,<u>2,3,2,2</u>]
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= fruits.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= fruits[i] &lt; fruits.length</code></li>
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
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int fruit1 = -1, fruit2 = -1, lastOccFruit1, lastOccFruit2;
        int maxLen = 0, i = 0, start = 0;

        // Iterate through the fruit trees in the farm
        while (i < fruits.size()) {
            if (fruit1 == -1) {
                // If fruit1 has not been assigned, set it as the current fruit and record its occurrence.
                fruit1 = fruits[i];
                lastOccFruit1 = i;
            } else if (fruits[i] == fruit1) {
                // If the current fruit is the same as fruit1, update its last occurrence.
                lastOccFruit1 = i;
            } else if (fruits[i] == fruit2) {
                // If the current fruit is the same as fruit2, update its last occurrence.
                lastOccFruit2 = i;
            } else if (fruit2 == -1) {
                // If we encounter a different fruit type and fruit2 is not assigned, change fruit2 and record its occurrence.
                fruit2 = fruits[i];
                lastOccFruit2 = i;
            } else {
                // We need to switch one of the fruit types as we've encountered a third type.
                // Choose which fruit to keep based on the most recent occurrence.
                if (lastOccFruit2 < lastOccFruit1) {
                    swap(fruit1, fruit2);
                    swap(lastOccFruit1, lastOccFruit2);
                }
                start = lastOccFruit1 + 1;
                // Update fruit1 to the new type and its last occurrence.
                fruit1 = fruit2;
                lastOccFruit1 = lastOccFruit2;
                // Set fruit2 as the current fruit type and record its occurrence.
                fruit2 = fruits[i];
                lastOccFruit2 = i;
            }
            // Update maxLen with the maximum length of collected fruits.
            maxLen = max(maxLen, i - start + 1);
            i++;
        }
        // Print the maximum length (for debugging, you can remove this line)
        cout << maxLen << endl;
        return maxLen; // Return the maximum number of fruits you can pick
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
    int totalFruit(vector<int>& fruits) {
        int fruit1 = -1, fruit2 = -1, lastOccFruit1, lastOccFruit2;
        int maxLen = 0, i = 0, start = 0;
        while (i < fruits.size()) {
            if (fruit1 == -1) {
                fruit1 = fruits[i];
                lastOccFruit1 = i;
            } else if (fruits[i] == fruit1) {
                lastOccFruit1 = i;
            } else if (fruits[i] == fruit2) {
                lastOccFruit2 = i;
            } else if (fruit2 == -1) {
                fruit2 = fruits[i];
                lastOccFruit2 = i;
            } else {
                if (lastOccFruit2 < lastOccFruit1) {
                    swap(fruit1, fruit2);
                    swap(lastOccFruit1, lastOccFruit2);
                }
                start = lastOccFruit1 + 1;
                fruit1 = fruit2;
                lastOccFruit1 = lastOccFruit2;
                fruit2 = fruits[i];
                lastOccFruit2 = i;
            }
            maxLen = max(maxLen, i - start + 1);
            i++;
        }
        cout << maxLen << endl;
        return maxLen; 
    }
};
```
</details>
</li>
</ul>
