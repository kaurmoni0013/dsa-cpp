/*
Problem: Print N-bit binary numbers having more 1s tan 0s
Platform: GFG
Difficulty: Medium
input n=2
output ["11","10"]
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    void solve(int n, int ones, int zeros,
               string &path, vector<string> &ans) {

        // Base case
        if (path.size() == n) {
            ans.push_back(path);
            return;
        }

        // Add 1
        path.push_back('1');
        solve(n, ones + 1, zeros, path, ans);
        path.pop_back();

        // Add 0 only when 1s > 0s
        if (ones > zeros) {
            path.push_back('0');
            solve(n, ones, zeros + 1, path, ans);
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

    for (string str : ans) {
        cout << str << endl;
    }

    return 0;
}
