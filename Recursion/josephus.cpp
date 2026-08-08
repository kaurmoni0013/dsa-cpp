/*
 * Problem: Find the Winner of the Circular Game
 * Platform: LeetCode
 * Problem No: 1823
 * Difficulty: Medium
 *
 * Description:
 * There are n players standing in a circle.
 * Starting from player 1, every k-th player is eliminated.
 * The process continues until only one player remains.
 *
 * Example:
 * Input:  n = 5, k = 2
 * Output: 3
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // ---------------------------------------------------------
    // Approach 1: Simulation
    // Time Complexity: O(n * k)
    // Space Complexity: O(n)
    // ---------------------------------------------------------

    int winner(vector<bool>& person, int index, int n,
               int k, int personLeft) {

        // Only one player remains
        if (personLeft == 1) {
            for (int i = 0; i < n; i++) {
                if (person[i] == 0)
                    return i;
            }
        }

        // Find the position of the player to eliminate
        int kill = (k - 1) % personLeft;

        while (kill--) {
            index = (index + 1) % n;

            // Skip eliminated players
            while (person[index] == 1) {
                index = (index + 1) % n;
            }
        }

        // Eliminate current player
        person[index] = 1;

        // Move to the next alive player
        while (person[index] == 1) {
            index = (index + 1) % n;
        }

        return winner(person, index, n, k, personLeft - 1);
    }

    int findTheWinnerSimulation(int n, int k) {
        vector<bool> person(n, false);

        return winner(person, 0, n, k, n) + 1;
    }


    // ---------------------------------------------------------
    // Approach 2: Optimal Josephus Recurrence
    // Time Complexity: O(n)
    // Space Complexity: O(n) due to recursion stack
    // ---------------------------------------------------------

    int josephus(int n, int k) {

        // Base case
        if (n == 1)
            return 0;

        return (josephus(n - 1, k) + k) % n;
    }

    int findTheWinner(int n, int k) {
        return josephus(n, k) + 1;
    }
};


int main() {

    Solution s1;

    int n, k;

    cout << "Enter the number of players: ";
    cin >> n;

    cout << "Enter the value of k: ";
    cin >> k;

    cout << "Winner: " << s1.findTheWinner(n, k) << endl;

    return 0;
}