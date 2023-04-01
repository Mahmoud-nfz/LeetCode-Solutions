# Problem : K Closest Points to Origin

### Difficulty : **Medium**

https://leetcode.com/problems/k-closest-points-to-origin/

---

### Tags : **sorting**

### Relevant Tutorials :



---

# Statement

<p>Given an array of <code>points</code> where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> represents a point on the <strong>X-Y</strong> plane and an integer <code>k</code>, return the <code>k</code> closest points to the origin <code>(0, 0)</code>.</p>

<p>The distance between two points on the <strong>X-Y</strong> plane is the Euclidean distance (i.e., <code>√(x<sub>1</sub> - x<sub>2</sub>)<sup>2</sup> + (y<sub>1</sub> - y<sub>2</sub>)<sup>2</sup></code>).</p>

<p>You may return the answer in <strong>any order</strong>. The answer is <strong>guaranteed</strong> to be <strong>unique</strong> (except for the order that it is in).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/closestplane1.jpg" style="width: 400px; height: 400px;">
<pre><strong>Input:</strong> points = [[1,3],[-2,2]], k = 1
<strong>Output:</strong> [[-2,2]]
<strong>Explanation:</strong>
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) &lt; sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> points = [[3,3],[5,-1],[-2,4]], k = 2
<strong>Output:</strong> [[3,3],[-2,4]]
<strong>Explanation:</strong> The answer [[-2,4],[3,3]] would also be accepted.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= points.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt; x<sub>i</sub>, y<sub>i</sub> &lt; 10<sup>4</sup></code></li>
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
    // define a comparator function to sort points based on their distance from the origin
    // we take the parameters by reference to avoid copying them each time the function is called
    // thus saving time and space
    static bool comp(vector<int>& a , vector<int>& b){
        return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1] ;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // sort the given points based on their distance from the origin using the defined comparator function
        sort(points.begin(),points.end(),comp) ;
        // resize the vector to only contain the first k closest points to the origin
        points.resize(k) ;
        // return the k closest points to the origin
        return points ;
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
    static bool comp(vector<int>& a , vector<int>& b){
        return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1] ;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),comp) ;
        points.resize(k) ;
        return points ;
    }
};
```
</details>
</li>
</ul>
