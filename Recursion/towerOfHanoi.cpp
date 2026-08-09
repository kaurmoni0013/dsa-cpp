/*
 * Problem: Tower of Hanoi
 * Platform: GFG / Practice
 * Topic: Recursion
 * Difficulty: Easy
 *
 * Description:
 * Move N disks from the source rod to the destination rod
 * using a helper rod while following the rules of Tower of Hanoi.
 *
 * Rules:
 * 1. Only one disk can be moved at a time.
 * 2. Only the top disk can be moved.
 * 3. A larger disk cannot be placed on a smaller disk.
 *
 * Number of moves required:
 * 2^n - 1
 */

#include <iostream>
using namespace std;

void TOH(int n, int source, int helper, int destination)
{
    // Base case
    if (n == 0)
        return;

    // Move n-1 disks from source to helper
    TOH(n - 1, source, destination, helper);

    // Move the largest disk from source to destination
    cout << "Move disk " << n
         << " from " << source
         << " to " << destination << endl;

    // Move n-1 disks from helper to destination
    TOH(n - 1, helper, source, destination);
}

int main()
{
    int n;

    cout << "Enter the number of disks: ";
    cin >> n;

    cout << "\nSequence of moves:\n";

    TOH(n, 1, 2, 3);

    return 0;
}