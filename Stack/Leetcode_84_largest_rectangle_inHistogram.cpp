#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: Largest Rectangle in Histogram

Platform: LeetCode
Problem No.: 84
Type: Hard

-----------------------------------------------------------
Problem Statement:
Given an array of integers heights representing the heights
of bars in a histogram, return the area of the largest
rectangle that can be formed in the histogram.

-----------------------------------------------------------
APPROACH 1: NSL + NSR

For every bar:
- NSL = index of the Nearest Smaller element on the Left.
- NSR = index of the Nearest Smaller element on the Right.

The bar can extend from:
    left[i] + 1  to  right[i] - 1

Width:
    right[i] - left[i] - 1

Area:
    heights[i] * width

-----------------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(n)

-----------------------------------------------------------
*/

class Solution {
public:

    void NSR(vector<int>& heights, vector<int>& right) {

        stack<int> st;

        for(int i = 0; i < right.size(); i++) {

            while(!st.empty() &&
                  heights[i] < heights[st.top()]) {

                right[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while(!st.empty()) {

            right[st.top()] = heights.size();
            st.pop();
        }
    }

    void NSL(vector<int>& heights, vector<int>& left) {

        stack<int> st;

        for(int i = left.size() - 1; i >= 0; i--) {

            while(!st.empty() &&
                  heights[i] < heights[st.top()]) {

                left[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while(!st.empty()) {

            left[st.top()] = -1;
            st.pop();
        }
    }

    int largestRectangleArea(vector<int>& heights) {

        vector<int> right(heights.size());
        vector<int> left(heights.size());

        NSL(heights, left);
        NSR(heights, right);

        int ans = 0;

        for(int i = 0; i < heights.size(); i++) {

            ans = max(ans,
                      heights[i] *
                      (right[i] - left[i] - 1));
        }

        return ans;
    }
};


/*
===========================================================
APPROACH 2: Single Stack

Instead of separately calculating NSL and NSR, use one stack.

The stack stores indices of bars in increasing height order.

When a smaller bar is found:
- The current index becomes the right boundary.
- The new stack top becomes the left boundary.
- Calculate the rectangle area for the popped bar.

After traversing the array, process all remaining bars by
considering n as their right boundary.

-----------------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(n)

-----------------------------------------------------------
*/

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {

        int ans = 0;
        int index;
        int n = heights.size();

        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() &&
                  heights[i] < heights[st.top()]) {

                index = st.top();
                st.pop();

                if(!st.empty()) {

                    ans = max(ans,
                              heights[index] *
                              (i - st.top() - 1));
                }
                else {

                    ans = max(ans,
                              heights[index] * i);
                }
            }

            st.push(i);
        }

        // Process remaining bars
        while(!st.empty()) {

            index = st.top();
            st.pop();

            if(!st.empty()) {

                ans = max(ans,
                          heights[index] *
                          (n - st.top() - 1));
            }
            else {

                ans = max(ans,
                          heights[index] * n);
            }
        }

        return ans;
    }
};

