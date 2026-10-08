#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: Pascal's Triangle

Platform: LeetCode
Problem No.: 118
Type: Easy

-----------------------------------------------------------
Problem Statement:
Given an integer numRows, return the first numRows of
Pascal's triangle.

In Pascal's triangle:
- The first and last element of every row is 1.
- Every middle element is the sum of the two elements
  directly above it.

Example:

        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1

-----------------------------------------------------------
APPROACH 1: Generate Complete Pascal's Triangle

For every row, calculate each element using:

    C(row - 1, col)

Instead of calculating factorials, use:

    ans = ans * (row - col) / col

This avoids unnecessary factorial calculations.

-----------------------------------------------------------
Time Complexity:
O(n²)

Space Complexity:
O(n²)

-----------------------------------------------------------
*/

class Solution {
public:

    // Generate one row of Pascal's Triangle
    vector<int> generateRow(int row) {

        long long ans = 1;

        vector<int> ansRow;

        ansRow.push_back(1);

        for(int col = 1; col < row; col++) {

            ans *= (row - col);
            ans /= col;

            ansRow.push_back(ans);
        }

        return ansRow;
    }

    // Generate complete Pascal's Triangle
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        for(int i = 1; i <= numRows; i++) {

            ans.push_back(generateRow(i));
        }

        return ans;
    }
};


/*
===========================================================
Problem: Pascal's Triangle II

Platform: LeetCode
Problem No.: 119
Type: Easy

-----------------------------------------------------------
Problem Statement:
Given an integer rowIndex, return the rowIndex-th row of
Pascal's triangle.

NOTE:
LeetCode uses 0-based row indexing.

For example:
rowIndex = 3

Answer:
[1, 3, 3, 1]

-----------------------------------------------------------
APPROACH 2: Generate Any Nth Row

For the Nth row, use the same combination formula:

    C(n, 0) = 1

Then:

    C(n, k) = C(n, k-1) * (n-k+1) / k

This generates the entire row without generating the
previous rows.

-----------------------------------------------------------
Example:

Input:
rowIndex = 4

Output:
[1, 4, 6, 4, 1]

-----------------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(n)

-----------------------------------------------------------
*/

vector<int> getNthRow(int n) {

    vector<int> row;

    long long ans = 1;

    row.push_back(1);

    for(int k = 1; k <= n; k++) {

        ans = ans * (n - k + 1) / k;

        row.push_back(ans);
    }

    return row;
}


/*
===========================================================
Problem: Find Element at a Given Position in Pascal's Triangle

Platform: General DSA / Maths

-----------------------------------------------------------
Problem Statement:
Given a row number n and column number r, find the element
at that position in Pascal's Triangle.

Here we use 1-based indexing:

        1
       1 1
      1 2 1
     1 3 3 1

For example:

n = 5
r = 3

Answer = 6

Because:

        1  4  6  4  1
             ^
             3rd element

-----------------------------------------------------------
APPROACH 3: Optimal Combination Formula

Every element in Pascal's Triangle is:

    C(n-1, r-1)

So instead of generating the complete triangle, calculate
only the required combination.

Formula:

    C(n, r) = n! / (r! * (n-r)!)

But we should NOT calculate factorials directly because
factorials become very large.

Instead:

    C(n, r)
    = C(n, r-1) * (n-r+1) / r

We can also use:

    r = min(r, n-r)

to reduce the number of iterations.

-----------------------------------------------------------
Example:

Input:
n = 5
r = 3

We need:

C(4, 2)

= (4 * 3) / (1 * 2)
= 6

Output:
6

-----------------------------------------------------------
Time Complexity:
O(min(r, n-r))

Space Complexity:
O(1)

-----------------------------------------------------------
*/

long long getElement(int n, int r) {

    // Convert from 1-based row/column
    // to combination C(n-1, r-1)

    n = n - 1;
    r = r - 1;

    // Use the smaller side
    r = min(r, n - r);

    long long ans = 1;

    for(int i = 1; i <= r; i++) {

        ans = ans * (n - i + 1) / i;
    }

    return ans;
}


/*
===========================================================
SUMMARY
===========================================================

1. Complete Pascal's Triangle:

    generate(numRows)

    Time: O(n²)
    Space: O(n²)


2. Generate Nth Row:

    getNthRow(n)

    Time: O(n)
    Space: O(n)


3. Find One Element:

    getElement(n, r)

    Time: O(min(r, n-r))
    Space: O(1)

-----------------------------------------------------------
IMPORTANT FORMULAS:

Complete row:

    C(n, k) = C(n, k-1) * (n-k+1) / k

Element at row n, column r:

    C(n-1, r-1)

-----------------------------------------------------------
*/