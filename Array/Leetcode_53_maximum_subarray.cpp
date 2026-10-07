#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: Maximum Subarray

Platform: LeetCode
Problem No.: 53
Type: Medium

-----------------------------------------------------------
Problem Statement:
Given an integer array nums, find the subarray with the
largest sum and return its sum.

A subarray is a contiguous part of the array.

-----------------------------------------------------------
Approach: Kadane's Algorithm

Idea:
We maintain two variables:

    currsum -> maximum sum of a subarray ending at the
               current position.

    maxsum  -> maximum subarray sum found so far.

For every element:
1. Add the current value to currsum.
2. Update maxsum.
3. If currsum becomes negative, reset it to 0 because a
   negative sum will only reduce the sum of a future subarray.

-----------------------------------------------------------
Example:
Input:
nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}

Maximum subarray:
{4, -1, 2, 1}

Sum:
4 + (-1) + 2 + 1 = 6

Output:
6

-----------------------------------------------------------
Why maxsum starts with INT_MIN:

If all numbers are negative, we still need to return the
largest negative number.

Example:
nums = {-5, -2, -8}

Answer = -2

If maxsum started with 0, the answer would incorrectly
become 0.

-----------------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(1)

-----------------------------------------------------------
*/

class Solution {
public:

    int maxSubArray(vector<int>& nums) {

        int currsum = 0;
        int maxsum = INT_MIN;

        for(int val : nums) {

            currsum += val;

            maxsum = max(currsum, maxsum);

            if(currsum < 0)
                currsum = 0;
        }

        return maxsum;
    }
};