// # Make Array Beautiful

// ## Problem

// Given an array of negative and non-negative integers, make the array beautiful.

// An array is beautiful if every pair of adjacent integers has the same sign.

// You can perform the following operation any number of times:

// * If two adjacent integers have different signs, remove both.
// * `0` is considered **positive**.
// * Scan the array from left to right for consistency.

// Return the resulting beautiful array.

// ### Example

// ```text
// Input:
// [4, 2, -2, 1]

// Output:
// [4, 1]
// ```

// ---

// ## Approach — Stack

// We process the array from **left to right**.

// Use a stack to store the elements that are currently part of the beautiful portion.

// For every element:

// 1. If the stack is empty → push it.
// 2. If stack top and current element have the **same sign** → push it.
// 3. If they have **different signs** → pop the stack top and **do not push the current element**, because both elements get removed.

// Since `0` is positive:

// ```cpp
// positive → >= 0
// negative → < 0
// ```

// At the end, elements come out of the stack in reverse order, so reverse the answer.

// ---

// ## Code

// ```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> makeBeautiful(vector<int> arr) {

        stack<int> st;

        for (int i = 0; i < arr.size(); i++) {

            if (st.empty()) {
                st.push(arr[i]);
            }
            else if ((st.top() >= 0 && arr[i] >= 0) ||
                     (st.top() < 0 && arr[i] < 0)) {

                st.push(arr[i]);
            }
            else {
                st.pop();
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
// ```

// ---

// ## Dry Run

// Input:

// ```text
// [2, 1, -4, 3, -5, 2, 6, -3]
// ```

// | Current | Stack     | Action                   |
// | ------- | --------- | ------------------------ |
// | `2`     | `[2]`     | Push                     |
// | `1`     | `[2,1]`   | Same sign → Push         |
// | `-4`    | `[2]`     | Different sign → Pop `1` |
// | `3`     | `[2,3]`   | Same sign → Push         |
// | `-5`    | `[2]`     | Different sign → Pop `3` |
// | `2`     | `[2,2]`   | Same sign → Push         |
// | `6`     | `[2,2,6]` | Same sign → Push         |
// | `-3`    | `[2,2]`   | Different sign → Pop `6` |

// Final stack:

// ```text
// [2, 2]
// ```

// Answer:

// ```text
// [2, 2]
// ```

// ---

// ## Time Complexity

// Each element is pushed and popped at most once.

// ```text
// Time: O(n)
// ```

// ## Space Complexity

// The stack can contain all `n` elements in the worst case.

// ```text
// Space: O(n)
// ```

// ## Important Point

// When opposite signs are found:

// ```cpp
// st.pop();
// ```

// **Do not push the current element.**

// Both elements are removed.

// For example:

// ```text
// Stack:  [2, 5]
// Current: -3

// 5 and -3 cancel

// Stack:  [2]
// ```

// The `-3` is also gone.
