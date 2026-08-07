#include <iostream>
using namespace std;
#include <vector>
// void findP(vector<int>& nums,int n,vector<vector<int>>& ans,vector<int>&temp,vector<bool>& visited){
//     if(n == temp.size()){
//         ans.push_back(temp);
//         return;
//    }
//    for(int i=0;i<n;i++){
//     if(visited[i] == 0){
//         visited[i] = 1;
//         temp.push_back(nums[i]);
//         findP(nums,n,ans,temp,visited);
//         visited[i] = 0;
//         temp.pop_back();
//     }
//    }

// }

void findP(vector<int> &nums, int n, vector<vector<int>> &ans, int index)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < n; i++)
    {
        swap(nums[index], nums[i]);
        findP(nums, n, ans, index + 1);
        swap(nums[index], nums[i]);
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> temp;
    int n = nums.size();
    findP(nums, n, ans, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
