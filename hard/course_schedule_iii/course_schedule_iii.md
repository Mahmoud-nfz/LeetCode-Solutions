# Problem : Course Schedule III

### Difficulty : **Hard**

https://leetcode.com/problems/course-schedule-iii/

---

### Tags : **two pointers, scheduling, arrays**

### Relevant Tutorials :



---

# Statement

<p>There are <code>n</code> different online courses numbered from <code>1</code> to <code>n</code>. You are given an array <code>courses</code> where <code>courses[i] = [duration<sub>i</sub>, lastDay<sub>i</sub>]</code> indicate that the <code>i<sup>th</sup></code> course should be taken <b>continuously</b> for <code>duration<sub>i</sub></code> days and must be finished before or on <code>lastDay<sub>i</sub></code>.</p>

<p>You will start on the <code>1<sup>st</sup></code> day and you cannot take two or more courses simultaneously.</p>

<p>Return <em>the maximum number of courses that you can take</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
<strong>Output:</strong> 3
Explanation: 
There are totally 4 courses, but you can take 3 courses at most:
First, take the 1<sup>st</sup> course, it costs 100 days so you will finish it on the 100<sup>th</sup> day, and ready to take the next course on the 101<sup>st</sup> day.
Second, take the 3<sup>rd</sup> course, it costs 1000 days so you will finish it on the 1100<sup>th</sup> day, and ready to take the next course on the 1101<sup>st</sup> day. 
Third, take the 2<sup>nd</sup> course, it costs 200 days so you will finish it on the 1300<sup>th</sup> day. 
The 4<sup>th</sup> course cannot be taken now, since you will finish it on the 3300<sup>th</sup> day, which exceeds the closed date.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> courses = [[1,2]]
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> courses = [[3,2],[4,3]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= courses.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= duration<sub>i</sub>, lastDay<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
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
    // Function to compare two arrays based on their second element
    static bool compareArrays(const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] > b[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {
        // Add a dummy course with a large duration and deadline 0
        vector<int> temp = {10000000, 0};
        courses.push_back(temp);

        int n = courses.size();
        // Sort courses by the latest deadline first
        sort(courses.begin(), courses.end(), this->compareArrays);

        int lastDeadline = courses[0][1];
        multiset<int> remTimeInCourses;
        remTimeInCourses.insert(courses[0][0]);

        int ans = 0;

        int currTime = lastDeadline;
        for (int i = 1; i < n; i++) {
            int x = 0;
            // Adjust current time and remove courses if needed
            while (x == 0 && remTimeInCourses.size() && currTime > courses[i][1]) {
                x = *remTimeInCourses.begin();
                remTimeInCourses.erase(remTimeInCourses.begin());
                int reduce = min(x, currTime - courses[i][1]);
                x -= reduce;
                currTime -= reduce;
                if (x == 0)
                    ans++;
                else
                    remTimeInCourses.insert(x);
            }

            // Update current time and add current course's duration
            currTime = courses[i][1];
            remTimeInCourses.insert(courses[i][0]);
        }

        return ans;
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
    static bool compareArrays(const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] > b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        vector<int> temp = {10000000, 0};
        courses.push_back(temp);
        int n = courses.size();
        sort(courses.begin(), courses.end(), this->compareArrays);
        int lastDeadline = courses[0][1];
        multiset<int> remTimeInCourses;
        remTimeInCourses.insert(courses[0][0]);
        int ans = 0;
        int currTime = lastDeadline;
        for (int i = 1; i < n; i++) {
            int x = 0;
            while (x == 0 && remTimeInCourses.size() && currTime > courses[i][1]) {
                x = *remTimeInCourses.begin();
                remTimeInCourses.erase(remTimeInCourses.begin());
                int reduce = min(x, currTime - courses[i][1]);
                x -= reduce;
                currTime -= reduce;
                if (x == 0)
                    ans++;
                else
                    remTimeInCourses.insert(x);
            }
            currTime = courses[i][1];
            remTimeInCourses.insert(courses[i][0]);
        }
        return ans;
    }
};
```
</details>
</li>
</ul>
