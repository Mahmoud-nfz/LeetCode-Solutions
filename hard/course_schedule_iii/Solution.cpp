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
