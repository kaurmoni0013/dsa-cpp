/*
LeetCode 69 - Sqrt(x)
Difficulty: Easy
Topics: Math, Binary Search

------------------------------------------------------------
PROBLEM STATEMENT
------------------------------------------------------------
Given a non-negative integer x, return the square root of x
rounded down to the nearest integer.

You must not use any built-in exponent function or operator.

Example 1:
Input:  x = 4
Output: 2

Example 2:
Input:  x = 8
Output: 2

------------------------------------------------------------
APPROACH
------------------------------------------------------------
We use Binary Search.

For a number x, we need to find the largest integer mid such
that:

    mid * mid <= x

If mid * mid == x:
    We found the exact square root.

If mid * mid < x:
    mid can be a possible answer, but there may be a larger
    valid value. So search in the right half.

If mid * mid > x:
    mid is too large. Search in the left half.

We store the last valid value in 'ans'.

------------------------------------------------------------
ALGORITHM
------------------------------------------------------------
1. If x is 0 or 1, return x.
2. Set low = 1 and high = x.
3. While low <= high:
      a. Find mid.
      b. If mid * mid == x, return mid.
      c. If mid * mid < x:
            store mid in ans
            search right half.
      d. Otherwise:
            search left half.
4. Return ans.

------------------------------------------------------------
CODE
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;

        int low = 1;
        int high = x;
        int ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid * mid == x) {
                return mid;
            }
            else if (mid * mid < x) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

/*
------------------------------------------------------------
DRY RUN
------------------------------------------------------------
x = 8

low = 1, high = 8
mid = 4
4 * 4 = 16 > 8
=> search left

low = 1, high = 3
mid = 2
2 * 2 = 4 < 8
=> ans = 2
=> search right

low = 3, high = 3
mid = 3
3 * 3 = 9 > 8
=> search left

low = 3, high = 2
Loop ends.

Answer = 2

------------------------------------------------------------
TIME COMPLEXITY
------------------------------------------------------------
O(log x)

------------------------------------------------------------
SPACE COMPLEXITY
------------------------------------------------------------
O(1)

------------------------------------------------------------
IMPORTANT POINT
------------------------------------------------------------
We use long long for 'mid' so that mid * mid does not
overflow the int range for large values of x.

------------------------------------------------------------
LEETCODE
------------------------------------------------------------
Question No: 69
Question: Sqrt(x)
Difficulty: Easy
Pattern: Binary Search
*/
