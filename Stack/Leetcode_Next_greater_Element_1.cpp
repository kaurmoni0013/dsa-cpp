/*
===========================================================
        NEXT GREATER ELEMENT I
        LeetCode 496
===========================================================

Problem:
Given two arrays nums1 and nums2, where nums1 is a subset
of nums2, find the next greater element of every element
of nums1.

The Next Greater Element of x is the first element to the
right of x in nums2 that is greater than x.

If no greater element exists, return -1.

Example:
nums1 = [4,1,2]
nums2 = [1,3,4,2]

Answer = [-1,3,-1]


===========================================================
APPROACH 1: BRUTE FORCE
===========================================================

Idea:
For every element of nums1:

1. Find that element in nums2.
2. Once found, start checking elements after it.
3. The first element greater than it is the answer.
4. If no greater element is found, return -1.

IMPORTANT LEARNING:
Initially, I was checking only nums2[j + 1].

That is WRONG because the next greater element does not
have to be the immediate next element.

Example:

nums2 = [6,5,4,3,2,1,7]

For 1:

Immediate next = 7
Answer = 7

But consider:

nums2 = [1,2,3,4]

For 1:
Immediate next = 2 -> answer is 2

Now consider:

nums2 = [6,5,4,3,2,1,7]

For 5:
next element = 4 (not greater)
then 3 (not greater)
then 2 (not greater)
then 1 (not greater)
then 7 (greater)

Answer = 7

Therefore, after finding the position of the element,
we need another loop to search ahead.


Time Complexity:
O(N * M)

Where:
N = nums1.size()
M = nums2.size()

If both arrays have approximately the same size:
O(N^2)

Space Complexity:
O(N)

For the answer array.
*/


#include <bits/stdc++.h>
using namespace std;


// =========================================================
// APPROACH 1: BRUTE FORCE
// =========================================================

class BruteForceSolution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {

        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {

            int digit = nums1[i];
            bool found = false;

            // Step 1: Find digit in nums2
            for(int j = 0; j < nums2.size(); j++) {

                if(digit == nums2[j]) {

                    // Step 2: Search for the first
                    // greater element after digit
                    for(int k = j + 1; k < nums2.size(); k++) {

                        if(nums2[k] > digit) {

                            ans.push_back(nums2[k]);
                            found = true;

                            break;
                        }
                    }

                    // digit is unique in nums2,
                    // so no need to search further.
                    break;
                }
            }

            // No greater element found
            if(found == false) {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};


/*
===========================================================
APPROACH 2: OPTIMIZED
        MONOTONIC STACK + HASH MAP
===========================================================

Idea:

Instead of finding the next greater element separately
for every element of nums1, process nums2 only once.

We maintain a stack of indices.

When nums2[i] is greater than the element at the top
of the stack:

    nums2[i] is the Next Greater Element
    for nums2[st.top()]

So we store:

    element -> next greater element

inside an unordered_map.

Example:

nums2 = [1,3,4,2]

Process:

1 -> stack

3 > 1
Therefore:
1 -> 3

4 > 3
Therefore:
3 -> 4

2 is not greater than 4
Push 2

At the end:
4 -> -1
2 -> -1


Why is this O(N)?

Every element:
- is pushed into the stack once
- is popped from the stack at most once

Therefore total stack operations are O(N).


Time Complexity:
O(N + M)

N = nums1.size()
M = nums2.size()

Space Complexity:
O(M + N)

Hash Map = O(M)
Stack   = O(M)
Answer  = O(N)
*/


// =========================================================
// OPTIMIZED SOLUTION
// =========================================================

class OptimizedSolution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {

        unordered_map<int, int> m;
        stack<int> st;

        // Process nums2
        for(int i = 0; i < nums2.size(); i++) {

            // Current element is greater than
            // stack top -> it is the next greater element
            while(!st.empty() &&
                  nums2[i] > nums2[st.top()]) {

                m[nums2[st.top()]] = nums2[i];

                st.pop();
            }

            st.push(i);
        }

        // Elements remaining in stack
        // don't have any greater element
        while(!st.empty()) {

            m[nums2[st.top()]] = -1;

            st.pop();
        }

        // Build answer for nums1
        vector<int> ans(nums1.size());

        for(int i = 0; i < nums1.size(); i++) {

            ans[i] = m[nums1[i]];
        }

        return ans;
    }
};


/*
===========================================================
KEY LEARNING
===========================================================

Brute Force:

Find element
     ↓
Find its position in nums2
     ↓
Search to the right
     ↓
First greater element = answer


Optimized:

Process nums2 once
     ↓
Maintain monotonic decreasing stack
     ↓
Current element > stack top
     ↓
Current element is the Next Greater Element
     ↓
Store answer in Hash Map
     ↓
Use Hash Map for nums1


IMPORTANT:
Number of loops does NOT directly determine complexity.

The brute-force solution has 3 loops, but its complexity
is O(N * M), not automatically O(N^3).

===========================================================
*/