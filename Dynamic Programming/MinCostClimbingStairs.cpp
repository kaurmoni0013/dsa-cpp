/*
===========================================================
             MIN COST CLIMBING STAIRS (LEETCODE - 746)
===========================================================

Problem:
You are given an array cost[] where cost[i] is the cost
of stepping on stair i.

You can climb either:
    - 1 step
    - 2 steps

You can start from step 0 or step 1.

Find the minimum cost required to reach the top.

===========================================================
RECURRENCE
===========================================================

To reach step i, we can come from:

    i - 1
    i - 2

Therefore:

dp[i] = min(
    dp[i-1] + cost[i-1],
    dp[i-2] + cost[i-2]
)

===========================================================
APPROACHES
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

4. Space Optimized DP
   TC = O(n)
   SC = O(1)

===========================================================
PS / WHAT I LEARNED
===========================================================

- First identify the recurrence.
- At every step, there are two possible previous states.
- Simple recursion creates repeated subproblems.
- Memoization stores already calculated answers.
- Tabulation builds answers from smaller states.
- Since dp[i] only depends on dp[i-1] and dp[i-2],
  the complete DP array is not required.
- Therefore, space can be optimized from O(n) to O(1).

===========================================================
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
===========================================================
APPROACH 1: RECURSION
===========================================================

TC = O(2^n)
SC = O(n)
*/

int minCostRecursion(vector<int>& cost, int n) {

    // Starting from step 0 or 1 costs nothing
    if (n <= 1)
        return 0;

    return min(
        cost[n - 1] + minCostRecursion(cost, n - 1),
        cost[n - 2] + minCostRecursion(cost, n - 2)
    );
}


/*
===========================================================
APPROACH 2: MEMOIZATION / TOP-DOWN DP
===========================================================

TC = O(n)
SC = O(n)

dp[n] stores the minimum cost required to reach step n.
*/

int minCostMemo(
    vector<int>& cost,
    int n,
    vector<int>& dp
) {

    // Base case
    if (n <= 1)
        return 0;

    // Already calculated
    if (dp[n] != -1)
        return dp[n];

    // Calculate and store answer
    return dp[n] = min(
        cost[n - 1] + minCostMemo(cost, n - 1, dp),
        cost[n - 2] + minCostMemo(cost, n - 2, dp)
    );
}


/*
===========================================================
APPROACH 3: TABULATION / BOTTOM-UP DP
===========================================================

TC = O(n)
SC = O(n)
*/

int minCostTabulation(vector<int>& cost) {

    int n = cost.size();

    // dp[i] = minimum cost to reach step i
    vector<int> dp(n + 1, 0);

    // dp[0] = 0
    // dp[1] = 0

    for (int i = 2; i <= n; i++) {

        dp[i] = min(
            dp[i - 1] + cost[i - 1],
            dp[i - 2] + cost[i - 2]
        );
    }

    return dp[n];
}


/*
===========================================================
APPROACH 4: SPACE OPTIMIZED DP
===========================================================

We only need:

    dp[i-1]
    dp[i-2]

So we don't need the complete DP array.

pre2 = dp[i-2]
pre1 = dp[i-1]
curr = dp[i]

TC = O(n)
SC = O(1)
*/

int minCostSpaceOptimized(vector<int>& cost) {

    int n = cost.size();

    // dp[0] = 0
    // dp[1] = 0

    int pre2 = 0;
    int pre1 = 0;

    for (int i = 2; i <= n; i++) {

        int curr = min(
            pre1 + cost[i - 1],
            pre2 + cost[i - 2]
        );

        // Move previous states
        pre2 = pre1;
        pre1 = curr;
    }

    return pre1;
}


int main() {

    vector<int> cost = {10, 15, 20};

    cout << "Recursion: "
         << minCostRecursion(cost, cost.size())
         << endl;

    vector<int> dp(cost.size() + 1, -1);

    cout << "Memoization: "
         << minCostMemo(cost, cost.size(), dp)
         << endl;

    cout << "Tabulation: "
         << minCostTabulation(cost)
         << endl;

    cout << "Space Optimized DP: "
         << minCostSpaceOptimized(cost)
         << endl;

    return 0;
}


/*
===========================================================
FINAL SUMMARY
===========================================================

Approach              TC          SC
-----------------------------------------------------------
Recursion             O(2^n)      O(n)
Memoization           O(n)        O(n)
Tabulation            O(n)        O(n)
Space Optimization    O(n)        O(1)
-----------------------------------------------------------

DP THINKING:

Recursion
    ↓
Repeated subproblems
    ↓
Memoization
    ↓
Bottom-Up Tabulation
    ↓
Check dependencies
    ↓
Space Optimization

===========================================================
*/