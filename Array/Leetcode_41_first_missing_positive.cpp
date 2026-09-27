#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: First Missing Positive

Platform: LeetCode
Problem No.: 41

-----------------------------------------------------------
Problem Statement:
Given an unsorted integer array nums, return the smallest
positive integer that is not present in nums.

The algorithm must run in O(n) time and use O(1) extra space.

-----------------------------------------------------------
Approach:
1. Let n = nums.size().
2. Replace all numbers that are:
       <= 0
       > n
   with n + 1 because they cannot be the answer.
3. Use the sign of array elements as a marker:
   - For each number x, mark index x - 1 as negative.
   - A negative value means that x exists in the array.
4. Traverse the array again:
   - The first positive nums[i] means i + 1 is missing.
5. If every position is negative, then all values from 1 to n
   are present, so the answer is n + 1.

-----------------------------------------------------------
Example:
Input:
nums = {3, 4, -1, 1}

After processing:
The positive numbers present are 1, 3 and 4.

The smallest missing positive is:
2

Output:
2

-----------------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(1)

-----------------------------------------------------------
*/

class Solution {
public:

    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Ignore numbers outside the range [1, n]
        for(int i = 0; i < n; i++) {

            if(nums[i] <= 0 || nums[i] > n)
                nums[i] = n + 1;
        }

        // Step 2: Mark numbers that exist
        for(int i = 0; i < n; i++) {

            int x = abs(nums[i]);

            if(x <= n) {

                int index = x - 1;

                if(nums[index] > 0)
                    nums[index] = -nums[index];
            }
        }

        // Step 3: Find the first missing positive
        for(int i = 0; i < n; i++) {

            if(nums[i] > 0)
                return i + 1;
        }

        // All numbers from 1 to n exist
        return n + 1;
    }
};
