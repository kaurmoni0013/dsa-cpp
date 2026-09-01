/*
===========================================================
LeetCode 67: Add Binary
===========================================================

Given two binary strings a and b, return their sum as a
binary string.

Example:

a = "11"
b = "1"

Output:
"100"

===========================================================
APPROACH:
===========================================================

1. Start from the rightmost digit of both strings.
2. Add the two digits along with carry.
3. Result digit = sum % 2.
4. Carry = sum / 2.
5. Move both pointers to the left.
6. Continue while either string has digits or carry exists.
7. Since digits are generated from right to left, reverse
   the answer at the end.

Binary addition:

0 + 0 = 0
0 + 1 = 1
1 + 0 = 1
1 + 1 = 10
1 + 1 + 1 = 11

===========================================================
TIME COMPLEXITY:
O(max(n, m))

SPACE COMPLEXITY:
O(max(n, m))
===========================================================
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0;

        string ans = "";

        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;

            if (i >= 0)
            {
                sum += a[i] - '0';
                i--;
            }

            if (j >= 0)
            {
                sum += b[j] - '0';
                j--;
            }

            ans += char((sum % 2) + '0');

            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};