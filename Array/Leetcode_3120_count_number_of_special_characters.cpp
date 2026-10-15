/*
Problem: Count the Number of Special Characters
Platform: LeetCode
Problem No.: 3120
Difficulty: Easy
Topic: String, Counting, Arrays

Problem Statement:
Given a string word, count how many English letters
appear in both lowercase and uppercase.

A letter is special if both its lowercase and uppercase
forms appear in the string.

Example:
Input: word = "aaAbcBC"
Output: 3

Explanation:
'a' and 'A' both exist.
'b' and 'B' both exist.
'c' and 'C' both exist.
Therefore, the answer is 3.

Approach:
1. Create two arrays of size 26 to track lowercase
   and uppercase letter frequencies.
2. Traverse the string and count each character.
3. Check all 26 letters.
4. If both lowercase and uppercase forms exist,
   increment the answer.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> upper(26, 0);
        vector<int> lower(26, 0);

        int count = 0;

        for(int i = 0; i < n; i++) {
            if(word[i] == tolower(word[i]))
                lower[word[i] - 'a']++;
            else
                upper[word[i] - 'A']++;
        }

        for(int i = 0; i < 26; i++) {
            if(lower[i] > 0 && upper[i] > 0)
                count++;
        }

        return count;
    }
};