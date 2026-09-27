#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: Find All Duplicates in an Array

Platform: LeetCode
Problem No.: 442

-----------------------------------------------------------
Problem Statement:
Given an integer array nums of length n where each integer
is in the range [1, n] and each integer appears once or
twice, return all the integers that appear twice.

The solution must run in O(n) time and use O(1) extra space
(excluding the returned answer).

-----------------------------------------------------------
Approach:
1. Traverse the array.
2. For every number nums[i], take its absolute value.
3. Convert the number x into an array index:
       index = x - 1
4. Use the sign of nums[index] to mark whether x has already
   appeared.
5. If nums[index] is already negative, x is a duplicate.
6. Otherwise, make nums[index] negative to mark x as seen.
7. Store all duplicates in the answer vector.

-----------------------------------------------------------
Example:
Input:
nums = {4, 3, 2, 7, 8, 2, 3, 1}

Output:
{2, 3}

-----------------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(1) extra space
(excluding the answer vector)

-----------------------------------------------------------
*/

class Solution {
public:

    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            int x = abs(nums[i]);

            int index = x - 1;

            if(nums[index] < 0)
                ans.push_back(x);

            else
                nums[index] = -nums[index];
        }

        return ans;
    }
};

