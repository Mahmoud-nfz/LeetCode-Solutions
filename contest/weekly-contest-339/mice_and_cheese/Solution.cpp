class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        // Create a vector of pairs to store the difference between reward2 and reward1 for each cheese
        vector<pair<int,int>> v;
        // Create a vector to keep track of which cheeses have already been assigned to a mouse
        vector<int> vis(n,0);
        for(int i = 0 ; i < n ; i ++){
            // Calculate the loss between reward2 and reward1 for each cheese and store it along with the index of the cheese in a pair
            v.push_back({reward2[i]-reward1[i],i});
        }
        // Sort the vector of pairs in increasing order of the difference between reward2 and reward1
        sort(v.begin(),v.end());
        // Initialize a variable to store the maximum points that the mice can achieve
        long long ans = 0;
        for(int i = 0 ; i < k ; i ++){
            // Assign the i-th smallest difference cheese to the first mouse and add its reward to the total points
            ans += reward1[v[i].second];
            // Mark the cheese as assigned to mouse 1
            vis[v[i].second] = 1;
        }
        for(int i = 0 ; i < n ; i ++){
            // If the cheese has not been assigned to a mouse, assign it to the second mouse and add its reward to the total points
            if(!vis[i])
                ans += reward2[i];
        }
        // Return the maximum points that the mice can achieve
        return ans;  
    }
};
