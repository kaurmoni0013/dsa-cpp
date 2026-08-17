/*
===========================================================
                CLIMBING STAIRS
===========================================================

Problem:
You are climbing a staircase. It takes n steps to reach
the top.

You can climb either:
    - 1 step
    - 2 steps

Return the number of distinct ways to reach the top.

Example:
n = 3

Ways:
1 + 1 + 1
1 + 2
2 + 1

Answer = 3

===========================================================
MY APPROACHES
===========================================================

1. Recursion
   TC = O(2^n)
   SC = O(n)

2. Memoization / Top-Down DP
   TC = O(n)
   SC = O(n)

3. Tabulation / Bottom-Up DP
   TC = O(n)
   SC = O(n)

4. Space Optimized Bottom-Up DP
   TC = O(n)
   SC = O(1)

===========================================================
PS / WHAT I LEARNED
===========================================================

The main observation is:

    ways(n) = ways(n-1) + ways(n-2)

Why?

To reach the nth stair, I can come from:

    1. (n-1)th stair by taking 1 step
    2. (n-2)th stair by taking 2 steps

Therefore:

    ways(n) = ways(n-1) + ways(n-2)

This creates the same pattern as Fibonacci.

But the starting values are different:

    Fibonacci:
    F(0) = 0
    F(1) = 1

    Climbing Stairs:
    ways(1) = 1
    ways(2) = 2

===========================================================
*/


#include <bits/stdc++.h>
using namespace std;


/*
===========================================================
APPROACH 1: RECURSION
===========================================================

For every stair, we have two choices:

    Take 1 step
    Take 2 steps

So:

    ways(n) = ways(n-1) + ways(n-2)

TC = O(2^n)
SC = O(n) -> recursion stack
*/

int climbRecursion(int n) {

    // Base cases
    if (n <= 2)
        return n;

    return climbRecursion(n - 1) +
           climbRecursion(n - 2);
}


/*
===========================================================
APPROACH 2: MEMOIZATION / TOP-DOWN DP
===========================================================

Use recursion but store already calculated values
in the dp array.

This avoids calculating the same subproblem repeatedly.

TC = O(n)
SC = O(n)
*/

int climbMemoHelper(int n, vector<int>& dp) {

    // Base cases
    if (n <= 2)
        return n;

    // Already calculated
    if (dp[n] != -1)
        return dp[n];

    // Calculate and store
    return dp[n] =
        climbMemoHelper(n - 1, dp) +
        climbMemoHelper(n - 2, dp);
}


int climbMemoization(int n) {

    vector<int> dp(n + 1, -1);

    return climbMemoHelper(n, dp);
}


/*
===========================================================
APPROACH 3: TABULATION / BOTTOM-UP DP
===========================================================

Instead of recursion, build the answer from smaller
subproblems.

    dp[1] = 1
    dp[2] = 2

Then:

    dp[i] = dp[i-1] + dp[i-2]

TC = O(n)
SC = O(n)
*/

int climbTabulation(int n) {

    // Base cases
    if (n <= 2)
        return n;

    // DP array
    vector<int> dp(n + 1, 0);

    dp[1] = 1;
    dp[2] = 2;

    // Build the answer
    for (int i = 3; i <= n; i++) {

        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}


/*
===========================================================
APPROACH 4: SPACE OPTIMIZED BOTTOM-UP DP
===========================================================

Observation:

    dp[i] = dp[i-1] + dp[i-2]

We only need the previous two values.

Therefore, we don't need the complete dp array.

    pre1 = ways(i-2)
    pre2 = ways(i-1)

After calculating current:

    pre1 = pre2
    pre2 = current

TC = O(n)
SC = O(1)
*/

int climbSpaceOptimized(int n) {

    // Base cases
    if (n <= 2)
        return n;

    // ways(1)
    int pre1 = 1;

    // ways(2)
    int pre2 = 2;

    // Calculate ways from 3 to n
    for (int i = 3; i <= n; i++) {

        // Current number of ways
        int temp = pre1 + pre2;

        // Move previous states forward
        pre1 = pre2;
        pre2 = temp;
    }

    // pre2 contains ways(n)
    return pre2;
}


/*
===========================================================
FINAL LEARNING
===========================================================

Approach                    Time       Space
-----------------------------------------------------------
Recursion                   O(2^n)     O(n)
Memoization                 O(n)       O(n)
Tabulation                  O(n)       O(n)
Space Optimized DP          O(n)       O(1)
-----------------------------------------------------------

IMPORTANT OBSERVATION:

Climbing Stairs is basically Fibonacci.

Fibonacci:

    0, 1, 1, 2, 3, 5, 8...

Climbing Stairs:

    1, 2, 3, 5, 8, 13...

The recurrence is the same:

    current = previous + previous_previous

Only the base cases are different.

===========================================================
*/


int main() {

    int n;

    cout << "Enter number of stairs: ";
    cin >> n;

    cout << "Recursion: "
         << climbRecursion(n) << endl;

    cout << "Memoization: "
         << climbMemoization(n) << endl;

    cout << "Tabulation: "
         << climbTabulation(n) << endl;

    cout << "Space Optimized DP: "
         << climbSpaceOptimized(n) << endl;

    return 0;
}