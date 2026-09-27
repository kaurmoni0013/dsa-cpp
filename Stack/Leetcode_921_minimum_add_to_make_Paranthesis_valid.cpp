
/*
===========================================================
Problem: Minimum Add to Make Parentheses Valid

Platform: LeetCode
Problem No.: 921

-----------------------------------------------------------
Problem Statement:
A parentheses string is valid if:
1. Every opening parenthesis '(' has a matching ')'.
2. Every closing parenthesis ')' has a matching '('.

Given a parentheses string s, return the minimum number
of parentheses that must be added to make the string valid.

-----------------------------------------------------------
Approach:
1. Use a stack to store unmatched opening parentheses '('.
   (class StackApproach)
2. Traverse the string:
   - If the character is '(', push it into the stack.
   - If the character is ')':
       a. If there is a matching '(' in the stack, pop it.
       b. Otherwise, this ')' is unmatched, so increment count.
3. After traversing the string, any '(' left in the stack
   is unmatched, so add its count to the answer.
4. Return count.

-----------------------------------------------------------
Example:
Input:
s = "()))(("

Processing:
- The first '(' matches the first ')'.
- One ')' remains unmatched.
- Two '(' remain unmatched.

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

class StackApproach {
public:

    int minAddToMakeValid(string s) {

        stack<char> st;
        long long count = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                st.push('(');
            }
            else {

                if(!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    count++;
                }
            }
        }

        while(!st.empty()) {
            count++;
            st.pop();
        }

        return count;
    }
};

class Solution {
public:

    // Approach 2: Counter (submitted)
    //
    // A stack is not actually needed. We only track how many
    // unmatched '(' we have seen so far.
    //
    // A ')' with left == 0 is unmatched and must be paired by
    // inserting a '(' before it. Any '(' left at the end needs
    // a ')' after it.
    //
    // Time : O(n)
    // Space: O(1)

    int minAddToMakeValid(string s) {
      int count = 0;
      int left = 0;
      for(int i=0; i< s.size(); i++){
        if(s[i] == '('){
            left++;
        }
        else{
            if(left == 0)
            count++;

            else
            left--;
        }
      }
      return abs(count+left);
    }
};


