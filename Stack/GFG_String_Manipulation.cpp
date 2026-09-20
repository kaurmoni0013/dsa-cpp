/*
===========================================================
Problem: Remove Consecutive Same

Platform: GeeksforGeeks (GFG)

Problem No.: N/A

-----------------------------------------------------------
Problem Statement:
Given an array of strings, repeatedly remove two consecutive
equal strings.

Return the number of strings remaining after all possible
removals.

-----------------------------------------------------------
Approach:
1. Use a stack to keep track of the remaining strings.
2. Traverse the array from left to right.
3. If the stack is empty, push the current string.
4. If the top of the stack is equal to the current string,
   pop the top element because the consecutive pair cancels.
5. Otherwise, push the current string.
6. The final stack size is the answer.

-----------------------------------------------------------
Example:
Input:
arr = {"ab", "aa", "aa", "bcd", "ab"}

Output:
3

-----------------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(n)

-----------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:

    int removeConsecutiveSame(vector<string>& arr) {

        stack<string> st;

        for(int i = 0; i < arr.size(); i++) {

            if(st.empty())
                st.push(arr[i]);

            else if(st.top() == arr[i])
                st.pop();

            else
                st.push(arr[i]);
        }

        return st.size();
    }
};
