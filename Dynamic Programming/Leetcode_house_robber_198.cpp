#include <bits/stdc++.h>
using namespace std;

/*
    LeetCode 198 - House Robber
    Difficulty: Medium
    Topic: Dynamic Programming

    Problem:
    You cannot rob two adjacent houses.
    Find the maximum amount of money you can rob.

    Example:
    nums = [2, 7, 9, 3, 1]
    Answer = 12

    Approaches:
    1. Recursion
    2. Top-Down DP (Memoization)
    3. Bottom-Up DP (Tabulation)
    4. Space Optimized DP
*/

class Solution
{
public:
    // =========================================================
    // 1. RECURSION
    // =========================================================
    //
    // At every house:
    //      1. Rob it  -> move to index + 2
    //      2. Skip it -> move to index + 1
    //
    // Time:  O(2^n)
    // Space: O(n) recursion stack
    //
    int solveRecursion(vector<int> &nums, int index)
    {

        if (index >= nums.size())
            return 0;

        return max(
            nums[index] + solveRecursion(nums, index + 2),
            solveRecursion(nums, index + 1));
    }

    // =========================================================
    // 2. TOP-DOWN DP - MEMOIZATION
    // =========================================================
    //
    // dp[index] means:
    // Maximum money that can be robbed starting from index.
    //
    // Time:  O(n)
    // Space: O(n) dp + O(n) recursion stack
    //
    int solveMemo(vector<int> &nums, int index, vector<int> &dp)
    {

        if (index >= nums.size())
            return 0;

        // Already calculated
        if (dp[index] != -1)
            return dp[index];

        return dp[index] = max(
                   nums[index] + solveMemo(nums, index + 2, dp),
                   solveMemo(nums, index + 1, dp));
    }

    // =========================================================
    // 3. BOTTOM-UP DP - TABULATION
    // =========================================================
    //
    // dp[i] = maximum money that can be robbed
    //         starting from index i.
    //
    // Recurrence:
    //
    // dp[i] = max(
    //     nums[i] + dp[i + 2],   // Rob current house
    //     dp[i + 1]              // Skip current house
    // )
    //
    // We calculate from right to left because
    // dp[i] depends on dp[i+1] and dp[i+2].
    //
    // Time:  O(n)
    // Space: O(n)
    //
    int solveTabulation(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> dp(n + 2, 0);

        for (int i = n - 1; i >= 0; i--)
        {

            dp[i] = max(
                nums[i] + dp[i + 2],
                dp[i + 1]);
        }

        return dp[0];
    }

    // =========================================================
    // 4. SPACE OPTIMIZATION
    // =========================================================
    //
    // dp[i] only depends on:
    //
    // dp[i-1]
    // dp[i-2]
    //
    // Therefore, we don't need the complete dp array.
    //
    // prev2 = dp[i-2]
    // prev1 = dp[i-1]
    //
    // Time:  O(n)
    // Space: O(1)
    //
    int solveOptimized(vector<int> &nums)
    {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        if (n == 2)
            return max(nums[0], nums[1]);

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {

            int current = max(
                nums[i] + prev2,
                prev1);

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }

    // =========================================================
    // LEETCODE FUNCTION
    // =========================================================

    int rob(vector<int> &nums)
    {

        // Approach 1: Recursion
        // return solveRecursion(nums, 0);

        // Approach 2: Top-Down DP
        // vector<int> dp(nums.size(), -1);
        // return solveMemo(nums, 0, dp);

        // Approach 3: Tabulation
        // return solveTabulation(nums);

        // Approach 4: Space Optimized DP
        return solveOptimized(nums);
    }
};

/*
    ============================================================
                         KEY LEARNING
    ============================================================

    At every house there are two choices:

        ROB
        ↓
        nums[i] + answer from i+2

        SKIP
        ↓
        answer from i+1


    Recurrence:

        dp[i] = max(nums[i] + dp[i+2], dp[i+1])


    DP progression:

        Recursion
            ↓
        Memoization
            ↓
        Tabulation
            ↓
        Space Optimization


    Final complexities:

    Recursion:
        Time  = O(2^n)
        Space = O(n)

    Memoization:
        Time  = O(n)
        Space = O(n)

    Tabulation:
        Time  = O(n)
        Space = O(n)

    Space Optimization:
        Time  = O(n)
        Space = O(1)
*/