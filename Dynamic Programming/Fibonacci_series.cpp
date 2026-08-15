/*
===========================================================
                FIBONACCI NUMBER
===========================================================

Problem:
Given n, return the nth Fibonacci number.

Fibonacci:
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2)

===========================================================
MY APPROACHES
===========================================================

1. Recursion
   TC = O(2^n)
   SC = O(n)      -> recursion stack

2. Memoization / Top-Down DP
   TC = O(n)
   SC = O(n)      -> DP array + recursion stack

3. Tabulation / Bottom-Up DP
   TC = O(n)
   SC = O(n)

4. Space Optimized Bottom-Up DP
   TC = O(n)
   SC = O(1)

===========================================================
PS / WHAT I LEARNED
===========================================================

- First I solved Fibonacci using simple recursion.
- Recursion calculates the same subproblems multiple times.
- To avoid repeated calculations, I used Memoization.
- Then I converted the recursive solution into Bottom-Up
  Tabulation.
- Finally, I observed that each Fibonacci value only depends
  on the previous two values.
- Therefore, I removed the complete DP array and optimized
  the space from O(n) to O(1).

Important DP Pattern:

If:

    dp[i] depends only on dp[i-1] and dp[i-2]

then we may not need the complete DP array.

We can keep only the required previous states.

===========================================================
*/


#include <bits/stdc++.h>
using namespace std;


/*
===========================================================
APPROACH 1: RECURSION
===========================================================

Idea:
Directly apply the Fibonacci recurrence:

    F(n) = F(n-1) + F(n-2)

Problem:
The same values are calculated again and again.

Example:

              F(5)
             /    \
          F(4)    F(3)
          /  \    /  \
       F(3) F(2) F(2) F(1)

Here F(3), F(2), etc. are calculated multiple times.

TC = O(2^n)
SC = O(n)  -> recursion stack
*/

int fibRecursion(int n) {

    // Base cases
    if (n <= 1)
        return n;

    return fibRecursion(n - 1) + fibRecursion(n - 2);
}


/*
===========================================================
APPROACH 2: MEMOIZATION / TOP-DOWN DP
===========================================================

Idea:
Use recursion but store already calculated answers in dp[].

If dp[n] is already calculated, return it instead of
calculating it again.

TC = O(n)
SC = O(n)

Why O(n)?

There are n different states:

    dp[0], dp[1], ..., dp[n]

and recursion stack can also go up to O(n).
*/

int fibMemoHelper(int n, vector<int>& dp) {

    // Base cases
    if (n <= 1)
        return n;

    // If already calculated, return stored answer
    if (dp[n] != -1)
        return dp[n];

    // Calculate and store the answer
    return dp[n] =
        fibMemoHelper(n - 1, dp) +
        fibMemoHelper(n - 2, dp);
}


int fibMemoization(int n) {

    // Create DP array
    vector<int> dp(n + 1, -1);

    return fibMemoHelper(n, dp);
}


/*
===========================================================
APPROACH 3: TABULATION / BOTTOM-UP DP
===========================================================

Idea:
Instead of starting from n and going backwards using
recursion, start from the smallest states and build the
answer upward.

dp[0] = 0
dp[1] = 1

Then:

dp[2] = dp[1] + dp[0]
dp[3] = dp[2] + dp[1]
dp[4] = dp[3] + dp[2]
...

TC = O(n)
SC = O(n)
*/

int fibTabulation(int n) {

    // Handle base cases
    if (n <= 1)
        return n;

    // DP array
    vector<int> dp(n + 1, -1);

    // Base values
    dp[0] = 0;
    dp[1] = 1;

    // Build the solution from bottom to top
    for (int i = 2; i <= n; i++) {

        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}


/*
===========================================================
APPROACH 4: SPACE OPTIMIZED BOTTOM-UP DP
===========================================================

Observation:

In Tabulation:

    dp[i] = dp[i-1] + dp[i-2]

We only need the previous two values.

We DON'T need the complete dp[] array.

Therefore:

    pre1 = F(i-2)
    pre2 = F(i-1)
    curr = F(i)

After calculating curr:

    pre1 = pre2
    pre2 = curr

This reduces:

    SC: O(n) -> O(1)

TC = O(n)
SC = O(1)
*/

int fibSpaceOptimized(int n) {

    // Base cases
    if (n <= 1)
        return n;

    // F(0)
    int pre1 = 0;

    // F(1)
    int pre2 = 1;

    // Calculate from F(2) to F(n)
    for (int i = 2; i <= n; i++) {

        // Current Fibonacci number
        int curr = pre1 + pre2;

        // Move the states forward
        pre1 = pre2;
        pre2 = curr;
    }

    // pre2 contains F(n)
    return pre2;
}


/*
===========================================================
FINAL LEARNING

Approach                    Time       Space
-----------------------------------------------------------
Recursion                   O(2^n)     O(n)
Memoization                 O(n)       O(n)
Tabulation                  O(n)       O(n)
Space Optimized DP          O(n)       O(1)
-----------------------------------------------------------

MY DP THINKING:

Recursion
    ↓
Identify repeated subproblems
    ↓
Memoization
    ↓
Convert recursion into iteration
    ↓
Tabulation
    ↓
Check which previous states are actually required
    ↓
Space Optimization


IMPORTANT PATTERN:

If:

    dp[i] = f(dp[i-1], dp[i-2])

and dp[i] does not depend on older states,

then we can usually optimize O(n) DP space to O(1).

===========================================================
*/


int main() {

    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Recursion: "
         << fibRecursion(n) << endl;

    cout << "Memoization: "
         << fibMemoization(n) << endl;

    cout << "Tabulation: "
         << fibTabulation(n) << endl;

    cout << "Space Optimized DP: "
         << fibSpaceOptimized(n) << endl;

    return 0;
}