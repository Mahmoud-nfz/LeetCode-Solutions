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
