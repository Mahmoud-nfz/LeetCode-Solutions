class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure that nums1 is not larger than nums2
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1) ;

        // Calculate the index of the middle element in the combined array
        int combinedHalf = (nums1.size() + nums2.size() + 1) / 2 ;
        
        int l1 = 0, r1 = nums1.size() ;
        int m1 = 0, m2 = 0 ;
        while(l1 <= r1){
            // Calculate the midpoint for nums1
            m1 = l1 + (r1 - l1) / 2 ;
            // Calculate the corresponding midpoint for nums2
            m2 = combinedHalf - m1 ;

            // Define boundaries for both arrays
            int Al = -1e9, Ar = 1e9, Bl = -1e9, Br = 1e9 ;

            // Set boundaries based on whether midpoints are within array bounds
            if (m1 > 0)
                Al = nums1[m1 - 1];
            if (m2 > 0)
                Bl = nums2[m2 - 1];
            if (m1 >= 0 && m1 < nums1.size())
                Ar = nums1[m1];
            if (m2 >= 0 && m2 < nums2.size())
                Br = nums2[m2];

            // Check if the correct partition is found
            if (Al <= Br && Bl <= Ar) {
                // Calculate the median based on array size (odd or even)
                if ((nums1.size() + nums2.size()) % 2 == 1)
                    return max(Al, Bl);
                else
                    return 0.5 * min(Ar, Br) + 0.5 * max(Al, Bl); 
            }
            else if (Al > Br)
                r1 = m1 - 1 ;
            else 
                l1 = m1 + 1 ;
        }
        // Return 0 if no median is found
        return 0;
    }
};
