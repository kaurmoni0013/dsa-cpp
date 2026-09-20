/*
===========================================================
Problem: Reverse Degree of a String

Platform: LeetCode
Problem No.: 3498

-----------------------------------------------------------
Problem Statement:
Given a string s, calculate its reverse degree.

For each character:
    reverse position = 26 - (character - 'a')

Multiply this value by the character's 1-based position
in the string and add all the results.

-----------------------------------------------------------
Approach:
1. Traverse the string from left to right.
2. For every character s[i], calculate its reverse alphabet
   position.
3. Multiply it by (i + 1).
4. Add it to the answer.
5. Return the total reverse degree.

-----------------------------------------------------------
Example:
Input:  s = "abc"

Reverse values:
a -> 26
b -> 25
c -> 24

Answer:
26 * 1 + 25 * 2 + 24 * 3
= 26 + 50 + 72
= 148

-----------------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(1)

-----------------------------------------------------------
*/

class Solution {
public:

    int reverseDegree(string s) {

        int i = 0;
        long long degree = 0;

        while (i < s.size()) {

            degree += abs(s[i] - 'a' - 26) * (i + 1);

            i++;
        }

        return degree;
    }
};