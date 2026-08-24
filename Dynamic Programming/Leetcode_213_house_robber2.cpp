#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    LeetCode 213 - House Robber II
    Difficulty: Medium
    Topic: Dynamic Programming

    Difference from House Robber I:
    Houses are arranged in a circle.

    Therefore:
    House 0 and House n-1 are adjacent.
    We cannot rob both.

    So we divide the problem into two cases:

    Case 1:
        Don't rob house n-1
        Consider houses: 0 ... n-2

    Case 2:
        Don't rob house 0
        Consider houses: 1 ... n-1

    Then take the maximum of both cases.

    We use the same space-optimized DP
    from House Robber I.
*/


class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();

        // Edge cases
        if (n == 1)
            return nums[0];

        if (n == 2)
            return max(nums[0], nums[1]);


        /*
            CASE 1:
            Don't rob the last house.

            Consider:
            [0 ... n-2]
        */

        int prev2 = nums[0];

        int prev1 = max(nums[0], nums[1]);

        for (int i = 2; i < n - 1; i++) {

            int current = max(
                nums[i] + prev2,
                prev1
            );

            prev2 = prev1;
            prev1 = current;
        }

        int case1 = prev1;


        /*
            CASE 2:
            Don't rob the first house.

            Consider:
            [1 ... n-1]
        */

        prev2 = nums[1];

        prev1 = max(nums[1], nums[2]);

        for (int i = 3; i < n; i++) {

            int current = max(
                nums[i] + prev2,
                prev1
            );

            prev2 = prev1;
            prev1 = current;
        }

        int case2 = prev1;


        // Best of the two cases
        return max(case1, case2);
    }
};


/*
    Example:

    nums = [2, 3, 2]

    Case 1:
        Don't rob last house
        [2, 3]
        Maximum = 3

    Case 2:
        Don't rob first house
        [3, 2]
        Maximum = 3

    Answer = 3


    --------------------------------------------

    DP progression:

    House Robber I:
        Recursion
            ↓
        Memoization
            ↓
        Tabulation
            ↓
        Space Optimization

    House Robber II:
        Circular array
            ↓
        Split into two linear problems
            ↓
        Apply House Robber I
            ↓
        Take maximum
        

    Complexity:

        Time  : O(n)
        Space : O(1)
*/