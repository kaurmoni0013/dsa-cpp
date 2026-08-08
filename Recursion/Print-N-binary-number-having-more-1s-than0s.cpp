/*
 * Problem: Print N-bit Binary Numbers Having More 1s Than 0s
 * Platform: GeeksforGeeks (GFG)
 * Difficulty: Medium
 *
 * Input:
 * n = 2
 *
 * Output:
 * 11
 * 10
 * 
 * Time Complexity  : O(N × 2^N) worst case
 * Space Complexity : O(N × 2^N) including output
 * Auxiliary Space  : O(N)
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    void solve(int n, int ones, int zeros,
               string& path, vector<string>& ans) {

        // Base case
        if (path.size() == n) {
            ans.push_back(path);
            return;
        }

        // We can always add '1'
        path.push_back('1');

        solve(n, ones + 1, zeros, path, ans);

        // Backtrack
        path.pop_back();

        // Add '0' only if number of 1s is greater than 0s
        if (ones > zeros) {

            path.push_back('0');

            solve(n, ones, zeros + 1, path, ans);

            // Backtrack
            path.pop_back();
        }
    }

    vector<string> nBitBinary(int n) {

        vector<string> ans;
        string path = "";

        solve(n, 0, 0, path, ans);

        return ans;
    }
};

int main() {

    int n;

    cout << "Enter n: ";
    cin >> n;

    Solution obj;

    vector<string> ans = obj.nBitBinary(n);

    cout << "Valid N-bit binary numbers:\n";

    for (string str : ans) {
        cout << str << endl;
    }

    return 0;
}