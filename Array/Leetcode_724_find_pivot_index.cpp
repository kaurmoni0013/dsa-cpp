#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    LeetCode 724 - Find Pivot Index
    Difficulty: Easy
    Topic: Array, Prefix Sum

    Problem:

    Given an integer array nums, find the leftmost pivot index.

    A pivot index is an index where:

        Sum of elements on the LEFT
        =
        Sum of elements on the RIGHT

    The current element nums[i] is NOT included
    in either leftSum or rightSum.


    Example:

        nums = [1, 7, 3, 6, 5, 6]

        At index 3:

        Left side:
            1 + 7 + 3 = 11

        Right side:
            5 + 6 = 11

        Therefore:
            Answer = 3


    Approach:

    First calculate the total sum of the array.

    Then traverse the array from left to right.

    At every index i:

        rightSum = totalSum - leftSum - nums[i]

    Why?

        totalSum
            =
        leftSum + nums[i] + rightSum

    Therefore:

        rightSum = totalSum - leftSum - nums[i]


    If:

        leftSum == rightSum

    then i is the pivot index.

    We return the first such index because
    the problem asks for the LEFTMOST pivot index.

    If no pivot index exists:

        return -1
*/


class Solution {
public:

    int pivotIndex(vector<int>& nums) {

        /*
            STEP 1:
            Calculate the total sum
            of all elements.
        */

        int totalSum = 0;

        for (int x : nums) {
            totalSum += x;
        }


        /*
            STEP 2:
            Keep track of the sum
            of elements to the left.
        */

        int leftSum = 0;


        /*
            STEP 3:
            Traverse the array.

            At every index:

                rightSum =
                totalSum - leftSum - nums[i]
        */

        for (int i = 0; i < nums.size(); i++) {

            int rightSum =
                totalSum - leftSum - nums[i];


            /*
                Check whether the
                left and right sums are equal.
            */

            if (leftSum == rightSum) {

                return i;
            }


            /*
                Add current element to leftSum
                before moving to the next index.
            */

            leftSum += nums[i];
        }


        /*
            No pivot index was found.
        */

        return -1;
    }
};


/*
    Example:

    nums = [1, 7, 3, 6, 5, 6]


    Total Sum:

        1 + 7 + 3 + 6 + 5 + 6
        = 28


    i = 0

        nums[0] = 1

        leftSum = 0

        rightSum = 28 - 0 - 1
                 = 27

        0 != 27

        leftSum = 0 + 1
                = 1


    i = 1

        nums[1] = 7

        leftSum = 1

        rightSum = 28 - 1 - 7
                 = 20

        1 != 20

        leftSum = 1 + 7
                = 8


    i = 2

        nums[2] = 3

        leftSum = 8

        rightSum = 28 - 8 - 3
                 = 17

        8 != 17

        leftSum = 8 + 3
                = 11


    i = 3

        nums[3] = 6

        leftSum = 11

        rightSum = 28 - 11 - 6
                 = 11

        leftSum == rightSum

        Therefore:

            Answer = 3


    --------------------------------------------

    Important Formula:

        totalSum
            =
        leftSum + nums[i] + rightSum


        Therefore:

        rightSum =
        totalSum - leftSum - nums[i]


    --------------------------------------------

    Approach:

        Calculate total sum
                ↓
        leftSum = 0
                ↓
        Traverse array
                ↓
        Calculate rightSum
                ↓
        leftSum == rightSum ?
             ↙           ↘
           YES            NO
            ↓             ↓
        return i      update leftSum
                          ↓
                     next index


    --------------------------------------------

    Complexity:

        Time  : O(n)

        Space : O(1)


    --------------------------------------------

    Key Concept:

        This is a Prefix Sum / Running Sum problem.

        We don't need to create a separate
        prefix-sum array.

        We only maintain:

            totalSum
            leftSum
            rightSum
*/