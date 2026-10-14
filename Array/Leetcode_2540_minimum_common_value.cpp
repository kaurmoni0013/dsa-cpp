/*
Problem: Minimum Common Value
Platform: LeetCode
Problem No.: 2540
Difficulty: Easy
Topic: Array, Two Pointers

Approach:
- Initialize two pointers i and j at index 0.
- Since both arrays are sorted, compare nums1[i] and nums2[j].
- If both values are equal, return that value.
- If nums1[i] is smaller, increment i.
- Otherwise, increment j.
- If no common value is found, return -1.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/
#include<vector>
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;

        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j])
                return nums1[i];

            else if(nums1[i] < nums2[j])
                i++;

            else
                j++;
        }

        return -1;
    }
};