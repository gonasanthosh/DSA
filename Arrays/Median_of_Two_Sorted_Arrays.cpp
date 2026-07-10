/*
LeetCode 4: Median of Two Sorted Arrays

Approach:
- Merge the two sorted arrays using the two-pointer technique.
- If the total number of elements is odd, return the middle element.
- If it is even, return the average of the two middle elements.

Time Complexity: O(m + n)
Space Complexity: O(m + n)

Note:
This is the straightforward merge-based solution. The optimal solution uses
binary search with O(log(min(m, n))) time complexity.
*/

#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> merged;

        int i = 0;
        int j = 0;

        // Merge both sorted arrays
        while (i < nums1.size() && j < nums2.size()) {

            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        // Add remaining elements from nums1
        while (i < nums1.size()) {
            merged.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements from nums2
        while (j < nums2.size()) {
            merged.push_back(nums2[j]);
            j++;
        }

        int n = merged.size();

        // Odd number of elements
        if (n % 2 == 1) {
            return merged[n / 2];
        }

        // Even number of elements
        return (merged[n / 2] + merged[n / 2 - 1]) / 2.0;
    }
};