/*
Problem: Container With Most Water
Platform: LeetCode
Problem No.: 11
Difficulty: Medium
Topic: Array, Two Pointers

Approach 1: Brute Force
- Check every possible pair of lines.
- Calculate area = min(height[i], height[j]) * (j - i).
- Update the maximum area.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/
#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int area = min(height[i], height[j]) * (j - i);
                maxi = max(area, maxi);
            }
        }

        return maxi;
    }
};

/*
Approach 2: Two Pointers (Optimized)
- Initialize left at index 0 and right at index n-1.
- Calculate the area using the shorter line and current width.
- Update the maximum area.
- Move the pointer with the smaller height.
- Continue until left >= right.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxi = 0;
        int left = 0, right = n - 1;

        while(left < right) {
            int water = min(height[left], height[right]) * (right - left);
            maxi = max(water, maxi);

            if(height[left] <= height[right])
                left++;
            else
                right--;
        }

        return maxi;
    }
};