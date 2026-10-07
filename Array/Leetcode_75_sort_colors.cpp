#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: Sort Colors

Platform: LeetCode
Problem No.: 75
Type: Medium

-----------------------------------------------------------
Problem Statement:
Given an array nums with n objects colored red, white, or
blue, sort them in-place so that objects of the same color
are adjacent, with colors in the order:

0 -> Red
1 -> White
2 -> Blue

You must solve this problem without using the library's
sort function.

-----------------------------------------------------------
APPROACH 1: Counting

Idea:
1. Count the number of 0s, 1s, and 2s.
2. Fill the array again:
   - First all 0s
   - Then all 1s
   - Then all 2s

-----------------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(1)

-----------------------------------------------------------
*/

class Solution {
public:

    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int red = 0;
        int white = 0;
        int blue = 0;

        // Count 0s, 1s and 2s
        for(int i = 0; i < n; i++) {

            if(nums[i] == 0)
                red++;

            else if(nums[i] == 1)
                white++;

            else
                blue++;
        }

        // Fill 0s
        for(int i = 0; i < red; i++)
            nums[i] = 0;

        // Fill 1s
        for(int i = red; i < red + white; i++)
            nums[i] = 1;

        // Fill 2s
        for(int i = red + white; i < n; i++)
            nums[i] = 2;
    }
};


/*
===========================================================
APPROACH 2: Dutch National Flag Algorithm

Idea:
Maintain three regions:

    [0 ... low-1]       -> 0
    [low ... mid-1]     -> 1
    [mid ... high]      -> Unknown
    [high+1 ... n-1]    -> 2

Rules:

1. nums[mid] == 0:
   Swap nums[low] and nums[mid].
   Move low and mid forward.

2. nums[mid] == 1:
   It is already in the correct middle region.
   Move mid forward.

3. nums[mid] == 2:
   Swap nums[mid] with nums[high].
   Move high backward.

IMPORTANT:
When nums[mid] == 2, we do NOT increment mid because the
element coming from high has not been checked yet.

-----------------------------------------------------------
Example:
Input:
nums = [2, 0, 2, 1, 1, 0]

Output:
[0, 0, 1, 1, 2, 2]

-----------------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(1)

-----------------------------------------------------------
*/

class Solution {
public:

    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int low = 0;
        int mid = 0;
        int high = n - 1;

        while(mid <= high) {

            if(nums[mid] == 0) {

                swap(nums[low], nums[mid]);

                low++;
                mid++;
            }

            else if(nums[mid] == 1) {

                mid++;
            }

            else {

                swap(nums[high], nums[mid]);

                high--;
            }
        }
    }
};

