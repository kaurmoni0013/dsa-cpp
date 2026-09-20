#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: Backspace String Compare

Platform: LeetCode
Problem No.: 844

-----------------------------------------------------------
Problem Statement:
Given two strings s and t, determine whether they are equal
after applying backspaces.

A '#' character represents a backspace. A backspace removes
the character immediately before it, if one exists.

-----------------------------------------------------------
APPROACH 1: Using Stack

Idea:
- Traverse each string from left to right.
- If the character is not '#', push it into the stack.
- If the character is '#', remove the top character if the
  stack is not empty.
- Build the final strings and compare them.

-----------------------------------------------------------
Example:
Input:
s = "ab#c"
t = "ad#c"

After applying backspaces:
s = "ac"
t = "ac"

Output:
true

-----------------------------------------------------------
Time Complexity:
O(n + m)

Space Complexity:
O(n + m)

-----------------------------------------------------------
*/

class Solution {
public:

    bool backspaceCompare(string s, string t) {

        stack<char> st;

        // Process string s
        int i = 0;

        while(i < s.size()) {

            if(s[i] != '#') {
                st.push(s[i]);
            }
            else {
                if(!st.empty())
                    st.pop();
            }

            i++;
        }

        // Construct final s
        string new_s;

        while(!st.empty()) {
            new_s += st.top();
            st.pop();
        }

        // Process string t
        i = 0;

        while(i < t.size()) {

            if(t[i] != '#') {
                st.push(t[i]);
            }
            else {
                if(!st.empty())
                    st.pop();
            }

            i++;
        }

        // Construct final t
        string new_t;

        while(!st.empty()) {
            new_t += st.top();
            st.pop();
        }

        return new_s == new_t;
    }
};


/*
===========================================================
APPROACH 2: Two Pointers (Optimized)

Idea:
Instead of actually creating the resulting strings, traverse
both strings from right to left.

- '#' means the next valid character should be skipped.
- skipS stores how many characters must be skipped in s.
- skipT stores how many characters must be skipped in t.
- Compare the characters that survive the backspaces.

This avoids using a stack and avoids constructing new strings.

-----------------------------------------------------------
Time Complexity:
O(n + m)

Space Complexity:
O(1)

-----------------------------------------------------------
*/

class Solution {
public:

    // Move i to the next character that survives backspaces
    void getValid(string &s, int &i, int &skip) {

        while(i >= 0) {

            if(s[i] == '#') {
                skip++;
                i--;
            }
            else if(skip > 0) {
                skip--;
                i--;
            }
            else {
                break;
            }
        }
    }

    bool backspaceCompare(string s, string t) {

        int i = s.size() - 1;
        int j = t.size() - 1;

        int skipS = 0;
        int skipT = 0;

        while(i >= 0 || j >= 0) {

            // Find valid character in s
            getValid(s, i, skipS);

            // Find valid character in t
            getValid(t, j, skipT);

            // Both strings finished
            if(i < 0 && j < 0)
                return true;

            // Only one string finished
            if(i < 0 || j < 0)
                return false;

            // Compare valid characters
            if(s[i] != t[j])
                return false;

            // Move both pointers
            i--;
            j--;
        }

        return true;
    }
};
