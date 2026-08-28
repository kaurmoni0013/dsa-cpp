#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    Frog Jump with K Jumps
    Problem: Minimize Cost

    Topic:
        Dynamic Programming

    Approaches learned:
        1. Recursion
        2. Top-Down DP (Memoization)
        3. Bottom-Up DP (Tabulation)


    -------------------------------------------------------
    Problem:
    -------------------------------------------------------

    Given an array arr[] representing heights of stairs
    and an integer k.

    The frog starts at index 0.

    From index i, the frog can jump at most k positions
    forward.

    Cost of a jump:

        abs(arr[current] - arr[previous])

    Find the minimum cost required to reach the last index.


    Example:

        arr = [10, 20, 30, 10]
        k = 2

        Answer = 20
*/


class Solution {
public:

    // =====================================================
    // 1. RECURSION
    // =====================================================

    /*
        minEnergy(index) means:

        Minimum energy required to reach 'index'.

        From index, we try every possible previous
        position within k jumps.
    */

    int minEnergyRecursive(
        int index,
        vector<int>& arr,
        int k
    ) {

        // Base case
        if (index == 0)
            return 0;

        int result = INT_MAX;

        // Try all possible jumps
        for (int jump = 1;
             jump <= k && jump <= index;
             jump++) {

            int cost =
                abs(arr[index] - arr[index - jump])
                + minEnergyRecursive(
                    index - jump,
                    arr,
                    k
                );

            result = min(result, cost);
        }

        return result;
    }


    // =====================================================
    // 2. TOP-DOWN DP - MEMOIZATION
    // =====================================================

    /*
        dp[index] =
        minimum energy required to reach index.

        Time  : O(n * k)
        Space : O(n) DP + O(n) recursion stack
    */

    int minEnergyMemo(
        int index,
        vector<int>& arr,
        int k,
        vector<int>& dp
    ) {

        // Base case
        if (index == 0)
            return 0;

        // Already calculated
        if (dp[index] != -1)
            return dp[index];

        int result = INT_MAX;

        // Try all possible jumps
        for (int jump = 1;
             jump <= k && jump <= index;
             jump++) {

            int cost =
                abs(arr[index] - arr[index - jump])
                + minEnergyMemo(
                    index - jump,
                    arr,
                    k,
                    dp
                );

            result = min(result, cost);
        }

        // Store the answer
        dp[index] = result;

        return dp[index];
    }


    // =====================================================
    // 3. BOTTOM-UP DP - TABULATION
    // =====================================================

    /*
        dp[i] =
        minimum energy required to reach index i.

        We calculate from left to right.

        dp[0] = 0

        For every index i:
        Try all possible jumps:

            i - 1
            i - 2
            ...
            i - k

        Recurrence:

        dp[i] = min(
            abs(arr[i] - arr[i-jump])
            + dp[i-jump]
        )


        Time  : O(n * k)
        Space : O(n)
    */

    int minimizeCost(int k, vector<int>& arr) {

        int n = arr.size();

        vector<int> dp(n, -1);

        // Starting point
        dp[0] = 0;

        for (int i = 1; i < n; i++) {

            int result = INT_MAX;

            // Try every possible jump
            for (int jump = 1;
                 jump <= k && jump <= i;
                 jump++) {

                result = min(
                    result,
                    abs(arr[i] - arr[i - jump])
                    + dp[i - jump]
                );
            }

            dp[i] = result;
        }

        return dp[n - 1];
    }
};


/*
    ========================================================
                       DP THINKING
    ========================================================

    Recursion:

        minEnergy(i)
              ↓
        Try k possible jumps
              ↓
        minEnergy(i-jump)


    Memoization:

        Same recursive calls repeat.

        So store:

            dp[i] = answer for index i


    Tabulation:

        Instead of recursion:

            dp[0]
            dp[1]
            dp[2]
            ...
            dp[n-1]


    ========================================================
                       COMPLEXITY
    ========================================================

    Recursion:
        Time  : O(k^n) approximately
        Space : O(n)

    Memoization:
        Time  : O(n * k)
        Space : O(n)

    Tabulation:
        Time  : O(n * k)
        Space : O(n)


    ========================================================
                    IMPORTANT LESSON
    ========================================================

    Unlike House Robber, we generally cannot reduce
    this DP to O(1) space.

    Why?

    dp[i] can depend on:

        dp[i-1]
        dp[i-2]
        dp[i-3]
        ...
        dp[i-k]

    We may need up to k previous values.

    Therefore:

        Space = O(n)

    is the normal tabulation solution.
*/